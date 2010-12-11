/*
ID: interne4
PROG: milk3
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("milk3.in");
ofstream fout("milk3.out");
int ma,mb,mc;
bool gone[100][100][100]={0},ans[100]={0};

void search(int a,int b,int c)
{
	if(gone[a][b][c])return;
	gone[a][b][c] = 1;
	if(a == 0 && !ans[c])
	ans[c] = 1;
	if(c<mc)
	{
		if(b-(mc-c)>0) search(a,b-(mc-c),mc);
		else search(a,0,c+b);
		if(a-(mc-c)>0) search(a-(mc-c),b,mc);
		else search(0,b,c+a);
	}
	if(b<mb)
	{
		if(c-(mb-b)>0) search(a,mb,c-(mb-b));
		else search(a,c+b,0);
		if(a-(mb-b)>0) search(a-(mb-b),mb,c);
		else search(0,a+b,c);
	}
	if(a<ma)
	{
		if(b-(ma-a)>0) search(ma,b-(ma-a),c);
		else search(a+b,0,c);
		if(c-(ma-a)>0) search(ma,b,c-(ma-a));
		else search(a+c,b,0);
	}
}

int main()
{
	int i,j;
	fin >> ma >> mb >> mc;
	search(0,0,mc);
	for(i=0;i<mc;i++)
		if(ans[i])
			fout << i << ' ';
	if(ans[i])fout << i << endl;
    return 0;
}
