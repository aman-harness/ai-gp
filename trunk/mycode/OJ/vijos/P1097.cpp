#include <iostream>
using namespace std;

void qs(int data[],int low,int high) //data[]����,low���λ,high���λ 
{ 
     int i,pivot,j,k; 
     if(low<high) 
     { 
       pivot = data[low];
       i=low;
       j=high;//pivot�洢֧��ֵ����ʼ��i,j 
     
       while(i<j) 
       { 
         while(i<j&&data[j]>=pivot) 
           j--;//��λС�ڸ�λ�Ҹ�λֵ>=֧�� ��λ����1λ 
         if(i<j) 
           data[i++]=data[j];//��λ��һλ��ֵΪ��λ 
         while (i<j&&data[i]<=pivot) 
           i++; 
         if(i<j) data[j--]=data[i];//���λ��һλ��ֵΪ��λ 12543
       } 
       data[i]=pivot;//�ߵ�λ�غϵ㸳ֵΪ֧�� 
       //��ʱi��ȫ��С��֧�㣬��ȫ������֧�� 
       qs(data,low,i-1); 
       qs(data,i+1,high);//�ݹ���ã��ֱ��������������� 
  
     } 
} 

int n,a[10000]={0}; 

int main(){
    int i,j;
    unsigned long long s,k;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    qs(a,0,n-1);
    s=k=0;
    for(i=0;i<n;i++)
