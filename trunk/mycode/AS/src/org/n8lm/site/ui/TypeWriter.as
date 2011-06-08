package org.n8lm.site.ui
{
	import flash.display.Sprite;
	import flash.text.TextFormatAlign;
	import flash.text.TextFormat;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.filters.GlowFilter;
	import flash.events.Event;
	
	import flupie.textanim.*;
	import caurina.transitions.Tweener;
	import flash.events.MouseEvent;
	
	import org.n8lm.font.DSDigital;
	import org.n8lm.site.assets.*;
	
    /**
     *  Animation is Completed.
     *
     *  @eventType flash.events.Event
     */
    [Event(name = "complete", type = "flash.events.Event")];
	
	public class TypeWriter extends Sprite
	{
		public var _tf:TextField;
		public var _fm:TextFormat;
		public var _ta:TextAnim;
		public var _cursor:ACursor;
		
		public var _space:int = 5;
		public var _chars:String = "^-.*@#$%!&543210";
		public var _color:uint = 0xC9F1FA;
		public var _glow:GlowFilter = new GlowFilter(_color, .4, 6, 6);
		
		
		public function TypeWriter()
		{			
			_cursor = new ACursor();
			_cursor.filters = [_glow];
			_cursor.scaleX = 1.2;
			_cursor.scaleY = 1.2;
			
			_fm = new TextFormat(new DSDigital().fontName, 24, _color);
			
			_tf = new TextField();
			_tf.autoSize = TextFieldAutoSize.LEFT;
			_tf.multiline = true;
			_tf.embedFonts = true;
			_tf.defaultTextFormat = _fm;
			_tf.text = "CLICK TO START";
			addChild(_tf);
			
			_ta = new TextAnim(_tf);
			_ta.filters = [_glow];
			_ta.effects = [shuffleEffectIn, shuffleEffectOut];
			_ta.interval = 40;
			_ta.blocksVisible = false;
			_ta.onStart = onTextAnimStart;
			
			//onTextAnimStart();
			//_ta.start(1000);
			
			//stage.addEventListener(MouseEvent.CLICK, clickStart, false, 0, true);
		}
		
		
		
		public function start(str:String):void
		{
			_ta.text = str;
			_ta.blocksVisible = false;
			
			onTextAnimStart();
			_ta.start(1000);
		}
		
		private function shuffleEffectIn(b:TextAnimBlock):void
		{
			b.vars.char = b.text;
			_cursor.x = _ta.x + b.x + _space;
			_cursor.y = _ta.y + b.y;
			
			Tweener.addTween(b, {time:.2, onUpdate:updateChars, onUpdateParams:[b], onComplete:completeRandom, onCompleteParams:[b]});
		}
		
		private function shuffleEffectOut(b:TextAnimBlock):void
		{
			Tweener.addTween(b, {time:.2, alpha:0, onComplete:completeShow, onCompleteParams:[b], delay:4});
		}
		
		private function updateChars(b:TextAnimBlock):void
		{
			var index:int = Math.round(Math.random() * _chars.length);
			b.text = _chars.slice(index, index + 1);
		}
		
		private function completeRandom(b:TextAnimBlock):void
		{
			b.text = b.vars.char;
		}
		
		private function completeShow(b:TextAnimBlock):void
		{
			if (b.index == _ta.text.length - 1)
			{
				removeChild(_cursor);
				this.dispatchEvent(new Event(Event.COMPLETE));
			}
		}
		
		private function onTextAnimStart():void
		{
			_ta.x = Math.round((stage.stageWidth * .5) - (_ta.width * .5));
			_ta.y = Math.round((stage.stageHeight * .5) - (_ta.height * .5));
			
			addChild(_cursor);
			_cursor.x = _ta.x;
			_cursor.y = _ta.y + _ta.firstBlock.y;
		}
		
	}

}