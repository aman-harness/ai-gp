package org.n8lm.site
{
	import flash.display.Sprite;
	import flash.events.Event;
	
	import org.n8lm.site.ui.*;
	import org.n8lm.site.effect.*;
	/**
	 * ...
	 * @author Alchemist
	 */
	public class MainSite extends Sprite 
	{
		private var photoView:PhotoView;
		private var blogView:BlogView;
		private var displayText3D:DisplayText3D;
		
		private var _tw:TypeWriter;
		private var _md:Matrixcode;
		private var isAnim:Boolean = false;
		private var isLoad:Boolean = false;
		
		public function MainSite():void 
		{
			if (stage) init();
			else addEventListener(Event.ADDED_TO_STAGE, init);
		}
		
		private function init(e:Event = null):void 
		{
			removeEventListener(Event.ADDED_TO_STAGE, init);
			stage.addEventListener(Event.RESIZE, resize);
			
			/*
			displayText3D = new DisplayText3D();
			addChild(displayText3D);*/
			
			photoView = new PhotoView();
			//blogView = new BlogView(800, 600);
			//blogView.load();
			//addChild(blogView);
			photoView.load();
			photoView.addEventListener(Event.INIT, onInitComplete);
			// entry point
			_md = new Matrixcode();
			
			_tw = new TypeWriter();
			addChild(_tw);
			_tw.start(Settings.insStr);
			_tw.addEventListener(Event.COMPLETE, onTypeComplete);
			
		}
		
		private function resize(e:Event):void
		{
			graphics.clear();
			graphics.beginFill(0x000000);
			graphics.drawRect(0, 0, stage.stageWidth, stage.stageHeight);
			graphics.endFill();
		}
		
		private function onTypeComplete(e:Event):void
		{
			isAnim = true;
			if(!isLoad)
				addChild(_md);
			else
			{
				if(!photoView.parent)
					addChild(photoView);
			}
				
		}
		
		private function onInitComplete(e:Event):void
		{
			isLoad = true;
			if (isAnim)
			{
				_md.stop();
				addChild(photoView);
			}
		}
	}
	
}