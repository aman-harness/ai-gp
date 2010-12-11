/*
ID: interne4
PROG: transform
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("transform.in");
ofstream fout("transform.out");
int n;
class rect
{
	bool ele[10][10];
	int size;
public:
	rect()
	{
		size = 0;
	}
	void setSize(int x)
	{
		size = x;
	}
	
	int getSize()
	{
		return size;
	}
	
	void whirl(int k)
	{
		int i,j;
		rect x;
		x.size = size;
		while(k>0)
		{
			for(i=0;i<size;i++)
			for(j=0;j<size;j++)
			{
				x.ele[j][size-i-1] = ele[i][j];
			}
			k--;
		}
		*this = x;
	}
	
	void flipHorizontal()
	{
		int i,j;
		rect x;
		x.size = size;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
			{
				x.ele[i][size-j-1]=ele[i][j];
			}
		*this = x;
	}
	
	bool operator == (rect& th)
	{
		int i,j;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
			{
				if(ele[i][j] != th.ele[i][j])
					return false;
			}
		return true;
	}
	rect& operator = (rect& th)
	{
		int i,j;
		size = th.size;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				ele[i][j] = th.ele[i][j];
		return *this;
	}
	
	friend istream& operator >> (istream& input,rect& th)
	{
		int i,j;
		char ch;
		if(th.size == 0)
			input >> th.size;
		for(i=0;i<th.size;i++)
			for(j=0;j<th.size;j++)
			{
				input >> ch;
				if(ch == '@') th.ele[i][j] = 1;
				else th.ele[i][j] = 0;
			}
		return input;
	}
	
	friend ostream& operator << (ostream& output,rect& th)
	{
		int i,j;
		output << th.size <<endl;
		for(i=0;i<th.size;i++)
		{
			for(j=0;j<th.size;j++)
			{
				output << th.ele[i][j];
			}
			output << endl;
		}
		return output;
	}
};

int main()
{
	rect a,b,c,d;
	int i,j;
	fin >> a;
	b.setSize(a.getSize());
	fin >> b;
	d = c = a;
	a.whirl(1);
	if(a==b)
	{
		fout << 1 << endl;
		return 0;
	}
	a.whirl(1);
	if(a==b)
	{
		fout << 2 << endl;
		return 0;
	}
	a.whirl(1);
	if(a==b)
	{
		fout << 3 << endl;
		return 0;
	}
	a = c;
	a.flipHorizontal();
	if(a==b)
	{
		fout << 4 << endl;
		return 0;
	}
	a.whirl(1);
	if(a==b)
	{
		fout << 5 << endl;
		return 0;
	}
	a.whirl(1);
	if(a==b)
	{
		fout << 5 << endl;
		return 0;
	}
	a.whirl(1);
	if(a==b)
	{
		fout << 5 << endl;
		return 0;
	}
	if(d==b)
	{
		fout << 6 << endl;
		return 0;
	}
	fout << 7 << endl;
    return 0;
}
//GREG
