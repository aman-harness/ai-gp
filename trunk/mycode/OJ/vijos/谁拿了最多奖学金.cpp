#include<stdio.h>
main()
{
    char n[101][30],c,d;
    int q,i,s,a,b,e,y=0,max=0,k;
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {                s=0;
                     scanf("%s %d %d %c %c %d",&n[i],&a,&b,&c,&d,&e);
                     if(a>80&&e>0)
                     s+=8000;
                     if(a>85&&b>80)
                     s+=4000;
                     if(a>90)
                     s+=2000;
                     if(a>85&&d=='Y')
                     s+=1000;
                     if(b>80&&c=='Y')
                     s+=850;
                     y+=s;
                     if(s>max){max=s;k=i;s=0;}
    }
    printf("%s\n%d\n%d\n",n[k],max,y);
    while(1);
}
    
