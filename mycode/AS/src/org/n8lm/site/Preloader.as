package org.n8lm.site
{
	import flash.display.DisplayObject;
	import flash.display.MovieClip;
	import flash.display.Graphics;
	import flash.display.StageAlign;
	import flash.display.StageScaleMode;
	import flash.display.StageDisplayState;
	import flash.events.Event;
	import flash.events.ProgressEvent;
	import flash.utils.getDefinitionByName;
	
	/**
	 * ...
	 * @author Alchemist
	 */
	[SWF(width="1024", height="600", backgroundColor="0xFFFFFF", frameRate="60")]
    public class Preloader extends MovieClip 
	{
		
		public function Preloader() 
		{
			addEventListener(Event.ENTER_FRAME, checkFrame);
			loaderInfo.addEventListener(ProgressEvent.PROGRESS, progress);
			
            stage.align = StageAlign.TOP_LEFT;
            stage.scaleMode = StageScaleMode.NO_SCALE;  
			// show loader
		}
		
		private function progress(e:ProgressEvent):void 
		{
			graphics.clear();
			graphics.beginFill(0x000000);
			graphics.drawRect(0, 0, stage.stageWidth, e.bytesLoaded/e.bytesTotal * stage.stageHeight);
            graphics.endFill();// update loader
		}
		
		private function checkFrame(e:Event):void 
		{
			if (currentFrame == totalFrames) 
			{
				removeEventListener(Event.ENTER_FRAME, checkFrame);
				startup();
			}
		}
		
		private function startup():void 
		{
			// hide loader
			stop();
			
			graphics.clear();
			graphics.beginFill(0x000000);
			graphics.drawRect(0, 0, stage.stageWidth, stage.stageHeight);
            graphics.endFill();
			
			loaderInfo.removeEventListener(ProgressEvent.PROGRESS, progress);
			var mainClass:Class = getDefinitionByName("org.n8lm.site.MainSite") as Class;
			addChild(new mainClass() as DisplayObject);
		}
		
	}
	
}