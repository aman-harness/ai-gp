/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
using namespace std;
const int maxN = 1000 + 1, maxM = 100 + 1;
int t[maxM] = {0};
int p[maxM] = {0};
int f[maxN][maxM] = {0};
int T,m;

void init()
{
	int i,j;
	cin >> T >> m;
	for(i=1;i<=m;i++)
		cin >> t[i] >> p[i];
}

int main()
{
	int i,j;
	init();
	for(j=1;j<=m;j++)
		for(i=1;i<=T;i++)
		{
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if(i >= t[j] && f[i - t[j]][j - 1] + p[j] >= f[i][j])
				f[i][j] = f[i - t[j]][j - 1] + p[j];
		}
	cout << f[T][m] << endl;
	//system("pause");
	return 0;
}
