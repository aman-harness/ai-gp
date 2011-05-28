#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("river.in");
ofstream fout("river.out");

int stone[101]={0},S,T,M,L;

int main(){
    int i,p=0,stoneNum=0,dis[101]={0},t;
    char a;
    fin>>L>>S>>T>>M;
    for(i=1;i<=M;i++){
        fin>>stone[i];
    }
    while(p<L){
        memset(dis,0,sizeof(dis));
        for(i=1;i<=M;i++){
            if(p+S <= stone[i] && p+T >= stone[i])
            dis[stone[i]-p]=1;
        }
        t=0;
        for(i=T;i>=S;i--){
            if(dis[i]==0){
            p+=i;
            t=1;
            }
        }
        if(t==0){
            p+=T;
            stoneNum+=1;
        }
    }
    fout<<stoneNum<<endl;    
    return 0;
}
/* 0 1 2 3 4 5 6 7 8 9 10
       1 1   1 1 1
   2~3    
*/
