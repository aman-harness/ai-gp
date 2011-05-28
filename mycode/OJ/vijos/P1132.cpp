#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("P1132.in");
ofstream fout("P1132.out");

string qfind(string a,string b)
{
	int f,length;
	length = a.size();
	if(length == 1)
		return a;
	char t = b[length-1];
	f = a.find(t);
	return a[f] + ((f>0)?qfind(a.substr(0,f),b.substr(0,f)):"") + ((length-f>1)?qfind(a.substr(f+1,length-f-1),b.substr(f,length-f-1)):"");
}


int main(){
	int i,j;
	string a,b;
	fin >> a >> b;
	fout << qfind(a,b);
    return 0;
}
//BADC BDCA
/*描述 Description   
   　　给出一棵二叉树的中序与后序排列。求出它的先序排列。(约定树结点用不同的大写字母表示，长度≤8)。
   　　
 输入格式 Input Format  
   第一行为二叉树的中序序列 
第二行为二叉树的后序序列     
 输出格式 Output Format  
   一行，为二叉树的先序序列 
      
 样例输入 Sample Input   
   BADC 左中右
   BDCA 左右中 
      
 样例输出 Sample Output   
   ABCD  中左右
 时间限制 Time Limitation  
   每个测试点1s 
*/
