/*
ID: interne4
PROG: theme
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("theme.in");
ofstream fout("theme.out");
const int maxN = 5000 + 1;
int n;
int music[maxN] = {0};
int c[maxN] = {0};
int ans;
bool isA = 0;

int main()
{
	int i,j,k;
	ans = 4;
	fin >> n;
	for(i = 1; i <= n; i ++)
		fin >> music[i];
	for(i = 1; i < n; i ++)
		c[i] = music[i + 1] - music[i];
	/*for(i = 1; i < n; i ++)
		fout << c[i] << ' ';
	fout << endl;
	*/
	for(i = 1; i < n - ans * 2; i ++)
		for(j = i + ans; j < n - ans; j ++)
			if(c[i] == c[j])
			{
				int d = n - j;
				if(j - i - 1 < d)
					d = j - i - 1;
				for(k = 1; k < d; k ++)
					if(c[i + k] != c[j + k])
						break;
				if(ans <= k)
				{
					isA = 1;
					ans = k;
				}
			}
	if(isA)
		fout << ans + 1 << endl;
	else
		fout << 0 << endl;
	return 0;
}
