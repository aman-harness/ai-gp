/*
ID: interne4
PROG: cryptcow
LANG: C++
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int hashSize=131071;//��ϣ���С
const int strSize=75+2;
const string dest="Begin the Escape execution at the Break of Dawn";//Ŀ���ַ���
bool used[hashSize];//����
string code;//����
int ans;//��
int cnt;//����
int Encode(const string&str){//ELFhash����
 unsigned long hash=0,tmp;
 int len=str.length(),i;
 for(i=0;i<len;i++){
  hash=(hash<<4)+str[i];
  tmp=hash&0xf0000000l;
  if(tmp){
   hash^=tmp>>24;
  }
  hash&=~tmp;
 }
 return hash;
}
bool AdvancedCut(const string&str){//Ԥ��֦
 int i,c,o,w,len=str.length();
 if(len<47||len%3!=2)//����Ϊ47+3*k
  return false;
 c=o=w=0;
 for(i=0;i<len;i++)//C,O,W�ĸ���������ͬ
  if(str[i]=='C')
   c++;
  else if(str[i]=='O')
   o++;
  else if(str[i]=='W')
   w++;
  cnt=c;
  return c==o&&o==w;
}
bool DFSCut(const string&str){//��ȥǰ׺�����ϵ�
 int i=0,j,len=str.length();
 while(i<len){
  j=i+1;
  if(str[i]!='C'&&str[i]!='O'&&str[i]!='W'){
   while(j<len&&str[j]!='C'&&str[j]!='O'&&str[j]!='W')
    j++;
   if(dest.find(str.substr(i,j-i))==string::npos)//����޷��ҵ�
    return false;
  }
  i=j;
 }
 return true;
}
string Update(const string&str,int c,int o,int w){//����str,ɾ��C,O,W
 static char buffer[80];//һ��Ҫ��̬��
 int cnt,i,len=str.length();
 for(i=cnt=0;i<c;i++)
  buffer[cnt++]=str[i];
 for(i=o+1;i<w;i++)
  buffer[cnt++]=str[i];
 for(i=c+1;i<o;i++)
  buffer[cnt++]=str[i];
 for(i=w+1;i<len;i++)
  buffer[cnt++]=str[i];
 buffer[cnt++]=0;
 return string(buffer);
}
void DFS(const string&str){
  printf("%s\n", str.c_str());
 if(str==dest){//�ҵ��Ļ�����¼
  printf("1 %d\n",cnt);
  exit(0);
 }
 int hash=Encode(str)%hashSize;
 if(used[hash])return;
 used[hash]=true;
 if(!DFSCut(str))return;
 int len=str.length(),c,o,w;
 for(o=1;o<len-1;o++)
  if(str[o]=='O')
   for(c=0;c<o;c++)
    if(str[c]=='C')
     for(w=len-1;w>o;w--)
      if(str[w]=='W')
       DFS(Update(str,c,o,w));
}
void Read(){//��������
 getline(cin,code);
}
void Solve(){//�������
 if(!AdvancedCut(code))
  printf("0 0\n");
 else {
  DFS(code);
   printf("0 0\n");
 }
}
void Read_Solve(){
 Read();
 Solve();
}
int main(){
 //freopen("C:\\Users\\loveKid\\Desktop\\data.txt","r",stdin);
 //freopen("C:\\Users\\loveKid\\Desktop\\dataOut.txt","w",stdout);
 freopen("cryptcow.in","r",stdin);
 freopen("cryptcow.out","w",stdout);
 Read_Solve();
 return 0;
}
