/*************************************************
Copyright:      No.8 Lightning Man Workgroup
Author:         Alchemist
Date    :       2011-02-21
Description:    Union Find Set
*************************************************/
#ifndef _UFSET_
#define _UFSET_

class UFSet
{
public:
    UFSet(int maxn);
    int findSet(int x);
    void combine(int x, int y);

private:
    int* p;
    int* rank;
    int length;

    void makeSet(int x);
    void link(int x, int y);
};

#endif // _UFSET_
