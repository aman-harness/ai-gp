/*
ID: interne4
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream fin("friday.in");
ofstream fout("friday.out");

int n;
int main()
{
	int day[7]={0};
	char* a=new char[10]; 
	int i,w,c,y,m,d;
    fin >> n;
    d=13;
	for(i=1900;i<=1900+n-1;i++)
	{
		c = (i-1)/100;
		y = (i-1)%100;
		for(m=13;m<=14;m++)
		{
			w = (c / 4) - (2 * c) + y + (y / 4) + (13 * (m + 1) / 5) + d - 1;
			if(w<0)
			{
				if(w%7)
					day[7+w%7]++;
				else
					day[0]++;
			}
			else
				day[w%7]++;
		}
		c = i/100;
		y = i%100;
		for(m=3;m<=12;m++)
		{
			w = (c / 4) - (2 * c) + y + (y / 4) + (13 * (m + 1) / 5) + d - 1;
			if(w<0)
			{
				if(w%7)
					day[7+w%7]++;
				else
					day[0]++;
			}
			else
				day[w%7]++;
		}
		
	}
    //²ÌÀÕ¹«Ê½
	fout << day[6] <<' ';
	for(i=0;i<5;i++)
	    fout << day[i] << ' ';
	 fout << day[5];
	fout<<endl;
	return 0;
}
