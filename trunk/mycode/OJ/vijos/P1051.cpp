#include <fstream>
using namespace std;
ifstream fin("P1051.in");
ofstream fout("P1051.out");

int map[101][101] = {0};
int gone[101][101] = {0};
int s,n,m;
void expand(int x,int y)
{
    if(!gone[x][y])
    {
		gone[x][y]=1;
        expand(x+1,y+1);
        expand(x-1,y+1);
        expand(x+1,y-1);
        expand(x-1,y-1);
        expand(x,y+1);
        expand(x+1,y);
        expand(x,y-1);
        expand(x-1,y);
        expand(x+2,y);
        expand(x,y+2);
        expand(x-2,y);
        expand(x,y-2);
    }
}

int main()
{
    int i,j;
    char ch;
    fin>>n>>m;
    for(i=2;i<=n+1;i++)
    for(j=2;j<=m+1;j++)
    {
		fin >> ch;
		if(ch=='#')
			gone[i][j] = 0;
		else
			gone[i][j] = 1;
    }
    for(i=1;i<=n+2;i++)
    gone[i][0] =gone[i][1] = gone[i][m+2]  = gone[i][m+3] = 1;
    for(i=1;i<=m+2;i++)
    gone[0][i] = gone[1][i] = gone[n+2][i]  = gone[n+3][i] = 1;
    s=0;
    for(i=2;i<=n+1;i++)
    for(j=2;j<=m+1;j++)
    {
        if(!gone[i][j])
        {
            expand(i,j);
			/*
			for(int k=2;k<=n+1;k++)
			{
				for(int l=2; l<=m+1; l++)
				{
					fout<< gone[k][l];
				}
				fout<<endl;
			}*/
            s++;
        }
    }
    fout<<s;
    return 0;
}
            
     
