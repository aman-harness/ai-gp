package org.n8lm.math.struct;

import java.util.*;
import net.sf.cglib.proxy.*;

public class ClassDatabase {
	
	public HashMap<String,VirtualClassStrategy> vcStrategies;
	/**
	 * Method ClassDatabase
	 *
	 *
	 */
	public ClassDatabase() {
		vcStrategies = new HashMap();
		// TODO: Add your code here
	}
	
	public Class getClassFromVCS(VirtualClassStrategy vcs)
	{
        Enhancer e = new Enhancer();
        e.setSuperclass(getClassFromName(vcs.baseClassName));
        e.setCallback(new VirtualClassGenMethod());
        e.setStrategy(vcs);
        return e.createClass();
	}
	
	public Class getClassFromName(String name)
	{
		try{
    		return Class.forName(name);
		}
		catch(ClassNotFoundException e)
		{
			if(vcStrategies.containsKey(name) && vcStrategies.get(name).ownClass != null)
    			return vcStrategies.get(name).ownClass;
		}
    	return Object.class;
	}
	
	public void addVCS(VirtualClassStrategy vcs)
	{
		vcStrategies.put(vcs.name,vcs);
	}
	
}
