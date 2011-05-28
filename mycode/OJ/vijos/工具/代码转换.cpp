#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int i=0;
    string fileName;
    cout<<"请输入转换文件名："
    cin<<fileName;
    ifstream fin(fileName+".cpp");
    ofstream fout(fileName+"New.cpp");
    string fileR[10000];
    while(fin){
        fin.getline(fileR[i++]);
        if(fileR[i-1].find("#include <fstream>",0,fileR[i-1].szie()-1))
        fileR[i-1].
        
