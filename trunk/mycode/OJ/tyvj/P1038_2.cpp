#include <cstdio>
#include <stdlib.h>
#define min(a,b) (a<b)?a:b
struct segment{
       int b,e,min;
       };
segment seg[500000];
void build (int b,int e,int s);//起始，结束，线段 
void insert(int x,int s,int num);//位置，线段，值 
int getmin(int b,int e,int s);//起始，结束，线段 
int M,N;
int main()
{
    int i,j,t;
    int b,e;
    scanf ("%d%d",&M,&N);
    build(1,M,1);
    for (i=1;i<=M;i++)
    {
        scanf ("%d",&t);
        insert(i,1,t);
	}
    for (i=1;i<=N;i++)
    {
        //scanf("%d",&t);
        t = 1;
        if (t==1)//get
		{
           scanf ("%d%d",&b,&e);
           printf("%d ",getmin(b,e,1));
		}
		else//修改
		{
            scanf("%d%d",&b,&t);
            insert(b,1,t);
		}
	}
    //system("pause");
}

void build (int b,int e,int s)
{
     seg[s].b=b;
     seg[s].e=e;
     seg[s].min=0x7fffffff;
     if (b!=e)
     {
        int mid =(b+e)>>1;
        build (b    ,mid,s<<1    );
        build (mid+1,e  ,(s<<1)+1);
	}
}

void insert(int x,int s,int num)

{//位置，线段，值 
     if (seg[s].b==seg[s].e ){
        seg[s].min=num;
        return ;
        }
     int mid=(seg[s].b + seg[s].e) >>1;
     if (x<=mid)
        insert(x,s<<1    ,num);
     else
        insert(x,(s<<1)+1,num);
     seg[s].min=min(seg[s<<1].min ,seg[(s<<1)+1].min);
}

int getmin(int b,int e,int s)//起始，结束，线段   
{
    if (seg[s].b==b && seg[s].e==e)
       return seg[s].min;
 
    int mid=(seg[s].b + seg[s].e)>>1;
    if   (e<=mid)
         return getmin(b,e,s<<1);
    else if (b>mid)//b>=mid+1
         return getmin(b,e,(s<<1)+1);
    else // 分割 
         return min(getmin(b,mid,s<<1) , getmin(mid+1,e,(s<<1)+1) );
}
