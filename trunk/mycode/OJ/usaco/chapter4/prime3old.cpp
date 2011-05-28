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
		int shu;
		for(i = 0; i < 5; i ++)
		{
			matrix[4][i] = le[3][i];
			if(matrix[4][i] < 0 || matrix[4][i] > 9)
				return;
		}
		/*for(i = 0; i < 5; i ++)
		{
			matrix[4][i] = sum;
			for(j = 0; j < 4; j ++)
			{
				matrix[4][i] -= matrix[j][i];
			}
			if(matrix[4][i] < 0 || matrix[4][i] > 9)
				return;
		}*/
		shu = 0;
		s = 0;
		for(i = 0; i < 5; i ++)
		{
			shu += matrix[4][i];
			s += matrix[4][i];
			shu *= 10;
		}
		shu /= 10;
		if(p[shu] || s != sum)
			return;
		bool t = 1;
		for(i = 0; i < 5; i ++)
		{
			s = 0;
			shu = 0;
			for(j = 0; j < 5; j ++)
			{
				shu += matrix[j][i];
				s += matrix[j][i];
				shu *= 10;
			}
			shu /= 10;
			if(p[shu] || s != sum)
			{
				t = 0;
				break;
			}
		}
		
		if(t)
		{
			shu = 0;
			s = 0;
			for(i = 0; i < 5; i ++)
			{
				shu += matrix[i][i];
				s += matrix[i][i];
				shu *= 10;
			}
			shu /= 10;
			if(!p[shu] && s == sum)
			{
				shu = 0;
				s = 0;
				for(i = 0; i < 5; i ++)
				{
					shu += matrix[4-i][i];
					s += matrix[4-i][i];
					shu *= 10;
				}
				shu /= 10;
				if(!p[shu] && s == sum)
				{
					print();
					none = 0;
				}
			}
		}
		return;
	}
	if(lv == 0)
	{
		is = s - first;
		in = first * 10000;
		matrix[lv][0] = first;
		le[0][0] = s - first;
		for(j = 1; j < 10 && j < is; j ++)
		{
			js = is - j;
			jn = j * 1000 + in;
			matrix[lv][1] = j;
			le[0][1] = s - j;
			for(k = 1; k < 10 && k < js; k ++)
			{
				ks = js - k;
				kn = k * 100 + jn;
				matrix[lv][2] = k;
				le[0][2] = s - k;
				for(l = 1; l < 10 && l < ks; l ++)
				{
					m = ks - l;
					if(m % 2 == 0 || m == 5 || m > 9)
						continue;
					n = m + l * 10 + kn;
					if(!p[n])
					{
						le[0][3] = s - l;
						matrix[lv][3] = l;
						le[0][4] = s - m;
						matrix[lv][4] = m;
						search(lv + 1);
					}
				}
			}
		}
		return;
	}
	for(i = 1; i < 10 && i < s; i ++)
	{
		le[lv][0] = le[lv - 1][0] - i;
		if(le[lv][0] < 1)
			continue;
		is = s - i;
		in = i * 10000;
		matrix[lv][0] = i;
		for(j = 0; j < 10 && j < is; j ++)
		{
			le[lv][1] = le[lv - 1][1] - j;
			if(le[lv][1] < 1)
				continue;
			js = is - j;
			jn = j * 1000 + in;
			matrix[lv][1] = j;
			for(k = 0; k < 10 && k < js; k ++)
			{
				le[lv][2] = le[lv - 1][2] - k;
				if(le[lv][2] < 1)
					continue;
				ks = js - k;
				kn = k * 100 + jn;
				matrix[lv][2] = k;
				for(l = 0; l < 10 && l < ks; l ++)
				{
					m = ks - l;
					if(m % 2 == 0 || m == 5 || m > 9)
						continue;
					le[lv][3] = le[lv - 1][3] - l;
					if(le[lv][3] < 1)
						continue;
					le[lv][4] = le[lv - 1][4] - m;
					if(le[lv][4] < 1)
						continue;
					n = m + l * 10 + kn;
					if(!p[n])
					{
						matrix[lv][3] = l;
						matrix[lv][4] = m;
						search(lv + 1);
					}
				}
			}
		}
	}
}

void init()
{
	int i,j;
	paN = 0;
	for(i = 2; i < 100000; i ++)
	{
		if(!p[i])
		{
			for(j = i*2; j < 100000; j += i)
				if(!p[j])
					p[j] = 1;
			if(i > 10000 && (i/10000 + i/1000%10 + i/100%10 + i/10%10 + i%10) == sum)
				sp[i] = 1, pa[paN ++] = i;
		}
	}
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
