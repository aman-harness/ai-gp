/*
ID: interne4
PROG: frac1
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("frac1.in");
ofstream fout("frac1.out");

int n;
struct Fraction
{
	double value;
	int numerator;
	int denominator;
}frac[100000];

int comp(const void *p, const void *q)
{
    if(((Fraction *)p)->value > ((Fraction *)q)->value)
	    return -1;
	else if(((Fraction *)p)->value < ((Fraction *)q)->value)
		return 1;
	else return ((Fraction *)q)->denominator < ((Fraction *)p)->denominator;
}

int main()
{
	int i,j,s=0;
	fin >> n;
	for(i=1;i<=n;i++)
		for(j=0;j<=i;j++)
		{
			frac[s].numerator = j;
			frac[s].denominator = i;
			frac[s++].value = float(i)/j;
		}
	qsort(frac,s,sizeof(frac[0]),comp);
	double last = -0.1;
	for(i=0;i<s;i++)
		if(frac[i].value != last)
		{
			fout << frac[i].numerator << '/' << frac[i].denominator << endl;
			last = frac[i].value;
		}
    return 0;
}
