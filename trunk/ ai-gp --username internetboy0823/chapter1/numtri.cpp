/*
ID: interne4
PROG: numtri
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("numtri.in");
ofstream fout("numtri.out");
int x[1001][1001]={0};
int main()
{
	int i,j,n;
	fin >> n;
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	fin >> x[i][j];
	for(i=n-2;i>=0;i--)
	for(j=0;j<=i;j++)
	{
		if(x[i+1][j] > x[i+1][j+1])
			x[i][j] += x[i+1][j];
		else
			x[i][j] += x[i+1][j+1];
	}
	fout << x[0][0] << endl;
    return 0;
}
