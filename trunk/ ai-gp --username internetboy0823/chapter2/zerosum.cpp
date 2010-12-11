/*
ID: interne4
PROG: zerosum
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int n;
int oper[10]={0};

void print()
{
	int i;
	for(i=1;i<n;i++)
	{
		fout << i;
		if(oper[i] == 1)
			fout << ' ';
		else if(oper[i] == 2)
			fout << '+';
		else if(oper[i] == 3)
			fout << '-';
	}
	fout << n << endl;
}

int calc()
{
	int s,x,i;
	bool isPast;
	s =	x = 0;
	isPast = 1;
	for(i=1;i<n;i++)
	{
		x *= 10;
		x += i;
		
		if(oper[i] != 1)
		{
			if(isPast)
				s += x;
			else
				s -= x;
		}
		if(oper[i] == 2)
		{
			x = 0;
			isPast = 1;
		}
		else if(oper[i] == 3)
		{
			x = 0;
			isPast = 0;
		}
	}
	x *= 10;
	x += i;
	
	if(isPast)
		s += x;
	else
		s -= x;
	return s;
}

void search(int x)
{
	if(x == n)
	{
		if(calc() == 0)
			print();
		return;
	}
	oper[x] = 1;
	search(x+1);
	oper[x] = 2;
	search(x+1);
	oper[x] = 3;
	search(x+1);
}

int main()
{
	fin >> n;
	search(1);
    return 0;
}
