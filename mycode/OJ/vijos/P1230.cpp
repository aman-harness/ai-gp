#include <iostream>
#include <cstring>
using namespace std;
const string dw="*SBQ",gw="*WYZ";
string readstr="",str;
string readz( string str );

string readz( string str )
{
       int i;
       string substr="",rstr="";
       int d,x;
       bool l=0,k=1,q=0;
       d=-1;
       for(i=str.length()-1 ,x=0 ; i>=0 ; i--,x++)
       {
            if(x%4==0)
            {
                if( k == 0 && d!=0 )
                {
                    if(substr[substr.size()-1] == '0')
                    {
                        substr = substr.substr( 0 , substr.size()-1);
                        substr += gw[d]; 
                        substr += '0';
                    }
                    else
                    substr += gw[d];
                }
                k = 1;
                d++;
                x=0;
                rstr = substr + rstr;
                substr="";
            }
            if( str[i] != '0')
            {
                k = 0;
                if( l == 1 && q == 1){
                substr = '0' + substr;
                l=0;
                }
                q = 1;
                if(x!=0)
                substr = dw[x] + substr;
                substr = str[i] + substr;
            }
            else
            l=1;
       }
       if( k == 0 && d!=0 )
       {
           if(substr[substr.size()-1] == '0')
           {
               substr = substr.substr( 0 , substr.size()-1);
               substr += gw[d]; 
               substr += '0';
           }
           else
           substr += gw[d] ;
       }
       rstr = substr + rstr;
       return rstr;
}
            
int main()
{
    cin>>str;
    int d;
    readstr="";
    if(str[0]=='+')
    str = str.substr( 1 , str.length() -1 );
    else if(str[0]=='-'){
    readstr="F";
    str = str.substr( 1 , str.length() -1 );
    }
    int i = 0;
    while(str[i]=='0')i++;
    str = str.substr( i , str.length() - i );
    
    d = str.find('.');
    if(d==-1){
    if(readz(str)=="")
    readstr = '0';
    else
    readstr += readz(str);
    }
    else
    { 
    if(readz(str.substr(0,d))=="")
    readstr += '0';
    else
    readstr += readz(str.substr(0,d));
    cout<<readstr<<endl;
    if( d!= str.length()-1 ){
    readstr += 'D';
    readstr += str.substr(d+1 , str.size()-1-d);
    }
    }
    cout<<readstr;
    //while(1);
    return 0;
}
    
    
