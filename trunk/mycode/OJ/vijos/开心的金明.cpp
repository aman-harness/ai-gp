#include <stdio.h>
long weights[25]={0},value[25]={0},n,max=0;
void qqq(long weight,int m,int temp)
{
  int i;
  for(i=m;i<n;i++)
  {
 if(weight-weights[i]>=0)
 {
 weight-=weights[i];
 temp+=value[i];
 if(max<temp)
 {
 max=temp;
 }
 qqq(weight,i+1,temp);
 weight+=weights[i];
 temp-=value[i];
 }
  }
}
main()
{
  long weight;
  int i,temp;
  scanf("%ld%ld",&weight,&n);
  for(i=0;i<n;i++)
  {
 scanf("%ld%d",&weights[i],&temp);
 value[i]=weights[i]*temp;
  }
  qqq(weight,0,0);
  printf("%ld\n",max);
}
