/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int map[300][300] = {0};	//1ÐÝÏ¢×´Ì¬£¬0×ÔÓÉ×´Ì¬
int n,m,f;

int main()
{
	int i,j,k;
	int x1,x2,y1,y2;
		
	cin >> n >> m >> f;
	for(k = 1; k <= f; k ++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for(i = x1; i <= x2; i ++)
			for(j = y1; j <= y2; j ++)
				map[i][j] = 1;
	}
	
	int s = 0;
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
			if(map[i][j])
				s ++;
				
	cout << s << endl;
	//while(1);
    return 0;
}
