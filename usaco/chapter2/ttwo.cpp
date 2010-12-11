/*
ID: interne4
PROG: ttwo
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

char map[12][12];
int x1,x2,y1,y2,d1=0,d2=0;
const short dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int main()
{
	int i,j,k;
	memset(map,'*',sizeof(map));
	for(i=1;i<=10;i++)
	for(j=1;j<=10;j++)
	{
		fin >> map[i][j];
		if(map[i][j] == 'F')
		{
			x1 = i;
			y1 = j;
		}
		else if(map[i][j] == 'C')
		{
			x2 = i;
			y2 = j;
		}
	}
	i = 0;
	while(i<1000000)
	{
		if(x1 == x2 && y1 == y2)
		{
			fout << i << endl;
			return 0;
		}
		x1 += dir[d1][0];
		y1 += dir[d1][1];
		if(map[x1][y1] == '*')
		{
			x1 -= dir[d1][0];
			y1 -= dir[d1][1];
			d1 = (d1 + 1)%4;
		}
		x2 += dir[d2][0];
		y2 += dir[d2][1];
		if(map[x2][y2] == '*')
		{
			x2 -= dir[d2][0];
			y2 -= dir[d2][1];
			d2 = (d2 + 1)%4;
		}
		i++;
		/*
		for(k=1;k<=10;k++)
		{
			for(j=1;j<=10;j++)
			{
				if(k == x1 && j == y1)
					fout << "F";
				else if(k == x2 && j == y2)
					fout << "C";
				else if(map[k][j] != '*')
				    fout << '.';
				else fout << '*';
			}
			fout << endl;
		}
		fout << endl;
		*/
	}
	fout << 0 << endl;
    return 0;
}
