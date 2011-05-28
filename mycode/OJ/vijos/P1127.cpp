#include <fstream>
using namespace std;
ifstream fin("P1127.in");
ofstream fout("P1127.out");
int main(){
	double x = 0.0,k;
	int n=1,i;
	fin >> k;
	while(1)
	{
		x += double(1.0/n);
    	if(x > k)
    	{
    		fout << n; 
    		break;
    	}
    	n++;
    }
    return 0;
}
/*
描述 Description   
   　　已知：Sn= 1＋1／2＋1／3＋…＋1／n。显然对于任意一个整数K，当n足够大的时候，Sn大于K。 
　　现给出一个整数K（1<=k<=15），要求计算出一个最小的n；使得Sn＞K。 
   
 输入格式 Input Format  
   输入 k  
 输出格式 Output Format  
   输出 n 
   
 样例输入 Sample Input   
   1 
   
 样例输出 Sample Output   
   2 
   
 时间限制 Time Limitation  
   每个测试点1s 
 来源 Source  
   noip2002普及组第一题 
*/
