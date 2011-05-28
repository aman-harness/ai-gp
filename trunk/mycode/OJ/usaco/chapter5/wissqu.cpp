/*
ID: interne4
PROG: wissqu
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("wissqu.in");
ofstream fout("wissqu.out");

const int dir[9][2] = {0,0,0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
int s = 0;
char map[5][5];
bool vis[5][5] = {0};
int cow[5] = {0};

int rec[17][2] = {0};
char recC[17];
bool isP = 0;

void print()
{
	int i;
	for(i=1;i<=16;i++)
	{
		fout << recC[i] << ' ' << rec[i][0] << ' ' << rec[i][1] << endl;
	}
}

void search(int l)
{
	int i,j,k,m;
	char temp;
	bool can[6][6];
	//print();
	if(l > 16)
	{
		s ++;
		if(!isP)
		{
			print();
			isP = 1;
		}
		return;
	}
	if(l == 1)
	{
		i = 3;
		memset(can,0,sizeof(can));
		for(j=1;j<=4;j++)
			for(k=1;k<=4;k++)
				if(map[j][k] == i + 'A')
				{
					for(m=0;m<9;m++)
						can[j+dir[m][0]][k+dir[m][1]] = 1;
				}
		for(j=1;j<=4;j++)
			for(k=1;k<=4;k++)
				if(!can[j][k] && !vis[j][k])
				{
					temp = map[j][k];
					vis[j][k] = 1;
					map[j][k] = 'A' + i;
					cow[i] --;
					if(!isP)
					{
						rec[l][0] = j;
						rec[l][1] = k;
						recC[l] = i + 'A';
					}
					search(l + 1);
					cow[i] ++;
					vis[j][k] = 0;
					map[j][k] = temp;
				}
	}
	else
	{
		for(i=0;i<5;i++)
		{
			//if(l < 10)
			//fout << l << ' ' << char(i + 'A') << endl;
			if(cow[i] <= 0)
				continue;
			memset(can,0,sizeof(can));
			for(j=1;j<=4;j++)
				for(k=1;k<=4;k++)
					if(map[j][k] == i + 'A')
					{
						for(m=0;m<9;m++)
							can[j+dir[m][0]][k+dir[m][1]] = 1;
					}
			for(j=1;j<=4;j++)
				for(k=1;k<=4;k++)
					if(!can[j][k] && !vis[j][k])
					{
						temp = map[j][k];
						vis[j][k] = 1;
						map[j][k] = 'A' + i;
						cow[i] --;
						
						if(!isP)
						{
							rec[l][0] = j;
							rec[l][1] = k;
							recC[l] = i + 'A';
						}
						search(l + 1);
						cow[i] ++;
						vis[j][k] = 0;
						map[j][k] = temp;
					}
		}
	}
}

int main()
{
	int i,j;
	for(i=1;i<=4;i++)
	for(j=1;j<=4;j++)
		fin >> map[i][j];
	for(j=0;j<5;j++)
		cow[j] = 3;
	cow[3] = 4;
	search(1);
	fout << s << endl;
    return 0;
}
