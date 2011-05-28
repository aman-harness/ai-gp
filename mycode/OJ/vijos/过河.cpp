#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int L;
int s, t, m;
int stone[104];
int dp[104][16];
bool bu[200];

void input()
{
int i;
stone[0] = 0;
scanf("%d %d %d",&s,&t, &m);
for( i=1; i<=m; i++){
scanf("%d", stone + i);
}
}

bool check( int  x ){
if( x < 0 ) return false;
if( x >= s*s-s ) return true;
return bu[x];
}

void Solve()
{
sort(&stone[1], &stone[m+1]);
memset(bu,0, sizeof(bu));
while( stone[m] > L && m>=1 ) m--;
int count=0,i,j,k;
if( s == t ){
for(int i=1; i<=m; i++)
if( stone[i] % s == 0 ) count++;
printf("%d\n", count );
return;
}
bu[0] = true;
for( i=1; i<=90; i++){
for(j=s ; j<=t; j++)
bu[i]=bu[i] | bu[i-j];
}
for( i=0; i<=m; i++){
for( j=0; j<t; j++) 
dp[i][j] = m+1;
}
dp[0][0] = 0;
for( i=1; i<=m; i++){
for(j=0; j<t; j++){
if( stone[i]-j <= stone[i-1] ){
dp[i][j] = dp[i-1][j-stone[i]+stone[i-1]];
}else{
for( k=0; k<t; k++){
if( check( stone[i]-j-stone[i-1]+k ) && dp[i-1][k] < dp[i][j] )
dp[i][j] = dp[i-1][k];
}
if( j==0) dp[i][j]+=1;
}
}
}
int ans = 1<<30;
for( i=0; i<t; i++){
if( dp[m][i] < ans ) ans = dp[m][i];
}
printf("%d\n",ans);
}

int main()
{
while( scanf("%d", &L) == 1){
input();
Solve();
}
return 0;
}
