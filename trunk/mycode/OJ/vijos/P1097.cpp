#include <iostream>
using namespace std;

void qs(int data[],int low,int high) //data[]数组,low最低位,high最高位 
{ 
     int i,pivot,j,k; 
     if(low<high) 
     { 
       pivot = data[low];
       i=low;
       j=high;//pivot存储支点值，初始化i,j 
     
       while(i<j) 
       { 
         while(i<j&&data[j]>=pivot) 
           j--;//低位小于高位且高位值>=支点 高位左移1位 
         if(i<j) 
           data[i++]=data[j];//低位右一位赋值为高位 
         while (i<j&&data[i]<=pivot) 
           i++; 
         if(i<j) data[j--]=data[i];//则高位左一位赋值为低位 12543
       } 
       data[i]=pivot;//高低位重合点赋值为支点 
       //此时i左全部小于支点，右全部大于支点 
       qs(data,low,i-1); 
       qs(data,i+1,high);//递归调用，分别排序左右两部分 
  
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
