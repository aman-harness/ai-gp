#include <iostream>
using namespace std;
int n,m;
float t;
struct point{
       float x;
       float y;
}a[1001]
struct point{
       float x;
       float y;
       float v;
}b[1001];
float v[1001];
int main(){
    int i,j;
    cin>>n>>m>>t;
    for(i=1;i<=m;i++)
    cin>>a[i].x>>a[i].y;
    for(i=1;i<=n;i++)
    cin>>b[i].x>>b[i].y>>b[i].v;
    return 0;
}
    
