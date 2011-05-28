/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
/*
Author:		Alchemist
Data:		2011.1.31
Problem:	Transform the Expression
*/
#include <iostream>
#include <cstring>
using namespace std;
const int maxN = 500, opN = 5;
const char op[5] = {'^','/','*','-','+'};
int t;
string str;

int getOpLv(char ch)
{
	for(int i = 0; i < opN; i ++)
		if(op[i] == ch)
			return i;
	return -1;
}

string trans(int l,int r)
{
	int i;
	int stack = 0;
	int opt = -1;
	int opd = 0;
	if(l == r)
	{
		string restr = "";
		restr += str[r];
		return restr;
	}
	for(i = l; i <= r; i ++)
	{
		if(str[i] == '(')
			stack ++;
		else if(str[i] == ')')
			stack --;
		else if(stack == 0 && str[i] < 'a')
		{
			int lv = getOpLv(str[i]);
			if(lv > opt)
			{
				opt = lv;
				opd = i;
			}
		}
	}
	if(opt == -1)
	{
		return trans(l + 1, r - 1);
	}
	else if(r - l == 2)
	{
		string restr = "";
		restr += str[l];
		restr += str[r];
		restr += str[l + 1];
		return restr;
	}
	else
	{
		return trans(l, opd - 1) + trans(opd + 1, r) + str[opd];
	}
	
}

int main()
{
	int i,j;
	
	cin >> t; 
	for(i = 1; i <= t; i ++)
	{
		cin >> str;
		cout << trans(0, str.size() - 1) << endl;
	}
	//while(1);
	return 0;
}
