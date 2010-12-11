/*
ID: interne4
PROG: nuggets
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("nuggets.in");
ofstream fout("nuggets.out");

int n, nuggets[10] = {0};
int dp[2][1000] = {0};
int maxNuggets = 0;
int main()
{
	int i,j;
	fin >> n;
	for(i=0;i<n;i++)
	{
		fin >> nuggets[i];
		if(nuggets[i] > maxNuggets)
			maxNuggets = nuggets[i];
		dp[0][nuggets[i]] = 1;
	}
	
	//fout << maxNuggets << endl;
	int l = 0, z;
	dp[0][0] = 1;
	for(i=0;i<maxNuggets;i++)
	{
		if(dp[0][i])
		{
			for(j=0;j<n;j++)
				if(i+nuggets[j] < maxNuggets)
					dp[0][(i+nuggets[j])] = dp[0][i];
				else
					dp[1][i + nuggets[j] - maxNuggets] = dp[0][i];
		}
		else
			l = i;
		//fout << dp[0][i];
	}
	//fout  << endl;
	int k = 0;
	bool ld = 0;
	bool isC;
	int *dl,*dn,dc[1000];
	while(1)
	{
		isC = 0;
		z = -1;
		dl = dp[ld];
		dn = dp[!ld];
		memcpy(dc,dl,maxNuggets*sizeof(dn[0]));
		for(i=0;i<maxNuggets;i++)
		{
			if(dn[i])
			{
				for(j=0;j<n;j++)
					if(i+nuggets[j] < maxNuggets)
						dn[(i+nuggets[j])] = dn[i];
					else
						dl[i + nuggets[j] - maxNuggets] = dn[i];
			}
			else
				z = i;
			if(!isC && dn[i]!=dc[i])
				isC = 1;
			//fout << dn[i];
		}
		//fout  << endl;
		if(z == -1)
		{
			fout << k * maxNuggets + l << endl;
			break;
		}
		if(!isC)
		{
			fout << 0 << endl;
			break;
		}
		l = z;
		ld = !ld;
		k++;
	}
    return 0;
}
