/*
ID: interne4
PROG: fc
LANG: C++
*/
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

struct point {
    double  x;
    double  y;
    double  angle;
};

struct vector {
    double  i;
    double  j;
};

point   P[10000];
int     hull[10000];

int 
zcross (vector * u, vector * v)
{
    double  p = u->i * v->j - v->i * u->j;
    if (p > 0)
 return 1;
    if (p < 0)
 return -1;
    return 0;
}

int 
cmpP (const void *a, const void *b)
{
    if (((point *) a)->angle < ((point *) b)->angle)
 return -1;
    if (((point *) a)->angle > ((point *) b)->angle)
 return 1;
    return 0;
}

int main ()
{
    int     N, i, hullstart, hullend, a, b;
    double  midx, midy, length;
    vector  v1, v2;

    ifstream fin ("fc.in");
    fin >> N;
    midx = 0, midy = 0;
    for (i = 0; i < N; i++) {
 fin >> P[i].x >> P[i].y;
 midx += P[i].x;
 midy += P[i].y;
    }
    fin.close ();
    midx = (double) midx / N;
    midy = (double) midy / N;
    for (i = 0; i < N; i++)
 P[i].angle = atan2 (P[i].y - midy, P[i].x - midx);
    qsort (P, N, sizeof (P[0]), cmpP);

    hull[0] = 0;
    hull[1] = 1;
    hullend = 2;
    for (i = 2; i < N - 1; i++) {
 while (hullend > 1) {
     v1.i = P[hull[hullend - 2]].x - P[hull[hullend - 1]].x;
     v1.j = P[hull[hullend - 2]].y - P[hull[hullend - 1]].y;
     v2.i = P[i].x - P[hull[hullend - 1]].x;
     v2.j = P[i].y - P[hull[hullend - 1]].y;
     if (zcross (&v1, &v2) < 0)
  break;
     hullend--;
 }
 hull[hullend] = i;
 hullend++;
    }

    while (hullend > 1) {
 v1.i = P[hull[hullend - 2]].x - P[hull[hullend - 1]].x;
 v1.j = P[hull[hullend - 2]].y - P[hull[hullend - 1]].y;
 v2.i = P[i].x - P[hull[hullend - 1]].x;
 v2.j = P[i].y - P[hull[hullend - 1]].y;
 if (zcross (&v1, &v2) < 0)
     break;
 hullend--;
    }
    hull[hullend] = i;

    hullstart = 0;
    while (true) {
 v1.i = P[hull[hullend - 1]].x - P[hull[hullend]].x;
 v1.j = P[hull[hullend - 1]].y - P[hull[hullend]].y;
 v2.i = P[hull[hullstart]].x - P[hull[hullend]].x;
 v2.j = P[hull[hullstart]].y - P[hull[hullend]].y;
 if (hullend - hullstart > 1 && zcross (&v1, &v2) >= 0) {
     hullend--;
     continue;
 }
 v1.i = P[hull[hullend]].x - P[hull[hullstart]].x;
 v1.j = P[hull[hullend]].y - P[hull[hullstart]].y;
 v2.i = P[hull[hullstart + 1]].x - P[hull[hullstart]].x;
 v2.j = P[hull[hullstart + 1]].y - P[hull[hullstart]].y;
 if (hullend - hullstart > 1 && zcross (&v1, &v2) >= 0) {
     hullstart++;
     continue;
 }
 break;
    }

    length = 0;
    for (i = hullstart; i <= hullend; i++) {
 a = hull[i];
 if (i == hullend)
     b = hull[hullstart];
 else
     b = hull[i + 1];
 length += sqrt ((P[a].x - P[b].x) * (P[a].x - P[b].x) + (P[a].y - P[b].y) * (P[a].y - P[b].y));
    }

    ofstream fout ("fc.out");
	fout.setf (ios::fixed);
    fout.precision (2);
    fout << length << '\n';
    fout.close ();
}

