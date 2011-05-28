/*
ID: interne4
PROG: msquare
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
ifstream fin("msquare.in");
ofstream fout("msquare.out");

class Record
{
public:
	int state;
	string way;

	Record()
	{
		state = 0;
		way = "";
	}
	
	Record(int x[],Record& r,char c = 0)
	{
		int s = 5040, o = 0 , b;
		bool zh[9]={0};
		int j;
		for(int i = 7; i > 0; i --)
		{
			b = 0;
			for(j = 0; j < x[i]; j ++)
				if(!zh[j])
					b++;
			zh[j] = 1;
			o += s * b;
			s /= i;
		}
		state = o;
		way = r.way;
		if(c)
			way += c;
	}
	
	void toArray(int a[])
	{
		int s = 1, o = state , b ,k[10]={0};
		bool zh[9]={0};
		int j;
		k[0] = 0;
		for(int i = 1; i < 8; i ++)
		{
			k[i] = o % (i+1);
			o /= (i+1);
		}
		for(int i = 7; i >= 0; i --)
		{
			b = 0;
			for(j = 0; b < k[i]; j ++)
				if(!zh[j])
					b++;
			while(zh[j])j++;
			zh[j] = 1;
			a[i] = j;
		}
	}
		
};

queue<Record> q;
bool state[10000000]={0};
string ans="";
int target;

void bfs()
{
	Record x;
	Record* newR;
	int a[8],n[8];
	do
	{
		x = q.front();
		q.pop();
		x.toArray(a);
		/*
		fout << endl << x.state << endl;
		fout << x.way << endl;
		for(int i=0;i<8;i++)
			fout << (a[i] + 1) << ' ';
		fout << endl;*/
		if(x.state == target)
		{
			ans = x.way;
			return;
		}
		
		n[0] = a[7];n[1] = a[6];n[2] = a[5];n[3] = a[4];
		n[7] = a[0];n[6] = a[1];n[5] = a[2];n[4] = a[3];
		newR = new Record(n,x,'A');
		if(!state[newR->state])
		{
			state[newR->state] = 1;
			q.push(*newR);
		}
		else delete newR;
		
		n[0] = a[3];n[1] = a[0];n[2] = a[1];n[3] = a[2];
		n[7] = a[4];n[6] = a[7];n[5] = a[6];n[4] = a[5];
		newR = new Record(n,x,'B');
		if(!state[newR->state])
		{
			state[newR->state] = 1;
			q.push(*newR);
		}
		else delete newR;
		
		n[0] = a[0];n[1] = a[6];n[2] = a[1];n[3] = a[3];
		n[7] = a[7];n[6] = a[5];n[5] = a[2];n[4] = a[4];
		newR = new Record(n,x,'C');
		if(!state[newR->state])
		{
			state[newR->state] = 1;
			q.push(*newR);
		}
		else delete newR;
	}while(!q.empty());
}

int main()
{
	int x[8],i,b[8]={0,1,2,3,4,5,6,7};
	for(i = 0; i < 8; i++)
	{
		fin >> x[i];
		x[i] --;
	}
	Record n;
	Record r(b,n),tar(x,n);
	target = tar.state;
	state[r.state] = 1;
	q.push(r);
	bfs();
	fout << ans.size() << endl;
	for(i = 0; i < ans.size();i++)
	{
		fout << ans[i];
		if((i+1)%60 == 0) fout << endl;
	}
	fout << endl;
    return 0;
}
