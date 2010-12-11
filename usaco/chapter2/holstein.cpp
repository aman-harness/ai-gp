/*
ID: interne4
PROG: holstein
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");

int value[100][100]={0},need[100]={0},n,m,now[100]={0},step[100]={0};
int minNow[100]={0},minN;
bool isY[100]={0};

void expand(int x,int s)
{
	int j;
	if(x == m)
	{
		bool t=1;
		for(j=0;j<n;j++)
			if(now[j] < need[j])
			{
				t=0;
				break;
			}
		if(t)
		{
			if(minN > s)
			{
				for(j=0;j<s;j++)
				minNow[j] = step[j];
				minN = s;
			}
		}
		return;
	}
	step[s] = x;
	isY[x] = 1;
	for(j=0;j<n;j++)
		now[j] += value[x][j];
	expand(x+1,s+1);
	for(j=0;j<n;j++)
		now[j] -= value[x][j];
	isY[x] = 0;
	expand(x+1,s);
}

int main()
{
	int i,j;
	minN = 100;
	fin >> n;
	for(i=0;i<n;i++)
		fin >> need[i];
	fin >> m;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			fin >> value[i][j];
	expand(0,0);
	fout << minN << ' ';
	for(i=0;i<minN-1;i++)
		fout << minNow[i]+1 << ' ';
	fout << minNow[minN-1]+1 << endl;
    return 0;
}
