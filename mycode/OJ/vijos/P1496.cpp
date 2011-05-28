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
火柴棒等式　 全国青少年信息学奥林匹克分区联赛 (NOIp) 竞赛原题  
   
 描述 Description   
   给你n根火柴棍，你可以拼出多少个形如“A+B=C”的等式？等式中的A、B、C是用火柴棍拼出的整数（若该数非零，则最高位不能是0）。用火柴棍拼数字0-9的拼法如图所示：

注意：
1. 加号与等号各自需要两根火柴棍
2. 如果A≠B，则A+B=C与B+A=C视为不同的等式（A、B、C>=0）
3. n根火柴棍必须全部用上

 输入格式 Input Format  
   输入文件matches.in共一行，有一个整数n（n<=24）。    
 输出格式 Output Format  
   输出文件matches.out共一行，表示能拼成的不同等式的数目。
 
 样例输入 Sample Input   
   Input 1:
14
Input 2:
18  
 样例输出 Sample Output   
   Output 1:
2
Output 2:
9
 时间限制 Time Limitation  
   1s
 注释 Hint  
   【输入输出样例1解释】
2个等式为0+1=1和1+0=1。
【输入输出样例2解释】
9个等式为：
0+4=4
0+11=11
1+10=11
2+2=4
2+7=9
4+0=4
7+2=9
10+1=11
11+0=11 
 来源 Source  
   NOIp2008 提高组第二题 
*/
