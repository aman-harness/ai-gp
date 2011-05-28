/*
ID: interne4
PROG: beads
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream fin("beads.in");
ofstream fout("beads.out");

string str;

char getchar(int x)
{
	return str[abs(int(x % str.length()))];
}

int main()
{
	int n,q,f,l,maxs;
	char ch;
	int i,j,sta;
	fin >> n >> str;
	bool t= false;
	i=0;
	while((ch = getchar(i))=='w' && i<n)i++;
	for(;i<n;i++)
		if(ch != getchar(i) && getchar(i)!='w')
		{
			t = true;
			sta = i;
			break;
		}
    //fout<<sta<<endl;
	if(!t)
	{
		fout<<n<<endl;
		return 0;
	}
	q=sta;
	ch = getchar(sta);
	f=l=-1;maxs = 0;
	for(i=sta+1;i<sta+n+1;i++)
		if(ch != getchar(i) && getchar(i)!='w')
		{
		    if(f == -1)
		    {
			    f = i - q;
				ch = getchar(i);
		    }
		    else
		    {
				while(getchar(q-1)=='w')
				{
					q--;
					f--;
				}
			    l = f;
			    f = i - q;
				ch = getchar(i);
			    if(l+f > maxs)
			        maxs = l+f;
		    }
		    //fout << i << endl;
		    //fout << q << endl;
		    q = i;
		}
	fout << maxs << endl;
    return 0;
}
