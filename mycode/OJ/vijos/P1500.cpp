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

/* ���� Description   
   ������һЩ���ʣ�����Ҫ����Щ���ʰ�һ��˳������
���ڱ�����N(N<=1000)�����ʣ�����Ҫ�㰴�������ֵ������Щ����˳����������к�����
���뱿�����ֵ����Լ�����Ҫ����ĵ��ʺ�����Ҫ������ʽ��˳�������˳����1��ʾ��������0��ʾ����
������źõĵ������,ÿ�����ʳ��Ȳ�����255���ַ�,�м�û�пո� 

 �����ʽ Input Format  
   ��һ�У�һ������Ϊ26����ĸ���ظ����ַ�������ʾ�������ֵ���26����ĸȫ�룩��
�ڶ���һ����N��
������N�У�ÿ��һ�����ʡ�
���һ���Ǳ�������Ҫ������ʽ��  
   
 �����ʽ Output Format  
   �����N�У���ʾ�ź���ĵ��ʡ����ÿ��һ�����ʡ� 
   
 �������� Sample Input   
abcdefghijklmnopqrstuvwxyz
2
big
small
1
 ������� Sample Output   
big
small
   
 ʱ������ Time Limitation  
   1s
 ע�� Hint  
   �Ǳ������ֵ��򣬲���һ����ֵ���Ŷ��
��������е���ĸ��ΪСд��ĸ��
ע��˳���������˵�����ǰ�һ����˳�����кã�������Ҫ��ѵ��ʷ�������
�磨���ֵ��򣩣�
˳��Ϊ��
aa
ba
ca
����Ϊ
ca
ba
aa 
 ��Դ Source  
   ����ԭ���� 
*/
