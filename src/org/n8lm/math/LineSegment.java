package org.n8lm.math;

import org.n8lm.math.Line;

class LineSegment extends Line {
	protected float Length;	
	protected Vertex pointA;
	protected Vertex pointB;
	/**
	 * Method LineSegment
	 *
	 *
	 */
	public LineSegment() {
		// TODO: Add your code here
	}		
		
	public LineSegment(String name,Vertex a,Vertex b) {
		super(name);
		pointA = a;
		pointB = b;
		// TODO: Add your code here
	}	
}
