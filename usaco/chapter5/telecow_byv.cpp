/*
ID: interne4
PROG: telecow
LANG: C++
DATA: 2011.2.21
ALGO: Dinic + Point to line
*/
 
#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 201
#define INF 0x7FFFFFFF
 
using namespace std;
 
class Tadjl
{
public:
	int cnt;
	int to[MAX];
	Tadjl(){cnt=0;}
	void ins(int k){to[++cnt]=k;}
};
 
class Tqueue
{
private:
	long first,last;
	long list[MAX*MAX];
public:
	long size;
 
	Tqueue()
	{
		reset();
	}
 
	void reset()
	{
		first=1;
		last=size=0;
	}
 
	void ins(long k)
	{
		size++;
		list[++last]=k;
	}
 
	long del()
	{
		size--;
		return list[first++];
	}
};
 
class Tstack
{
public:
	int stack[MAX];
	int top;
	int min,p;
	void reset()
	{
		top=0;
		min=INF;
	}
 
	Tstack()
	{
		reset();
	}
	void ins(int k)
	{
		stack[++top]=k;
	}
	void del()
	{
		top--;
	}
};
 
ifstream fi("telecow.in");
ofstream fo("telecow.out");
Tqueue Q;
Tstack AP;
int c1,c2,RN,RM,S,T,netflow;
Tadjl adjl[MAX];
int odis[MAX][MAX],dis[MAX][MAX],Flow[MAX][MAX];
int level[MAX],set[MAX];
bool used[MAX];
 
void init()
{
	int i,a,b,a1,a2,b1,b2,c;
	fi >> RN >> RM >> c1 >> c2;
	if (c1>c2) {c=c1;c1=c2;c2=c;}
	for (i=1;i<=RN;i++)
	{
		a=i*2-1;b=i*2;
		adjl[a].ins(b);
		dis[a][b]=1;
		adjl[b].ins(a);
		dis[b][a]=0;
	}
	for (i=1;i<=RM;i++)
	{
		fi >> a >> b;
		if (a>b) {c=a;a=b;b=c;}
		a1=a*2-1;a2=a1+1;
		b1=b*2-1;b2=b1+1;
		adjl[a2].ins(b1);
		dis[a2][b1]=INF;
		adjl[b1].ins(a2);
		dis[b1][a2]=0;
		adjl[b2].ins(a1);
		dis[b2][a1]=INF;
		adjl[a1].ins(b2);
		dis[a1][b2]=0;
	}
	S=c1*2;
	adjl[T=c2*2-1].cnt=0;
	memcpy(odis,dis,sizeof(dis));
}
 
void Dinic_level()
{
	int i,j,k;
	Q.reset();
	memset(used,0,sizeof(used));
	memset(level,0,sizeof(level));
	Q.ins(S);
	while (Q.size)
	{
		i=Q.del();
		used[i]=true;
		for (k=1;k<=adjl[i].cnt;k++)
		{
			j=adjl[i].to[k];
			if (!dis[i][j]) continue;
			if (used[j] || j==1) continue;
			level[j]=level[i]+1;
			Q.ins(j);
		}
	}
}
 
void Dinic_Argument()
{
	int i,u,v;
	AP.stack[0]=S;
	for (i=1;i<=AP.top;i++)
	{
		u=AP.stack[i-1];
		v=AP.stack[i];
		if (dis[u][v]<AP.min)
		{
			AP.min=dis[u][v];
			AP.p=u;
		}
	}
	for (i=AP.top;i>=1;i--)
	{
		u=AP.stack[i-1];
		v=AP.stack[i];
		Flow[u][v]+=AP.min;
		dis[u][v]-=AP.min;
		dis[v][u]+=AP.min;
	}
}
 
bool Dinic_dfs(int u)
{
	int outdegree=0;
	int i,v;
	bool B;
	if (u!=T)
	{
		for (i=1;i<=adjl[u].cnt;i++)
		{
			v=adjl[u].to[i];
			if (level[v]==level[u]+1 && dis[u][v])
			{
				outdegree++;
				AP.ins(v);
				B=Dinic_dfs(v);
				AP.del();
				if (B && u!=AP.p)
					return true;
			}
		}
		if (outdegree==0)
			level[u]=0;
	}
	else
	{
		Dinic_Argument();
		return true;
	}
	return false;
}
 
void Dinic()
{
	memset(Flow,0,sizeof(Flow));
	for (;;)
	{
		Dinic_level();
		if (level[T]==0)
			return;
		AP.reset();
		Dinic_dfs(S);
	}
}
 
int getflow()
{
	int i,flow=0;
	for (i=1;i<=RN*2;i++)
		flow+=Flow[S][i];
	return flow;
}
 
void Getset()
{
	int i,a,b,nowflow,cnt=0;
	Dinic();
	netflow=getflow();
 
 
	for (i=1;i<=RN;i++)
	{
		if (i!=c1 && i!=c2)
		{
			a=i*2-1;b=a+1;
			odis[a][b]=0;
			memcpy(dis,odis,sizeof(odis));
			Dinic();
			nowflow=getflow();
			if (nowflow+1==netflow-cnt)
				set[++cnt]=i;
			else
				odis[a][b]=1;
		}
		if (cnt==netflow)
			return;
	}
}
 
void print()
{
	int i;
	fo << netflow << endl << set[1];
 
	for (i=2;i<=netflow;i++)
		fo <<' ' << set[i];
	fo << endl;
	fi.close();
	fo.close();
}
 
int main()
{
	init();
	Getset();
	print();
	return 0;
}
