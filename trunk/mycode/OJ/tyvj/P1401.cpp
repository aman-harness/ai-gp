#include <iostream>
#include <cmath>
using namespace std;

void trans(unsigned long long x, int& n, int* a)
{
    n = 0;
    while(x > 0)
    {
        a[n ++] = x % 10;
        x /= 10;
    }
    if(n == 0) n ++;
}
/*

void add(int& an, int* a, int& bn, int* b)
{
    int i, n = max(an, bn);
    for(i = 0; i < n; i ++)
    {
        a[i] += b[i];
        a[i+1] += a[i]/10;
        a[i] %= 10;-293478327487237499 9000000000000000000
    }
    while(a[n]) n ++;
    an = n;
}

void minu(int& an, int* a, int& bn, int* b)
{
    int i, n = max(an, bn);
    for(i = 0; i < n; i ++)
    {
        a[i] -= b[i];
        if(a[i] < 0)
        {
            a[i] += 10;
            a[i+1] --;
        }
    }
    while(!a[n] && n > 1) n --;
    an = n;
}
*/
void print(int& n, int* a)
{
    for(int i = 0; i < n; i ++)
    {
        cout << a[n - i - 1];
        if((n - i)%3 == 1 && i != n - 1)
            cout << ',';
    }
    cout << endl;
}

int main()
{
    int an, ax[100] = {0};
    long long a,b;
    unsigned long long p,q;
    cin >> a >> b;
    if(a < 0) p = -a;
    else p = a;
    if(b < 0) q = -b;
    else q = b;
    if(a < 0 && b > 0)
    {
        cout << '-';
        p += q;
        trans(p, an ,ax);
        print(an, ax);
    }
    else if(a > 0 && b < 0)
    {
        p += q;
        trans(p, an ,ax);
        print(an, ax);
    }
    else if(a <= 0 && b <= 0)
    {
        if(p > q)
        {
            p -= q;
            cout << '-';
            trans(p, an ,ax);
            print(an, ax);
        }
        else
        {
            q -= p;
            trans(q, an ,ax);
            print(an, ax);
        }
    }
    else if(a >= 0 && b >= 0)
    {
        if(p < q)
        {
            q -= p;
            cout << '-';
            trans(q, an ,ax);
            print(an, ax);
        }
        else
        {
            p -= q;
            trans(p, an ,ax);
            print(an, ax);
        }
    }
    return 0;
}
