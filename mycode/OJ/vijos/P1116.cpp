#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
ifstream fin("P1116.in");
ofstream fout("P1116.out");
int main(){
	double a,b,c,d,i;
	const double l = -100.0, r = 100.0;
	fin >> a >> b >> c >> d;
	for(i = l ; i <= r ; i += 0.01)
	{
		if(abs(a*i*i*i + b*i*i + c*i + d) <= 0.005)
			fout << setiosflags(ios::fixed) << setprecision(2)<< i << ' ';
	}
    return 0;
}
