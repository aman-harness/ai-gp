#include <stdio.h>
struct trees
{
int from;
int to;
}trees[10000];

main()
{
  struct trees *p;
  int l,num,count=0,i,j;
  p=trees;
  scanf("%d %d",&l,&num);
  for(i=0;i<num;i++,p++)
   scanf("%d %d",&p->from,&p->to);
  
  for(i=1;i<=l;i++)
  {
p=trees;
for(j=0;j<num;j++,p++)
if(p->from<=i && i<=p->to)
   {if(i==1)count++;
count++;break;}
  }
printf("%d",l-count+1);
}
