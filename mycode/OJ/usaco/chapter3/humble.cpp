/*
ID: interne4
PROG: humble
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("humble.in");
ofstream fout("humble.out");
const unsigned int maxN = 100000,maxK = 100;

unsigned int n,k;
unsigned int q[maxN + maxK + 1] = {0};
unsigned int p[maxK] = {0};
unsigned int prime[maxK] = {0};

int main()
{
	int i,j;
	int minN,minK;
	q[0] = 1;
	fin >> k >> n;
	for(i=0;i<k;i++)
		fin >> prime[i];
    i = 0;
    while(i <= n)
    {
		minN = 2000000000;
		for(j=0;j<k;j++)
			if(prime[j]*q[p[j]] < minN)
			{
				minN = prime[j]*q[p[j]];
				minK = j;
			}
		p[minK]++;
		if(q[i] != minN)
		{
			q[++i] = minN;
			//fout << q[i] << ' ';
		}
    }
    fout << q[n]<< endl;
    return 0;
}
