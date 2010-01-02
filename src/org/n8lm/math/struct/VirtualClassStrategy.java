package org.n8lm.math.struct;

import net.sf.cglib.transform.*;
import net.sf.cglib.core.ClassGenerator;
import net.sf.cglib.core.DefaultGeneratorStrategy;
import net.sf.cglib.core.GeneratorStrategy;
import net.sf.cglib.core.ClassGenerator;
import org.objectweb.asm.Type;

public class VirtualClassStrategy extends DefaultGeneratorStrategy implements GeneratorStrategy {
	
	protected ClassTransformer[] classTransformers;
	protected List<String> propertiesName;
	protected List<Type> propertiesType;
	/**
	 * Method VirtualClassStrategy
	 *
	 *
	 */
	public VirtualClassStrategy() {
		super();
		classTransformers = new ClassTransformer[];
		propertiesName = new List();
		propertiesType = new List();
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
	 	return new TransformingClassGenerator(cg,new ClassTransformerChain(classTransformers));
	 }

	public addPorperty(String name,Type type)
	{
		propertiesName.add(name);
		propertiesType.add(type);
	}
}
