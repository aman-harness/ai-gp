#include <iostream>
#include <cstring>
using namespace std;

//template <class T>
class XMLNode{
public:
       XMLNode(){repeat=1;child = NULL; next = NULL;}
       ~XMLNode(){delete child; delete next;}
        
      string name;
      unsigned short repeat;
      XMLNode* child;
      XMLNode* next;
};
/*
class XMLLastNode: public XMLNode{
public:
      bool show;
}
*/
XMLNode* XMLroot;
int jm=26;

void readXMLNode(XMLNode* myRoot){
     cout<<"name="<<myRoot->name;
     string str;
     int i;
     int posi=0;
     if(cin.eof()){
         myRoot->child = NULL;
         myRoot->next = NULL;
         return ;
     }
     char cstr[256];
     cin.ignore(1024,'<');
     cin.get(cstr,255,'>');
     cin.get();
     str.assign(cstr);
     
     while( (posi=str.find(' ',posi)) != -1 ) str.erase(posi,1);
     cout<<"str="<<str;
     if(str[0]=='/'){
         //if (str.substr(1,str.size()-2) == myRoot->name)
         //{
             myRoot->child=NULL;
             myRoot->next=NULL;
             return ;
         //}
     }
     else{
          if(str == "program" && myRoot->name=="root"){
                 cout<<endl<<' ';
                 myRoot->child = new XMLNode();
                 myRoot->child->name = str;
                 myRoot->child->repeat = myRoot->repeat;
                 readXMLNode(myRoot->child);
          }
          else if(str == "repeat" && myRoot->name=="begin"){
                 cin.get(cstr,255,'<');
                 cin.ignore(1024,'>');
                 myRoot->repeat = atoi(cstr);
          }
          else if(str == "begin" && (myRoot->name == "program" || myRoot->name=="begin")){
                 cout<<endl<<' ';
                 myRoot->child = new XMLNode();
                 myRoot->child->name = str;
                 myRoot->child->repeat = myRoot->repeat; 
                 readXMLNode(myRoot->child);
          }
          else if((str == "writeshow=\"true\""||str == "write"||str == "writeshow=true"||str == "writeshow=¡±ture¡±" )&& myRoot->name=="begin"){
                 cin.get(cstr,255,'<');
                 str.assign(cstr);
                 cin.ignore(255,'>');
                 cout<<"Êä³ö"<<endl;
                 for(i=1;i<=myRoot->repeat;i++)cout<<"Êý¾Ý"<<str<<endl;
          }
          else {
                 cin.ignore(1024,'>');
                 cin.get();
          }
     }
     cout<<endl;
     myRoot->next = new XMLNode();
     myRoot->next->name = myRoot->name;
     myRoot->next->repeat = myRoot->repeat;
     readXMLNode(myRoot->next);
     
}
void readXML(){
     string str,str2;
     char cstr[256];
     int posi = 0;
     cin.ignore(1024,'<');
     char ch;
     if((ch=cin.get())=='?'){
         cin.ignore(255,'T');
         cin.get(cstr,255,'"');
         str2.assign(cstr);
         cout<<str2;
         jm = atoi( str2.c_str());
         if( jm<1 || jm>27 ){
             cout<<"ERR0R";
             return;
         }
         cin.ignore(255,'<');
         ch = cin.get();
     }
     XMLroot = new XMLNode();
     XMLroot->name = "root";
     XMLroot->repeat = 1;
     cin.get(cstr,255,'>');
     cin.get();
     str.assign(cstr);
     //while(1);
     str = ch + str;
     while( (posi=str.find(' ',posi)) != -1 ) str.erase(posi,1);
     cout<<str;
     if(str=="program"){
         XMLroot->child = new XMLNode();
         XMLroot->child->name = "program";
         XMLroot->child->repeat = XMLroot->repeat;
         readXMLNode(XMLroot->child);
     }
     XMLroot->next = new XMLNode();
     XMLroot->next->name = XMLroot->name;
     XMLroot->next->repeat = XMLroot->repeat;
     readXMLNode(XMLroot->next);
}
     
int main(){
    int n;
    cin>>n;
    readXML();
    while(1);
    return 0;
}
/*14
<?xml version="1.0" encoding="T25" ?>
25<program>
programname=program  <begin>
str=begin
 name=begin    <repeat>3</repeat>
str=repeat
name=begin    <begin>
str=begin
 name=begin      <write show=¡±ture¡± >x.</write><write show=¡±true¡± >x</write>

str=writeshow=¡±ture¡±
name=beginstr=/write
name=begin    </begin>
str=/begin
name=program  </begin>
str=/beginname=root  <begin>
str=begin    <write show=true>.mpsbcju.dpn</write>

name=rootstr=/write
*/
