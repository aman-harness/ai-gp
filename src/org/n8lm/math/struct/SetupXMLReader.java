package org.n8lm.math.struct;

import org.xml.sax.*;
import org.xml.sax.helpers.DefaultHandler;
import org.objectweb.asm.Type;
import org.n8lm.math.*;
import java.util.*;

class SetupXMLReader extends DefaultHandler {
	
	public Map<String,VirtualClassStrategy> vcStrategies;
	public Map<String,Class> vClasses;
	
	private boolean inside;
	private String nowClassName,QName,lastWord;
	private Type lastType;
	private VirtualClassStrategy nowVcs;
	private ClassState classState;
	
	public enum ClassState
	{
		property,
		condition,
		theorem,
		inside,
		none
	}
	/**
	 * Method SetupXMLReader
	 *
	 *
	 */
	public SetupXMLReader() {
		super();
		vcStrategies = new Vector();
		classState = ClassState.none;
		// TODO: Add your code here
	}	
	public void characters(char ch[], int start, int length) throws SAXException {
		String tag, str, parent;
		switch (classState) {
    		case ClassState.none: 
    			if(qName.equals("shape"))
    			{
    				nowClassName = attrs.getValue("name");
    				nowVcs = new VirtualClassStrategy();
    				classState = ClassState.inside;
    			}
    			break;
    		case ClassState.inside: 
    			if(qName.equals("property"))
    				classState = ClassState.property;
    			else if(qName.equals("condition"))
    				classState = ClassState.condition;
    			else if(qName.equals("theorem"))
    				classState = ClassState.theorem;
    			break;
    		case ClassState.property:
    			if(inside)
    				lastWord = new String(ch, start, length);
    			break;
    			
    		default :
		}
	}

	public void startElement(String uri, String localName, String qName, Attributes attrs)
	{
		switch (classState) {
    		case ClassState.none: 
    			if(qName.equals("shape"))
    			{
    				nowClassName = attrs.getValue("name");
    				nowVcs = new VirtualClassStrategy();
    				classState = ClassState.inside;
    			}
    			break;
    		case ClassState.inside: 
    			if(qName.equals("property"))
    				classState = ClassState.property;
    			else if(qName.equals("condition"))
    				classState = ClassState.condition;
    			else if(qName.equals("theorem"))
    				classState = ClassState.theorem;
    			break;
    		case ClassState.property:
    			inside = true;
    			QName = qName;
    			if(Class.forName(QName) != null)
    			{
    				lastType = Type.getType(Class.forName(QName));
    			}
    			else
    			{
    				if(vClasses.containsKey(QName))
    					lastType = Type.getType(vClasses.get(QName));
    			}
    			break;
    			
    		default :
		}
	}
	
	public void endElement(String uri, String localName, String qName)
	{
		switch (classState) {
    		case ClassState.none: 
    			if(qName.equals("shape"))
    			{
    				nowClassName = attrs.getValue("name");
    				nowVcs = new VirtualClassStrategy();
    				classState = ClassState.inside;
    			}
    			break;
    		case ClassState.inside: 
    			if(qName.equals("property"))
    				classState = ClassState.property;
    			else if(qName.equals("condition"))
    				classState = ClassState.condition;
    			else if(qName.equals("theorem"))
    				classState = ClassState.theorem;
    			break;
    		case ClassState.property:
    			inside = false;
    			nowVcs.addPorperty(lastWord,lastType);
    			break;
    			
    		default :
		}
		tags.push(qName);
	}
}
