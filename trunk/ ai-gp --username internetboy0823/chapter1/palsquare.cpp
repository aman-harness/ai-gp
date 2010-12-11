/*
ID: interne4
PROG: palsquare
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

string cstr_to_string(char *p_str)   
{
	return   p_str;
}

int trans(int n,int d,char s[])
{
  static char digits[]="0123456789ABCDEFGHIJK";
  char buf[101];
  int j,i=100;
  s[0]='\0'; /*不合理的进制，置s为空字符串*/
  buf[i]='\0';
  do
  {
    buf[--i] = digits[n%d]; /*得出最低位，将对应字符存入对应数组中*/
    n /= d;
  }while(n);
  /*将工作数组中的字符串复制到s*/
  for(j=0;(s[j]=buf[i])!='\0';j++,i++);
  /*其中控制条件可简写成s[j]=buf[i]*/
  return j;
}

int main()
{
	char a[101],d[101];
	string c;
	int b,x;
	int i,j;
	bool t;
	fin >> b;
	for(i=1;i<=300;i++)
	{
		x = i*i;
		trans(x,b,a);
		c = cstr_to_string(a);
		t = 0;
		for(j=0;j<c.length()/2;j++)
			if(c[c.length()-j-1] != c[j])
			{
				t=1;
				break;
			}
		trans(i,b,d);
		if(!t)
			fout << d << ' ' << c << endl;
	}
    return 0;
}
