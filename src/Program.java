/**
 * @(#)Program.java
 *
 * ai-gp application
 *
 * @author Alchemist
 * @version 1.00 2009/12/21
 */
import org.n8lm.math.*;
import java.util.Vector;
import java.io.*;
import org.xml.sax.*;
import javax.xml.parsers.*; 
import java.lang.reflect.Method;

import net.sf.cglib.core.ClassGenerator;
import net.sf.cglib.core.DefaultGeneratorStrategy;
import net.sf.cglib.proxy.*;
//import net.sf.cglib.transform.TransformingClassGenerator;
//import net.sf.cglib.transform.impl.AddPropertyTransformer;
import net.sf.cglib.transform.impl.AddPropertyTransformer;
import net.sf.cglib.transform.*;

import org.objectweb.asm.Type;

public class Program {
    
    static public Vector<Vertex> vertexes;
    static public Vector<InfiniteLine> infiniteLines;
    
    public static void main(String[] args) {
    	
		long lasting = System.currentTimeMillis(); 
		int i;
    	init();
    	
    	for(i=0;i<vertexes.size();i++)
    		System.out.println(vertexes.get(i).toString());
    	for(i=0;i<infiniteLines.size();i++)
    		System.out.println(infiniteLines.get(i).toString());
    	
		System.out.println("Run Time：" + (System.currentTimeMillis() - lasting) + " ms");
        
        try{
        Enhancer e = new Enhancer();
        e.setSuperclass(Object.class);
        e.setCallback(new TestCGLib());
        e.setStrategy(new DefaultGeneratorStrategy() {
            protected ClassGenerator transform(ClassGenerator cg) {
                return new TransformingClassGenerator(
                        cg,
                        new ClassTransformerChain(
                        	new ClassTransformer[]{
                        		new AddPropertyTransformer(
                                	new String[] { "XX" },//这个地方根据你的Xml来构造相应的名称和类型
                                	new Type[] { Type.INT_TYPE }
                        		)
                        	}
                        )
                	);
            }
        });
        Object object = e.create();
        System.out.println(object.getClass().getMethod("setXX", new Class[]{int.class}).invoke(object, 123));//.getMethod("settestint", new Class[]{int.class}).invoke(o, 123));
        System.out.println(object.getClass().getMethod("getXX").invoke(object));
        }
        catch(NoSuchMethodException e)
        {
        	System.out.println("No Method");
        }
        catch(IllegalAccessException e)
        {
        	System.out.println("No Method");
        }
        catch(java.lang.reflect.InvocationTargetException e)
        {
        	System.out.println("No Method");
        }
    }
    
    public static void init()
    {
    	ProblemXMLReader reader;
		reader = new ProblemXMLReader();
		SAXParserFactory sf = SAXParserFactory.newInstance(); 
		try { 
			SAXParser sp = sf.newSAXParser(); 
			sp.parse(new InputSource("problem.xml"), reader);
    		
		} catch (Exception e) { 
			e.printStackTrace(); 
		} 
    	vertexes = reader.vertexes;
    	infiniteLines = reader.infiniteLines;
    	/*
    	String str;
    	int i,j,k,a,n;
    	i=0;
		vertexes = new Vector();
		infiniteLines = new Vector();
		try{
			BufferedReader ipt = new BufferedReader(new FileReader("problem.txt"));
			
  			n = Integer.parseInt(ipt.readLine());
			for(i=0;i<n;i++)
			{
				str = ipt.readLine();
				str.trim();
    			for(j=0;j<i;j++)
    				if(vertexes.get(j).Name.equals(str))
    				{
    					System.out.println("You have a same angle!");
    					i--;
    					continue;
    				}
				vertexes.add(new Vertex(str));
  			}
  			i = 0;
  			k = 0;
  			
			str = ipt.readLine();
  			n = Integer.parseInt(str);
			for(i=0;i<n;i++)
			{
				str = ipt.readLine();
  				k = Integer.parseInt(str);
				str = ipt.readLine();
				infiniteLines.add(new InfiniteLine(str));
				while(k>0)
				{
					str = ipt.readLine();
					str.trim();
    				for(j=0;j<vertexes.size();j++)
    				{
    					if(vertexes.get(j).Name.equals(str))
    					{
    						infiniteLines.get(i).add(vertexes.get(j));
    						break;
    					}
    				}
    				k--;
				}
  			}
    	}
    	catch (IOException e)
    	{
    		System.out.println("OI Error!!!");
    		return ;
    	}*/
    }
}
