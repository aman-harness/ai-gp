/*
ID: interne4
PROG: castle
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("castle.in");
ofstream fout("castle.out");
bool gone[100][100]={0};
int map[100][100]={0},pic[100][100]={0};
int n,m,s,maxSize,size[10001]={0};

//const int dirA[5][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};

int maxX,maxY,maxCutSize;
char maxDir;
int floodFill(int x,int y)
{
	int all=1;
	if(gone[x][y])
		return 0;
	pic[x][y] = s;
	gone[x][y] = 1;
	if(map[x][y]%2/1 == 0)
		all += floodFill(x,y-1);
	if(map[x][y]%4/2 == 0)
		all += floodFill(x-1,y);
	if(map[x][y]%8/4 == 0)
		all += floodFill(x,y+1);
	if(map[x][y]/8 == 0)
		all += floodFill(x+1,y);
	return all;
}

int main()
{
	int i,j,t;
	fin >> m >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			fin >> map[i][j];
	s=1;
	maxSize = 0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			size[s] = floodFill(i,j);
			if(size[s] > maxSize)
				maxSize = size[s];
			if(size[s] > 0)
				s++;
		}
	s--;
	maxCutSize = 0;
	
	for(j=1;j<=m;j++)
		for(i=n;i>=1;i--)
		{
			if(pic[i-1][j] != pic[i][j])
			{
				if(size[pic[i-1][j]] + size[pic[i][j]] > maxCutSize)
				{
					maxCutSize = size[pic[i-1][j]] + size[pic[i][j]];
					maxX = i;
					maxY = j;
					maxDir = 'N';
				}
			}
			if(pic[i][j+1] != pic[i][j])
			{
				if(size[pic[i][j+1]] + size[pic[i][j]] > maxCutSize)
				{
					maxCutSize = size[pic[i][j+1]] + size[pic[i][j]];
					maxX = i;
					maxY = j;
					maxDir = 'E';
				}
			}
		}
	/*
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			fout << pic[i][j] << ' ';
		fout << endl;
	}
	*/
	fout << s << endl;
	fout << maxSize << endl;
	fout << maxCutSize << endl;
	fout << maxX << ' ' << maxY << ' ' << maxDir << endl;
    return 0;
}

/*
写程序做题要有针对性，只要解决某一个问题就行了，注意题目细节。
这题由于最后的砍墙顺序WA了两次。

void floodFillSearch(int x,int y,int color,int dir)
{
	int all=1;
	if(color != pic[x][y])
	{
		if(dir != 2 || dir != 3)
		int newX,newY;
		newX = x + dirA[dir][0];
		newY = y + dirA[dir][1];
		if(size[color] + size[pic[x][y]] > maxCutSize)
		{
			maxCutSize = size[color] + size[pic[x][y]];
			maxX = newX;
			maxY = newY;
		}
		else if(size[color] + size[pic[x][y]] == maxCutSize)
		{
			if(newY < maxY || (newY == maxY && newX > maxX))
			{
				maxX = newX;
				maxY = newY;
			}
		}
		return;
	}
	if(gone[x][y])
		return;
	gone[x][y] = 1;
	floodFillSearch(x,y-1,color,1);
	floodFillSearch(x-1,y,color,2);
	floodFillSearch(x,y+1,color,3);
	floodFillSearch(x+1,y,color,4);
	return;
}*/
