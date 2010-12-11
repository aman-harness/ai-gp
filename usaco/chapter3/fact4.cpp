/*
ID: interne4
PROG: fact4
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("fact4.in");
ofstream fout("fact4.out");

int main()
{
	int i,j,n,n2,x,o;
	n2 = 0;
	fin >> n;
	o = 1;
	for(i=1;i<=n;i++)
	{
		x = i;
		while(x%2==0)
		{x/=2;n2++;}
		while(x%5==0)
		{x/=5;n2--;}
		o = o * x % 10;
	}
	while(n2--) o = o * 2 % 10;
	fout << o << endl;
    return 0;
}
