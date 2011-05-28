#include <iostream>
using namespace std;
int card[101]={0},cardN,allS;
bool listS[100001]={0};
int cardS=0,cardX[101]={0},x=0,cardOK[101]={0},exitT=0;

void op(){
     int i;
     x=1;
     for(i=1;i<=cardN;i++)
         cardOK[i]=cardX[i];
     return;
}
void expand(int cardI,bool shu){
     int i,s;
     if(exitT==0){
         if(shu == 1){
         if(listS[cardS] == 0)
             listS[cardS]=1;
         else if( cardS==allS ){
             if(x == 0) op();
             else{ cout<<-1; x=2; exitT=1;}
             return;
         }
         else return;
         }
         if(cardS>allS)
             return;
         else if(cardI==cardN){
             if(cardS+card[cardN]==allS){
                 if(x == 0){cardX[cardN]=1;op();}
                 else{ cout<<-1; x=2; exitT=1;}
             }
             return;
         }
         /*
         for(i=1;i<=cardN;i++)
            if(cardI==i)cout<<'#'<<' ';
            else cout<<cardX[i]<<' ';
         cout<<cardS<<endl;
         */
         expand(cardI+1,0);
         
         cardX[cardI]=1;
         cardS+=card[cardI];
         expand(cardI+1,1);
         cardS-=card[cardI];
         cardX[cardI]=0;
     }
     return ;
}

int main(){
    int i,j;
    cin>>allS>>cardN;
    for(i=1;i<=cardN;i++)
        cin>>card[i];
    listS[allS]=2;
    expand(1,1);
    if(x==1){
    for(i=1;i<=cardN;i++)
        if(cardOK[i]==0)
            cout<<i<<' ';
    }
    else if(x==0)
        cout<<0;
    //while(1);
    return 0;
}
