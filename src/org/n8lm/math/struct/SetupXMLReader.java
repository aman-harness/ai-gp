package org.n8lm.math.struct;

import org.xml.sax.*;
import org.xml.sax.helpers.DefaultHandler;
import org.objectweb.asm.Type;
import org.n8lm.math.*;
import java.util.*;

public class SetupXMLReader extends DefaultHandler {
	
	private ClassDatabase database;
	
	private boolean inside;
	private String QName,lastWord;
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
		classState = ClassState.none;
		// TODO: Add your code here
	}	
		
	public void setDatabase(ClassDatabase data)
	{
		database = data;
	}
	
	public void characters(char ch[], int start, int length) throws SAXException {
		String tag, str, parent;
		switch (classState) {
    		case property:
    			if(inside)
    				lastWord = new String(ch, start, length);
    			break;
    			
    		default :
		}
	}

	public void startElement(String uri, String localName, String qName, Attributes attrs)
	{
		switch (classState) {
    		case none: 
    			if(qName.equals("shape"))
    			{
    				if(attrs.getIndex("base") == -1)
    				{
    					nowVcs = new VirtualClassStrategy(attrs.getValue("name"));
    				}
    				else
    				{
    					nowVcs = new VirtualClassStrategy(attrs.getValue("name"),attrs.getValue("base"));
    					nowVcs.baseClass = database.getClassFromName(nowVcs.baseClassName);
    				}
    				classState = ClassState.inside;
    			}
    			break;
    			
    		case inside: 
    			if(qName.equals("property"))
    				classState = ClassState.property;
    			/*
    			else if(qName.equals("condition"))
    				classState = ClassState.condition;
    			else if(qName.equals("theorem"))
    				classState = ClassState.theorem;
    			break;
    			*/
    			
    		case property:
    			inside = true;
    			QName = qName;
    			lastType = Type.getType(database.getClassFromName(QName));
    			break;
    			
    		default :
		}
	}
	
	public void endElement(String uri, String localName, String qName)
	{
		switch (classState) {    			
    		case inside: 
    			if(qName.equals("shape"))
    			{
    				nowVcs.ownClass = database.getClassFromVCS(nowVcs);
    				database.addVCS(nowVcs);
    				classState = ClassState.none;
    			}
    			break;
    			
    		case property:
    			if(!qName.equals("property"))
    				nowVcs.addPorperty(lastWord,lastType);
    			else
    				classState = ClassState.inside;
    			inside = false;
    			break;
    			
    		default :
		}
	}
}
