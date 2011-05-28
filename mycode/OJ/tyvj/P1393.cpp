#include<stdio.h>
#define M 101

int a[M] = {0},now = 0,need;
int main()
{
    int m,n,total=0,j,x,i;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
    {
        need=1;
        scanf("%d",&x);
        for(j=1;j<=now;j++)
            if(a[j]==x)
            {
                need=0;
                break;
            }
        if(need)
        {
            if(now<m)
                a[++now]=x;
            else
            {
                for(j=2;j<=m;j++)
                    a[j-1]=a[j];
                a[m]=x;
            }
            total++;
        }
    }
    printf("%d",total);
    return 0;
}
