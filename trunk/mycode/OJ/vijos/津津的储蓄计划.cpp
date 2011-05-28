#include <iostream>
using namespace std;
#include <cstdlib>
int main (void)
{
int i,t;
int index=0,plan,sum=0;
for (i=1;i<=12;i++)
{
cin>>plan;
index+=300;
index-=plan;
if (index<0)
{
 cout<<'-'<<i<<endl;
 exit(0);
}
if (index>=100)
{
sum+=index/100*100;
index-=index/100*100;
}
}
cout<<index+sum*120/100<<endl;
}
