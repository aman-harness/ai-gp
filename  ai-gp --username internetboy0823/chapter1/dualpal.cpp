/*
ID: interne4
PROG: dualpal
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
ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

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
	char a[101];
	string c;
	int x,n;
	int i,j,k,l;
	int t;
	bool s;
	fin >> n;
	fin >> x;
	for(i=x+1,j=0;j<n;i++)
	{
		t = 0;
		for(k=2;k<=10;k++)
		{
			s = 0;
			trans(i,k,a);
			c = cstr_to_string(a);
			for(l=0;l<c.length()/2;l++)
				if(c[c.length()-l-1] != c[l])
				{
					s = 1;
					break;
				}
			
			if(!s)
				t++;
		}
		if(t >= 2)
		{
			j++;
			fout << i << endl;
		}
	}
    return 0;
}
