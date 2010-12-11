/*
ID: interne4
PROG: buylow
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/

#include <fstream>
#include <cstring>
using namespace std;
/* This BitInt class is programmed by Alchemist, all right reserved.*/

#ifndef _BIG_INT_
#define  _BIG_INT_
#include <cstring>
#include <iostream>
using namespace std;

const int maxLength = 100;

class BigInt
{
	void checkData();
	friend ostream& operator << (ostream& output , BigInt& b);
	friend bool operator == (const BigInt& a, long b);
	friend bool operator != (const BigInt& a, long b);
public:
	BigInt();
	char data[maxLength];
	int length;
	BigInt& operator = (const BigInt& b);
	BigInt& operator = (long b);
	BigInt& operator += (const BigInt& b);
	//BigInt& operator -= (const BigInt& b);
};

void BigInt::checkData()
{
	data[length] = 0;
}

bool operator == (const BigInt& a, long b)
{
	int i = 0;
	while(i < a.length)
	{
		if(a.data[i] != b % 10)
			return false;
		b /= 10;
		i ++;
		if(b == 0)
			break;
	}
	if(b == 0 && i == a.length)
		return true;
	return false;
}

bool operator != (const BigInt& a, long b)
{
	return !(a == b);
}

ostream& operator << (ostream& output, BigInt& b)
{
	int i;
	for(i = b.length - 1; i >= 0; i--)
	{
		output << (int)b.data[i];
	}
	return output;
}

BigInt::BigInt()
{
	memset(data,0,sizeof(data));
	length = 1;
}

BigInt& BigInt::operator = (long b)
{
	memset(data,0,sizeof(data));
	length = 0;
	if(b == 0)
	{
		length = 1;
		data[0] = 0;
	}
	while(b > 0)
	{
		data[length] = b % 10;
		b /= 10;
		length ++;
	}
	checkData();
	return *this;
	
}

BigInt& BigInt::operator = (const BigInt& b)
{
	memset(data,0,sizeof(data));
	for(int i = 0; i < b.length;i++)
		data[i] = b.data[i];
	length = b.length;
	checkData();
	return *this;
}
//5253120000

BigInt& BigInt::operator += (const BigInt& b)
{
	int l = max(length,b.length);
	int i;
	for(i = length; i <= l; i ++)
		data[i] = 0;
	for(i = 0; i < l; i ++)
	{
		data[i] += b.data[i];
		if(data[i] > 9)
		{
			data[i+1] += 1;
			data[i] -= 10;
		}
	}
	if(data[l] > 0)
		length = l + 1;
	else
		length = l;
	checkData();
	return *this;
}
/*
BigInt& BigInt::operator -= (const BigInt& b)
{
	int i;
	for(i = 0; i < b.length; i ++)
	{
		data[i] -= b.data[i];
		if(data[i] < 0)
		{
			data[i] += 10;
			data[i+1] --;
		}
	}
	while(data[length - 1] == 0)
		length --;
	return *this;
}*/


#endif
/********************end******************/


ifstream fin("buylow.in");
ofstream fout("buylow.out");

const int maxN = 5010 + 1;
int n;
int stock[maxN] = {0};
int day[maxN] = {0};
BigInt total[maxN];
BigInt lastNum;
int last;

inline void tempEmpty();

int main()
{
	int i,j;
	int maxD = 0,maxI = 1;
	BigInt t;
	t = 0;
	fin >> n;
	for(i=1;i<=n;i++)
		fin >> stock[i];
	for(i=1;i<=n;i++)
	{
		maxD = 0;
		t = 0;
		last = 0;
		lastNum = 0;
		for(j=1;j<i;j++)
			if(stock[j] > stock[i] && day[j] > maxD)
				maxD = day[j];
		
		for(j=1;j<i;j++)
		{
			if(stock[j] > stock[i] && day[j] == maxD)
			{
				if(last == stock[j])
				{
					lastNum = total[j];
				}
				else
				{
					t += lastNum;
					last = stock[j];
					lastNum = total[j];
				}
			}
		}
		if(last > 0)
			t += lastNum;
		if(t == 0) t = 1;
		total[i] = t;
		day[i] = maxD + 1;
		//fout << total[i] << ' ';
	}
	for(i=2;i<=n;i++)
		if(day[i] > day[maxI])
			maxI = i;
	int ans = day[maxI];
	BigInt ans2;
	ans2 = 0;
	last = 0;
	lastNum = 0;
	for(i=1;i<=n;i++)
		if(day[i] == ans)
		{
			if(last == stock[i])
			{
				lastNum = total[i];
			}
			else
			{
				ans2 += lastNum;
				last = stock[i];
				lastNum = total[i];
			}
		}
	if(last > 0)
		ans2 += lastNum;
	fout << ans << ' ' << ans2 << endl;
    return 0;
}


