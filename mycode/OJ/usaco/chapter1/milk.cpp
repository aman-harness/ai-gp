/*
ID: interne4
PROG: milk
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("milk.in");
ofstream fout("milk.out");

struct Milk
{
	int price;
	int quality;
}milk[5001];

int n,s;
typedef int (*compfn)(const void*, const void*);

int comp(const Milk* q, const Milk* p)
{
	return (q->price - p->price);
}

int main()
{
	int i,j,k,l,v;
	int s;
	fin >> s >> n;
	for(i=0;i<n;i++)
		fin >> milk[i].price >> milk[i].quality;
	qsort(milk,n,sizeof(Milk),(compfn)comp);
	
	/*for(i=0;i<n;i++)
		fout << milk[i].price << ' ' << milk[i].quality << endl;*/
	v = 0;
	for(i=0;;i++)
	{
		if(milk[i].quality < s)
		{
			s -= milk[i].quality;
			v += milk[i].price * milk[i].quality;
		}
		else
		{
			v += milk[i].price * s;
			break;
		}
	}
	fout << v <<endl;
    return 0;
}
