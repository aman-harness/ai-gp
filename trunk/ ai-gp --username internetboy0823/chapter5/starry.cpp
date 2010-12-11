/*
ID: interne4
PROG: starry
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("starry.in");
ofstream fout("starry.out");

const int maxN = 100 + 1;
const int maxC = 26;

int n,m;

struct point
{
	int x,y;
};
point dir[8];

struct cluster
{
	bool map[maxN][maxN];
	int w,h;
	int s;
}c[maxC];
int cN = 0;

bool lmap[maxN][maxN] = {0};

bool map[maxN][maxN];
char cmap[maxN][maxN];
bool vis[maxN][maxN] = {0};

int t,b,l,r;						/*top,bottom,left,right*/
int s;
void search(int x, int y)
{
	int i,j;
	int nx,ny;
	vis[x][y] = 1;
	lmap[x][y] = 1;
	
	if(y < l)
		l = y;
	if(y > r)
		r = y;
	if(x < t)
		t = x;
	if(x > b)
		b = x;
	
	s ++;
	for(i = 0 ; i < 8 ;i ++)
	{
		nx = x + dir[i].x;
		ny = y + dir[i].y;
		if(map[nx][ny] && !vis[nx][ny])
			search(nx,ny);
	}
	
}

void init();

int main()
{
	int i,j,k;
	int lv1,lv2;
	int w,h;
		
	init();
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(map[i][j] && !vis[i][j])
			{
				t = n;
				r = b = 0;
				l = m;
				s = 0;
				memset(lmap,0,sizeof(lmap));
				search(i,j);
				w = r - l + 1;
				h = b - t + 1;
				//fout << w << ' ' << h << endl;
				bool temp;
				temp = 0;
				for(k=0;k<cN;k++)
				{
					if(s == c[k].s)
					{
						if(w == c[k].w && h == c[k].h)
						{
							temp = 1;
							for(lv1 = 1;lv1 <= h; lv1 ++)
								for(lv2 = 1;lv2 <= w; lv2 ++)
									if(c[k].map[lv1][lv2] && !map[t + lv1 - 1][l + lv2 - 1])
									{
										temp = 0;
										break;
									}
							if(temp)
								break;
							temp = 1;
							for(lv1 = 1;lv1 <= h; lv1 ++)
								for(lv2 = 1;lv2 <= w; lv2 ++)
									if(c[k].map[lv1][w - lv2 +1] && !map[t + lv1 - 1][l + lv2 - 1])
									{
										temp = 0;
										break;
									}
							if(temp)
								break;
							temp = 1;
							for(lv1 = 1;lv1 <= h; lv1 ++)
								for(lv2 = 1;lv2 <= w; lv2 ++)
									if(c[k].map[h - lv1 + 1][w - lv2 +1] && !map[t + lv1 - 1][l + lv2 - 1])
									{
										temp = 0;
										break;
									}
							if(temp)
								break;
							temp = 1;
							for(lv1 = 1;lv1 <= h; lv1 ++)
								for(lv2 = 1;lv2 <= w; lv2 ++)
									if(c[k].map[h - lv1 + 1][lv2] && !map[t + lv1 - 1][l + lv2 - 1])
									{
										temp = 0;
										break;
									}
							if(temp)
								break;
						}
						if(h == c[k].w && w == c[k].h)
						{
							temp = 1;
							for(lv1 = 1;lv1 <= h; lv1 ++)
								for(lv2 = 1;lv2 <= w; lv2 ++)
									if(c[k].map[lv2][lv1] && !map[t + lv1 - 1][l + lv2 - 1])
									{
										temp = 0;
										break;
									}
							if(temp)
								break;
								
							temp = 1;
							for(lv1 = 1;lv1 <= h; lv1 ++)
								for(lv2 = 1;lv2 <= w; lv2 ++)
									if(c[k].map[lv2][h - lv1 + 1] && !map[t + lv1 - 1][l + lv2 - 1])
									{
										temp = 0;
										break;
									}
							if(temp)
								break;
								
							temp = 1;
							for(lv1 = 1;lv1 <= h; lv1 ++)
								for(lv2 = 1;lv2 <= w; lv2 ++)
									if(c[k].map[w - lv2 + 1][h - lv1 + 1] && !map[t + lv1 - 1][l + lv2 - 1])
									{
										temp = 0;
										break;
									}
							if(temp)
								break;
								
							temp = 1;
							for(lv1 = 1;lv1 <= h; lv1 ++)
								for(lv2 = 1;lv2 <= w; lv2 ++)
									if(c[k].map[w - lv2 + 1][lv1] && !map[t + lv1 - 1][l + lv2 - 1])
									{
										temp = 0;
										break;
									}
							if(temp)
								break;
						}
					}
					temp = 0; 
				}
				char cc;
				if(!temp)
				{
					c[cN].s = s;
					c[cN].w = w;
					c[cN].h = h;
					for(lv1 = 1;lv1 <= h; lv1 ++)
						for(lv2 = 1;lv2 <= w; lv2 ++)
							c[cN].map[lv1][lv2] = lmap[t + lv1 - 1][l + lv2 - 1];
					cc = cN + 'a';
					cN ++;
				}
				else
					cc = k + 'a';
				for(lv1 = 1;lv1 <= h; lv1 ++)
					for(lv2 = 1;lv2 <= w; lv2 ++)
						if(lmap[t + lv1 - 1][l + lv2 - 1])
							cmap[t + lv1 - 1][l + lv2 - 1] = cc;
			}
			else if(!vis[i][j])
				cmap[i][j] = '0';
		}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			fout << cmap[i][j];
		fout << endl;
	}
    return 0;
}

void init()
{
	int i,j;
		
	dir[0].x = 1;
	dir[0].y = 0;
	dir[1].x = 1;
	dir[1].y = 1;
	dir[2].x = 0;
	dir[2].y = 1;
	dir[3].x = -1;
	dir[3].y = 1;
	dir[4].x = -1;
	dir[4].y = 0;
	dir[5].x = -1;
	dir[5].y = -1;
	dir[6].x = 0;
	dir[6].y = -1;
	dir[7].x = 1;
	dir[7].y = -1;
		
	fin >> m >> n;
	char c;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			fin >> c;
			if(c == '0')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
				
}
