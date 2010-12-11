/*
ID: interne4
PROG: buylow
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

ifstream fin("buylow.in");
ofstream fout("buylow.out");

const int maxN = 5000 + 1;
int n;
int stock[maxN] = {0};
int day[maxN] = {0};
int total[maxN];
int temp[maxN];

inline void tempEmpty();

int main()
{
	int i,j;
	int maxD = 0,maxI = 1;
	int t;
	t = 0;
	fin >> n;
	for(i=1;i<=n;i++)
		fin >> stock[i];
	for(i=1;i<=n;i++)
	{
		maxD = 0;
		t = 1;
		memset(temp,0,sizeof(temp));
		for(j=1;j<i;j++)
		{
			if(stock[j] > stock[i])
			{
				if(day[j] > maxD)
				{
					maxD = day[j];
					t = total[j];
					memset(temp,0,sizeof(temp));
					temp[stock[j]] = total[j];
				}
				else if(day[j] == maxD)
				{
						/*if(stock[i] == 17)
							fout << temp[stock[j]] << ' ' << total[j];*/
					if(temp[stock[j]] != 0)
						t -= temp[stock[j]];
					temp[stock[j]] = total[j];
					t += total[j];
					/*if(stock[i] == 17)
						fout << stock[j] << ' ' << t << endl;*/
				}
			}
		}
		total[i] = t;
		day[i] = maxD + 1;
		fout << stock[i] << ' ' << day[i] << ' ' << total[i] << endl;
	}
	for(i=2;i<=n;i++)
		if(day[i] > day[maxI])
			maxI = i;
	int ans = day[maxI];
	int ans2;
	ans2 = 0;
	memset(temp,0,sizeof(temp));
	for(i=1;i<=n;i++)
		if(day[i] == ans)
		{
			if(temp[stock[i]] != 0)
				ans2 -= temp[stock[i]];
			temp[stock[i]] = total[i];
			ans2 += total[i];
		}
	fout << ans << ' ' << ans2 << endl;
	
    return 0;
}

