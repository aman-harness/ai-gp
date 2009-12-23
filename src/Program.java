/**
 * @(#)ai-gp.java
 *
 * ai-gp application
 *
 * @author 
 * @version 1.00 2009/12/21
 */
import org.n8lm.math.*;
import java.util.*;
import java.io.*;

public class Program {
    
    static public Vector<Vertex> vertexes;
    
    public static void main(String[] args) {
    	
    	init();
    	
    	int i;
    	for(i=0;i<vertexes.size();i++)
    		System.out.println(vertexes.get(i).Name);
    	// TODO, add your application code
    	System.out.println("Hello World!");
    }
    
    public static void init()
    {
    	String str;
    	int i,a,n;
    	i=0;
		vertexes = new Vector();
    	BufferedReader ipt = new BufferedReader(new InputStreamReader(System.in));
    	try
    	{
			while((str = ipt.readLine()) != null){
				str.trim();
				if(i>2)break;
    			System.out.println(str);
				vertexes.add(new Vertex(str)); 
				i++;  
  			}
    	}
    	catch (IOException e)
    	{
    	}
    }
}
