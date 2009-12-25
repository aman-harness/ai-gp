package org.n8lm.math;

import org.n8lm.math.Line;
import java.util.Vector;

public class InfiniteLine extends Line {
	protected Vector<Vertex> vertexes;
	/**
	 * Method InfiniteLine
	 *
	 *
	 */
	public void add(Vertex before,Vertex th)
	{
		int i;
		if((i = vertexes.indexOf(before)) != -1)
			vertexes.add(i,th);
	}
	
	public void add(Vertex th)
	{
		th.add(this);
		vertexes.add(th);
	}
	 
	public InfiniteLine() {
		vertexes = new Vector();
		// TODO: Add your code here
	}
	
	public InfiniteLine(String name) {
		super(name);
		vertexes = new Vector();
		// TODO: Add your code here
	}
	
	public String toString()
	{
		int i;
		String str = "[name:" + Name;
		if(vertexes.size() > 0)
		{
			str += " point:";
			for(i=0;i<vertexes.size()-1;i++)
				str += vertexes.get(i).Name + ",";
			str += vertexes.get(vertexes.size()-1).Name;
		}
		str += "]";
		return str;
	}
}
