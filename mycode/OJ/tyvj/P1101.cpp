/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string v[10010];
/*
int cmp(const void *x,const void *y)
{
　　char *p,*q;
　　p=(char *)x;
　　q=(char *)y;
　　return strcmp(p,q);//strcmp系比较字符串函数
}*/
int main(int argc, char *argv[])
{
	int i,n;
	cin >> n;
	for(i = 0; i < n; i ++)
	{
		cin >> v[i];
	}
	sort(&v[0],&v[n]);
	
	for(i = 0; i < n; i ++)
		cout << v[i] << endl;
	//while(1);
    return 0;
}
