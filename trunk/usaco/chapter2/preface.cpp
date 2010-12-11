/*
ID: interne4
PROG: preface
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cstring>
#include <map>
using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");
const string x[4][9]={
						{"I","II","III","IV","V","VI","VII","VIII","IX"},
						{"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
						{"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
						{"M","MM","MMM","GM","G","GM","GMM","GMMM","MW"}
						};
int n;

map<char,int> ans;

void check(string str)
{
	int i,n = str.length();
	for(i=0;i<n;i++)
		ans[str[i]] ++;
}

int main()
{
	int i,j,l;
	fin >> n;
	ans['I'] = ans['L'] = ans['X'] = ans['L'] = ans['C'] = ans['D'] = ans['M'] = 0;
	for(i=1;i<=n;i++)
	{
		j = i;
		l = 0;
		while(j)
		{
			if(j%10)
				check(x[l][j%10-1]);
			j/=10;
			l++;
		}
	}
	if(ans['I'])
		fout << 'I' << ' ' << ans['I'] << endl;
	if(ans['V'])
		fout << 'V' << ' ' << ans['V'] << endl;
	if(ans['X'])
		fout << 'X' << ' ' << ans['X'] << endl;
	if(ans['L'])
		fout << 'L' << ' ' << ans['L'] << endl;
	if(ans['C'])
		fout << 'C' << ' ' << ans['C'] << endl;
	if(ans['D'])
		fout << 'D' << ' ' << ans['D'] << endl;
	if(ans['M'])
		fout << 'M' << ' ' << ans['M'] << endl;
    return 0;
}
/*
I II III IV V VI VII VIII IX X
*/
