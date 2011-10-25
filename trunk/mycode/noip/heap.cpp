/*
Problem:    Heap
Assemble:   NOIP_moni_7
Anthor:     Alchemist
Date:       2011.10.21
Tag:        Tree, LCS
Difficulty: ***
Description:
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 100000 + 1;
int a[maxn] = {0},n;
int t[maxn] = {0},tn = 0;

void dfs(int x)
{
    if(x * 2 <= n)
        dfs(x * 2);
    if(x * 2 + 1 <= n)
        dfs(x * 2 + 1);
    t[++ tn] = a[x];
}

int li[maxn] = {0}, ln = 0;
void lcs()
{
    int i,j;
    int l,r,mid;
    for(i = 1; i <= tn; i ++)
    {
        l = 1;
        r = ln;
        mid = l + r / 2;
        if(ln == 0 || t[i] > li[ln])
            li[++ ln] = t[i];
        else
        {
            while(l < r)
            {
                if(t[i] < li[mid])
                    r = mid - 1;
                else if(t[i] > li[mid])
                    l = mid + 1;
                else
                    break;
                mid = l + r / 2;
            }
            while(li[mid] <= t[i])
                mid ++;
            li[mid] = t[i];
        }/*
        for(j = 1; j <= ln; j ++)
            cout << li[j] << ' ';*/
        //cout << endl;
        //if(i > 2)
        //    break;
    }
}

int main()
{
    freopen("heap.in","r",stdin);
    freopen("heap.out","w",stdout);
    int i,j,k;
    cin >> n;
    for(i = 1; i <= n; i ++)
        scanf("%d",&a[i]);
    dfs(1);
    lcs();
    cout << tn - ln << endl;
    return 0;
}
