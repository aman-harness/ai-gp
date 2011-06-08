/**
 * Copyright sakef ( http://wonderfl.net/user/sakef )
 * MIT License ( http://www.opensource.org/licenses/mit-license.php )
 * Downloaded from: http://wonderfl.net/c/os6m
 */

/*
    Vectorvision3DがPV3Dに統合されたらしいと。
    ただ、Word3D → text3Dと、VectorShapeMaterial → Letter3DMaterial　となってる。
    ここ以外はたぶん同じ。
*/
package org.n8lm.site
{
    import caurina.transitions.Tweener;
    import flash.display.Sprite;
    import flash.events.Event;
    import flash.filters.BlurFilter;
    import flash.utils.setInterval;
    import org.papervision3d.cameras.Camera3D;
    import org.papervision3d.materials.special.Letter3DMaterial;
    import org.papervision3d.objects.DisplayObject3D;
    import org.papervision3d.render.BasicRenderEngine;
    import org.papervision3d.scenes.Scene3D;
    import org.papervision3d.typography.Text3D;
    import org.papervision3d.typography.fonts.HelveticaBold;
    import org.papervision3d.view.Viewport3D;
    import org.papervision3d.view.layer.ViewportLayer;
    
    public class DisplayText3D extends Sprite
    {
        private var viewport:Viewport3D;
        private var scene:Scene3D;
        private var camera:Camera3D;
        private var render:BasicRenderEngine;
        private var rootNode:DisplayObject3D;
        private var words:Vector.<Text3D>;
        private var theta:Number;
        private var delayTime:Number;
        private var WordMoveType:Number;
        private var _text:String;
		private var texts:Array;
        private static const distance:Number=600;
        
		[SWF(width="800", height="600", backgroundColor="0x000000", frameRate="60")]
        public function DisplayText3D(text:String = "My Workbench No.8 Lightning Man")
        {
			_text = text;
            theta=0;
            WordMoveType=0;
            delayTime=0;
            
            viewport=new Viewport3D(0, 0, true, true);
            scene=new Scene3D();
            camera=new Camera3D();
            render=new BasicRenderEngine();
            rootNode=scene.addChild(new DisplayObject3D("rootNode"));
            addChild(viewport);
            
            camera.target=DisplayObject3D.ZERO;
            camera.zoom=20;
            camera.focus=30;
            
            var mat:Letter3DMaterial = new Letter3DMaterial();
            mat.fillColor = 0xFFFFFF;
            mat.doubleSided = true;
            mat.doubleSided = mat.interactive = true;
			
			texts = new Array;
			texts = text.split('\n');
			words = new Vector.<Text3D>;
			var i:int;
			for (i = 0; i < texts.length; i ++)
			{
				words[i] = new Text3D(texts[i], new HelveticaBold(), mat);
				rootNode.addChild(words[i]);
				words[i].y = -i * 50 + 100;
				words[i].scale = 0.4;
				dispersionWords(words[i]);
			}
            setInterval(moveWords, 10000);
            addEventListener(Event.ENTER_FRAME, onFrame);
        }
        
        private function dispersionWords(words:Text3D):void
        {
            for each(var word:DisplayObject3D in words.letters)
            {
                word.extra={x:word.x, y:word.y, z:word.z};
                word.x=word.y=word.z=word.scale=0;
                Tweener.addTween(word, {scale:1, x:Math.random() * 2000 - 1000, y:Math.random() * 2000 - 1000, z:Math.random() * 2000 - 1000, rotationX:Math.random() * 360, rotationY:Math.random() * 360, rotationZ:Math.random() * 360, time:3, delay:2 * Math.random() + 1});
            }
        }
        
        private function moveWords():void
        {
			var i:int;
            if (WordMoveType % 2 == 0)
            {
				for (i = 0; i < texts.length; i ++)
					resetWords(words[i]);
                delayTime=0;
                WordMoveType++;
            }
            else
            {
				for (i = 0; i < texts.length; i ++)
					breakWords(words[i]);
                WordMoveType++;
            }
        }
        
        private function resetWords(words:Text3D):void
        {
            for each(var word:DisplayObject3D in words.letters)
            {
                Tweener.addTween(word, {x:word.extra.x, y:word.extra.y, z:word.extra.z, rotationX:0, rotationY:0, rotationZ:0, time:1, transition:"easeOutBounce", delay:delayTime});
                Tweener.addTween(word, {rotationY:720, time:1, delay:delayTime + 2});
                delayTime+=0.1;
            }
        }
        
        private function breakWords(words:Text3D):void
        {
            for each(var word:DisplayObject3D in words.letters)
            {
                Tweener.addTween(word, {x:Math.random() * 2000 - 1000, y:Math.random() * 2000 - 1000, z:Math.random() * 2000 - 1000, rotationX:Math.random() * 360, rotationY:Math.random() * 360, rotationZ:Math.random() * 360, time:4, delay:3 * Math.random()});
            }
        }
        
        private function onFrame(e:Event):void
        {
            camera.x=distance * Math.sin(theta * Math.PI / 180);
            camera.z=distance * Math.cos(theta * Math.PI / 180);
            theta+=0.2;
            
			var i:int;
			for (i = 0; i < texts.length; i ++)
				setBlur(words[i]);
            render.renderScene(scene, camera, viewport);
        }
        
        private function DistanceFromCamera(obj:DisplayObject3D):Number
        {
            var vecX:Number=obj.sceneX - camera.x;
            var vecY:Number=obj.sceneY - camera.y;
            var vecZ:Number=obj.sceneZ - camera.z;
            return Math.sqrt((vecX * vecX) + (vecY * vecY) + (vecZ * vecZ));
        }
        
        private function setBlur(words:Text3D):void
        {
            for each(var word:DisplayObject3D in words.letters)
            {
                var vpl:ViewportLayer=word.createViewportLayer(viewport, true);
                var d:Number=Math.abs(DistanceFromCamera(word) - distance) / 40;
                vpl.filters=[new BlurFilter(d, d, 1)];
            }
        }
    }
}