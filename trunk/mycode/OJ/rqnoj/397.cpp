#include <iostream>
#include <cstring>
using namespace std;
void qs(int data[],int low,int high)//data[]����,low���λ,high���λ 
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
int main(){
    int i,j,k,n,t,a[100000];
    string all,word[26];
    cin>>word[0]>>all;
    n=word[0].size();
    t=1;
    j=1;
    if(word[0].find('z',0)==string::npos){
    t=1;
    for(j=1;j<26 && t==1;j++){
        word[j]=word[j-1];
        for(i=0;i<n;i++){
            word[j][i]+=1;
            if(word[j][i]=='z') t=0;
        }
    }
    }
    else t=1;
    k=j;
    t=1;
    if(word[0].find('a',0)==string::npos){
    word[j]=word[0];
    for(i=0;i<n;i++){
            word[j][i]-=1;
            if(word[j][i]=='a') t=0;
    }
    }
    else t=0;
    if(t==1){
    t=1;
    for(j=k+1;j<26 && t==1;j++){
        word[j]=word[j-1];
        for(i=0;i<n;i++){
            word[j][i]-=1;
            if(word[j][i]=='a') t=0;
        }
    }
    }
    k=j;
    t=0;
    for(i=0;i<k;i++){
        j=0;
        while((j=all.find(word[i],j))!=string::npos)a[t++]=j;
    }
    
    qs(a,0,t-1);cout<<'a';
    cout<<t-1<<endl;
    for(i=0;i<t;i++)
        cout<<a[i]<<endl;
    while(1);
    return 0;
}
