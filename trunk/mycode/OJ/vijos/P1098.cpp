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
���� Description   
   ����Nλͬѧվ��һ�ţ�������ʦҪ�����е�(N-K)λͬѧ���У�ʹ��ʣ�µ�Kλͬѧ�ųɺϳ����Ρ� 
�����ϳ�������ָ������һ�ֶ��Σ���Kλͬѧ���������α��Ϊ1��2����K�����ǵ���߷ֱ�ΪT1��T2������TK��  �����ǵ��������T1<...<Ti>Ti+1>��>TK(1<=i<=K)�� 
������������ǣ���֪����Nλͬѧ����ߣ�����������Ҫ��λͬѧ���У�����ʹ��ʣ�µ�ͬѧ�ųɺϳ����Ρ� 
 
 �����ʽ Input Format  
   ����ĵ�һ����һ������N(2<=N<=100)����ʾͬѧ����������һ����n���������ÿո�ָ�����i������Ti(130<=Ti<=230)�ǵ�iλͬѧ�����(����)�� 
 
 �����ʽ Output Format  
   �������һ�У���һ��ֻ����һ������������������Ҫ��λͬѧ���С� 
 
 �������� Sample Input   
   8
186 186 150 200 160 130 197 220
 ������� Sample Output   
   4 
 ʱ������ Time Limitation  
   ÿ�����Ե�1s
   
 ��Դ Source  
   NOIp 2004 
*/

