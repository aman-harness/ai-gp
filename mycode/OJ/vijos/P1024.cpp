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
        //颠倒
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
        //保存 
        memset(q,0,j*4);
        i=0;
        while(a>0){
            q[i++]=a%10;
            a/=10;
        }
        //减法 
        quickSort(q,0,j-1);
        for(i=0;i<j;i++){
            a+=q[j-i-1];
            a*=10;
        }
        a/=10;
        //cout<<a<<endl;
        //各位排序 
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
卡布列克圆舞曲　   
   
 描述 Description   
   　　卡布列克是一位数学家，他在研究数字时发现：任意一个不是用完全相同数字组成的四位数，如果对它们的每位数字重新排序，组成一个较大的数和一个较小的数，然后用较大数减去较小数，差不够四位数时补零，类推下去，最后将变成一个固定的数：6174，这就是卡布列克常数。
　　例如：4321-1234=3087
　　　　 8730-378=8352
　　　　 8532-2358=6174
　　　　 7641-1467=6147
　　如果K位数也照此办理，它们不是变成一个数，而是在几个数字之间形成循环，称作卡布列克圆舞曲。例如对于五位数54321：
　　54321-12345=41976
　　97641-14679=82962
　　98622-22689=75933
　　97533-33579=63954
　　96543-34569=61974
　　97641-14679=82962
　　我们把82962 75933 63954 61974称作循环节，即卡布列克圆舞曲。
 
 输入格式 Input Format  
   文件包含若干行，每行为一个待求“卡布列克圆舞曲”的起始整数（小于maxlongint）
 
 输出格式 Output Format  
   每行为对应整数的循环节，数据之间用空格隔开。
 
 样例输入 Sample Input   
   4321
54321
 
 样例输出 Sample Output   
   6174
82962 75933 63954 61974
 
 时间限制 Time Limitation  
   各个测试点1s
 
 来源 Source  
   Xiaomengxian
高一的第二次考试题
*/
