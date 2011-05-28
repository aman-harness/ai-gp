#include <iostream>
#include <cstring>
using namespace std;

int n,o,s,TrieN=1;
string word[1000],TrieStr[1000],dictionary,str;
int Trie[3000][26]={0};
int BTrie[3000]={0};
char t;
void reseach(int s){
    int i;
    if(BTrie[s]>0){
        for(i=1;i<=BTrie[s];i++)
            cout<<TrieStr[s]<<endl;
        return ;
    }
    if(s>=TrieN)return ;
    for(i=0;i<26;i++)
        if(Trie[s][i]!=0)
            reseach(Trie[s][i]);
    return ;
}        
int main(){
    int i,j;
    cin>>dictionary;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>word[i];
    cin>>o;
    if(o==-1)
    for(i=0;i<13;i++){
        t=dictionary[i];
        dictionary[i]=dictionary[26-i-1];
        dictionary[26-i-1]=t;
    }
    TrieStr[0]="";
    for(i=0;i<n;i++){
        j=0;
        s=0;
        while(j<word[i].size()){
            o=dictionary.find(word[i][j],0);
            if(Trie[s][o]==0){
                 TrieStr[TrieN]=TrieStr[s]+word[i][j];
                 Trie[s][o]=TrieN++;
            }
            s=Trie[s][o];
            j++;
        }
        BTrie[s]++;
    }
    reseach(0);
    return 0;
}

/* 描述 Description   
   笨笨有一些单词，他想要把这些单词按一定顺序排序。
现在笨笨有N(N<=1000)个单词，他想要你按笨笨的字典序把这些单词顺序或逆序排列好来。
输入笨笨的字典序以及他所要排序的单词和他所要的排序方式（顺序或逆序，顺序用1表示，逆序用0表示）。
请你把排好的单词输出,每个单词长度不超过255个字符,中间没有空格。 

 输入格式 Input Format  
   第一行，一个长度为26的字母不重复的字符串，表示笨笨的字典序（26个字母全齐）。
第二行一个数N。
接下来N行，每行一个单词。
最后一行是笨笨所想要的排序方式。  
   
 输出格式 Output Format  
   输出共N行，表示排好序的单词。输出每行一个单词。 
   
 样例输入 Sample Input   
abcdefghijklmnopqrstuvwxyz
2
big
small
1
 样例输出 Sample Output   
big
small
   
 时间限制 Time Limitation  
   1s
 注释 Hint  
   是笨笨的字典序，不是一般的字典序哦。
输入输出中的字母均为小写字母。
注：顺序逆序就是说把它们按一定的顺序排列好，而不是要你把单词反过来。
如（按字典序）：
顺序为：
aa
ba
ca
逆序为
ca
ba
aa 
 来源 Source  
   笨笨原创。 
*/
