/*
ID: interne4
PROG: concom
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin ("concom.in");
ofstream fout ("concom.out");
int n,h,com[101][101],temp[101];
bool vis[101];
void dfs(int pos)
{
	vis[pos]=true;
	for(int i = 1; i <= h;i ++)
		temp[i] += com[pos][i];
	for(int j = 1;j <= h;j ++)
		if((temp[j] > 50)&&(!vis[j])) dfs(j);
}
int main()
{
	int i,j,p;
	fin >> n;
	for(int i1 = 1; i1 <= n; i1 ++)
	{
		fin >> i >> j >> p;
		com[i][j] = p;
		if(i > h) h = i;
		if(j > h) h = j;
	}
	for(int k = 1; k <= h; k ++)
	{
		for(int p = 1; p <= h; p ++)
		{
			vis[p] = false;
			temp[p] = 0;
		}
		dfs(k);
		for(int q = 1; q <= h; q ++)
		if((temp[q] > 50)&&(q != k)) 
		fout << k << ' ' << q << endl;
	}
    return 0;
}

/*#include <fstream>
#include <memory.h>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");

short map[101][101]={0},chu[101]={0},bb[101]={0};
bool isK[101][101]={0};
int n,chuN;

void expand(int ,short*);

int main()
{
	int i,j,a,b,x;
	fin >> n;
	chuN = 0;
	for(i=1;i<=n;i++)
	{
		fin >> a >> b >> x;
		map[a][b] = x;
		if(x > 50)
		{
			isK[a][b] = 1;
			chu[a] = 1;
		}
		else
		{
			isK[b][b] = 1;
		}
	}
	
	for(i=1;i<=100;i++)
	{
		if(chu[i] > 0)
		{
			expand(i,bb);
			//fout << endl;
		}
	}
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
		{
			if(i!=j && isK[i][j])
				fout << i << ' ' << j << endl;
		}
	return 0;
}

void expand(int x,short y[101])
{
	int i;
	bool sha;
	short k[101]={0};
	chu[x] = 0;
	//fout << x << endl;
	do
	{
		memset(k,0,sizeof(k));
		for(i=1;i<=100;i++)
		{
			if(i == x) continue;
			if(isK[x][i])
			{
				//fout << x << ' ';
				expand(i,k);
			}
			k[i] += map[x][i];
			
			if(map[x][i] > 0)
				y[i] += map[x][i];
		}
		sha = 0;
		for(i=1;i<=100;i++)
		{
			if(k[i] > 50 && !isK[x][i])
			{
				isK[x][i] = 1;
				sha = 1;
			}
			//if(k[i] > 0)
				//fout << i << ' ' << k[i] << endl;
		}
		
	}while(sha);
	
}

template <class Value>
class TreeNode
{
public:
	int id;
	Value value;
	vector<TreeNode> items;
};

template <class T>
class Tree
{
public:
	TreeNode<T>* root;
	
	Tree()
	{
		root = new TreeNode<T>();
	}
	
	void add(int a,int b,T value)
	{
		TreeNode x;
		
	}
};
*/
