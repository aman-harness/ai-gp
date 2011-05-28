#include<cstdio>
main()
{
      int i,x,y,min=0,s=0;
      for(i=1;i<=7;i++)
      {
                       scanf("%d %d",&x,&y);
                       if(x+y-8>min){min=x+y-8;s=i;}
      }
      printf("%d",s);
}
