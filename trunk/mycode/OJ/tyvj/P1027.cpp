/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int map[100][100] = {0};	//1ÐÝÏ¢×´Ì¬£¬0×ÔÓÉ×´Ì¬
int n,m,f;
const int dir[4][2] = {0,1,0,-1,1,0,-1,0};

int main()
{
	int i,j,k,s;
	int x,y;
	
	cin >> n >> m;
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
			cin >> map[i][j];
	
	x = y = 1;
	s = map[1][1];
	while(!(x == n && y == m))
	{
		int ma = -1,ml;
		for(k = 0; k < 4; k ++)
			if(ma < map[x + dir[k][0]][y + dir[k][1]])
			{
				ma = map[x + dir[k][0]][y + dir[k][1]];
				ml = k;
			}
		s += ma;
		map[x][y] = -1;
		x += dir[ml][0];
		y += dir[ml][1];
		map[x][y] = -1;
		//cout << x << ' ' << y << endl;
	}
	cout << s << endl;
	//while(1);
    return 0;
}
