/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
long long n, k;

void init()
{
	cin >> n >> k;
}

int main()
{
	init();
	long long i,s = 1, kn = 1, l, c;
	c = 10000;
	c *= 1000000;
	l = k;
	while(k > 0)
	{
		kn *= 10;
		k --;
	} 
	for(i = 1; i <= n; i ++)
	{
		s *= i;
		while(s % 10 == 0)
			s /= 10;
		s %= c;
	}
	s %= kn;
	stringstream ss;
	string str;
	ss << s;
	ss >> str;
	while(str.size() < l)
		str = "0" + str;
	cout << str << endl;
	//system("pause");
	return 0;
}
