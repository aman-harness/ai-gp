#include <iostream>
#include <cmath>
using namespace std;
int n;

void init()
{
	cin >> n;
}

int main()
{
	unsigned short j,a,b;
	int i,m;
	init();
	a = b = 1;
    /*
	for(i=3;i<=100000;i++)
	{
	    j = b;
	    b = (a + b) & 32767;
	    a = j;
	    if(a == 1 && b == 1)
            break;
    }
    cout << i - 2 << endl;*/
    m = n % 49152;//(i - 2);
    //cout << m << endl;
	a = b = 1;
	for(i=3;i<=m;i++)
	{
	    j = b;
	    b = (a + b) & 32767;
	    a = j;
    }
	cout << b << endl;
	return 0;
}
