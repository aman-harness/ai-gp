#include <iostream>
using namespace std;
bool ch[112]={0};
int main(){
    int i,j,k,a,b,c,all=0,n,s,Num[10]={6,2,5,5,4,5,6,3,7,6};
    cin>>n;
    n-=4;
    if(n<=8){
        cout<<0;
        return 0;
    }
    for(i=0;i<=1000;i++){
        for(j=0;j<=1000;j++){
            if(i==j && ch[i]==1 ) continue;
            k=i+j;
            s=4;
            a=i;b=j;c=k;
            s=Num[a%10];
            while(a>9){a/=10; s+=Num[a%10];}
            s+=Num[b%10];
            while(b>9){b/=10; s+=Num[b%10];}
            s+=Num[c%10];
            while(c>9){c/=10; s+=Num[c%10];}
            if(s==n){
                all+=1;
                if(i==j) ch[i]=1;
            }
        }
    }
    cout<<all;
    return 0;
} 
/*
 From there 
������ʽ�� ȫ����������Ϣѧ����ƥ�˷������� (NOIp) ����ԭ��  
   
 ���� Description   
   ����n�������������ƴ�����ٸ����硰A+B=C���ĵ�ʽ����ʽ�е�A��B��C���û���ƴ�������������������㣬�����λ������0�����û���ƴ����0-9��ƴ����ͼ��ʾ��

ע�⣺
1. �Ӻ���ȺŸ�����Ҫ��������
2. ���A��B����A+B=C��B+A=C��Ϊ��ͬ�ĵ�ʽ��A��B��C>=0��
3. n����������ȫ������

 �����ʽ Input Format  
   �����ļ�matches.in��һ�У���һ������n��n<=24����    
 �����ʽ Output Format  
   ����ļ�matches.out��һ�У���ʾ��ƴ�ɵĲ�ͬ��ʽ����Ŀ��
 
 �������� Sample Input   
   Input 1:
14
Input 2:
18  
 ������� Sample Output   
   Output 1:
2
Output 2:
9
 ʱ������ Time Limitation  
   1s
 ע�� Hint  
   �������������1���͡�
2����ʽΪ0+1=1��1+0=1��
�������������2���͡�
9����ʽΪ��
0+4=4
0+11=11
1+10=11
2+2=4
2+7=9
4+0=4
7+2=9
10+1=11
11+0=11 
 ��Դ Source  
   NOIp2008 �����ڶ��� 
*/
