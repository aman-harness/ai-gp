package org.n8lm.site 
{
	import flash.events.Event;
	import flash.events.MouseEvent;
	
	import com.bit101.components.PushButton;
	import com.bit101.components.RadioButton;
	import com.bit101.components.VBox;
	
	import org.papervision3d.core.proto.MaterialObject3D;
	import org.papervision3d.materials.BitmapMaterial;
	import org.papervision3d.objects.DisplayObject3D;
	import org.papervision3d.view.BasicView;
	import org.papervision3d.scenes.Scene3D;
	import org.papervision3d.objects.primitives.Plane;
	import org.papervision3d.events.InteractiveScene3DEvent;
	import org.papervision3d.cameras.CameraType;
	
	import br.com.stimuli.loading.BulkLoader;
	import br.com.stimuli.loading.BulkProgressEvent;
	
	import caurina.transitions.Tweener;
	
	import org.n8lm.button.SmartButton;
	import org.n8lm.site.assets.*;
	/**
	 * ...
	 * @author Alchemist
	 */
	public class PhotoView extends BasicView
	{
		//ui
		private var nextButton:SmartButton;
		private var previousButton:SmartButton;
		
		private var modeBox:VBox;
		private var tileButton:RadioButton;
		private var randomButton:RadioButton;
		
		private var photo3DView:Photo3DView;
		
		private var loadingBar:LoadingBar;
		
		//3d
		private var photos:Vector.<Plane> = new Vector.<Plane>;
		
		//data
		private var xml:XML;
		
		private var loader:BulkLoader = new BulkLoader("photo loader");
		
		private var nowLookId:int = -1;
		private var isLoadFull:Boolean = false;
		
		public function PhotoView() 
		{
			this.addEventListener(Event.ADDED_TO_STAGE, addstage);
			super(640, 480, true, true, CameraType.FREE);
			
			//addChild(photo3DView);
			//3d
			camera.extra = {
				target: new DisplayObject3D()
			}
		}
		
		private function addstage(e:Event):void	{
			removeEventListener(Event.ADDED_TO_STAGE, addstage);
			
			init2D();
			
			stage.addEventListener(Event.RESIZE, resize);
		}		
		
		private function resize(e:Event):void {
			nextButton.x = stage.stageWidth - 160;
			nextButton.y = stage.stageHeight / 2;
			previousButton.x = 10;
			previousButton.y = stage.stageHeight / 2;
			modeBox.y = stage.stageHeight - 50;
			
			graphics.clear();
			graphics.beginFill(0x000000);
			graphics.drawRect(0, 0, stage.stageWidth, stage.stageHeight);
			graphics.endFill();
		}
		
		public function init2D():void {
			
			nextButton = new SmartButton(this, stage.stageWidth - 160, stage.stageHeight / 2 , "Next", nextPhoto);
			previousButton = new SmartButton(this, 10, stage.stageHeight / 2 , "Previous", previousPhoto);
			
			modeBox = new VBox(this, 10, stage.stageHeight - 50);
			tileButton = new RadioButton(modeBox, 0, 0, "Tile" , false , onModeChange);
			tileButton.groupName = "ViewMode";
			randomButton = new RadioButton(modeBox, 0, 0,"Random" ,true , onModeChange);//Need modification
			randomButton.groupName = "ViewMode";
			
			photo3DView = new Photo3DView(stage.stageWidth, stage.stageHeight);
			photo3DView.addEventListener(MouseEvent.CLICK, onPhotoClose);
			photo3DView.addEventListener(Event.COMPLETE, onFullPhotoCompleteHandler);
			
			loadingBar = new LoadingBar();
			loadingBar.x = (stage.stageWidth - loadingBar.width)/ 2;
			loadingBar.y = (stage.stageHeight - loadingBar.height) / 2;
			loadingBar.visible = false;
			addChild(loadingBar);
		}
		
		public function load():void {
			loader.add(Settings.PhotoXmlPath);
			loader.addEventListener(BulkProgressEvent.COMPLETE, onXMLCompleteHandler);
			loader.start();
		}
		
		private function onXMLCompleteHandler(evt : BulkProgressEvent) : void{
			trace("xml items are loaded and ready to consume");
			// Get the xml object:
			xml = loader.getXML(Settings.PhotoXmlPath);
			
			var i:int;
			for (i = 0; i < xml.photo.length(); i ++)
			{
				loader.add(xml.photo[i].toString());
			}
			loader.removeEventListener(BulkProgressEvent.COMPLETE, onXMLCompleteHandler);
			loader.addEventListener(BulkProgressEvent.COMPLETE, onPhotosCompleteHandler);
			loader.start();
		}
		
		private function onPhotosCompleteHandler(evt : BulkProgressEvent) : void {
			
			var delayTime:Number = 0;
			var i:int;
			for (i = 0; i < xml.photo.length(); i ++)
			{
				var mat:MaterialObject3D = new BitmapMaterial(loader.getBitmapData(xml.photo[i].toString()));
				mat.interactive = true;
				mat.doubleSided = true;
				photos[i] = new Plane(mat, xml.photo[i].@width, xml.photo[i].@height);
				photos[i].name = xml.photo[i].@name;
				photos[i].extra = {
					id: i,
					path: xml.photo[i].toString()
				};
				//photos[i].x = photos[i].y = photos[i].z = 0;
				photos[i].addEventListener(InteractiveScene3DEvent.OBJECT_PRESS, onPress);
				photos[i].addEventListener(InteractiveScene3DEvent.OBJECT_OUT, onOut);
				photos[i].addEventListener(InteractiveScene3DEvent.OBJECT_OVER, onOver);
				scene.addChild(photos[i]);
				Tweener.addTween(photos[i], {x:Math.random() * 1000 - 500, y:Math.random() * 1000 - 500, z:Math.random() * 1000 - 500, rotationX:Math.random() * 360, rotationY:Math.random() * 360, rotationZ:Math.random() * 360, time:1, transition:"easeOutSine", delay:delayTime});
				delayTime += 0.1;
			}
			
			this.dispatchEvent(new Event(Event.INIT));
			
			loader.removeEventListener(BulkProgressEvent.COMPLETE, onPhotosCompleteHandler);
			loader.addEventListener(BulkProgressEvent.COMPLETE, onFullPhotoCompleteHandler);
			
			startRendering();
			trace("photo items are loaeded and ready to consume");
		}
		
		private function onFullPhotoCompleteHandler(evt : Event) : void {
			if (xml.photo[nowLookId].@is3d == "false")
			{
				var mat:MaterialObject3D = new BitmapMaterial(loader.getBitmapData((photos[nowLookId].extra.path as String).replace(".", "Full.")));
				mat.interactive = true;
				mat.doubleSided = true;
				photos[nowLookId].material = mat;
			}
			isLoadFull = true;
			loadingBar.visible = false;
		}
		
		override protected function onRenderTick(event:Event = null):void 
		{
			super.onRenderTick(event);
 
			//Rotate the plane
		}
		
		private function onOut(e:InteractiveScene3DEvent):void 
		{
			e.displayObject3D.scale = 1;
			this.buttonMode = false;
		}
		private function onOver(e:InteractiveScene3DEvent):void 
		{
			if (e.displayObject3D.extra.id != nowLookId)
			{
				e.displayObject3D.scale = 1.2;
				this.buttonMode = true;
			}
		}
		
		private function onPress(e:InteractiveScene3DEvent):void 
		{
			trace("press")
			if (nowLookId != e.displayObject3D.extra.id)
			{
				nowLookId = e.displayObject3D.extra.id;
				gotoPhoto(nowLookId);
			}
			
		}
		
		private function onMoveEnd():void 
		{
			if (xml.photo[nowLookId].@is3d == "true")
			{
				addChild(photo3DView);
				photos[nowLookId].visible = false;
			}
			if (!isLoadFull)
			{
				loadingBar.x = (stage.stageWidth - loadingBar.width)/ 2;
				loadingBar.y = (stage.stageHeight - loadingBar.height) / 2;
				loadingBar.visible = true;
			}
			photos[nowLookId].scale = 1;
		}
		
		private function nextPhoto(event:MouseEvent = null):void
		{
			nowLookId ++;
			if (nowLookId >= xml.photo.length())
				nowLookId = 0;
			gotoPhoto(nowLookId);
		}
		
		private function previousPhoto(event:MouseEvent = null):void
		{
			nowLookId --;
			if (nowLookId < 0)
				nowLookId = xml.photo.length() - 1;
			gotoPhoto(nowLookId);
		}
		
		private function gotoPhoto(num:int):void
		{
			camera.extra.target.copyTransform(photos[num]);
			camera.extra.target.moveBackward(100);
			
			isLoadFull = false;
			if (xml.photo[nowLookId].@is3d == "true")
			{
				photo3DView.changeSource((photos[num].extra.path as String).replace(".", "Full."), (photos[num].extra.path as String).replace(".", "Map."));
			}
			else
			{
				loader.add((photos[num].extra.path as String).replace(".", "Full."));
				loader.start();
			}
			Tweener.addTween(camera, { x:camera.extra.target.x, y:camera.extra.target.y, z:camera.extra.target.z, rotationX:camera.extra.target.rotationX, rotationY:camera.extra.target.rotationY, rotationZ:camera.extra.target.rotationZ, time:2, transition:"easeOutSine", onComplete: onMoveEnd } );
		}
		
		private function onPhotoClose(event:MouseEvent):void
		{
			removeChild(photo3DView);
			photos[nowLookId].visible = true;
		}
		
		private function onModeChange(event:MouseEvent):void
		{
			var delayTime:Number = 0;
			var i:int;
			if (tileButton.selected)
			{
				for (i = 0; i < xml.photo.length(); i ++)
				{
					Tweener.addTween(photos[i], {x:(i % 5) * 250 - 500, y:int(i / 5) * 250 - 500, z:0 , rotationX:0, rotationY:0, rotationZ:0, time:1, transition:"easeInSine", delay:delayTime});
					delayTime += 0.05;
				}
			}
			else if (randomButton.selected)
			{
				for (i = 0; i < xml.photo.length(); i ++)
				{
					Tweener.addTween(photos[i], {x:Math.random() * 1000 - 500, y:Math.random() * 1000 - 500, z:Math.random() * 1000 - 500, rotationX:Math.random() * 360, rotationY:Math.random() * 360, rotationZ:Math.random() * 360, time:1, transition:"easeInSine", delay:delayTime});
					delayTime += 0.05;
				}
			}
			Tweener.addTween(camera, { x:0, y:0, z: -1000 , rotationX:0, rotationY:0, rotationZ:0, time:1, transition:"easeInSine" } );
			
			nowLookId = -1;
		}
	}

}