#include <iostream>
using namespace std;
int main(){
    bool b[21]={0};
    unsigned long long i,j,s=1,n,m,a;
    cin>>n>>m;
    for(i=1;i<n;i++)
        s*=i;
    m--;
    for(i=n-1;i>=1;i--){
        a=m/s;
        for(j=1;j<=n;j++)
            if(b[j]==0){
                if(a==0){
                    cout<<j<<' ';
                    b[j]=1;
                    break;
                }
                else a--;
            }
        m=m%s;
        s/=i;
    }
    for(i=1;i<=n;i++){
        if(b[i]==0)
            cout<<i<<' ';
    }
    return 0;
}
    
/*1  2  3  4 
  11 11 5  1
  24 6  2  1
  0  1  2  1
  
  2431
  
  
  1234
  1243
  1324
  1342
  .
  .
  2134
  2143
  .
  .
  .
  2431
*/
