#include <fstream>
#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream fin("dataB.in");
ofstream fout("dataB.out");
const int maxn = 200 + 1;
char ch[maxn][maxn] = {0};
bool isC[maxn][maxn] = {0};
unsigned int t;
unsigned int c,d,n;
char l[maxn] = {0};
int ln;
char str[maxn];
int ans;


void work()
{
    int i,j;
    for(i = 1; i <= n; i ++)
    {
        l[ln ++] = str[i];
        if(ch[l[ln-1]][l[ln-2]] > 0)
        {
            l[ln - 2] = ch[l[ln-1]][l[ln-2]];
            ln -- ;
        }
        else
        {
            for(j = 1; j < ln - 1;j ++)
                if(isC[l[j]][l[ln - 1]])
                {
                    ln = 1;
                    break;
                }
        }
    }
}

void init()
{
    memset(isC,0,sizeof(isC));
    memset(ch,0,sizeof(ch));
    ln = 1;
    char a,b,cc;
    fin >> c;
    for(int i = 1; i <= c; i ++)
    {
        fin >> a >> b >> cc;
        ch[b][a] = ch[a][b] = cc;
    }
    fin >> d;
    for(int i = 1; i <= d; i ++)
    {
        fin >> a >> b;
        isC[a][b] = 1;
        isC[b][a] = 1;
    }
    fin >> n;
    for(int i = 1; i <= n; i ++)
        fin >> str[i];
}

void output()
{
    fout << '[';
    for(int i = 1; i < ln - 1; i ++)
        fout << l[i] << ", ";
    if(ln > 1)
        fout << l[ln - 1];
    fout << ']' << endl;
}

int main()
{
    int i,j;
    fin >> t;
    for(i=1;i<=t;i++)
    {
        init();
        work();
        fout << "Case #" << i << ": ";
        output();
    }
    return 0;
}
