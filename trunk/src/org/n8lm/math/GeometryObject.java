package org.n8lm.math;


abstract class GeometryObject {
	
	/**
	 * Method GeometryObject
	 *
	 *
	 */
	public String Name;
	
	public GeometryObject()
	{
		// TODO: Add your code here
	}
	
	public GeometryObject(String name)
	{
		this.Name = name;
		// TODO: Add your code here
	}
	
	public String toString()
	{
		return "[name:" + Name + "]";
	}
}
