/*
ID: interne4
PROG: bigbrn
LANG: C++
DATA: 2010.12.14
ALGO: Dymatic Program
PROV: 
*/
#include <fstream>
using namespace std;
ifstream cin("bigbrn.in");
ofstream cout("bigbrn.out");

const int maxN = 1000 + 1;
int map[maxN][maxN] = {0};
int f[maxN][maxN] = {0};
int n,t;

int main()
{
    int a,b,i,j;
    cin >> n >> t;
    for(i=1;i<= t; i ++)
    {
        cin >> a >> b;
        map[a][b] = 1; 
    }
    
    int maxX = 0;
    for(i = 1; i <= n; i ++)
    for(j = 1; j <= n; j ++)
    {
         if (!map[i][j])
             f[i][j] = min(min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
         if(f[i][j] > maxX)
             maxX = f[i][j];
    }  
    cout << maxX << endl;
    return 0; 
}


