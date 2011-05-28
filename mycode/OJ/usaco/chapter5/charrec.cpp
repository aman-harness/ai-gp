/*
ID: interne4
PROG: charrec
LANG: C++
DATA: 2010.12.17
ALGO: Simulation
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("charrec.in");
ifstream fontin("font.in");
ofstream fout("charrec.out");
const int maxN = 1200 + 1;
const int fontW = 20;

class Font
{
public:
	char ch;
	bool bitmap[fontW][fontW];
};

Font f[27];
int fontNum = 0;
int n;
bool recmap[maxN][fontW] = {0};

void init()
{
	int i,j,k;
	char c;
	fontin >> n;
	fontNum = n / 20;
	for(i = 0; i < n / 20; i ++)
	{
		if(i == 0)
			f[i].ch = ' ';
		else
			f[i].ch = i + 'a' - 1;
		//fout << f[i].ch << endl;
		for(j = 0; j < fontW; j ++)
		{
			for(k = 0; k < fontW; k ++)
			{
				fontin >> c;
				f[i].bitmap[j][k] = c - '0';
				//fout << f[i].bitmap[j][k] << ' ';
			}
			//fout << endl;;
		}
	}
	
	fin >> n;
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < fontW; j ++)
		{
			fin >> c;
			recmap[i][j] = c - '0';
		}
	}
	
}

int skipl,ms;
char reco(bool map[][fontW])
{
	int i, j, k, l;
	int s = 0;
	ms = 280;
	char rec = '?';
	skipl = 20;
	
	for(l = 0; l < fontNum; l ++)
	{
		s = 0;
		for(j = 0; j < fontW; j ++)
			for(k = 0; k < fontW; k ++)
			{
				if(map[j][k] == f[l].bitmap[j - 1][k])
					s ++;
			}
		if(s > ms)
		{
			ms = s;
			rec = f[l].ch;
			skipl = 20;
		}
	}
		
	for(l = 0; l < fontNum; l ++)
		for(i = 0; i < fontW; i ++)
		{
			s = 20;
			for(j = 0; j < i; j ++)
				for(k = 0; k < fontW; k ++)
				{
					if(map[j][k] == f[l].bitmap[j][k])
						s ++;
				}
			for(j = i; j < fontW - 1; j ++)
				for(k = 0; k < fontW; k ++)
				{
					if(map[j][k] == f[l].bitmap[j + 1][k])
						s ++;
				}
			//s = int(double(400) / 380 * double(s));
			if(s > ms)
			{
				ms = s;
				rec = f[l].ch;
				skipl = 19;
			}
		}
	
	for(l = 0; l < fontNum; l ++)
		for(i = 0; i <= fontW; i ++)
		{
			s = 0;
			for(j = 0; j < i; j ++)
				for(k = 0; k < fontW; k ++)
				{
					if(map[j][k] == f[l].bitmap[j][k])
						s ++;
				}
			for(j = i + 1; j < fontW + 1; j ++)
				for(k = 0; k < fontW; k ++)
				{
					if(map[j][k] == f[l].bitmap[j - 1][k])
						s ++;
				}
			if(s > ms)
			{
				ms = s;
				rec = f[l].ch;
				skipl = 21;
			}
		}
	return rec;
}

int main()
{
	int i,j;
	bool map[fontW][fontW];
	
	init();
	
	i = 0;
	while(i + 18 <= n)
	{
		/*for(j = i + 0; j <= fontW + i; j ++)
		{
			for(k = 0; k < fontW; k ++)
			{
				map[j-i][k] = recmap[j][k];
			}
		}*/
		char co1,co2,co3;
		int m1,m2,skipl1,skipl2;
		
		co1 = reco(&recmap[i]);
		m1 = ms;
		skipl1 = skipl;
		
		/*
		co2 = reco(&recmap[i + 1]);
		m2 = ms;
		skipl2 = skipl + 1;
		
		if(m2 > m1)
		{
			co1 = co2;
			m1 = m2;
			skipl1 = skipl2;
		}
		
		co2 = reco(&recmap[i - 1]);
		m2 = ms;
		skipl2 = skipl - 1;
		
		if(m2 > m1)
		{
			co1 = co2;
			m1 = m2;
			skipl1 = skipl2;
		}*/
		
		fout << co1;
		fout << i << endl;
		i += skipl1;
	}
	fout << endl;
	
	return 0;
}
