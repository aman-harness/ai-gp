/*
Problem:    书架
Assemble:   NOIP_moni_8
Anthor:     Alchemist
Date:       2011.10.20
Tag:        Simulation, Balanced Tree
Difficulty: ****
Description:
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>
using namespace std;
int n, m, q, sn;
list<vector<string> > vl;
string s[101000];

void insert(string s, int p)
{
    list<vector<string> >::iterator it;
    int pt = 0;
    for(it = vl.begin(); it != vl.end(); it ++)
    {
        pt += it -> size();
        if(p <= pt)
            break;
    }
    it->insert(it->begin() + p - pt + it -> size(),s);
}

void pop()
{
    sn = 0;
    list<vector<string> >::iterator it;
    vector<string>::iterator vit;
    for(it = vl.begin(); it != vl.end(); it ++)
    {
        for(vit = it->begin(); vit != it->end(); vit ++)
        {
            s[sn ++] = *vit;
            //cout << s[sn - 1] << endl;
        }
    }

}

int main()
{
    freopen("book.in","r",stdin);
    freopen("book.out","w",stdout);
    int i,j,k;
    string str;
    cin >> n;
    for(i = 0; i < n; i ++)
    {
        cin >> str;
        vector<string> a;
        a.push_back(str);
        vl.push_back(a);
    }
    cin >> m;
    for(i = 0; i < m; i ++)
    {
        cin >> str >> k;
        insert(str, k);
    }
    pop();
    cin >> q;
    for(i = 0; i < q; i ++)
    {
        cin >> k;
        cout << s[k] << endl;
    }
    return 0;
}
