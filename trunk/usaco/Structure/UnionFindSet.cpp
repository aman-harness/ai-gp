#include <iostream>
using namespace std;

class UFSet
{
public:
    int p*;
    int rank*;
    int length;

    UFSet(int maxn)
    {
        int p* = new int[maxn];
        int rank* = new int[maxn];
        length = maxn;
    }

    int findSet(int x)
    {
        while (p[x] != x)
            p[x] = findSet(p[x]);
        return p[x];
    }

    void Union(int x, int y)
    {
        link(findSet(x), findSet(y));
    }

private:
    void makeSet(int x)
    {
        p[x] = x;
        rank[x] = 0;
    }

    void link(int x, int y)
    {
        if (rank[x] > rank[y])
            p[y] = x;
        else
        {
            p[x] = y;
            if(rank[x] == rank[y])
                rank[y] ++;
        }
    }
}
