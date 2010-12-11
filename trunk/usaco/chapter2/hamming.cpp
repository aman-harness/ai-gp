/*
ID: interne4
PROG: hamming
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cmath>
#include <bitset>
using namespace std;
using std::bitset;
ifstream fin("hamming.in");
ofstream fout("hamming.out");

unsigned int n,b,d,s,ans[100];

int main()
{
	int i,j,k;
	fin >> n >> b >> d;
	s = 1;
	ans[0] = 0;
	if(n == 0)
	{
		fout << endl;
		return 0;
	}
	fout << ans[0] << ' ';
	for(i=1;s < n;i++)
	{
		bool t = 1;
		for(j = 0; j < s; j ++)
		{
			k = i^ans[j];
			bitset<8> a(k);
			if(a.count() < d)
			{
				t = 0;
				break;
			}
		}
		if(t == 1)
		{
			ans[s] = i;
			j = i;
			fout << ans[s];
			if((s+1)%10 == 0)
				fout << endl;
			else
			{
				if(s+1 == n)
					fout << endl;
				else
					fout << ' ';
			}
			s++;
		}
	}
    return 0;
}
