/*
ID: interne4
PROG: cowcycle
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cowcycle.in");
ofstream fout("cowcycle.out");

int f,r,f1,f2,r1,r2;
int df[10],dr[10],af[10],ar[10];
double minF = 100;

int comp(const void* p,const void* q)
{
	//fout << *(double*)p  << ' ' << *(double*)q << ' ' << (*((double*)p) > *((double*)q)) << endl;
	if( *((double*)p) > *((double*)q))
		return 0;
	else
		return 1;
}

void check()
{
	double x[51],s = 0,fa = 0;
	int i,j;
	
	for(i = 1; i <= f; i ++ )
		fout << df[i] << ' ' ;
	fout << endl;
	for(i = 1; i <= r; i ++ )
		fout << dr[i] << ' ' ;
	fout << endl;
	
	for(i = 1; i <= f; i ++ )
	for(j = 1; j <= r; j ++ )
		x[(i-1)*r+j-1] = double(df[i])/dr[j];
		//fout << x[0] << endl;
	//fout << endl;
	sort(&x[0],&x[r*f]);
	//qsort(x,r*f,sizeof(x[0]),comp);
	for(i = 0; i < r*f-1; i ++ )
	{
		//fout << x[i] << ' ';
		x[i] = x[i+1] - x[i];
		s += x[i];
	}
	//fout << endl;
	s /= r*f-1;
	for(i = 0; i < r*f-1; i ++ )
		fa += (s - x[i]) * (s - x[i]);
	
	//fout << s << endl;
	fout << fa << endl;
	if(minF - fa > 0.0000001 )
	{
		minF = fa;
		for(i = 1; i <= f; i ++ )
			af[i] = df[i];
		for(i = 1; i <= r; i ++ )
			ar[i] = dr[i];
	}
	//fout << endl;
	
}

int main()
{
	int i,j,lvf,lvr;
	fin >> f >> r >> f1 >> f2 >> r1 >> r2;
	
	lvf = 1;
	df[lvf] = f1;
	i = f1;
	while(1)
	{
		if(lvf == f)
		{
			lvr = 1;
			dr[lvr] = r1;
			j = r1;
			while(1)
			{
				if(lvr == r)
				{
					//if(df[1] == 43 && df[2] == 71 && df[3] == 75)
					//	fout << i << ' ' << j; 
					if(/*df[1] == 44 &&*/ double(df[1])/dr[r] * 3 <=  double(df[f])/dr[1])
						check();
					dr[lvr] = ++j;
				}
				else
				{
					dr[++lvr] = ++j;
				}
				while(j + r - lvr > r2)
				{
					lvr --;
					dr[lvr] ++;
					j = dr[lvr];
					
					if(df[1] == 43 && df[2] == 59 && df[3] == 63)
						fout << lvr << ' ' << dr[1] << ' ' <<  dr[2] << ' ' << j <<endl; 
				}
				if(df[1] == 43 && df[2] == 59 && df[3] == 63)
				{
						fout << lvr << ' ' << dr[1] << ' ' <<  dr[2] << ' ' << j <<endl; 
						fout << 's' <<endl;
						}
				
				if(lvr < 1)
					break;
				
			}
			df[lvf] = ++i;
		}
		else
		{
			df[++lvf] = ++i;
		}
		while(i + f - lvf > f2)
		{
			lvf --;
			df[lvf] ++;
			i = df[lvf];
		}
			
		if(lvf < 1)
			break;
	}
	for(i=1;i<f;i++)
		fout << af[i] << ' ' ;
	fout << af[i];
	fout << endl;
	for(i=1;i<r;i++)
		fout << ar[i] << ' ' ;
	fout << ar[i];
    fout << endl;
	return 0;
}
