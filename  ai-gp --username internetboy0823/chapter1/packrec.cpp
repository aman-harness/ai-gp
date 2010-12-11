/*
ID: interne4
PROG: packrec
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("packrec.in");
ofstream fout("packrec.out");
class Rect
{
public:
	int wid,hei;
	Rect()
	{
	}
	Rect(int a,int b)
	{
		Set(a,b);
	}
	void Set(int a,int b)
	{
		if(a > b)
		{
			wid = a; hei = b;
		}
		else
		{
			wid = b; hei = a;
		}
	}
private:
	friend ostream& operator << (ostream output,Rect rect)
	{
		output << rect.hei << ' ' << rect.wid;
	}
}rect[5];

template <class T>
class AnsNode
{
public:
	T ans;
	AnsNode* next;
	AnsNode()
	{
	}
	AnsNode(T i,AnsNode n =0)
	{
		ans = i;
		next = n;
	}
};

class Answer
{
public:
	int area;
	AnsNode<Rect> *solution;
	
	Answer()
	{
		area = 100000000;
		solution = new AnsNode<Rect>;
	}
	
	void InPut(Rect in)
	{
		if(in.wid * in.hei > area)
			return;
		if(in.wid * in.hei < area)
		{
			Clear();
		}
		AnsNode* ie,inext;
		ie = solution;
		while(ie->next != null)
		{
			if(ie->next->ans.wid > in.wid)
			{
				inext = ie->next;
				break;
			}
			if(ie->next->ans.wid == in.wid)
				return;
			ie = ie->next;
		}
		ie->next = new AnsNode(in,inext);
		
	}

private:
	void Clear()
	{
		AnsNode* ie,id;
		ie = solution->next;
		while(ie != null)
		{
			id = ie;
			ie = ie->next;
			delete id;
		}
	}
	friend ostream& operator << (ostream output,Answer ans)
	{
		ie = solution->next;
		output << area << endl;
		while(ie != null)
		{
			output << ie->ans << endl;
			ie = ie->next;
		}
	}
}answer;


int main()
{
	int i,j;
	int a,b;
	for (i=1;i<=4;i++)
	{
		fin >> a >> b;
		rect[i].Set(a,b);
	}
	int s=0,wid=0;
	for(i=1;i<=4;i++)
	{
		if(wid < rect[i].wid)
			wid = rect[i].wid;
		s += rect[i].hei;
	}
	answer.InPut(new Rect(wid,s));
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		if(wid < rect[i].wid)
			wid = rect[i].wid;
		s += rect[i].hei;
	}
	
    return 0;
}
