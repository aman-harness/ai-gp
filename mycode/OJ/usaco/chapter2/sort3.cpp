/*
ID: interne4
PROG: sort3
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("sort3.in");
ofstream fout("sort3.out");

int map[10000],n,a,b,c;

void exchange(int& a,int& b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

int main()
{
	int i,j,t,s=0;
	fin >> n;
	a = b = c = 0;
	for(i=0;i<n;i++)
		fin >> map[i];
	for(i=0;i<n;i++)
	{
		if(map[i] == 1)
			a++;
		else if(map[i] == 2)
			b++;
		else if(map[i] == 3)
			c++;
	}
	
	
	for(i=0;i<a;i++)
	{
		if(map[i] == 2)
		{
			for(j=a;j<n;j++)
			if(map[j] == 1)
			{
				exchange(map[i],map[j]);
				s++;
				break;
			}
		}
		else if(map[i] == 3)
		{
			t = 0;
			for(j=a+b;j<n;j++)
			if(map[j] == 1)
			{
				exchange(map[i],map[j]);
				s++;
				t = 1;
				break;
			}
			if(t==0)
			for(j=a;j<a+b;j++)
			if(map[j] == 1)
			{
				exchange(map[i],map[j]);
				s++;
				break;
			}
		}
	}
	
	//1
	for(i=a;i<a+b;i++)
	{
		if(map[i] == 3)
		{
			t = 0;
			for(j=a+b;j<n;j++)
			if(map[j] == 2)
			{
				exchange(map[i],map[j]);
				s++;
				t = 1;
				break;
			}
			if(t==0)
			for(j=0;j<a;j++)
			if(map[j] == 2)
			{
				exchange(map[i],map[j]);
				s++;
				break;
			}
		}
	}
	fout << s << endl;
    return 0;
}
