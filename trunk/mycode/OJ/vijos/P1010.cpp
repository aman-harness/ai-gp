#include <fstream>
using namespace std;
ifstream fin("P1010.in");
ofstream fout("P1010.out");
int a[10000]={0},b[10000]={0},c[10000]={0},ka,kb,kc,na,nb,nc,n;

void readStr(string str,int x[],int& kx,int& nx)
{
	int i,j=0,k;
	int tw = 0;
	k = str.length();
	for(i = k-1;i >= 0; i--)
	{
	    if (tw == 0 && str[i] == '0')
	        continue;
	    else if(str[i] == '.')
	    {
		    nx = j;
	    }
	    else
	    {
		    tw = 1;
		    x[j] = str[i]-'0';
		    j++;
		    if( str[i] != '0')
		        kx = j;
	    }
	}
	int t;
	/*
	for(i=0;i<kx/2;i++)
	{
		t = x[i];
		x[i] = x[kx - i - 1];
		x[kx - i - 1] = t;
	}*/
}

int main()
{
	string str,strd="";
	int i,j,k;
	while(fin >> str)
	{
		na = nb = nc = ka = kb = kc = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		
		
		fin >> k;
		readStr(str,a,ka,na);
		memcpy(b,a,sizeof(a));
		kb=ka;nb=na;
		while(k > 1)
		{
		    for(i = 0; i < ka; i++)
		    for(j = 0; j < kb; j++)
		    {
			    c[i+j] += a[i]*b[j];
			    c[i+j+1] += c[i+j]/10;
			    c[i+j] = c[i+j]%10;
		    }
		    kc = ka + kb;
            if(!c[kc-1]) kc--;
		    nc = na + nb;
		    memcpy(b,c,sizeof(c));
		    kb=kc;nb=nc;
		    memset(c,0,sizeof(c));
		    k--;
		}
		bool tt=0;
		str = "";
		for(i=0 ; i < kb ;i++)
			if(b[i] != 0 || (b[i] == 0 && tt))
			{
				if( i == nb)
				    str = "." + str;
		        str = char(b[i] + '0') + str;
			    if( !tt )
			        tt = true;
			}
		tt = false;
		for(i=kb ; i < nb ;i++)
		{
		    str = "0" + str;
			tt = 1;
		}
		if(tt)
		    str = "." + str;
		fout << str <<endl;
		n--;
		strd = str;
	}
	return 0;
}
