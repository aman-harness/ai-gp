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
���� Description   
   ������֪��Sn= 1��1��2��1��3������1��n����Ȼ��������һ������K����n�㹻���ʱ��Sn����K�� 
�����ָ���һ������K��1<=k<=15����Ҫ������һ����С��n��ʹ��Sn��K�� 
   
 �����ʽ Input Format  
   ���� k  
 �����ʽ Output Format  
   ��� n 
   
 �������� Sample Input   
   1 
   
 ������� Sample Output   
   2 
   
 ʱ������ Time Limitation  
   ÿ�����Ե�1s 
 ��Դ Source  
   noip2002�ռ����һ�� 
*/
