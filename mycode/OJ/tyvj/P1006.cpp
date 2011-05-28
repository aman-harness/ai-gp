#include<iostream>
#include<string>
using namespace std;

int main()
{
	long n;
	string s;
	
	cin>>s;
	
	n=0;
	for(long i=0,j=0;i<11;i++)
		if(i!=1&&i!=5)
		{
			j++;
			n+=j*(s.at(i)-'0');
		}
	n%=11;
    
	if((n==10&&s.at(12)=='X')||(n<10&&s.at(12)==n+'0'))
		cout<<"Right"<<endl;
	else
	{
		if(n==10) s.at(12)='X';
		else s.at(12)=(char)(n+'0');
		cout<<s<<endl;
	}
	return 0;
}