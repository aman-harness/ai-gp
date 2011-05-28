/*
ID: interne4
PROG: clocks
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("clocks.in");
ofstream fout("clocks.out");

bool state[1000000]={0};
int table[1000000]={0},last[1000000]={0},way[1000000]={0},open,closed;
const bool change[9][10]={{1,1,0,1,1,0,0,0,0,0},{1,1,1,0,0,0,0,0,0,0},{0,1,1,0,1,1,0,0,0,0},{1,0,0,1,0,0,1,0,0,0},{0,1,0,1,1,1,0,1,0,0},{0,0,1,0,0,1,0,0,1,0},{0,0,0,1,1,0,1,1,0,0},{0,0,0,0,0,0,1,1,1,0},{0,0,0,0,1,1,0,1,1,0}};
int ans = 0;

inline int setClock(int num,int way)
{
	/*
	int s,j,x;
	x = 0;
	s = 1;
	for(j=0;j<9;j++)
	{
		x += (num%4 + change[way][j])%4 * s;
		num/=4;
		s*=4;
	}
	return x;*/
	int s,j,x[10]={0};
	j = 0;
	while(num>0)
	{
		x[j] = num%4;
		num/=4;
		j++;
	}
	s = 1;
	num = 0;
	for(j=0;j<9;j++)
	{
		x[j] = (x[j] + change[way][j])%4;
		//fout << x[j] << ' ';
		num += x[j] * s;
		s*=4;
	}
	//fout << endl;
	return num;
}

void expand(int init)
{
	int now,x;
	int i,j;
	open = 0;
	closed = 0;
	table[closed] = init;
	do
	{
		now = table[closed];
		//fout << now << ' ' << closed << ' ' << last[closed] << ' ' << way[closed] << endl;
		
		if(now == 262143)
		{
			ans = closed;
			return;
		}
		for(i=0;i<9;i++)
		{
			x = setClock(now,i);
			if(!state[x])
			{
				table[++open] = x;
				state[x] = 1;
				last[open] = closed;
				way[open] = i;
			}
		}
			
		closed++;
	}while(open >= closed);
	
}

int main()
{
	int i,j,outArray[100]={0},outN = 0,x[10];
	for(i=0;i<9;i++)
		fin >> x[i];
	int num=0,s=1;
	for(i=0;i<9;i++)
	{
		num += (x[i]/3-1) * s;
		s *= 4;
	}
	expand(num);
	int ie;
	outN = 0;
	ie = ans;
	while(ie != 0)
	{
		outArray[outN++] = way[ie]+1;
		ie = last[ie];
	}
	for(i=outN-1;i>0;i--)
		fout << outArray[i] << ' ';
	fout << outArray[0] << endl;
	
	return 0;
}
/*
1 4 16 64 256 1024 4096 16384 65536

2 2 3 1 1 1 1 0 1
3 3 3 2 2 1 1 0 1

bfs算法注意边界判定
类型名检察，注意分号
*/
