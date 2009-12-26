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
		if(vertexes.size() > 0)
		{
			vertexes.lastElement().add(new Radial(vertexes.lastElement().Name + th.Name, this, vertexes.lastElement(), false));
			th.add(new Radial(th.Name + vertexes.lastElement().Name, this, th, true));
		}
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
	
	public boolean isVertexOnLine(Vertex vertex)
	{
		if(vertexes.indexOf(vertex) == -1)
			return false;
		return true;
	}
	
	public boolean isVertexOnLine(Vertex vertex,Vertex before,boolean direction)
	{
		int x,l;
		if(vertex == before)
			return false;
		if((x = vertexes.indexOf(before)) == -1)
			return false;
		if(direction)
		{
			if((l = vertexes.indexOf(vertex)) >= x || l == -1)
				return false;
		}
		else
		{
			if(vertexes.indexOf(vertex, x) == -1)
				return false;
		}
		return true;
	}
}
