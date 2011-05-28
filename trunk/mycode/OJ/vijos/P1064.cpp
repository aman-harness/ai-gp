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
迎春舞会之数字舞蹈　迎春舞会 系列　   
 背景 Background  
   　　HNSDFZ的同学们为了庆祝春节，准备排练一场舞会。  
  
 描述 Description   
   　　在越来越讲究合作的时代，人们注意的更多的不是个人物的舞姿，而是集体的排列。
　　为了配合每年的倒计时，同学们决定排出——“数字舞蹈”。顾名思义就是所有人一起排成若干个数字 -___-||||  更为创新的是，每个人都是趴在地上，保证横竖。
　　现在给出数字及其要求摆出的大小，请你编程，模拟同学们的优美姿态。
   
 输入格式 Input Format  
   　　第一行为k。k表示要摆出数字的大小。  
　　第二行为全部由数字组成的字符串，即要摆出的几个数字。
 
 输出格式 Output Format  
   　　按题目要求输出。 
 样例输入 Sample Input   
   2
1234567890
 样例输出 Sample Output 
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
 时间限制 Time Limitation  
   各个测试点1s
   
 注释 Hint  
每个数字之前有1个空格，所有数字全部对齐。
k<=30,s的长度不超过255
建议大家直接输出，不要保存。
如果对于大小和k有疑问，请点击这里下载当k=3时对于上述样例输入的标准输出，自行理解。 
*/
