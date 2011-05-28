#include <stdio.h>
int f[101][1001]={0},w[101]={0},v[101]={0};
int max(int a,int b){
  return a>b?a:b;
}
int main(){
int i,j,t,m,temp1,temp2;
scanf("%d %d",&t,&m);
for(i=1;i<=m;i++){
  scanf("%d %d",&(w[i]),&(v[i]));
  }
for(i=1;i<=m;i++)
  for(j=1;j<=t;j++)
if(j>=w[i])f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
else f[i][j]=f[i-1][j];
printf("%d",f[m][t]);
return 0;
}
