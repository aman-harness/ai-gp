package org.n8lm.math;
import java.util.Vector;


public class Vertex extends GeometryObject{
	
	/**
	 * Method main
	 *
	 *
	 * @param args
	 *
	 */
	 
	protected Vector<Radial> radials;
	protected Vector<InfiniteLine> infiniteLines;

	/**
	 * Method Point
	 *
	 *
	 */
	public Vertex() {
		radials = new Vector();
		infiniteLines = new Vector();
		// TODO: Add your code here
	}	
	
	public Vertex(String name) {
		super(name);
		radials = new Vector();
		infiniteLines = new Vector();
		// TODO: Add your code here
	}
	
	public void add(Radial th)
	{
		radials.add(th);
	}
	
	public void add(InfiniteLine th)
	{
		infiniteLines.add(th);
	}
	
	public String toString()
	{
		int i;
		String str = "[name:" + Name;
		if(infiniteLines.size() > 0)
		{
			str += " line:";
			for(i=0;i<infiniteLines.size()-1;i++)
				str += infiniteLines.get(i).Name + ",";
			str += infiniteLines.get(infiniteLines.size()-1).Name;
		}
		str += "]";
		return str;
	}
}
