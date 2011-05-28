#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
int main(){
 int i;
 string str,str2,b="abc";
 stringstream a;
 cin>>str2;
 for(i=1;i<=1000000;i++)a<<i;
 a>>str;
 cout<<int(str.find(str2.c_str())+1);
 while(1);
 return 0;
}
