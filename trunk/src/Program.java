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

public class Program {
    
    static public Vector<Vertex> vertexes;
    static public Vector<InfiniteLine> infiniteLines;
    
    public static void main(String[] args) {
    	
    	init();
    	
    	int i;
    	for(i=0;i<vertexes.size();i++)
    		System.out.println(vertexes.get(i).toString());
    	for(i=0;i<infiniteLines.size();i++)
    		System.out.println(infiniteLines.get(i).toString());
    	// TODO, add your application code
    	System.out.println("Hello World!");
    }
    
    public static void init()
    {
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
    					System.out.println("重输入一个角");
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
    					System.out.println(str + " " + vertexes.get(j).Name);
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
    		System.out.println("输入错误");
    		return ;
    	}
    	/*
    	catch (FileNotFoundException e)
    	{
    		System.out.println("文件没找到");
    		return ;
    	}*/
    }
}
