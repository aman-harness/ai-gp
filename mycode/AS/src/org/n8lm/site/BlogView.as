package org.n8lm.site 
{
	import flash.events.Event;
	import flash.display.Sprite;
	import flash.text.TextField;
	import flash.events.MouseEvent;
	import flash.text.TextFormat;
	import flash.text.TextFieldAutoSize;
	
	import com.bit101.components.PushButton;
	import com.bit101.components.RadioButton;
	import com.bit101.components.VBox;
	
	import flupie.textanim.*;
	
	import br.com.stimuli.loading.BulkLoader;
	import br.com.stimuli.loading.BulkProgressEvent;
	
	import org.papervision3d.events.InteractiveScene3DEvent;
	import org.papervision3d.view.BasicView;
	import org.papervision3d.cameras.CameraType;
	import org.papervision3d.objects.DisplayObject3D;
	
	import caurina.transitions.Tweener;
	/**
	 * ...
	 * @author ...
	 */
	public class BlogView extends BasicView 
	{
		private var modeBox:VBox;
		private var tileButton:RadioButton;
		private var orbitalButton:RadioButton;
		
		private var currentTextField:TextField = new TextField();
		
		private var loader:BulkLoader = new BulkLoader("blog loader");
		
		private var xml:XML;
		private var articles:Vector.<ArticlePlane> = new Vector.<ArticlePlane>;
		private var aAontainer:DisplayObject3D = new DisplayObject3D("articles container");
		private var nowLookId:int = -1;
		
		
		public function BlogView(viewportWidth:Number = 640, viewportHeight:Number = 480) 
		{
			super(viewportWidth, viewportHeight, true, true, CameraType.FREE);
			
			init2D(viewportWidth, viewportHeight);
		}
		
		public function init2D(viewportWidth:Number, viewportHeight:Number):void 
		{
			modeBox = new VBox(this, 10, viewportHeight - 50);
			tileButton = new RadioButton(modeBox, 0, 0, "Tile" , false , onModeChange);
			tileButton.groupName = "ViewMode";
			orbitalButton = new RadioButton(modeBox, 0, 0,"Orbital" ,true , onModeChange);//Need modification
			orbitalButton.groupName = "ViewMode";
			
			currentTextField.defaultTextFormat = new TextFormat("Lithos Pro Regular", 18, 0xDDDDDD);
			currentTextField.text = "AAAAAAAAAAAAAA";
			currentTextField.multiline = true;
			currentTextField.width = 400;
			currentTextField.autoSize = TextFieldAutoSize.LEFT;
			currentTextField.selectable = false;
			addChild(currentTextField);
		}
		
		public function load():void 
		{
			loader.add(Settings.BlogXmlPath);
			loader.addEventListener(BulkProgressEvent.COMPLETE, onXMLCompleteHandler);
			loader.start();
		}
		
		private function onXMLCompleteHandler(evt : BulkProgressEvent) : void{
			trace("xml items are loaded and ready to consume");
			// Get the xml object:
			xml = loader.getXML(Settings.BlogXmlPath);
			
			var i:int;
			var delayTime:Number = 0;
			for (i = 0; i < xml.article.length(); i ++)
			{
				articles[i] = new ArticlePlane(xml.article[i]);
				articles[i].extra = {
					id: i,
					x: Math.cos(i * 36 / 180 * Math.PI) * 600,
					z: Math.sin(i * 36 / 180 * Math.PI) * 600,
					y: - i * 20,
					ry: - i * 36 - 90
				};
				
				articles[i].addEventListener(InteractiveScene3DEvent.OBJECT_PRESS, onPress);
				articles[i].addEventListener(InteractiveScene3DEvent.OBJECT_OUT, onOut);
				articles[i].addEventListener(InteractiveScene3DEvent.OBJECT_OVER, onOver);
				
				aAontainer.addChild(articles[i]);
				trace(articles[i]);
				Tweener.addTween(articles[i], { x:articles[i].extra.x, y:articles[i].extra.y, z:articles[i].extra.z, rotationY:articles[i].extra.ry, time:0.5, transition:"easeOutSine", delay:delayTime} );
				
				delayTime += 0.1;
			}
			aAontainer.y = 300;
			scene.addChild(aAontainer);
			startRendering();
		}
		
		private function onOut(e:InteractiveScene3DEvent):void 
		{
			this.buttonMode = false;
		}
		
		private function onOver(e:InteractiveScene3DEvent):void 
		{
			if (e.displayObject3D.extra.id != nowLookId)
			{
				this.buttonMode = true;
			}
		}
		
		private function onPress(e:InteractiveScene3DEvent):void 
		{
			trace("press");
			if (nowLookId != e.displayObject3D.extra.id)
			{
				gotoPhoto(e.displayObject3D.extra.id);
			}
			
		}
		
		private function gotoPhoto(num:int):void
		{
			if(nowLookId != -1)
				Tweener.addTween(articles[nowLookId], { x:articles[nowLookId].extra.x, y:articles[nowLookId].extra.y, z:articles[nowLookId].extra.z, rotationY:articles[nowLookId].extra.ry, time:0.5, transition:"easeOutSine" } );
			nowLookId = num;
			Tweener.addTween(articles[nowLookId], { x:0, y:-100, z:-800, time:0.5, rotationY: 0, transition:"easeInSine",  onComplete:ShowContent } );
		}
		
		private function ShowContent():void
		{
			currentTextField.x = stage.stageWidth / 2 - 200;
			currentTextField.y = stage.stageHeight - 200;
			display(nowLookId);
		}
		
		private function onModeChange(event:MouseEvent):void
		{
			var delayTime:Number = 0;
			var i:int;
			if (tileButton.selected)
			{
				for (i = 0; i < xml.article.length(); i ++)
				{
					Tweener.addTween(articles[i], {x:(i % 5) * 250 - 500, y: - int(i / 5) * 250 + 500, z:0 , rotationX:0, rotationY:0, rotationZ:0, time:1, transition:"easeInSine", delay:delayTime});
					delayTime += 0.05;
				}
			}
			else if (orbitalButton.selected)
			{
				for (i = 0; i < xml.article.length(); i ++)
				{
					Tweener.addTween(articles[i], {x:Math.random() * 1000 - 500, y:Math.random() * 1000 - 500, z:Math.random() * 1000 - 500, rotationX:Math.random() * 360, rotationY:Math.random() * 360, rotationZ:Math.random() * 360, time:1, transition:"easeInSine", delay:delayTime});
					delayTime += 0.05;
				}
			}
			Tweener.addTween(camera, { x:0, y:0, z: -1000 , rotationX:0, rotationY:0, rotationZ:0, time:1, transition:"easeInSine" } );
			
			nowLookId = -1;
		}
		
		private function display(i:int):void
		{
			trace(articles[i].xml);
			currentTextField.htmlText = articles[i].xml;
			var txtanim:TextAnim = new TextAnim(currentTextField);
			txtanim.blocksVisible = false;
			txtanim.interval = 50;
			txtanim.mode = TextAnimMode.FIRST_LAST;
			txtanim.split = TextAnimSplit.CHARS;
			txtanim.effects = artEffect;
			txtanim.start();
		}
		
		private function artEffect(block:TextAnimBlock):void 
		{
			trace(block.index);
			block.scaleX = block.scaleY = 0;
			block.rotation = -120;
			block.alpha = 0;
			Tweener.addTween(block, {rotation:0, scaleX:1, scaleY:1, alpha: 1, time:.5, transition:"easeoutback"});
		}
		
		override protected function onRenderTick(event:Event = null):void 
		{
			super.onRenderTick(event);
		}
		
	}
	
	

}