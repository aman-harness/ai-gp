/*
ID: interne4
PROG: job
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("job.in");
ofstream fout("job.out");

const int maxM = 30 + 1,maxN = 1000 + 1;
int timeA[maxM] = {0}, timeB[maxM] = {0};
int mA,mB,n,workA[maxM] = {0},workB[maxM] = {0};
int ic[maxN] = {0},icB[maxN] = {0};

int main()
{
	int i,j;
	fin >> n >> mA >> mB;
	for(i=1;i<=mA;i++)
    	fin >> workA[i];
    for(i=1;i<=mB;i++)
    	fin >> workB[i];
    for(i=1;i<=n;i++)
    {
	    int minT = 1000000, minM = -1;
	    for(j=1;j<=mA;j++)
		    if(timeA[j] + workA[j] < minT)
			    minT = timeA[j] + workA[j],minM = j;
		timeA[minM] = minT;
		ic[i] = minT;
    }
    fout << ic[n] << ' ';
    for(i=1;i<=n;i++)
    {
	    int minT = 1000000, minM = -1;
	    for(j=1;j<=mB;j++)
		    if(timeB[j] + workB[j] < minT)
			    minT = timeB[j] + workB[j],minM = j;
		timeB[minM] = minT;
		icB[i] = minT;
    }
    int ans = 0;
    for(i=1;i<=n;i++)
    	if(ans < ic[i] + icB[n-i+1])
    		ans = ic[i] + icB[n-i+1];
    fout << ans << endl;
    return 0;
}
