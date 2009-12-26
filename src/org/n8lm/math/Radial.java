package org.n8lm.math;

import org.n8lm.math.Line;

class Radial extends Line {
		
	protected InfiniteLine parent;
	protected Vertex endpoint;
	protected boolean isLeft;
	/**
	 * Method Radial
	 *
	 *
	 */
	public Radial() {
		// TODO: Add your code here
	}	
	
	public Radial(String name) {
		super(name);
	}
		
	public Radial(String name, InfiniteLine parent, Vertex endpoint, boolean isLeft) {
		super(name);
		this.endpoint = endpoint;
		this.parent = parent;
		this.isLeft = isLeft;
	}	
		
	public boolean isVertexOnLine(Vertex vertex)
	{
		return parent.isVertexOnLine(vertex,endpoint,isLeft);
	}
}
