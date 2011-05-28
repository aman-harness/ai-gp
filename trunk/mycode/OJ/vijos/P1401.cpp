#include <iostream>
#include <iomanip> 
using namespace std;
struct ChaShi{
       long double a;
       long double b;
}t[1000];
int comp(const void *p, const void *q)
{
    return int( ((ChaShi*)(p))->a - (((ChaShi*)(q))->a));
}

int n,m,k;
long double myTime;
int s;
int main(){
    int i,j,f,l,p;
    cin>>n>>k>>m;
    for(i=0;i<m;i++)cin>>t[i].a>>t[i].b;
    qsort(t,m,sizeof(ChaShi),comp);
    
    //for(i=0;i<m;i++)cout<<t[i].a<<' '<<t[i].b<<endl;
    s=1;
    f=0;
    while(s<n){
        //cout<<myTime<<' '<<s<<' '<<f;
        if(f==m){
            if(s<k){
                    s+=s;
                    myTime+=1.0;
            //cout<<' '<<1;
            }
            else{
                 l = (n-s-1)/k+1;
                 s += k * l;
                 myTime += l;
                 continue;
            }
            //cout<<' '<<3;
        }
        else{
        p=0;
        while(myTime>t[f].a){
            f++;
            if(f>=m){p=1;break;}
        }
        if(p==1)continue;
        if(myTime+1<=t[f].a){
            if(s<k){
            s+=s;
            myTime+=1.0;
            //cout<<' '<<1;
            }
            else{
                     l=int((t[f].a-myTime)/1);
                     s+=k*l;
                     myTime = t[f].a + t[f].b;
                     f++;
            }
        }
        else{
             myTime = t[f].a + t[f].b;
             f++;
            //cout<<' '<<myTime;
        }
        }
        //cout<<endl;
    }
    cout<<setprecision(2)<<fixed<<myTime;
    //while(1);
    return 0;
}
