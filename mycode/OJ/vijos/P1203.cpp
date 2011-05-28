#include <iostream>
using namespace std;
long n,k,f,length[1001];
int main()
{
    long a,b,i,carry,ans;
    cin>>n>>k>>f;
    for(i=1;i<=n;++i)
                     length[i]=1;
    for(i=1;i<=f;++i)
    {
     cin>>a>>b;
     length[a]+=b;
    }
    ans=1;
    carry=0;
    for(i=1;i<=n;++i)
                     if(carry+length[i]>k)
                     ++ans,carry=length[i];
                     else
                     carry+=length[i];
    cout<<ans;
    return 0;
}

/*   
1 1 1 1 1
1 
1 0 0 0 0
*/
