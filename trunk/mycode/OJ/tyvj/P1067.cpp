/**************************************
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
using namespace std;
const int maxM = 100 + 1;
int t[maxM] = {0};
int f[2][maxM] = {0};
int n;

void init()
{
	int i,j;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> t[i];
}

int main()
{
	int i,j;
	init();
	for(i=1;i<=n;i++)
	{
	    int x = -1;
		for(j=1;j<i;j++)
		    if(t[j] < t[i] && f[0][j] > x)
                x = f[0][j];
        f[0][i] = x + 1;
	}

	for(i=n;i>=1;i--)
    {
        int x = -1;
		for(j=n;j>i;j--)
		    if(t[j] < t[i] && f[1][j] > x)
                x = f[1][j];
        f[1][i] = x + 1;
    }
    int ans = 0;
	for(i=1;i<=n;i++)
        if(f[0][i] + f[1][i] > ans)
            ans = f[0][i] + f[1][i];
	ans ++;
	cout << n - ans << endl;
	return 0;
}
