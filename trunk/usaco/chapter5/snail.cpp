/*
ID: interne4
PROG: snail
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("snail.in");
ofstream fout("snail.out");
const int maxN = 200 + 1;
const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int n,b,maxS = 0;
short map[maxN][maxN] = {0};

void search(int x,int y,int s)
{
	int i,j;
	bool temp;
	bool isT;
	isT = 0;
	for(i=0;i<4;i++)
	{
		if(!map[x + dir[i][0]][y + dir[i][1]])
		{
			isT = 1;
			temp = 1;
			j = 1;
			while(1)
			{
				if(map[x + dir[i][0] * j][y + dir[i][1] * j] == 1)
				{
					break;
				}
				else if(map[x + dir[i][0] * j][y + dir[i][1] * j] == 2)
				{
					temp = 0;
					break;
				}
				else 
				{
					map[x + dir[i][0] * j][y + dir[i][1] * j] = 2;
				}
				j ++;
			}
			
			
			j --;
			if(temp)
			{
				search(x + dir[i][0] * j, y + dir[i][1] * j, s + j);
			}
			else
			{
				if(s + j > maxS)
					maxS = s + j;
			}
			
			while(j > 0)
			{
				map[x + dir[i][0] * j][y + dir[i][1] * j] = 0;
				j --;
			}
		}
	}
	if(!isT)
	{
		if(s > maxS)
			maxS = s;
	}
}

int main()
{
	int i,j,x;
	fin >> n >> b;
	char c;
	for(i=0;i<=n+1;i++)
		map[0][i] = map[n+1][i] = 1;
	for(i=0;i<=n+1;i++)
		map[i][0] = map[i][n+1] = 1;
	
	for(i=1;i<=b;i++)
	{
		fin >> c >> x;
		map[x][c - 'A' + 1] = 1;
	}
	
	map[1][1] = 2; 
	search(1,1,1);
	
	fout << maxS << endl;
	
    return 0;
}
