/*
ID: interne4
PROG: pathfind
LANG: C++
*/
/**********************************************************************

Problem 12: Pathfinding [Sherry Wu, 2011]

Bessie is stranded on a deserted arctic island and wants to determine
all the paths she might take to return to her pasture. She has
tested her boat and knows she can travel from one island to another
island in 1 unit of time if a route with proper currents connects
the pair.

She has experimented to create a map of the ocean with valid
single-hop routes between each pair of the N (1 <= N <= 100) islands,
conveniently numbered 1..N. The routes are one-way (unidirectional),
owing to the way the currents push her boat in the ocean. It's
possible that a pair of islands is connected by two routes that use
different currents and thus provide a bidirectional connection. The
map takes care to avoid specifying that a route exists between an
island and itself.

Given her starting location M (1 <= M <= N) and a representation
of the map, help Bessie determine which islands are one 'hop' away,
two 'hops' away, and so on. If Bessie can take multiple different
paths to an island, consider only the path with the shortest distance.

By way of example, below are N=4 islands with connectivity as shown
(for this example, M=1):

       start--> 1-------->2
                |         |
                |         |
                V         V
                4<--------3

Bessie can visit island 1 in time 0 (since M=1), islands 2 and 4
at time 1, and island 3 at time 2.

The input for this task is a matrix C where the element at row r,
column c is named C_rc (0 <= C_rc <= 1) and, if it has the value
1, means "Currents enable Bessie to travel directly from island r
to island c in one time unit". Row C_r has N elements, respectively
C_r1..C_rN, each one of which is 0 or 1.

PROBLEM NAME: pathfind

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 contains N space-separated integers: C_r

SAMPLE INPUT (file pathfind.in):

4 1
0 1 0 1
0 0 1 0
0 0 0 1
0 0 0 0

OUTPUT FORMAT:

* Lines 1..???: Line i+1 contains the list of islands (in ascending
        numerical order) that Bessie can visit at time i.  Do not
        include any lines of output after all reachable islands have
        been listed.

SAMPLE OUTPUT (file pathfind.out):

1
2 4
3

***********************************************************************/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("pathfind.in");
ofstream fout("pathfind.out");
const int maxN = 101;
int n,m;
int c[maxN][maxN] = {0};

void init()
{
	int i,j;
	fin >> n >> m;
	for(i = 1; i <= n; i ++)
	for(j = 1; j <= n; j ++)
	{
		fin >> c[i][j];
	}
}

int a[maxN] = {0};
int an;

bool v[maxN] = {0};
bool s[maxN] = {0};

void expand()
{
	int i,j;
	s[m] = 1;
	v[m] = 1;
	while(1)
	{
		an = 0;
		for(i = 1; i <= n; i ++)
			if(s[i])
			{
				a[an ++] = i;
				s[i] = 0;
			}
		
		if(an == 0)
			break;
		
		for(i = 0; i < an; i ++)
			for(j = 1; j <= n; j ++)
				if(c[a[i]][j] && !v[j])
				{
					v[j] = 1;
					s[j] = 1;
				}
		for(i = 0; i < an - 1; i ++)
			fout << a[i] << ' ';
		fout << a[an - 1] << endl;
	}
}

int main()
{
	init();
	expand();
	return 0;
}
