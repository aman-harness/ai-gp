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
/* ���� Description   
   һЩ��ׯ����һ����ֱ�ĸ��ٹ�·���ϣ�������һ��������������������·��ÿ����ׯ�����궼��������û��������ׯ��������ͬ��������ׯ�ľ��붨��Ϊ����֮��ľ���ֵ��������Ҫ��ĳЩ��ׯ�����ʾ֡�ʹÿ����ׯʹ����������������ʾ֣������ʾֵ�ԭ���ǣ����д�ׯ������ʹ�õ��ʾֵľ����ܺ���С��
���ݹ�ģ��1<=��ׯ��<=300,  1<=�ʾ���<=30,  1<=��ׯ����<=10000 
   
   
 �����ʽ Input Format  
   2��

��һ��:n m {��ʾ��n����ׯ������m���ʾ�}
�ڶ���:a1 a2 a3 .. an {��ʾn����ׯ������}
 
   
   
 �����ʽ Output Format  
   1��

��һ��:l {l��ʾ��С�����ܺ�}
 
 10 5
1 2 3 6 7 9 11 22 44 50

9
*/
    
