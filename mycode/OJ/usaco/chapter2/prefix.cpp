/*
ID: interne4
PROG: prefix
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>

using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");

int start[200010],best = 0,maplen = 0;
string maps[201];
string all;

int init()
{
	string str;
	all = "";
	for(int i = 0; i < 200001; i++)
		start[i] = -1;
	while(!fin.eof())
	{
		fin >> str;
		if(str == ".") break;
		maps[maplen++] = str;
	}
	fin >> str;
	while(!fin.eof())
	{
		all += str;
		fin >> str;
	}
	//fout << all << endl;
}

int main()
{
	int i,j,k,len;
	string str;
	
	init();
	i=0;
	for(j = 0;j < maplen; j ++)
		{
			k = maps[j].size();
			if(maps[j] == all.substr(i,k))
			{
				//fout << i << ' ' << j << ' ' << all.substr(i,j)<< ' ' << start[i] << ' ' << start[i+j] << endl;
				if(start[i] != -1)
				{
					if(start[i+k] == -1)
						start[i+k] = start[i];
					else if(start[i+k] > start[i])
						start[i+k] = start[i];
				}
				else
					if(start[i+k] == -1)
						start[i+k] = i;
			}
		}
	len = all.size();
	for(i=1;i<len+1;i++)
	{
		if(start[i] == 0)
		{
		if(i - start[i] > best)
			best = i - start[i];
		for(j = 0;j < maplen; j ++)
		{
			k = maps[j].size();
			if(start[i+k] == 0) continue;
			if(maps[j] == all.substr(i,k))
				start[i+k] = 0;
		}
		}
	}
	fout << best << endl;
    return 0;
}

