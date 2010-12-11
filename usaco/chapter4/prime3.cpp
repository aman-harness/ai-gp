/*
ID: interne4
PROG: prime3
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("prime3.in");
ofstream fout("prime3.out");

int sum,first;
int matrix[5][5] = {0};
int le[5][5] = {0};
bool p[100000] = {0};
bool sp[100000] = {0};
int pa[100000] = {0},paN;
int fs[100000] = {0},fsN;
bool none = 1;
void print();

void search(int lv)
{
	int s = sum;
	int i,j,k,l,m;
	int is,js,ks;
	int in,jn,kn,n;
	if(lv == 4)
	{
		//print();
		for(i = 0; i < 5; i ++)
		{
			matrix[4][i] = sum;
			for(j = 0; j < 4; j ++)
			{
				matrix[4][i] -= matrix[j][i];
			}
			if(matrix[4][i] < 0 || matrix[4][i] > 9)
				return;
			if(!sp[matrix[0][i]*10000 + matrix[1][i]*1000 + matrix[2][i]*100 + matrix[3][i]*10 + matrix[4][i]])
				return;
		}
		if(!sp[matrix[4][0]*10000 + matrix[4][1]*1000 + matrix[4][2]*100 + matrix[4][3]*10 + matrix[4][4]])
			return;
		if(!sp[matrix[0][0]*10000 + matrix[1][1]*1000 + matrix[2][2]*100 + matrix[3][3]*10 + matrix[4][4]])
			return;
		if(!sp[matrix[4][0]*10000 + matrix[3][1]*1000 + matrix[2][2]*100 + matrix[1][3]*10 + matrix[0][4]])
			return;
		print();
		none = 0;
		return;
	}
	if(lv == 0)
	{
		for(i = 0; i < fsN; i ++)
		{
			
			matrix[lv][0] = first;
			matrix[lv][1] = fs[i]/1000%10;
			matrix[lv][2] = fs[i]/100%10;
			matrix[lv][3] = fs[i]/10%10;
			matrix[lv][4] = fs[i]%10;
			search(lv + 1);
		}
		return;
	}
	for(i = 0; i < paN; i ++)
	{
		matrix[lv][0] = pa[i]/10000;
		matrix[lv][1] = pa[i]/1000%10;
		matrix[lv][2] = pa[i]/100%10;
		matrix[lv][3] = pa[i]/10%10;
		matrix[lv][4] = pa[i]%10;
		search(lv + 1);
	}
}

void init()
{
	int i,j;
	fsN = paN = 0;
	for(i = 2; i < 100000; i ++)
	{
		if(!p[i])
		{
			for(j = i*2; j < 100000; j += i)
				if(!p[j])
					p[j] = 1;
			if(i > 10000 && (i/10000 + i/1000%10 + i/100%10 + i/10%10 + i%10) == sum)
			{
				sp[i] = 1, pa[paN ++] = i;
				if(i/10000 == first && i/1000%10 != 0 && i/100%10 != 0 && i/10%10 != 0 && i%10 != 0)
					fs[fsN ++] = i;
			}
		}
	}
	fout << paN;
}

int main()
{
	fin >> sum >> first;
	init();
	search(0);
	if(none)
		fout << "NONE" << endl;
    return 0;
}

void print()
{
	int i,j;
	if(!none)
		fout << endl;
	for(i = 0; i < 5; i ++)
	{
		for(j = 0; j < 5; j ++)
			fout << matrix[i][j];
		fout << endl;
	}
}
