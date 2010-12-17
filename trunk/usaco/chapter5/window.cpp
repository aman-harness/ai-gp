/*
ID: interne4
PROG: window
LANG: C++
DATA: 2010.12.15
ALGO: Links , Simulation , Clip Rectangle
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <iomanip>
#include <memory.h>
#include <list>
#include <queue>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");

const int maxN = 256 + 1;
const int T_DIGIT = 1;
const int T_LETTER = 2;
const int T_BACKET = 3;
const int T_OTHER = 4;

const int funcN = 5;
const char func[funcN] = {'w','t','b','d','s'};
const int argn[5] = {5,1,1,1,1};
const int arg[5] = {T_LETTER,T_DIGIT,T_DIGIT,T_DIGIT,T_DIGIT};

int wType(const char c)
{
	if('A' <= c <= 'Z' && 'a' <= c <= 'z')
		return T_LETTER;
	else if('0' <= c <= '9')
		return T_DIGIT;
	else if('(' == c || c == ')')
		return T_BACKET;
	else
		return T_OTHER;
}

struct rect
{
	int x1,y1,x2,y2;	
};

class Window
{
public:
	char id;
	rect r;
	Window(int arg[5])
	{
		id = arg[0];
		r.x1 = arg[1];
		r.y1 = arg[2];
		r.x2 = arg[3];
		r.y2 = arg[4];
	}
};

list<Window> windows;
list<Window>::iterator its[maxN];

const rect NP = {0,0,0,0};

double calcS(int id)
{
	int i;
	queue<rect> q;
	list<Window>::iterator it;
	rect g,nr,r;
	
	q.push(its[id] -> r);
	
	for(it = windows.begin(); it != its[id]; it ++)
	{
		r = it -> r;
		q.push(NP);
		while(!q.empty())
		{
			g = q.front();
			q.pop();
			
			if(g.x1 == 0)
				break;
			if(g.x1 < r.x1)
			{
				nr.x1 = g.x1;
				nr.x2 = r.x1;
				nr.y1 = g.y1;
				nr.y2 = g.y2;
				q.push(nr);
			}
			if(g.x2 > r.x2)
			{
				nr.x1 = r.x2;
				nr.x2 = g.x2;
				nr.y1 = g.y1;
				nr.y2 = g.y2;
				q.push(nr);
			}
			if(g.y1 < r.y1)
			{
				nr.x1 = max(g.x1,r.x1);
				nr.x2 = min(g.x2,r.x2);
				nr.y1 = g.y1;
				nr.y2 = r.y1;
				q.push(nr);
			}
			if(g.y2 > r.y2)
			{
				nr.x1 = max(g.x1,r.x1);
				nr.x2 = min(g.x2,r.x2);
				nr.y1 = r.y2;
				nr.y2 = g.y2;
				q.push(nr);
			}
		}
		
	}
	if(q.empty())
		return 0.0;
	
	double s = 0;
	while(!q.empty())
	{
		g = q.front();
		q.pop();
		s += (g.x2 - g.x1) * (g.y2 - g.y1);
	}
	r = its[id] -> r;
	return s / ((r.x2 - r.x1) * (r.y2 - r.y1)) * 100;
}

void proc(int f, int narg[5])
{
	if(narg[1] > narg[3])
		swap(narg[1],narg[3]);
	if(narg[2] > narg[4])
		swap(narg[2],narg[4]);
	
	Window w(narg);
	switch(f)
	{
		case 0:
			windows.push_front(w);
			its[narg[0]] = windows.begin();
		break;
		case 1:
			windows.push_front(*its[narg[0]]);
			windows.erase(its[narg[0]]);
			its[narg[0]] = windows.begin();
		break;
		case 2:
			windows.push_back(*its[narg[0]]);
			windows.erase(its[narg[0]]);
			its[narg[0]] = windows.end();
		break;
		case 3:
			windows.erase(its[narg[0]]);
		break;
		case 4:
			fout << calcS(narg[0]) << endl;
		break;
	}
}

int main()
{
	list<int>::iterator it;
	int i,j,k;
	int narg[5];
	char c;
	fout << fixed << setprecision(3);
	
	while(1)
	{
		c = fin.get();
		while(c == ' ' || c == 10)
			c = fin.get();
		for(i=0;i<funcN;i++)
		{
			if(func[i] == c)
			{
				break;
			}
		}
		
		fin.get();
		
		if(i < funcN)
		{
			for(j=0;j<argn[i];j++)
			{
				if(arg[j] == T_LETTER)
				{
					c = fin.get();
					narg[j] = c;
				}
				else if(arg[j] == T_DIGIT)
				{
					fin >> k;
					narg[j] = k;
				}
				
				c = fin.get();
				while(c == ' ' || c == 10)
					c = fin.get();
			}
			
			proc(i,narg);
				
		}
		else if(c != '(')
			break;
	}
	return 0;
}
