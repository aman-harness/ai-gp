/*
Problem:    消息传递
Assemble:   NOIP_moni_9
Anthor:     Alchemist
Date:       2011.10.21
Tag:        DFS, Dynamic Programme
Difficulty: **
Description:
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>

#define pb push_back
using namespace std;

const int maxn = 1000 + 1;
vector<int> adj[maxn];
bool vis[maxn];
int n;


void init()
{
    int r;
    cin >> n;
    for(int i = 2; i <= n ; i ++)
    {
        cin >> r;
        adj[i].pb(r);
        adj[r].pb(i);
    }
}

int dfs(int x)
{
    vis[x] = 1;
    //if(adj[x].size() == 1)
    //   return 0;
    vector<int> vs;
    for(int i = 0; i < adj[x].size(); i ++)
        if(!vis[adj[x][i]])
        {
            vs.pb(dfs(adj[x][i]));
        }
    sort(vs.begin(), vs.end());

    int s,n;
    s = 0;
    n = vs.size();
    for(int i = 1; i <= n; i ++)
    {
        if(vs[n - i] + i > s)
            s = vs[n - i] + i;
        //cout << vs[n - i] << " ";
    }
    //cout << endl;
    //cout << x << ':' << s << endl;
    return s;
}

int minx;
vector<int> ans;

int main()
{
    freopen("news.in","r",stdin);
    freopen("news.out","w",stdout);
    init();

    minx = 0x7fffffff;
    for(int i = 1; i <= n; i ++)
    {
        memset(vis,0,sizeof(vis));
        int k = dfs(i);
        if(k < minx)
        {
            minx = k;
            ans.clear();
            ans.pb(i);
        }
        else if(k == minx)
            ans.pb(i);
        //cout << endl;
        //cout << k << endl;
    }

    cout << minx + 1 << endl;
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
