/*
ID: interne4
PROG: runround
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");
int n,m;
int x[10]={0},a[10]={0},bt[10]={0};
bool isT[10]={0};

int main()
{
	int i,j;
	bool t;
	fin >> n;
	i=0;
	while(n)
	{
		x[i++] = n%10;
		n /= 10;
	}
	m = i;
	/*
	for(i=m-1;i>=0;i--)
		fout << x[i];
	*/
	while(1)
	{
		i=0;
		x[i]++;
		memset(isT,0,sizeof(isT));
		
		while(x[i]>9)
		{
			x[i] = 1;
			x[++i] ++;
			if(i >= m)
				m = i + 1;
		}
		t=1;
		for(i=0;i<m;i++)
			if(isT[x[i]])
			{
				t=0;
				break;
			}
			else isT[x[i]] = 1;
		if(!t)
			continue;
		
		
		for(i=m-1;i>=0;i--)
			bt[m-i-1] = x[i];
			
			
		j = i = 0;
		t = 1;
		
		
		memset(isT,0,sizeof(isT));
		isT[i]=1;
			//break;
		while(j < m-1)
		{
			i = (i + bt[i]) % m;
			if(isT[i])
			{
				t = 0;
				break;
			}	
			//fout << i << endl;
			isT[i] = 1;
			j++;
		}
		if(t && (i + bt[i]) % m == 0)
		{
			
			for(i=0;i<m;i++)
				fout << bt[i];
			fout << endl;
			break;
		}
	}
    return 0;
}
/*inove 12345
		12354
		12435
		
		12543
		13245

*/
