/*
ID: interne4
PROG: contact
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <memory.h>
using namespace std;
ifstream fin("contact.in");
ofstream fout("contact.out");

const int maxN = 2000000;
int n,A,B,bitsL;
bool bits[maxN + 1]={0};		
struct Sequence
{
	int n;
	int size;
	int times;
}seq[10000];								//the array's size > 2^12

typedef int (*compfn)(const void*, const void*);

int comp(const Sequence* q, const Sequence* p)
{
	if(q->times != p->times)
		return (p->times - q->times);
	else if(q->size != p->size)
		return (q->size - p->size);
	else
		return (q->n - p->n);
}

const int pow2[13]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096};

int trans(int n,int d,char s[])
{
  static char digits[]="0123456789ABCDEFGHIJK";
  char buf[101];
  int j,i=100;
  s[0]='\0'; 
  buf[i]='\0';
  do
  {
    buf[--i] = digits[n%d]; 
    n /= d;
  }while(n);
  for(j=0;(s[j]=buf[i])!='\0';j++,i++);
  return j;
}

int main()
{
	int i,j,s;
    fin >> A >> B >> n;
	s = 0;
	//init
	for(i=1;i<13;i++)
	{
		for(j=0;j<pow2[i];j++)
		{
			seq[s+j].size = i;
			seq[s+j].n = j;
		}
		s += pow2[i];
	}
	i = 0;
	while(!fin.eof())
	{
		char ch;
		fin.get(ch);
		if(ch == '1')
			bits[i]=1;
		else if(ch == '0')
			bits[i]=0;
		else continue;
		i++;
	}
	//start
	bitsL = i;
	int k;
	int l;
	
	for(i=0;i<bitsL;i++)
	{
		s = 0;
		l = 1;
		k = 0;
		for(j=1;j<=(i+1>12?12:i+1);j++)
		{
			k += bits[i-j+1]*l;
			if(j >= A && j <= B)
				seq[s + k].times ++;
			s += pow2[j];
			l *= 2;
		}
	}
	//end
	qsort(seq, 4096*2 ,sizeof(Sequence),(int (*)(const void*, const void*))comp);
	int last = 0;
	int x;
	j = 0;
	for(i=0;i<4096*2;i++)
	{
		if(last != seq[i].times)
		{
			if(j != 0)
			fout << endl;
			j ++;
			if(n < j || seq[i].times == 0) break;
			last = seq[i].times;
			fout << last << endl;
			x = 0;
		}
		else
		{
			if(x%6 == 0)
				fout << endl;
			else
				fout << ' ';
		}
		char str[13];
		trans(seq[i].n,2,str);
		k = seq[i].size - strlen(str);
		while(k-- > 0)fout << '0';
		fout << str;
		x++;
			//fout << outs << ' ';
	}
	return 0;
}
