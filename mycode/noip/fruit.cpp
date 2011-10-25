/*
Problem:    果子合并
Assemble:   NOIP_moni_9
Anthor:     Alchemist
Date:       2011.10.21
Tag:        Math, Heap
Difficulty: ***
Description:
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int maxn = 10000;
int n, k;
priority_queue<int> q;

int main()
{
    freopen("fruit.in","r",stdin);
    freopen("fruit.out","w",stdout);
    int i,j;
    unsigned long long s = 0;
    cin >> n >> k;
    for(i = 0; i < n; i ++)
    {
        scanf("%d",&j);
        q.push(-j);
    }
    if((n - 1) % (k - 1) != 0)
    {
        j = 0;
        i = 0;
        while(i < ((n - 1) % (k - 1)) + 1 && !q.empty())
        {
            j += -q.top();
            q.pop();
            i ++;
        }
        s += j;
        q.push(-j);
    }

    while(q.size() > 1)
    {
        j = 0;
        i = 0;
        while(i < k && !q.empty())
        {
            j += -q.top();
            q.pop();
            i ++;
        }
        s += j;
        q.push(-j);
    }
    cout << s << endl;
    return 0;
}
