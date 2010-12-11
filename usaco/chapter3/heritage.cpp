/*
ID: interne4
PROG: heritage
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
ifstream fin("heritage.in");
ofstream fout("heritage.out");
int n;
string postOrder, inOrder, preOrder;

string order(int pl,int il,int len)
{
	if(len == 0)
		return "";
	else if(len == 1)
		return preOrder.substr(pl,1);
	int j = inOrder.find(preOrder[pl]) - il;
	return order(pl + 1, il, j) + order(pl + j + 1, il + j + 1, len - j - 1) + preOrder[pl];
}

int main()
{
	int i,j;
	fin >> inOrder >> preOrder;
	n = inOrder.size();
	fout << order(0,0,n) << endl;
    return 0;
}
