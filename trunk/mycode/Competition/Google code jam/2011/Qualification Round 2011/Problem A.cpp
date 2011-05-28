#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("dataA.in");
ofstream fout("dataA.out");
const int maxn = 100 + 1;
int p[maxn] = {0};
char r[maxn]={0};
int t;
int n;
int ans;


void work()
{
    int i,b,o,bn,on;
    b = o = bn = on = 1;
    for(i = 1; ; i ++)
    {
        while(r[bn] == 'O' && bn <= n)bn ++;
        while(r[on] == 'B' && on <= n)on ++;
        if(bn <= n)
        {
            if(p[bn] > b)
                b ++;
            else if(p[bn] < b)
                b --;
            else if(bn < on)
                bn ++;
        }
        if(on <= n)
        {
            if(p[on] > o)
                o ++;
            else if(p[on] < o)
                o --;
            else if(on < bn)
                on ++;
        }
        //cout << b << ' ' << o << endl;
        if(bn > n && on > n)
            break;
    }
    ans = i;
}

void init()
{
    fin >> n;
    for(int i = 1; i <= n; i ++)
        fin >> r[i] >> p[i];
}

void output()
{
    fout << ans << endl;
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
