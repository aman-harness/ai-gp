/*
ID: interne4
PROG: subset
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("subset.in");
ofstream fout("subset.out");

const unsigned int MAX_SUM = 1024;
int n;
unsigned int dyn[MAX_SUM];

int main() {
    fin >> n;
    fin.close();
    int s = n*(n+1);
    if (s % 4) {
        fout << 0 << endl;
        fout.close ();
        return 0;
    }
    s /= 4;
    int i, j;
    dyn [0] = 1;
    for (i = 1; i <= n; i++)
        for (j = s; j >= i; j--) 
            dyn[j] += dyn[j-i];
    //for(i=1;i<=s;i++)
    //	fout << dyn[i] << endl;
    fout << (dyn[s]/2) << endl;
    fout.close();
    return 0;
}

/*
search
int n=0,s=0,ans=0;
void expand(int i,int x)
{
	i++;
	do
	{
		i--;
		if(i==0)
			return;
		if(x+i < s)
		{
			//fout << i << ' '  << x+i << endl;
			expand(i-1,x+i);
			continue;
		}
		else if(x+i == s)
			ans ++;
	}while(1);
}

int main()
{
	int i,j;
	fin >> n;
	s = n*(n+1)/4;
	if(n*(n+1)/2%2 != 0)
	{
		fout << 0 << endl;
		return 0;
	}
	if(n == 3)
	{
		fout << 1 << endl;
		return 0;
	}
	expand(n-1,n);
	fout << ans << endl;
    return 0;
}
*/


