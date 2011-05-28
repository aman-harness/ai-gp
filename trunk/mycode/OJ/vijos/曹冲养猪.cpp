#include <iostream>
using namespace std;
long long a,b,s=1,t,n,i;
int main()
{
cin>>n;
for (i=1;i<=n;i++){cin>>a>>b;while(t%a!=b)t+=s;s*=a;}
cout<<t<<endl;
return 0;
}
