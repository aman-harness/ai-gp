#include <fstream>
using namespace std;
ifstream fin("P1098.in");
ofstream fout("P1098.out");
int n,x,a[200]={0},b[200]={0},maxn,s,maxs;
int main(){
	int i,j;
	fin >>n;
	for(i=1;i<=n;i++)
		fin >> a[i];
	maxs = 0;
	for(x=1;x<=n;x++)
	{
		memset(b,0,sizeof(b));
		s = 1;
		b[1] = 1;
		maxn = 0;
		for(i=1;i<x;i++)
		{
			b[i] = 0;
			if(a[i] < a[x])
			{
				b[i] = 1;
				for(j=1;j<i;j++)
					if(a[j]<a[i] && b[j]+1>b[i])
						b[i] = b[j]+1;
			}
		}
		for(i=1;i<x;i++)
			if(b[i] > maxn)
				maxn = b[i];
		s += maxn;
		b[n] = 1;
		maxn = 0;
		for(i=n;i>x;i--)
		{
			b[i] = 0;
			if(a[i] < a[x])
			{
				b[i] = 1;
				for(j=n;j>i;j--)
					if(a[j]<a[i] && b[j]+1>b[i])
						b[i] = b[j]+1;
			}
		}
		for(i=n;i>x;i--)
			if(b[i] > maxn)
				maxn = b[i];
		s += maxn;
		if(s > maxs)
			maxs = s;
	}
	fout << maxs;
    return 0;
}
/*
描述 Description   
   　　N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。 
　　合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，  则他们的身高满足T1<...<Ti>Ti+1>…>TK(1<=i<=K)。 
　　你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。 
 
 输入格式 Input Format  
   输入的第一行是一个整数N(2<=N<=100)，表示同学的总数。第一行有n个整数，用空格分隔，第i个整数Ti(130<=Ti<=230)是第i位同学的身高(厘米)。 
 
 输出格式 Output Format  
   输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。 
 
 样例输入 Sample Input   
   8
186 186 150 200 160 130 197 220
 样例输出 Sample Output   
   4 
 时间限制 Time Limitation  
   每个测试点1s
   
 来源 Source  
   NOIp 2004 
*/

