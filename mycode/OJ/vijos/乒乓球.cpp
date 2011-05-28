#include<cstdio>
#define maxn 100000
int my,em,len;
char c,str[maxn];
int main()
{
int i;
scanf("%c",&c);
while(c!='E')
{
  if(c=='W'||c=='L')
  str[len++]=c;
  scanf("%c",&c);
} 
if(len==0)
{printf("0:0\n\n0:0");return 0;}
for(i=0;i<len;i++)
{
  if(str[i]=='W')
  my++;
  if(str[i]=='L')
  em++;
  if((my>=11&&my-em>=2)||(em>=11&&em-my>=2))
  {
printf("%d:%d\n",my,em);
my=0;em=0;
  }
  if(i==len-1)
   printf("%d:%d\n",my,em);
}
printf("\n");
my=0;em=0;
for(i=0;i<len;i++)
{
  if(str[i]=='W')
  my++;
  if(str[i]=='L')
  em++;
  if((my>=21&&my-em>=2)||(em>=21&&em-my>=2))
  {
printf("%d:%d\n",my,em);
my=0;em=0;
  }
  if(i==len-1)
   printf("%d:%d",my,em);
}
return 0;
}
