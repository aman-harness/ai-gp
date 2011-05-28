#include <iostream>
using namespace std;
int village[301],n,m,mindis=20000000,dis=0;
int cost(int a,int b){
    int i=a,j=b,s=0;
    while(i<j)
    s+=village[j--]-village[i++];
    return s;
}
int f(int v,int p){
    int i,j,a;
    if(p==m){
             dis+=cost(v,n);
            if(dis<mindis){
                           mindis=dis;
            }
            return 0;
    }
    if(dis>mindis){
        return 0;
    }
    for(i=v;i<=n-(m-p);i++){
        a=dis;
        dis+=cost(v,i);
        f(i+1,p+1);
        dis=a;
    }
    return 0;
}
int main(){
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    cin>>village[i];
    f(1,1);
    cout<<mindis;
    system("pause");
    return 0;
}
/* 描述 Description   
   一些村庄建在一条笔直的高速公路边上，我们用一条坐标轴来描述这条公路，每个村庄的坐标都是整数，没有两个村庄的坐标相同。两个村庄的距离定义为坐标之差的绝对值。我们需要在某些村庄建立邮局。使每个村庄使用与它距离最近的邮局，建立邮局的原则是：所有村庄到各自使用的邮局的距离总和最小。
数据规模：1<=村庄数<=300,  1<=邮局数<=30,  1<=村庄坐标<=10000 
   
   
 输入格式 Input Format  
   2行

第一行:n m {表示有n个村庄，建立m个邮局}
第二行:a1 a2 a3 .. an {表示n个村庄的坐标}
 
   
   
 输出格式 Output Format  
   1行

第一行:l {l表示最小距离总和}
 
 10 5
1 2 3 6 7 9 11 22 44 50

9
*/
    
