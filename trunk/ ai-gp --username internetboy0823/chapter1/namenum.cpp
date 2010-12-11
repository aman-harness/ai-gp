/*
ID: interne4
PROG: namenum
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("namenum.in");
ifstream fdict("dict.txt");
ofstream fout("namenum.out");

long long n,x,trans[5000];
string str[5001];
int main()
{
	long long i,j,num;
	bool t = 1;
	fin >> x;
	for(i=0;!fdict.eof();i++)
	{
		fdict >> str[i];
		num = 0;
		for(j=0;j<str[i].length();j++)
		{
			if(str[i][j] <= 'P')
				num += (str[i][j]-'A')/3 + 2;
			else
				num += (str[i][j]-1-'A')/3 + 2;
			if(str[i][j] =='Z' || str[i][j] =='Q' )
			{
				num = -20;
				break;
			}
			num *= 10;
		}
		trans[i] = num/10;
		//fout<<num/10 <<endl;
	}
	n=i;
	for(i=0;i<n;i++)
		if(x==trans[i])
		{
			fout << str[i] << endl;
			t = 0;
		}
	if(t)
		fout << "NONE" <<endl;
    return 0;
}
