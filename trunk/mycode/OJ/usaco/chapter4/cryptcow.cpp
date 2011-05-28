/*
ID: interne4
PROG: cryptcow
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");


/*
web:	http://www.n8lm.cn
This template code is writed by Alchemist.
*/
template <class T>
struct LinkedNode
{
	T data;
	LinkedNode<T> *next;
	LinkedNode<T> *last;
};

template <class T>
class LinkedList
{
	LinkedNode<T>* first;
	LinkedNode<T>* end;
	
	friend bool operator == (LinkedList<T>& l1, LinkedList<T>& l2)
	{
		LinkedNode<char>* th = l1.getFirst();
		LinkedNode<char>* c = l2.getFirst();
		while(th != NULL && c != NULL)
		{
			if(th -> data != c -> data)
				return false;
			th = th -> next;
			c = c -> next;
		}
		if(th  == NULL && c  == NULL)
			return true;
		else
			return false;
	}
	
	friend ostream& operator << (ostream& output, LinkedList<T>& l)
	{
		LinkedNode<char>* th = l.getFirst();
		while(th != NULL)
		{
			output << th -> data;
			th = th -> next;
		}
		return output;
	}
	
public:
	LinkedList();
	bool isEmpty();
	LinkedNode<T>* getFirst();
	void add(LinkedNode<T>* node);
};

template <class T>
LinkedList<T>::LinkedList()
{
	first = new LinkedNode<T>();
	end = first;
}

template <class T>
void LinkedList<T>::add(LinkedNode<T>* node)
{
	end->next = node;
	node->last = end;
	end = node;
}

template <class T>
LinkedNode<T>* LinkedList<T>::getFirst()
{
	return first->next;
}

string str;
LinkedList<char> strl,oril;
int letter[256] = {0};
const string ori = "Begin the Escape execution at the Break of Dawn";


void strArray(const char ch ,LinkedNode<char>* array[10],int* qa,int& n)
{
	n = 0;
	int i = 1;
	LinkedNode<char>* th = strl.getFirst();
	while(th != NULL)
	{
		if(th -> data == ch)
		{
			array[n] = th;
			qa[n ++] = i;
		}
		th = th -> next;
		i++;
	}
}


void search(int x)
{
	
	LinkedNode<char>* Ct[10];
	int Cn = 0;
	LinkedNode<char>* Ot[10];
	int On = 0;
	LinkedNode<char>* Wt[10];
	int Wn = 0;
	int Cp[10];
	int Op[10];
	int Wp[10];
	
	strArray('C',Ct,Cp,Cn);
	strArray('O',Ot,Op,On);
	strArray('W',Wt,Wp,Wn);
	
	//fout << strl << endl << x << endl;
	//fout << Cn << ' '  << On << ' '  << Wn << endl; 
	
	if(Cn == 0 || On == 0 || Wn == 0)
	{
		if(strl == oril)
		{
			fout << 1 << ' '<< x << endl;
			exit(0);
		}
	}
	
	int i,j,k;
	int il = 0,jl = 0,kl = 0;
	for(i=0;i<Cn;i++)
	{
		for(j=jl;j<On;j++)
		{
			if(Cp[i] > Op[j])
			{
				jl = j + 1;
				continue;
			}
			else
			for(k=kl;k<Wn;k++)
			{
				if(Op[j] > Wp[k])
				{
					kl = k + 1;
					continue;
				}
				else
				{
					LinkedNode<char> *nc,*lc,*no,*lo,*nw,*lw;
					lc = Ct[i] -> last;
					lo = Ot[j] -> last;
					lw = Wt[k] -> last;
					nc = Ct[i] -> next;
					no = Ot[j] -> next;
					nw = Wt[k] -> next;
					
					if(nc == Ot[j])
					{
						if(no == Wt[k])
						{
							lc -> next = nw;
							nw -> last = lc;
						}
						else
						{
							lc -> next = no;
							no -> last = lc;
							lw -> next = nw;
							nw -> last = lw;
						}
					}
					else if(no == Wt[k])
					{
						lc -> next = nc;
						nc -> last = lc;
						lo -> next = nw;
						nw -> last = lo;
					}
					else
					{
						lc -> next = no;
						no -> last = lc;
						lw -> next = nc;
						nc -> last = lw;
						lo -> next = nw;
						nw -> last = lo;
					}
					//fout << i << ' ' << j << ' ' << k <<endl;
					
					search(x+1);
					
					
					lc -> next = Ct[i];
					nc -> last = Ct[i];
					lo -> next = Ot[j];
					no -> last = Ot[j];
					lw -> next = Wt[k];
					nw -> last = Wt[k];
					
					//fout << strl << endl;
					
					
				}
			}
		}
	}
}

int main()
{
	int i;
	getline(fin, str);
	for(i=0;i<ori.size();i++)
		letter[ori[i]]++;
	for(i=0;i<str.size();i++)
		letter[str[i]]--;
	letter['C'] = letter['O'] = letter['W'] = 0;
	for(i=0;i<127;i++)
		if(letter[i] != 0)
		{
			fout << 0 << ' ' << 0 << endl;
			fout << i;
			return 0;
		}
	LinkedNode<char>* node;
	for(i=0;i<str.size();i++)
	{
		node = new LinkedNode<char>();
		node->data = str[i];
		strl.add(node);
	}
	
	for(i=0;i<ori.size();i++)
	{
		node = new LinkedNode<char>();
		node->data = ori[i];
		oril.add(node);
	}
	
	search(0);
	fout << 0 << ' ' << 0 << endl;
    return 0;
}
