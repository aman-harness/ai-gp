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
̰���������ߡ�   
   
 ���� Description   
   ����һȺҪ������������ѣ���Ҫȷ��ÿ�����ͳ���������յ��Ķ���١�
����һ�������У�ÿ���˶�׼����һЩǮ�����������ЩǮ���ᱻƽ���ָ���Щ���յ�����������ˡ�
Ȼ�������κ�һȺ�����У���Щ�˽��ͳ��϶������(��������Ϊ�н϶������)����Щ����׼���˽϶��Ǯ��
����һȺ���ѣ� û���˵����᳤ֻ�� 14 �ַ�������ÿ���˽����������ϵ�Ǯ���ͽ��յ�����������˵��б�
��ȷ��ÿ�����յ��ı��ͳ���Ǯ�����Ŀ��
 
 �����ʽ Input Format  
   �� 1 ��: ����NP,2<= NP<=10  

�� 2�� NP+1 ��: 
��NP���������˵����֡�һ������һ��

��NP��2�����
�����NP��������������֯�ģ�
��һ���ǽ����ͳ������˵����֡�
�ڶ��а�����������:����һ����ԭ�е�Ǯ����Ŀ����0��2000�ķ�Χ����ڶ���NGi�ǽ��յ����������������˵ĸ��� ��� NGi �Ƿ����, ������ NGi ���г�����Ľ����ߵ����֣�һ������һ�С�

 �����ʽ Output Format  
   ��� NP ��
ÿ����һ�������ּ��Ͽո��ټ����յ��ı��ͳ���Ǯ�����Ŀ��
����ÿһ���ˣ������ֵĴ�ӡ˳��Ӧ�����������2��NP��1���������˳����ͬ�����е������Ǯ����������
ÿ���˰���ͬ��Ŀ��Ǯ��ÿλҪ��������ѣ����Ҿ����ܶ�������ܸ�����Ǯ���������Լ�������
 
 �������� Sample Input   
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
 
 ������� Sample Output   
   dave 302
laura 66
owen -359
vick 141
amr -150
 
 ʱ������ Time Limitation  
   ����1S
 
 ��Դ Source  
   from USACO
cdwind ���� 
 
*/
