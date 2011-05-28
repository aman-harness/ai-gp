/*
ID: interne4
PROG: game1
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("game1.in");
ofstream fout("game1.out");
/*
Note: When you answer this problem you should think the even parity.
Different parity, Different order of the output.
*/
const int MaxN = 100 + 1;
int n, v[MaxN] = {0};
int f[MaxN][MaxN] = {0};
/*
f[start][end] mean the most sum of first-person in the list from start to 
end.
*/ 

int main()
{
	int i,j,l,r,sum;
	fin >> n;
	sum = 0;
	for(i=1;i<=n;i++)
	{
		fin >> v[i];
		sum += f[i][i] = v[i];
	}
	for(i=2;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			l = j - i + 1;
			r = j;
			if(i%2==0)
				f[l][r] = min(f[l+1][r], f[l][r-1]);
			else
				f[l][r] = max(f[l+1][r] + v[l], f[l][r-1] + v[r]);
		}
	if(n % 2 == 0)
		fout << sum - f[1][n] << ' ' << f[1][n] << endl;
	else
		fout << f[1][n] << ' ' << sum - f[1][n] << endl;
    return 0;
}


