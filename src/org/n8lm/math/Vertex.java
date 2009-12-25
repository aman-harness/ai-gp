package org.n8lm.math;


public class Vertex extends GeometryObject{
	
	/**
	 * Method main
	 *
	 *
	 * @param args
	 *
	 */
	 
	protected Vector<Radial> radials;

	/**
	 * Method Point
	 *
	 *
	 */
	public Vertex() {
		radials = new Radial();
		// TODO: Add your code here
	}	
	
	public Vertex(String name) {
		super(name);
		radials = new Radial();
		// TODO: Add your code here
	}
}
