package org.n8lm.site 
{
	import flash.display.BitmapData;
	import flash.display.Sprite;
	import flash.text.TextField;
	import flash.text.TextFormat;
	import org.papervision3d.core.proto.MaterialObject3D;
	import org.papervision3d.materials.BitmapMaterial;
	import org.papervision3d.objects.primitives.Plane;
	/**
	 * ...
	 * @author ...
	 */
	public class ArticlePlane extends Plane 
	{
		public var xml:XML;
		
		public function ArticlePlane(xml:XML) 
		{
			this.xml = xml;
			
			var sp:Sprite = new Sprite();
			var tf:TextField = new TextField();
			tf.x = tf.y = 20;
			tf.defaultTextFormat = new TextFormat("Hobo Std",36);
			tf.text = xml.@name;
			tf.textColor = 0xFFFFFF;
			sp.addChild(tf);
			sp.graphics.beginFill(0x3040D0);
			sp.graphics.drawRect(0, 0, 320, 200);
			sp.graphics.endFill();
			var bmd:BitmapData = new BitmapData(320, 200);
			bmd.draw(sp);
			var mat:MaterialObject3D = new BitmapMaterial(bmd);
			mat.doubleSided = true;
			mat.interactive = true;
			super(mat, 320, 200);
			
			name = xml.@name;
		}
		
	}

}