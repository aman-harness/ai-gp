/*
ID: interne4
PROG: fracdec
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

stringstream firOut;

const int maxN = 100001;
int n,d;
int remainder[maxN*10] = {0};
char ans[maxN];

int main()
{
	int k,i,x;
	fin >> n >> d;
	remainder[0]=100000000;
	if(n < d)
		x = 0;
	else
		x = n/d;
	firOut << x << '.';
	n = n % d;
	n *= 10;
	k = 1;
	while(1)
	{
		if(remainder[n])
			break;
		else
			remainder[n] = k;
		for(i=0;i<=9;i++)
			if(n < d*(i+1))
			{
				n -= d*i;
				ans[k] = i + '0';
				break;
			}
		n *= 10;
		k ++;
	}
	for(i=1;i<k;i++)
	{
		if(i == remainder[n])
			firOut << '(';
		firOut << ans[i];
	}
	if(k == 1)
		firOut << '0';
	if(n != 0)firOut << ')';
	string lastout;
	firOut >> lastout;
	for(i=0;i<lastout.size();i++)
	{
		fout << lastout[i];
		if((i+1)%76 == 0)
			fout << endl;
	}
	fout << endl;
    return 0;
}
