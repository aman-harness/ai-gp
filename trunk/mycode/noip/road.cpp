/*
Problem:    路标设置
Assemble:   NOIP_moni_8
Anthor:     Alchemist
Date:       2011.10.24
Tag:        Divide
Difficulty: **
Description:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
void init()
{

}

const int maxn = 100000 + 1;
int a[maxn] = {0};
int n, l, k;


int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    init();

    int i, j;
    cin >> l >> n >> k;
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i ++)
        a[i] = a[i + 1] - a[i];
    n --;
    sort(&a[0], &a[n]);
    /*
    for(i = 0; i < n; i ++)
        cout << a[i] << ' ';
    cout << endl;*/
    int left, right, mid;
    left = 0;
    right = l;
    mid = (left + right) / 2;
    while(left + 1 < right)
    {
        int s = 0;
        for(j = 0; j < n; j ++)
            s += ((a[j] - 1) / mid);
        if(s <= k)
            right = mid;
        else if(s > k)
            left = mid;
        mid = (left + right) / 2;
        //cout << left << ' ' << right <<  endl;
    }
    mid = (left + right) / 2;


    while(1)
    {
        int s = 0;
        for(j = 0; j < n; j ++)
            s += ((a[j] - 1) / mid);
        if(s > k)
            mid ++;
        else
            break;
    }

    cout << mid << endl;
    return 0;
}
