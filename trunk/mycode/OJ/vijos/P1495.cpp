#include <iostream>
#include <cmath>
using namespace std;
int main(){
    char word[101]="";
    int dict[26]={0},max=0,min=101,i,j,t=1;
    cin>>word;
    for(i=0;i<strlen(word);i++)
        dict[word[i]-'a']++;
    for(i=0;i<26;i++){
        if(dict[i]>max)
           max=dict[i];
        if(dict[i]<min && dict[i]!=0)
           min=dict[i];
    }
    j=max-min;
    if(j<2)t=0;
    else if(j==2)t=1;
    else
    for(i=2;i<=sqrt(j);i++)
        if(j%i==0)
            t=0;
    
    if(t==0)
    cout<<"No Answer"<<endl<<0;
    else
    cout<<"Lucky Word"<<endl<<j;
    return 0;
}
/*��С� ȫ����������Ϣѧ����ƥ�˷������� (NOIp) ����ԭ�� 
 ���� Background  
   ��С��Ĵʻ�����С������ÿ����Ӣ��ѡ�����ʱ�򶼺�ͷ�ۡ��������ҵ���һ�ַ�����������֤���������ַ���ȥѡ��ѡ���ʱ��ѡ�Եļ��ʷǳ���  
 ���� Description   
   ���ַ����ľ����������£�����maxn�ǵ����г��ִ���������ĸ�ĳ��ִ�����minn�ǵ����г��ִ������ٵ���ĸ�ĳ��ִ��������maxn-minn��һ����������ô��С�����Ϊ���Ǹ�Lucky Word�������ĵ��ʺܿ��ܾ�����ȷ�Ĵ𰸡� 
 �����ʽ Input Format  
   ����ֻ��һ�У���һ�����ʣ�����ֻ���ܳ���Сд��ĸ�����ҳ���С��100��  
   
 �����ʽ Output Format  
   ��������У���һ����һ���ַ�������������ĵĵ�����Lucky Word����ô�����Lucky
    Word�������������No Answer���� 
�ڶ�����һ��������������뵥����Lucky Word�����maxn-minn��ֵ���������0��

 �������� Sample Input   
   ������1��
error
������2��
olympic 
 ������� Sample Output   
   ������1��
Lucky Word
2
������2��
No Answer
0 
 ʱ������ Time Limitation  
   �������Ե�1s 
   
 ע�� Hint  
   �������������1���͡�
����error�г���������ĸr������3�Σ����ִ������ٵ���ĸ������1�Σ�3-1=2��2��������
�������������2���͡�
����olympic�г���������ĸi������2�Σ����ִ������ٵ���ĸ������1�Σ�2-1=1��1����������  
 ��Դ Source  
   NOIp2008 ������һ�� 
*/
