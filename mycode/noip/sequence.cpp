#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 1000 + 1;
struct E
{
    int u,v,w;
}edge[maxn] = {0};
int d[maxn] = {0};
int p[maxn] = {0};
int n,en = 0;
const int INF = 07fffffff;

int bellman_ford(int s)
{
    for(int i = 0; i <= 1000; i ++)
    {
        d[i] = INF;
        p[i] = -1;
    }
    d[s] = 0;
    int u,v;
    for(int i = 0; i <= 1000; i ++)
    {
        for(int j = 0; j < en ; j++)
        {
            u = edge[j].u;
            v = edge[j].v;
            if(d[u] + edge[j].w < d[v])
            {
                d[v] = d[u] + edge[j].w;
                p[v] = u;
            }
        }
    }

    for(int i = 0; i < en; i ++)
    {
        u = edge[j].u;
        v = edge[j].v;
        if(d[u] + edge[j].w < d[v])
            return -1;
    }
    return d[0];
    /*procedure BellmanFord(list vertices, list edges, vertex source)
   // This implementation takes in a graph, represented as lists of vertices
   // and edges, and modifies the vertices so that their distance and
   // predecessor attributes store the shortest paths.

   // Step 1: initialize graph
   for each vertex v in vertices:
       if v is source then v.distance := 0
       else v.distance := infinity
       v.predecessor := null

   // Step 2: relax edges repeatedly
   for i from 1 to size(vertices)-1:
       for each edge uv in edges: // uv is the edge from u to v
           u := uv.source
           v := uv.destination
           if u.distance + uv.weight < v.distance:
               v.distance := u.distance + uv.weight
               v.predecesso
            if(d[u] + edge[j].w < d[v])r := u

   // Step 3: check for negative-weight cycles
   for each edge uv in edges:
       u := uv.source
       v := uv.destination
       if u.distance + uv.weight < v.distance:
           error "Graph contains a negative-weight cycle"*/
}

void init()
{
    int a,b,c;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        edge[en].u = a - 1;
        edge[en].v = b;
        edge[en ++].w = -c;
    }

    for(int i = 0; i < n; i++)
    {
        edge[en].u = i;
        edge[en].v = i + 1;
        edge[en ++].w = 1;
        edge[en].u = i + 1;
        edge[en].v = i;
        edge[en ++].w = 0;
    }

}

int main()
{
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    int i,j;
    init();
    cout << bellman_ford(n) << endl;
    return 0;
}
