/*
ID: interne4
PROG: pprime
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("pprime.in");
ofstream fout("pprime.out");

int p[100000]={0},n=0,ans[100000]={0},ansN=0;

int a,b;

void init()
{
	int i,j,x;
	bool t;
	for(i=2;i<=100000;i++)
	{
		x = sqrt(i);
		t = 1;
		for(j=2;j<=x;j++)
		if(i%j==0)
		{
			t=0;
			break;
		}
		if(t)
			p[n++] = i;
	}
}

void work(int num)
{
	int i,j,x;
	bool t;
	if(num > b || num < a)
		return;
	x = sqrt(num);
	t = 1;
	for(j=0;p[j]<=x;j++)
	if(num%p[j]==0)
	{
		t=0;
		break;
	}
	if(t)
		ans[ansN++] = num;
}

int comp(const void* q, const void* p)
{
	return *(int *)q - *(int *)p;
}

int main()
{
	int i,j,palindrome,d1,d2,d3,d4,d5;
	fin >> a >> b;
	init();
	for (d1 = 1; d1 <= 9; d1+=2) 	/* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++)
    for (d3 = 0; d3 <= 9; d3++)
   	for (d4 = 0; d4 <= 9; d4++) 
    for (d5 = 0; d5 <= 9; d5++)
    {
	    palindrome = 100000000*d1 + 10000000*d2 + 1000000*d3 +100000*d4 + 10000*d5  + 1000*d4 + 100*d3 + 10*d2 + d1;
		work(palindrome);
			
	}
	for (d1 = 1; d1 <= 9; d1+=2) 	/* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++)
    for (d3 = 0; d3 <= 9; d3++)
   	for (d4 = 0; d4 <= 9; d4++)
    {
	    palindrome = 1000000*d1 + 100000*d2 + 10000*d3 +1000*d4 + 100*d3 + 10*d2 + d1;
		work(palindrome);
		palindrome = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1;
		work(palindrome);
	}
	for (d1 = 1; d1 <= 9; d1+=2) 	/* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++)
    for (d3 = 0; d3 <= 9; d3++)
    {
	    palindrome = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
	    work(palindrome);
		palindrome = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
		work(palindrome);
	}
	for (d1 = 1; d1 <= 9; d1+=2) 	/* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++)
    {
	    palindrome = 100*d1 + 10*d2 + d1;
	    work(palindrome);
		palindrome = 1000*d1 + 100*d2 + 10*d2 + d1;
		work(palindrome);
	}
	for (d1 = 1; d1 <= 9; d1+=2)
    {
	    palindrome = d1;
		work(palindrome);
	    palindrome = d1 + d1*10;
		work(palindrome);
	}
	qsort(ans,ansN,sizeof(ans[0]),comp);
	for(i=0;i<ansN;i++)
		fout << ans[i] << endl;
    return 0;
}
