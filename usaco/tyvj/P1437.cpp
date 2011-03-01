#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 25000 + 1, maxm = 50000 + 1;
int t,r,p,s;
struct node
{
    int e;
    int n;
    node* next;
}*v[maxn];

node* tail[maxn];

void addEdge(int a, int b, int c)
{
    tail[a] -> next = new node();
    tail[a] = tail[a] -> next;
    tail[a] -> n = b;
    tail[a] -> e = c;
}

void init()
{
    int i,j;
    int a,b,c;
    cin >> t >> r >> p >> s;
    for(i = 1; i <= t; i ++)
    {
        v[i] = new node();
        v[i] -> next = 0;
        tail[i] = v[i];
    }

    for(i = 0; i < r; i ++)
    {
        cin >> a >> b >> c;
        addEdge(a,b,c);
        addEdge(b,a,c);
    }
    for(i = 0; i < p; i ++)
    {
        cin >> a >> b >> c;
        addEdge(a,b,c);
    }
}

bool vis[maxn] = {0};
bool intree[maxn] = {0};
int dis[maxn] = {0};

void dijkstra()
{
    map<int, int> tree;
    map<int, int>::iterator it;
    int i,j;
    int c;
    memset(vis,0,sizeof(vis));
    memset(intree,0,sizeof(intree));
    memset(dis,0x7f,sizeof(dis));
    dis[s] = 0;
    vis[s] = true;
    intree[s] = true;
    tree.insert(pair<int,int>(0,s));
    while(!tree.empty())
    {
        it = tree.upper_bound(-10001);
        c = (*it).second;
        intree[c] = false;
        tree.erase(it);
        node* cn = v[c] -> next;

        cout << c << endl;

        while(1)
        {
            if(vis[cn->n])
            {
                if(intree[cn->n])
                {
                    if(dis[c] + cn->e < dis[cn->n])
                    {
                        tree.erase(dis[cn->n]);
                        dis[cn->n] = dis[c] + cn->e;
                        tree.insert(pair<int,int>(dis[cn->n], cn->n));
                    }
                }
            }
            else
            {
                vis[cn->n] = true;
                intree[cn->n] = true;
                dis[cn->n] = dis[c] + cn->e;
                cout << dis[cn->n] << ' ' << cn->n << endl;
                tree.insert(pair<int,int>(dis[cn->n], cn->n));
            }
            if(cn -> next)
                cn = cn -> next;
            else
                break;
        }
    }
}

void work()
{
    int i;
    dijkstra();
    cout << 0x7f7f7f7f << endl;
    for(i = 1; i <= t; i ++)
        if(dis[i] != 0x7f7f7f7f)
            cout << dis[i] << endl;
        else
            cout << "NO PATH" << endl;
}

int main()
{
    init();
    work();
    return 0;
}
