/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	bool out[100] = {0};
	long long n;
	long long s;
	int i;
	s = 1;
	cin >> n;
	
	s = 1;
	for(i=0;i<32;i++)
	{
		if(abs(double(n)) <= s)
			break;
		s *= 2;
	}
	
	int  l = i + 1;
	
	while(n != 0)
	{
		if(n > 0)
		{
			if(n - s/2 >= s - n)
			{
				n -= s;
			}
			else
			{
				s /= 2;
				n -= s;
				i --;
			}
			if(i % 2 == 0)
			{
				out[i] = 1;
			}
			else
			{
				out[i+1] = 1;
				out[i] = 1;
			}
		}
		else
		{
			if(-s/2 - n >= n + s)
			{
				n += s;
			}
			else
			{
				s /= 2;
				n += s;
				i --;
			}
			if(i % 2 == 0)
			{
				out[i+1] = 1;
				out[i] = 1;
			}
			else
			{
				out[i] = 1;
			}
		}
		i--;
		s /= 2;
		
		if(n == 0)
			break;
		while(abs(double(n)) <= s/2)
		{
			i --;
			s /= 2;
		}
		//cout << n << ' ' << s << ' ' << i << endl;
	}
	bool t = 0;
	for(i=l + 1;i>=0;i--)
	{
		if(out[i] > 0)
			t = 1;
		if(t)
			cout << out[i];
	}
	if(!t)
		cout << 0;
	cout << endl;
	//while(1);
    return 0;
}
