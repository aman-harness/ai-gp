/**
 * Copyright jozefchutka ( http://wonderfl.net/user/jozefchutka )
 * MIT License ( http://www.opensource.org/licenses/mit-license.php )
 * Downloaded from: http://wonderfl.net/c/50I3
 */

package org.n8lm.site 
{
    // read more and download pbk file here:
    // http://3ddm.yoz.sk/
    // http://blog.yoz.sk/2010/05/pixel-bender-displacement-map-fakes-3d-effect
    
    import flash.display.Bitmap;
    import flash.display.BitmapData;
    import flash.display.Loader;
    import flash.display.Shader;
    import flash.display.Sprite;
    import flash.events.Event;
    import flash.events.MouseEvent;
    import flash.filters.BitmapFilterQuality;
    import flash.filters.BlurFilter;
    import flash.filters.ShaderFilter;
	import flash.geom.Point;
    import flash.net.URLLoader;
    import flash.net.URLLoaderDataFormat;
    import flash.net.URLRequest;
    import flash.utils.ByteArray;
	
	import br.com.stimuli.loading.BulkLoader;
	import br.com.stimuli.loading.BulkProgressEvent;
    
    public class Photo3DView extends Sprite
    {
		private var _width:Number;
		private var _height:Number;
		
		private var loader:BulkLoader = new BulkLoader("photoShader loader");
        private var shaderLoader:URLLoader = new URLLoader();
        
        private var shaderURL:String = "displacementMapFader.pbj";
        private var shader:Shader;
        private var filter:ShaderFilter;
        
        private var imageLegend:Bitmap = new Bitmap();
		
		private var imageSource:String;
		private var mapSource:String;
        
        private var imageContainer:Sprite = new Sprite();
        private var shape:Sprite = new Sprite();
        
        public function Photo3DView(w:Number = 800,h:Number = 600):void
        {
			_width = w;
			_height = h;
			
            imageContainer.x = _width/2;
            imageContainer.y = _height/2;
            addChild(imageContainer);
            
            shape.graphics.beginFill(0, 0);
            shape.graphics.drawRect(0, 0, _width, _height);
            shape.graphics.endFill();
            addChild(shape);
			
			
            shaderLoader.dataFormat = URLLoaderDataFormat.BINARY;
            shaderLoader.load(new URLRequest(shaderURL));
            shaderLoader.addEventListener(Event.COMPLETE, shaderComplete);
			/*
			loader.add(shaderURL);
			loader.addEventListener(BulkProgressEvent.COMPLETE, shaderComplete);
			loader.start();
            */
            addEventListener(Event.ENTER_FRAME, enterFrame);
        }
        
        public function changeSource(imagesource:String,mapsource:String):void
        {
			imageSource = imagesource;
			mapSource = mapsource;
            
			loader.add(imageSource);
			loader.add(mapSource);
			loader.addEventListener(BulkProgressEvent.COMPLETE, loadComplete);
			
			loader.start();
            imageContainer.addChild(imageLegend);
        }
        
        private function shaderComplete(event:Event):void
        {			
            //shader = new Shader(loader.getBinary(shaderURL));
            var loader:URLLoader = URLLoader(event.currentTarget);
            shader = new Shader(loader.data as ByteArray);
            filter = new ShaderFilter(shader);
			
			loader.removeEventListener(BulkProgressEvent.COMPLETE, shaderComplete);
        }
        
        private function loadComplete(event:BulkProgressEvent):void
        {
			dispatchEvent(event);
			
			imageLegend.bitmapData = loader.getBitmapData(imageSource);
            imageLegend.x = -imageLegend.width / 2;
            imageLegend.y = -imageLegend.height / 2;
            testComplete();
        }
        
        private function testComplete():void
        {
            if(!filter || !imageLegend.bitmapData)
                return;
                
            var map:BitmapData = loader.getBitmapData(mapSource);
            var image:BitmapData = loader.getBitmapData(imageSource);
            var fader:BitmapData = new BitmapData(image.width, image.height, true, 0);
            fader.draw(image);
            fader.applyFilter(fader, fader.rect, new Point(), 
                new BlurFilter(5, 5, BitmapFilterQuality.HIGH));
            
            shader.data.map.input = map;
            shader.data.fader.input = fader;
            shader.data.fadeNear.value = [0];
            shader.data.fadeDistant.value = [1];
        }
        
        private function enterFrame(event:Event):void
        {
            if(!filter || !imageLegend.bitmapData)
                return;
            
            var dx:Number = (_width / 2 - mouseX);
            var dy:Number = (_height / 2 - mouseY);
            
            imageContainer.rotationX -= (imageContainer.rotationX + dy / 15) / 10;
            imageContainer.rotationY -= (imageContainer.rotationY - dx / 15) / 10;
            
            shader.data.dx.value = [imageContainer.rotationY * 1.5];
            shader.data.dy.value = [-imageContainer.rotationX * 1.5];
            imageLegend.filters = [filter];
        }
    }
}