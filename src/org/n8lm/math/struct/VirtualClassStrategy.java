package org.n8lm.math.struct;

import java.util.*;
import net.sf.cglib.transform.*;
import net.sf.cglib.transform.impl.*;
import net.sf.cglib.core.ClassGenerator;
import net.sf.cglib.core.DefaultGeneratorStrategy;
import net.sf.cglib.core.GeneratorStrategy;
import net.sf.cglib.core.ClassGenerator;
import org.objectweb.asm.Type;

public class VirtualClassStrategy extends DefaultGeneratorStrategy implements GeneratorStrategy {
	
	protected ArrayList<ClassTransformer> classTransformers;
	protected ArrayList<String> propertiesName;
	protected ArrayList<Type> propertiesType;
	public String name;
	public Class ownClass;
	public String baseClassName;
	public Class baseClass;
	/**
	 * Method VirtualClassStrategy
	 *
	 *
	 */
	public VirtualClassStrategy(String name) {
		super();
		classTransformers = new ArrayList();
		propertiesName = new ArrayList();
		propertiesType = new ArrayList();
		this.name = name;
		// TODO: Add your code here
	}
	
	
	public VirtualClassStrategy(String name,String baseName) {
		super();
		classTransformers = new ArrayList();
		propertiesName = new ArrayList();
		propertiesType = new ArrayList();
		this.name = name;
		this.baseClassName = baseName;
		// TODO: Add your code here
	}
	/**
	 * Method transform
	 *
	 *
	 * @param parm1
	 *
	 @throws Exception
	 *
	 * @return 
	 *
	 */
	 protected ClassGenerator transform(ClassGenerator cg) throws Exception {
	 	classTransformers.add(new AddPropertyTransformer((String[])propertiesName.toArray(),(Type[])propertiesType.toArray()));
	 	return new TransformingClassGenerator(cg,new ClassTransformerChain((ClassTransformer[])classTransformers.toArray()));
	 }

	public void addPorperty(String name,Type type)
	{
		propertiesName.add(name);
		propertiesType.add(type);
	}
}
