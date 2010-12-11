/*
ID: interne4
PROG: lamps
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int n,c,light[101]={0},ansN=0;
string ans[1000];

bool pd1()
{
	int i;
	for(i=1;i<=n;i++)
		if(light[i] == -1)
			return false;
	return true;
}

void cl1()
{
	int i;
	if(pd1())
	{
		stringstream a;
		for(i=1;i<=n;i++)
			a << 1;
		a >> ans[ansN++];
	}
}

bool pd2()
{
	int i;
	for(i=1;i<=n;i++)
		if(i%2)
		{
			if(light[i] == -1)
				return false;
		}
		else
		{
			if(light[i] == 1)
				return false;
		}
	return true;
}

void cl2()
{
	int i;
	if(pd2())
	{
		stringstream a;
		for(i=1;i<=n;i++)
			if(i%2)
			a << 1;
			else
			a << 0;
		a >> ans[ansN++];
	}
}

bool pd3()
{
	int i;
	for(i=1;i<=n;i++)
		if(i%2)
		{
			if(light[i] == 1)
				return false;
		}
		else
		{
			if(light[i] == -1)
				return false;
		}
	return true;
}

void cl3()
{
	int i;
	if(pd3())
	{
		stringstream a;
		for(i=1;i<=n;i++)
			if(i%2)
			a << 0;
			else
			a << 1;
		a >> ans[ansN++];
	}
}

bool pd4()
{
	int i;
	for(i=1;i<=n;i++)
		if(light[i] == 1)
			return false;
	return true;
}

void cl4()
{
	int i;
	if(pd4())
	{
		stringstream a;
		for(i=1;i<=n;i++)
			a << 0;
		a >> ans[ansN++];
	}
}

bool pd5(int k)
{
	int i;
	for(i=1;i<=n;i++)
		if(i%k==1)
		{
			if(light[i] == 1)
				return false;
		}
		else
		{
			if(light[i] == -1)
				return false;
		}
	return true;
}

void cl5(int k)
{
	int i;
	if(pd5(k))
	{
		stringstream a;
		for(i=1;i<=n;i++)
			if(i%k==1)
			a << 0;
			else
			a << 1;
		a >> ans[ansN++];
	}
}

bool pd6(int k)
{
	int i;
	for(i=1;i<=n;i++)
		if(i%2)
		{
			if(i%k==1)
			{
				if(light[i] == 1)
					return false;
			}
			else
			{
				if(light[i] == -1)
					return false;
			}
		}
		else
		{
			if(i%k==1)
			{
				if(light[i] == -1)
					return false;
			}
			else
			{
				if(light[i] == 1)
					return false;
			}
		}
	return true;
}

void cl6(int k)
{
	int i;
	if(pd6(k))
	{
		stringstream a;
		for(i=1;i<=n;i++)
			if(i%2)
			{
				if(i%k==1)
					a << 0;
				else
					a << 1;
			}
			else
			{
				if(i%k==1)
					a << 1;
				else
					a << 0;
			}
		a >> ans[ansN++];
	}
}

bool pd7(int k)
{
	int i;
	for(i=1;i<=n;i++)
		if(i%2)
		{
			if(i%k==1)
			{
				if(light[i] == -1)
					return false;
			}
			else
			{
				if(light[i] == 1)
					return false;
			}
		}
		else
		{
			if(i%k==1)
			{
				if(light[i] == 1)
					return false;
			}
			else
			{
				if(light[i] == -1)
					return false;
			}
		}
	return true;
}

void cl7(int k)
{
	int i;
	if(pd7(k))
	{
		stringstream a;
		for(i=1;i<=n;i++)
			if(i%2)
			{
				if(i%k==1)
					a << 1;
				else
					a << 0;
			}
			else
			{
				if(i%k==1)
					a << 0;
				else
					a << 1;
			}
		a >> ans[ansN++];
	}
}

bool pd8(int k)
{
	int i;
	for(i=1;i<=n;i++)
		if(i%k==1)
		{
			if(light[i] == -1)
				return false;
		}
		else
		{
			if(light[i] == 1)
				return false;
		}
	return true;
}

void cl8(int k)
{
	int i;
	if(pd8(k))
	{
		stringstream a;
		for(i=1;i<=n;i++)
			if(i%k==1)
			a << 1;
			else
			a << 0;
		a >> ans[ansN++];
	}
}

int main()
{
	int i,j,x,k;
	fin >> n >> c;
	fin >> x;
	while(x != -1)
	{
		light[x] = 1;
		fin >> x;
	}
	fin >> x;
	while(x != -1)
	{
		light[x] = -1;
		fin >> x;
	}
	
	if(c == 0)
	{
		cl1();
	}
	else if(c == 1)
	{
		cl2();
		cl3();
		cl4();
		cl5(3);
	}
	else if(c == 2)
	{
		cl1();
		cl4();
		cl3();
		cl2();
		cl6(3);
		cl7(3);
		cl8(3);
	}
	else if(c >= 3)
	{
		cl2();
		cl3();
		cl4();
		cl5(3);
		cl1();
		cl8(3);
		cl6(3);
		cl7(3);
	}
	if(ansN == 0)
	{
		fout << "IMPOSSIBLE" << endl;
		return 0;
	}
	stable_sort(&ans[0],&ans[ansN]);
	for(i=0;i<ansN-1;i++)
		if(ans[i] != ans[i+1])
			fout << ans[i] << endl;
	fout << ans[ansN-1] << endl;
    return 0;
}
