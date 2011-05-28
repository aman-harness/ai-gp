#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("P1132.in");
ofstream fout("P1132.out");

string qfind(string a,string b)
{
	int f,length;
	length = a.size();
	if(length == 1)
		return a;
	char t = b[length-1];
	f = a.find(t);
	return a[f] + ((f>0)?qfind(a.substr(0,f),b.substr(0,f)):"") + ((length-f>1)?qfind(a.substr(f+1,length-f-1),b.substr(f,length-f-1)):"");
}


int main(){
	int i,j;
	string a,b;
	fin >> a >> b;
	fout << qfind(a,b);
    return 0;
}
//BADC BDCA
/*���� Description   
   ��������һ�ö�������������������С���������������С�(Լ��������ò�ͬ�Ĵ�д��ĸ��ʾ�����ȡ�8)��
   ����
 �����ʽ Input Format  
   ��һ��Ϊ���������������� 
�ڶ���Ϊ�������ĺ�������     
 �����ʽ Output Format  
   һ�У�Ϊ���������������� 
      
 �������� Sample Input   
   BADC ������
   BDCA ������ 
      
 ������� Sample Output   
   ABCD  ������
 ʱ������ Time Limitation  
   ÿ�����Ե�1s 
*/
