/**
 * @(#)TestSetup.java
 *
 * ai-gp application
 *
 * @author Alchemist
 * @version 1.00 2010/01/05
 */
import org.n8lm.math.*;
import org.n8lm.math.struct.*;
import java.util.Vector;
import java.io.*;
import org.xml.sax.*;
import javax.xml.parsers.*;

public class TestSetup {
    
    static public ClassDatabase database;
    
    public static void main(String[] args) {
    	
		long lasting = System.currentTimeMillis();
    	init();
		System.out.println("Run Time£º" + (System.currentTimeMillis() - lasting) + " ms");
        
    }
    
    public static void init()
    {
    	SetupXMLReader reader;
		reader = new SetupXMLReader();
		database = new ClassDatabase();
		reader.setDatabase(database);
		SAXParserFactory sf = SAXParserFactory.newInstance(); 
		try { 
			SAXParser sp = sf.newSAXParser(); 
			sp.parse(new InputSource("setup.xml"), reader);
    		
		} catch (Exception e) {
			e.printStackTrace(); 
		}
    }
}
