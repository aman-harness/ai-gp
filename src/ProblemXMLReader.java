
import org.xml.sax.*;
import org.xml.sax.helpers.*;
import org.objectweb.asm.Type;
import org.n8lm.math.*;
import java.util.Vector;

public class ProblemXMLReader extends DefaultHandler { 
	
	java.util.Stack tags = new java.util.Stack();
	
	public Vector<Vertex> vertexes;
	public Vector<InfiniteLine> infiniteLines;
	
	public ProblemXMLReader() { 
		super();
		vertexes = new Vector();
		infiniteLines = new Vector();
	} 

	public void characters(char ch[], int start, int length) throws SAXException { 
		String tag, str, parent;
		if(tags.empty()) return ;
		tag = (String) tags.peek();
		int i;
		if(tags.size() < 2) return ;
		parent = (String)tags.get(tags.size()-2);
		if(parent ==  "line")
		{
			if (tag.equals("name"))
			{
				infiniteLines.add(new InfiniteLine(new String(ch, start, length)));
			} 
			if (tag.equals("vertex"))
			{
				str = new String(ch, start, length);
    			for(i=0;i<vertexes.size();i++)
    			{
    				if(vertexes.get(i).Name.equals(str))
    				{
    					infiniteLines.lastElement().add(vertexes.get(i));
    					break;
    				}
    			}
			} 
		}
		else if(parent ==  "vertexes")
		{
			if (tag.equals("vertex"))
			{
				vertexes.add(new Vertex(new String(ch, start, length)));
			}
		}
	} 

	public void startElement(String uri, String localName, String qName, Attributes attrs)
	{ 
		tags.push(qName); 
	}
	
	public void endElement(String uri, String localName, String qName)
	{
		tags.pop();
	}
} 