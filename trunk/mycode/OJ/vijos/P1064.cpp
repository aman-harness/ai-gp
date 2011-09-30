#include <iostream>
#include <cstring>
using namespace std;
bool Num[10][7]={{1,1,1,0,1,1,1}, //0
                 {0,0,1,0,0,1,0}, //1
                 {1,0,1,1,1,0,1}, //2
                 {1,0,1,1,0,1,1}, //3
                 {0,1,1,1,0,1,0}, //4
                 {1,1,0,1,0,1,1}, //5
                 {1,1,0,1,1,1,1}, //6
                 {1,0,1,0,0,1,0}, //7
                 {1,1,1,1,1,1,1}, //8
                 {1,1,1,1,0,1,1}}; //9
int h;
string Line;

int main(){
    int i,j,k,s;
    cin>>h>>Line;
    for(i=0;i<Line.size();i++){
        s=Line[i]-'0';
        cout<<' ';
        if(Num[s][0] == 1)
            for(k=1;k<=h;k++)cout<<'-';
        else
            for(k=1;k<=h;k++)cout<<' ';
        cout<<' ';
        if(i!=Line.size()-1)
        cout<<' ';
    }
    cout<<endl;
    for(j=1;j<=h;j++){
        for(i=0;i<Line.size();i++){
            s=Line[i]-'0';
            if(Num[s][1] == 1) cout<<'|';
            else cout<<' ';
            for(k=1;k<=h;k++)cout<<' ';
            if(Num[s][2] == 1) cout<<'|';
            else cout<<' ';
            if(i!=Line.size()-1)
            cout<<' ';
        }
        cout<<endl;
    }
    for(i=0;i<Line.size();i++){
        s=Line[i]-'0';
        cout<<' ';
        if(Num[s][3] == 1)
            for(k=1;k<=h;k++)cout<<'-';
        else
            for(k=1;k<=h;k++)cout<<' ';
        cout<<' ';
        if(i!=Line.size()-1)
        cout<<' ';
    }
    cout<<endl;
    for(j=1;j<=h;j++){
        for(i=0;i<Line.size();i++){
            s=Line[i]-'0';
            if(Num[s][4] == 1) cout<<'|';
            else cout<<' ';
            for(k=1;k<=h;k++)cout<<' ';
            if(Num[s][5] == 1) cout<<'|';
            else cout<<' ';
            if(i!=Line.size()-1)
            cout<<' ';
        }
        cout<<endl;
    }
    for(i=0;i<Line.size();i++){
        s=Line[i]-'0';
        cout<<' ';
        if(Num[s][6] == 1)
            for(k=1;k<=h;k++)cout<<'-';
        else
            for(k=1;k<=h;k++)cout<<' ';
        cout<<' ';
        if(i!=Line.size()-1)
        cout<<' ';
    }
    while(1);
    return 0;
}

/* 
ӭ�����֮�����赸��ӭ����� ϵ�С�   
 ���� Background  
   ����HNSDFZ��ͬѧ��Ϊ����ף���ڣ�׼������һ����ᡣ  
  
 ���� Description   
   ������Խ��Խ����������ʱ��������ע��ĸ���Ĳ��Ǹ���������ˣ����Ǽ�������С�
����Ϊ�����ÿ��ĵ���ʱ��ͬѧ�Ǿ����ų������������赸��������˼�����������һ���ų����ɸ����� -___-||||  ��Ϊ���µ��ǣ�ÿ���˶���ſ�ڵ��ϣ���֤������
�������ڸ������ּ���Ҫ��ڳ��Ĵ�С�������̣�ģ��ͬѧ�ǵ�������̬��
   
 �����ʽ Input Format  
   ������һ��Ϊk��k��ʾҪ�ڳ����ֵĴ�С��  
�����ڶ���Ϊȫ����������ɵ��ַ�������Ҫ�ڳ��ļ������֡�
 
 �����ʽ Output Format  
   ��������ĿҪ������� 
 �������� Sample Input   
   2
1234567890
 ������� Sample Output 
       ---   ---         ---   ---   ---   ---   ---   ---
    |     |     | |   | |     |         | |   | |   | |   |
    |     |     | |   | |     |         | |   | |   | |   |
    |     |     | |   | |     |         | |   | |   | |   |
       ---   ---   ---   ---   ---         ---   ---
    | |         |     |     | |   |     | |   |     | |   |
    | |         |     |     | |   |     | |   |     | |   |
    | |         |     |     | |   |     | |   |     | |   |
       ---   ---         ---   ---         ---   ---   ---

       ---   ---         ---   ---   ---   ---   ---   --- 
    |     |     | |   | |     |         | |   | |   | |   |
    |     |     | |   | |     |         | |   | |   | |   |
    |     |     | |   | |     |         | |   | |   | |   |
       ---   ---   ---   ---   ---         ---   ---       
    | |         |     |     | |   |     | |   |     | |   |
    | |         |     |     | |   |     | |   |     | |   |
    | |         |     |     | |   |     | |   |     | |   |
       ---   ---         ---   ---         ---   ---   --- 
 ʱ������ Time Limitation  
   �������Ե�1s
   
 ע�� Hint  
ÿ������֮ǰ��1���ո���������ȫ�����롣
k<=30,s�ĳ��Ȳ�����255
������ֱ���������Ҫ���档
������ڴ�С��k�����ʣ������������ص�k=3ʱ����������������ı�׼������������⡣ 
*/