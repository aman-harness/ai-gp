/*************************************************
Copyright:      No.8 Lightning Man Workgroup
Author:         Alchemist
Date    :       2011-02-21
Description:    Union Find Set
*************************************************/
#include "UnionFindSet.h"

UFSet::UFSet(int maxn)
{
    p = new int[maxn];
    rank = new int[maxn];
    length = maxn;
    for(int i = 0; i < length; i ++)
        makeSet(i);
}

int UFSet::findSet(int x)
{
    if (p[x] != x)
        p[x] = findSet(p[x]);
    return p[x];
}

void UFSet::combine(int x, int y)
{
    link(findSet(x), findSet(y));
}

void UFSet::makeSet(int x)
{
    p[x] = x;
    rank[x] = 0;
}

void UFSet::link(int x, int y)
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

