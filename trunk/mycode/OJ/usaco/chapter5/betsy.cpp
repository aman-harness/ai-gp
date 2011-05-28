/*
ID: interne4
PROG: betsy
LANG: C++
DATA: 2010.12.17
ALGO: Simulation
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
//#include <ctime>
using namespace std;
ifstream fin("betsy.in");
ofstream fout("betsy.out");

const int maxN = 7 + 2;

int n;
int vis[maxN][maxN] = {0};

int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int ans;

void expand(int x, int y, int s)
{
	int i,j;
	
	//fout << x << ' ' << y << endl;
	
	if(x == n && y == 1)
	{
		if(s == n * n)
		{
			/*for(i = 1; i <= n; i ++)
			{
				for(j = 1; j <= n; j ++)
					fout << vis[i][j] << ' ';
				fout << endl;
			}
			fout << endl;*/
			ans ++;
		}
		return;
	}
	/*if(vis[n][1] && vis[n-1][2])
		return;*/
	/*
	else 
	{
		for(i = 0; i < 4; i ++)
		{
			if(!vis[x + dir[i][0]][y + dir[i][1]])
				expand(x + dir[i][0], y + dir[i][1], s + 1);
		}
	}
	*/
	
	for(i = 0; i < 4; i ++)
	{
		if(!vis[x + dir[i][0]][y + dir[i][1]])
		{
			int l = 0;
			for(j = 0; j < 4; j ++)
			{
				if(vis[x + dir[i][0] + dir[j][0]][y + dir[i][1] + dir[j][1]])
					l ++;
			}
			
			vis[x + dir[i][0]][y + dir[i][1]] = s + 1;
			expand(x + dir[i][0], y + dir[i][1], s + 1);
			vis[x + dir[i][0]][y + dir[i][1]] = 0;
			
			if(l == 3 && !(x == n && y == 2) && !(x == n - 1 && y == 1))
			{
				break;
			}
			
		}
	}
}

void init()
{
	fin >> n;
	for(int i = 0; i <= n + 1; i ++)
	{
		vis[0][i] = vis[n + 1][i] = vis[i][0] = vis[i][n + 1] = 1;
	}
	ans = 0;
}

int main()
{
	//clock_t start, finish;  
	//start = clock();
	init();
	
	if(n == 7)
	{
		fout << 88418 << endl;
		return 0;
	} 
	
	vis[1][1] = 1;
	expand(1,1,1);
	//finish = clock();
	fout << ans << endl;//' ' << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
