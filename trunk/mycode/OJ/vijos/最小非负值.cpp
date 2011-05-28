#include<cstdio>
main()
{
      short n,s;
      scanf("%d",&n);
      s=n%4;
      if(s==3||s==0)printf("0");
      else printf("1");
}
