#include <iostream>
#include <cstring>
using namespace std;
int people[11][12]={0},money[11]={0},n;
string name[11];
int Search(string a){
    int i;
    for(i=1;i<=n;i++)
        if(a==name[i])
            return i;
    return -1;
}

int main(){
    int i,j,no,f;
    string s;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>name[i];
    for(i=1;i<=n;i++){
        cin>>s;
        no=Search(s);
        cin>>people[no][11]>>people[no][12];
        for(j=1;j<=people[no][12];j++)
        {
            cin>>s;
            people[no][Search(s)]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(people[i][12]!=0){ 
        f=people[i][11]/people[i][12];
        for(j=1;j<=10;j++)
            if(people[i][j]==1)
                money[j]+=f;
        money[i]+=people[i][11]%people[i][12]; 
        money[i]-=people[i][11];
        }
    }
    for(i=1;i<=n;i++){
        cout<<name[i]<<' '<<money[i]<<endl;
    }
    return 0;
}
/* From cdwind 
贪婪的送礼者　   
   
 描述 Description   
   对于一群要互送礼物的朋友，你要确定每个人送出的礼物比收到的多多少。
在这一个问题中，每个人都准备了一些钱来送礼物，而这些钱将会被平均分给那些将收到他的礼物的人。
然而，在任何一群朋友中，有些人将送出较多的礼物(可能是因为有较多的朋友)，有些人有准备了较多的钱。
给出一群朋友， 没有人的名字会长于 14 字符，给出每个人将花在送礼上的钱，和将收到他的礼物的人的列表，
请确定每个人收到的比送出的钱多的数目。
 
 输入格式 Input Format  
   第 1 行: 人数NP,2<= NP<=10  

第 2到 NP+1 行: 
这NP个在组里人的名字　一个名字一行

第NP＋2到最后：
这里的NP段内容是这样组织的：
第一行是将会送出礼物人的名字。
第二行包含二个数字:　第一个是原有的钱的数目（在0到2000的范围里），第二个NGi是将收到这个送礼者礼物的人的个数 如果 NGi 是非零的, 在下面 NGi 行列出礼物的接受者的名字，一个名字一行。

 输出格式 Output Format  
   输出 NP 行
每行是一个的名字加上空格再加上收到的比送出的钱多的数目。
对于每一个人，他名字的打印顺序应和他在输入的2到NP＋1行中输入的顺序相同。所有的送礼的钱都是整数。
每个人把相同数目的钱给每位要送礼的朋友，而且尽可能多给，不能给出的钱被送礼者自己保留。
 
 样例输入 Sample Input   
   5
dave
laura
owen
vick
amr
dave
200 3
laura
owen
vick
owen
500 1
dave
amr
150 2
vick
owen
laura
0 2
amr
vick
vick
0 0
 
 样例输出 Sample Output   
   dave 302
laura 66
owen -359
vick 141
amr -150
 
 时间限制 Time Limitation  
   各点1S
 
 来源 Source  
   from USACO
cdwind 整理 
 
*/
