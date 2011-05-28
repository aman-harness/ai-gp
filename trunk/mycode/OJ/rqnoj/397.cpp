#include <iostream>
#include <cstring>
using namespace std;
void qs(int data[],int low,int high)//data[]数组,low最低位,high最高位 
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
