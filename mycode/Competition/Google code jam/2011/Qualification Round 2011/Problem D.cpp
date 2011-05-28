#include <fstream>
#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream fin("dataC.in");
ofstream fout("dataC.out");
const int maxn = 1000 + 1;
unsigned int c[maxn] = {0};
unsigned int num[maxn] = {0};
unsigned int t;
unsigned int n;
unsigned int total[20] = {0};
int ans;


void work()
{
    int i,j;
    memcpy(num, c, sizeof(c))
    sort(&num[1],&num[n+1]);
    for(i = 1; i <= n; i ++)
    {
        bitset<21> bits(c[i]);
        for(j = 0; j < 20; j ++)
            if(bits[j] == 1)
                total[j] ++;
    }
    ans = 0;
    for(j = 0; j < 20; j ++)
        if(total[j] % 2 == 1)
        {
            //cout << total[j] << endl;
            ans = -1;
            break;
        }
    if(ans == 0)
    {
        for(i = 1; i < n ; i ++)
            ans += c[i];
    }
}

void init()
{
    memset(total,0,sizeof(total));
    fin >> n;
    for(int i = 1; i < =n; i ++)
        fin >> c[i];
}

void output()
{
    if(ans >= 0)
        fout << ans << endl;
    else
        fout << "NO" << endl;
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
