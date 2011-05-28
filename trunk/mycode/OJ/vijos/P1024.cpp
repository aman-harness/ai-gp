#include <iostream>
#include <cmath>
using namespace std;
void quickSort(int* arr,int startPos, int endPos) 
{ 
int i,j; 
int ch; 
ch=arr[startPos]; 
i=startPos; 
j=endPos; 
while(i<j) 
{ 
while(arr[j]>=ch && i<j)--j; 
arr[i]=arr[j]; 
while(arr[i]<=ch && i<j)++i; 
arr[j]=arr[i]; 
} 
arr[i]=ch; 
if(i-1>startPos) quickSort(arr,startPos,i-1); 
if(endPos>i+1) quickSort(arr,i+1,endPos); 
}

int main(){
    int q[12];
    long long a,b,i,j,s,Num[1000],k,t,tc,l,OP[1000],opNum=0;
    while(cin>>a){
       k=1;
       t=1;
       while(t){
        b=0;
        j=0;
        tc=a;
        while(tc>0){
            b+=tc%10;
            j++;
            b*=10;
            tc/=10;
        }
        b/=10;
        if(a>b)a=a-b;
        else a=b-a;
        //�ߵ�
        //cout<<a<<endl;
        for(i=1;i<k;i++)
           if(a==Num[i]){
               for(l=i;l<k;l++)
                   OP[opNum++]=Num[l];
               OP[opNum++]=-1;
               t=0;
               break;
           }
        Num[k++]=a;
        //���� 
        memset(q,0,j*4);
        i=0;
        while(a>0){
            q[i++]=a%10;
            a/=10;
        }
        //���� 
        quickSort(q,0,j-1);
        for(i=0;i<j;i++){
            a+=q[j-i-1];
            a*=10;
        }
        a/=10;
        //cout<<a<<endl;
        //��λ���� 
       }
    }
    for(i=0;i<opNum;i++){
        if(OP[i]==-1) cout<<endl;
        else cout<<OP[i]<<' ';
    }
    while(1);
    return 0;
}
        
    
    
/*   
 From xiaomengxian 
�����п�Բ������   
   
 ���� Description   
   ���������п���һλ��ѧ�ң������о�����ʱ���֣�����һ����������ȫ��ͬ������ɵ���λ������������ǵ�ÿλ���������������һ���ϴ������һ����С������Ȼ���ýϴ�����ȥ��С���������λ��ʱ���㣬������ȥ����󽫱��һ���̶�������6174������ǿ����п˳�����
�������磺4321-1234=3087
�������� 8730-378=8352
�������� 8532-2358=6174
�������� 7641-1467=6147
�������Kλ��Ҳ�մ˰������ǲ��Ǳ��һ�����������ڼ�������֮���γ�ѭ�������������п�Բ���������������λ��54321��
����54321-12345=41976
����97641-14679=82962
����98622-22689=75933
����97533-33579=63954
����96543-34569=61974
����97641-14679=82962
�������ǰ�82962 75933 63954 61974����ѭ���ڣ��������п�Բ������
 
 �����ʽ Input Format  
   �ļ����������У�ÿ��Ϊһ�����󡰿����п�Բ����������ʼ������С��maxlongint��
 
 �����ʽ Output Format  
   ÿ��Ϊ��Ӧ������ѭ���ڣ�����֮���ÿո������
 
 �������� Sample Input   
   4321
54321
 
 ������� Sample Output   
   6174
82962 75933 63954 61974
 
 ʱ������ Time Limitation  
   �������Ե�1s
 
 ��Դ Source  
   Xiaomengxian
��һ�ĵڶ��ο�����
*/
