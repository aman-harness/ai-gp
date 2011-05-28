/*
from http://hi.baidu.com/xiszishu/blog/
*/
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
int n,m,f[2001][2001];
string s1,s2;
void dp()
{
     int i,j;
     memset(f,0,sizeof(f));
     for (i=1;i<=s1.length();i++)
     {
         for (j=1;j<=s2.length();j++)
         {
             if (s1[i-1]==s2[j-1])
             f[i][j]=f[i-1][j-1]+1;
             else
             f[i][j]=max(f[i-1][j],f[i][j-1]);
         }
     }
}

void readdata()
{
     int i,j;
     cin>>s1>>s2;
     dp();
     cout<<f[s1.length()][s2.length()]<<endl;
}

int main(int argc, char *argv[])
{
    readdata();
    return 0;
}
