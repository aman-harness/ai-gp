package org.n8lm.math;

import org.n8lm.math.GeometryObject;

abstract class Line extends GeometryObject {
	
	public Line() {
		// TODO: Add your code here
	}
	
	public Line(String name) {
		super(name);
	}
	
	abstract public boolean isVertexOnLine(Vertex vertex);
}
