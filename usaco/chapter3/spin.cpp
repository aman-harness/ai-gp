/*
ID: interne4
PROG: spin
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
ifstream fin("spin.in");
ofstream fout("spin.out");

int speed[5];      /* speed of each wheel */
int wedgest[5][5]; /* start of each wedge (-1 == no wedge) */
int wedglen[5][5]; /* length of each wedge */

int pos[5];        /* angular position of each wheel */
int t;             /* time (in seconds) since start */

/* (light[deg] >> wid) & 0x1 is true if and only if there
   is a wedge in wheel wid that a light can shine through at
   angle deg */
int light[360];    
 
/* mark all the degrees we can see through wheel w */
void mark_light(int w)
 {
  int lv, lv2; /* loop variables */
  int wpos; /* wedge position */

  for (lv = 0; lv < 5; lv++)
   {
    if (wedglen[w][lv] < 0) /* no more wedges for this wheel */
      break;

    /* start of wedge */
    wpos = (pos[w] + wedgest[w][lv]) % 360;

    for (lv2 = 0; lv2 <= wedglen[w][lv]; lv2++)
     { /* throughout extent of wedge */
      light[wpos] |= (1 << w); /* mark as hole in wheel */
      wpos = (wpos + 1) % 360; /* go to the next degree */
     }
   }
 }

int main()
 {
  int w, f;
  int lv, lv2;
  
  /* read in the data */
  for (lv = 0; lv < 5; lv++)
   {
    fin >> speed[lv] >> w;
    for (lv2 = 0; lv2 < w; lv2++)
      fin >> wedgest[lv][lv2] >> wedglen[lv][lv2];

    /* mark the rest of the wedges as not existing for this wheel */
    for (; lv2 < 5; lv2++)
      wedglen[lv][lv2] = -1;
   }

  f = 0;
  while (t < 360) /* for each time step */
   {
    memset(light, 0, sizeof(light));

    /* mark the degrees we can see through each wheel */
    for (lv = 0; lv < 5; lv++)
      mark_light(lv);

    for (lv = 0; lv < 360; lv++)
      if (light[lv] == 31) /* we can shine a light through all five wheels */
        f = 1;

    if (f) break; /* we found a match! */

    /* make a time step */
    t++;
    for (lv = 0; lv < 5; lv++)
      pos[lv] = (pos[lv] + speed[lv]) % 360;
   }

  /* after 360 time steps, all the wheels have returned to their
     original location */
  if (t >= 360) 
	fout << "none" << endl;
  else 
	fout << t << endl;

  return 0;
 }
/*
int main()
{
	int i,j,k,a,b;
	for(i=0;i<5;i++)
	{
		fin >> d[i] >> w[i];
		for(j=0;j<w[i];j++)
		{
			fin >> a >> b;
			for(k=a;k<a+b;k++)
				l[k][i] = 1;
		}
	}
	bool t;
	for(i=0;i<5;i++)
	{
		z[i] = 0;
		fout << d[i] << ' ' << w[i] << endl;
		
		for(k=0;k<360;k++)
			fout << l[k][i];
		fout << endl;
	}
	j=0;
	while(j<10000)
	{
		for(k=0;k<360;k++)
		{
			t = 1;
			fout << l[(k+(360-z[i]))%360][i];
			for(i=0;i<5;i++)
			if(!l[(k+(360-z[i]))%360][i])
			{
				t = 0;
				break;
			}
			if(t)
			{
				fout << j << endl;
				return 0;
			}
		}
		for(i=0;i<5;i++)
			z[i] = (z[i] + d[i])%360;
		j ++;
		fout << endl;
	}
	fout << "none" << endl;
    return 0;
}*/
