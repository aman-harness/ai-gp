#include <iostream>
#include <cmath>
using namespace std;
long long n;

void init()
{
	cin >> n;
}

int main()
{
	long long i,j,a,b;
	init();
	a = n;
	for(i=2;i<=sqrt(n);i++)
	{
	    while(n%(i*i) == 0) n /= i*i;
	}
	b = a / n;
	b = sqrt(b) + 1;
	b *= b;
	b *= n;
	cout << b << endl;
	return 0;
}
