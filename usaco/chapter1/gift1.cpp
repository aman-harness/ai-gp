/*
ID: interne4
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("gift1.in");
ofstream fout("gift1.out");
int n;
int x;

class Person
{
public:
	string name;
	int count;
	int money;
	int reciveMoney;
	string *sendPersons;
    
    Person()
    {
	    name = "";
	    count = 0;
		money = reciveMoney = 0;
    }
    Person(string in)
    {
	    name = in;
	    count = 0;
		money = reciveMoney = 0;
    }
    void read(istream& input)
    {
	    input >> this->money;
		input >> this->count;
		int i;
		if(this->count)
		{
			sendPersons = new string[this->count]();
			for(i=0;i<this->count;i++)
			    input >> sendPersons[i];
		}
    }
private:
    friend ostream& operator <<(ostream& output,Person& th)
    {
	    output << "Name:" << th.name << endl;
	    output << "Money:" << th.money << endl;
	    output << "reciveMoney:" << th.reciveMoney << endl;
	    output << "Count:" << th.count << endl;
	    return output;
    }
		
}*person[100];

int main()
{
	int i,j,k,give;
	fin >> n;
	string name;
	//init
	for(i=0;i<n;i++)
	{
		fin >> name;
		person[i] = new Person(name);
	}
	//main
	for(i=0;i<n;i++)
	{
		fin >> name;
		for(j=0;j<n;j++)
		    if(name == person[j]->name)
		    {
			    person[j]->read(fin);
				//fout << *person[j] << endl;
				break;
		    }
	}
	//output
	for(i=0;i<n;i++)
	{
	    if(person[i]->count > 0 && person[i]->money > 0 )
	    {
		    give = person[i]->money/person[i]->count;
		    person[i]->reciveMoney += person[i]->money - give * person[i]->count;
		    for(j=0;j<person[i]->count;j++)
		    {
		        for(k=0;k<n;k++)
		        if(person[i]->sendPersons[j] == person[k]->name)
		        {
			        person[k]->reciveMoney += give;
			        break;
		        }
		    }
	    }
	}
	for(i=0;i<n;i++)
	    fout << person[i]->name << ' '  << person[i]->reciveMoney -  person[i]->money <<endl;
    return 0;
}
