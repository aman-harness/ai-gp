/*
ID: interne4
PROG: ratios
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("ratios.in");
ofstream fout("ratios.out");

int main()
{
	int x1,x2,x3;
	int y1,y2,y3;
	int z1,z2,z3;
	int s1,s2,s3;
	fin >> s1 >> s2 >> s3;
    fin >> x1 >> x2 >> x3;
    fin >> y1 >> y2 >> y3;
    fin >> z1 >> z2 >> z3;
    int i,j,k,l;
    int a,b,c;
    if(s3 == 0)
    {
    for(i=1;i<=300;i++)
    {
	    for(j=0;j<=i;j++)
	    {
	    	for(k=0;k<=i-j;k++)
	    	{
		    	l = i - j - k;
			    a = (x1*j + y1*k + z1*l);
			    b = (x2*j + y2*k + z2*l);
			    c = (x3*j + y3*k + z3*l);
			    
			    if( a % s1 ||  b % s2 || c != 0)
			    	continue;
			    if( a / s1 == b / s2 )
			    {
				    fout << j << ' ' << k << ' ' << l << ' ' << a/s1 << endl;
				    return 0;
				}
			}
    	}
    }
    }
    else if(s2 == 0)
    {
	    
    for(i=1;i<=300;i++)
    {
	    for(j=0;j<=i;j++)
	    {
	    	for(k=0;k<=i-j;k++)
	    	{
		    	l = i - j - k;
			    a = (x1*j + y1*k + z1*l);
			    b = (x2*j + y2*k + z2*l);
			    c = (x3*j + y3*k + z3*l);
			    if( a % s1 || c % s3 || b != 0)
			    	continue;
			    if( a / s1  == c / s3 )
			    {
				    fout << j << ' ' << k << ' ' << l << ' ' << a/s1 << endl;
				    return 0;
				}
			}
    	}
    }
    }
    else if(s1 == 0)
    {
	    
    for(i=1;i<=300;i++)
    {
	    for(j=0;j<=i;j++)
	    {
	    	for(k=0;k<=i-j;k++)
	    	{
		    	l = i - j - k;
			    a = (x1*j + y1*k + z1*l);
			    b = (x2*j + y2*k + z2*l);
			    c = (x3*j + y3*k + z3*l);
			    if( b % s2 ||  c % s3 || a != 0)
			    	continue;
			    if( b / s2 == c / s3 )
			    {
				    fout << j << ' ' << k << ' ' << l << ' ' << c / s3 << endl;
				    return 0;
				}
			}
    	}
    }
    }
    else
    {
    for(i=1;i<=300;i++)
    {
	    for(j=0;j<=i;j++)
	    {
	    	for(k=0;k<=i-j;k++)
	    	{
		    	l = i - j - k;
			    //fout << j << ' ' << k << ' ' << l << endl;
			    a = (x1*j + y1*k + z1*l);
			    b = (x2*j + y2*k + z2*l);
			    c = (x3*j + y3*k + z3*l);
			    if( a % s1 ||  b % s2 ||  c % s3 )
			    	continue;
			    if( a / s1 == b / s2 && b / s2 == c / s3 )
			    {
				    fout << j << ' ' << k << ' ' << l << ' ' << a/s1 << endl;
				    return 0;
				}
			}
    	}
    }
    }
    fout << "NONE" << endl;
    return 0;
}
