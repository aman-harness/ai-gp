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
/*笨小猴　 全国青少年信息学奥林匹克分区联赛 (NOIp) 竞赛原题 
 背景 Background  
   笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！  
 描述 Description   
   这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。 
 输入格式 Input Format  
   输入只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。  
   
 输出格式 Output Format  
   输出共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky
    Word”，否则输出“No Answer”； 
第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。

 样例输入 Sample Input   
   【样例1】
error
【样例2】
olympic 
 样例输出 Sample Output   
   【样例1】
Lucky Word
2
【样例2】
No Answer
0 
 时间限制 Time Limitation  
   各个测试点1s 
   
 注释 Hint  
   【输入输出样例1解释】
单词error中出现最多的字母r出现了3次，出现次数最少的字母出现了1次，3-1=2，2是质数。
【输入输出样例2解释】
单词olympic中出现最多的字母i出现了2次，出现次数最少的字母出现了1次，2-1=1，1不是质数。  
 来源 Source  
   NOIp2008 提高组第一题 
*/
