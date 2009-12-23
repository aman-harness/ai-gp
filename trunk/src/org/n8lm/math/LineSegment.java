package org.n8lm.math;

import org.n8lm.math.Line;

class LineSegment extends Line {
	protected int Length;	
	protected Point pointA;
	protected Point pointB;
	/**
	 * Method LineSegment
	 *
	 *
	 */
	public LineSegment() {
		// TODO: Add your code here
	}		
		
	public LineSegment(String name,Point a,Point b) {
		base(name);
		pointA = a;
		pointB = b;
		// TODO: Add your code here
	}	
}
