/*
ID: interne4
PROG: fence
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
#include <vector>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");

const int MaxE = 1024 + 1, MaxV = 500 + 1;
int F,N;
unsigned int EtV[MaxE][2]={0},adj[MaxV][MaxV]={0},edge[MaxV]={0},edgeN[MaxV]={0};
unsigned int visited[MaxE]={0},visitedV[MaxV]={0},VtE[MaxV][MaxV]={0};
vector<int> ans;

inline int goV(int v,int e)
{
	if(EtV[e][0] == v)
		return EtV[e][1];
	else
		return EtV[e][0];
}

int main()
{
	int i,j,start,tar;
	fin >> F;
	N = 0;
	for(i = 1; i <= F; i++)
	{
		fin >> EtV[i][0] >> EtV[i][1];
		if( EtV[i][0] > N )
			N = EtV[i][0];
		if( EtV[i][1] > N )
			N = EtV[i][1];
		adj[EtV[i][0]][edge[EtV[i][0]]++] = i;
		adj[EtV[i][1]][edge[EtV[i][1]]++] = i;
		VtE[EtV[i][0]][EtV[i][1]] = i;
		VtE[EtV[i][1]][EtV[i][0]] = i;
	}
	for(i = 1; i <= N; i++)
		if(edge[i] != 0)
		{
			start = i;
			break;
		}
	for(i = 1; i <= N; i++)
		if(edge[i]%2 != 0)
		{
			start = i;
			break;
		}
	memcpy(edgeN,edge,sizeof(edge));
	
	vector<int>::iterator iter = ans.end();
	iter = ans.insert(iter,start);
	iter ++;
	while(1)
	{
		unsigned int minS = 0xffffffff,tar;
		visitedV[start] = 1;
		for(j = 0; j < edge[start]; j++)
			if(!visited[adj[start][j]] && minS > goV(start, adj[start][j]))
			{
				tar = adj[start][j];
				minS = goV(start, tar);
			}
		if(minS != -1)
		{
			edgeN[minS] --;
			edgeN[start] --;
		}
		start = minS;
		
		visited[tar] = 1;
		if(start != -1)
		{
			iter = ans.insert(iter, start);
			iter ++;
		}
		else
		{
			bool t = 0;
			for(iter -- = ans.end(); iter >= ans.begin(); iter--)
			{
				//fout << *iter << '.' << edgeN[*iter] << ' ';
				if(edgeN[*iter] > 0)
				{
					start = *iter;
					iter ++;
					t = 1;
					break;
				}
			}
			if(t == 0)
				break;
		}
		//i ++;
	}
	for(i = 0; i < ans.size(); i++)
		fout << ans[i] << endl;
    return 0;
}
