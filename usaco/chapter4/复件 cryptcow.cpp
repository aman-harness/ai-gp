/*
ID: interne4
PROG: cryptcow
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");

string str;
int letter[256] = {0};
const string ori = "Begin the Escape execution at the Break of Dawn";
bool hash[70][1400] = {0};
bool hash2[1400] = {0};
bool hash3[1400] = {0};
bool hashC[1400000] = {0};

unsigned int BKDRHash(const char *str)
{
	unsigned int seed = 131;
	unsigned int hash = 0;
 
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
 
	return (hash & 0x7FFFFFFF);
}

void search(string str,int x)
{
	int i,l;
	bool cow;
	string c;
	l = 0;
	int Cp[10],Cn = 0;
	int Op[10],On = 0;
	int Wp[10],Wn = 0;
	
	int dd = BKDRHash(str.c_str())%1313131;
	if(hashC[dd])
		return;
	else
		hashC[dd] = 1;
	
	for(i=0;i<str.size();i++)
	{
		cow = 0;
		if(str[i] == 'C')
		{
			Cp[Cn++] = i;
			cow = 1;
		}
		else if(str[i] == 'O')
		{
			Op[On++] = i;
			cow = 1;
		}
		else if(str[i] == 'W')
		{
			Wp[Wn++] = i;
			cow = 1;
		}
		if(cow)
		{
			if(l<i)
			{
				if(l == 0)
				{
					if(str[i] == 'O' || str[i] == 'W')
						return;
					c = str.substr(0,i);
					if(!hash2[BKDRHash(c.c_str())%1313])
					{
						return;
					}
				}
				else
				{
					c = str.substr(l,i-l);
					if(!hash[c.size()][BKDRHash(c.c_str())%1313])
					{
						return;
					}
				}
			}
			
			l = i+1;
		}
	}
	if(l > 0)
	{
		if(str[l-1] == 'O' || str[l-1] == 'C')
		{
			return;
		}
	}
	if(l < i)
	{
		c = str.substr(l,str.size()-l);
		if(!hash3[BKDRHash(c.c_str())%1313])
		{
			return;
		}
	}
	
	if(Cn == 0 || On == 0 || Wn == 0)
	{
			fout << 1 << ' '<< x << endl;
			exit(0);
	}
	
	int j,k;
	int il = 0,jl = 0,kl = 0;
	for(i=0;i<Cn;i++)
	{
		for(j=jl;j<On;j++)
		{
			if(Cp[i] > Op[j])
			{
				jl = j + 1;
				continue;
			}
			else
			for(k=kl;k<Wn;k++)
			{
				if(Op[j] > Wp[k])
				{
					kl = k;
					continue;
				}
				else
				{
					string o;
					o = str;
					o.replace(Cp[i] + Wp[k] - Op[j] + 1,Op[j]-Cp[i]-1,str.substr(Cp[i]+1,Op[j]-Cp[i]-1));
					o.replace(Cp[i] + 1,Wp[k]-Op[j]-1,str.substr(Op[j]+1,Wp[k]-Op[j]-1));
					o.erase(Cp[i],1);
					o.erase(Wp[k] - Op[j] + Cp[i] -1 ,1);
					o.erase(Wp[k]-2,1);
					search(o,x+1);
				}
			}
		}
	}
}

int main()
{
	int i,j;
	getline(fin, str);
	for(i=0;i<ori.size();i++)
		letter[ori[i]]++;
	for(i=0;i<str.size();i++)
		letter[str[i]]--;
	letter['C'] = letter['O'] = letter['W'] = 0;
	for(i=0;i<127;i++)
		if(letter[i] != 0)
		{
			fout << 0 << ' ' << 0 << endl;
			return 0;
		}
	
	for(i=0;i<ori.size();i++)
		for(j=1;j<=ori.size()-i;j++)
			hash[j][BKDRHash(ori.substr(i,j).c_str())%1313] = 1;
			
	for(j=1;j<=ori.size();j++)
		hash2[BKDRHash(ori.substr(0,j).c_str())%1313] = 1;
			
	for(j=1;j<=ori.size();j++)
		hash3[BKDRHash(ori.substr(ori.size() - j,j).c_str())%1313] = 1;
	
	search(str,0);
	fout << 0 << ' ' << 0 << endl;
    return 0;
}
