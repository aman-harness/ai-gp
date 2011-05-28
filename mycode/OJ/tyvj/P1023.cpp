/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
#include <cmath>
using namespace std;

int dp[510][2] = {0};	//1ÐÝÏ¢×´Ì¬£¬0×ÔÓÉ×´Ì¬
int n,m;
int d[2010] = {0};

int main()
{
	int i,j;
		
	cin >> n >> m;
	for(i = 1; i <= n; i ++)
		cin >> d[i];
		
	for(i = 1; i <= n; i ++)
	{
		int x = dp[0][1];
		for(j = 0; j < m; j ++)
		{
			dp[j][1] = max(dp[j + 1][1], dp[j + 1][0]);
		}
		dp[0][1] = max(dp[0][1], x);
		
		for(j = m; j > 0; j --)
		{
			dp[j][0] = dp[j - 1][0] + d[i]; 
		}
		dp[1][0] = max(dp[1][0],x + d[i]);
		
		//cout << dp[1][0] << ' ' << dp[0][1] << endl;
	}
	cout << dp[0][1] << endl;
	//while(1);
    return 0;
}
