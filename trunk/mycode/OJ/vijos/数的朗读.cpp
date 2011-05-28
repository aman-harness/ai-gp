#include <stdio.h>
#include <string.h>
#define MAX 101
main()
{
char st[MAX],ct[MAX],res,re[]={'0','#','S','B','Q','W','S','B','Q','Y','S','B','Q'};
int lst=0,lct=0,h,q,i,j,k;
scanf("%s",st) ;
lst = strlen(st) ;
for(i=0 ; (st[i] == '0' || st[i] == '-' || st[i] == '+') && i< lst ; i ++)
if(st[i] == '-' && i == 0)
printf("F");
if( i >= lst-1)
{
printf("0");
return 0 ;
}
for(j=i ; st[j] != '.' && j < lst ; j++)
ct[++lct] = st[j] ;
if( lct == 0 && st[j] == '.' )
printf("0");
else
{
for(h=1,q=lct; h<= lct ;)
{
 if(ct[h] == '0')
 {
  while ( ct[h] == '0' && h <= lct )
  {
    h++;
    q--;
  }
  if( h <= lct)
  printf("0");
 }
 else
 {
 printf("%c",ct[h]);
 if( 1 != q )
 printf("%c",re[q]);
 h ++ ;
 q -- ;
 }
}
}
if( j <= lst-2)  
{
printf("D");
for(k=j+1 ; k< lst ; k++)
printf("%c",st[k]);
}
}
