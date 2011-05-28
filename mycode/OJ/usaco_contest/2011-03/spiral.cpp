/*
ID: interne4
PROG: spiral
LANG: C++
*/
/*
This program can only run successfully in Linux OS. 
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

**********************************************************************

Problem 13: A spiral walk [Traditional, 2011]

Oh how the cows love to walk in their square pasture with sides of
length N (1 <= N <= 750) and which is partitioned into N*N squares.
They enjoy the sights, the smells, and the general ambience of the
grass and trees.

Bessie has decided to take the cows on the longest possible walk
from the upper left corner to the center (or near the center when
N is even) of the pasture, passing through each and every square
along the way after starting.

She has decided to create the obvious clockwise spiral route (example
below) for this evening's stroll. Write a program to create a map
for her that shows the order of squares she should visit.

By way of example, for pastures of size N=3 and N=4, here are the
routes Bessie should use:

      1  2  3        1  2  3  4
      8  9  4       12 13 14  5
      7  6  5       11 16 15  6
                    10  9  8  7

PROBLEM NAME: spiral

INPUT FORMAT:

* Line 1: A single integer: N

SAMPLE INPUT (file spiral.in):

3

OUTPUT FORMAT:

* Lines 1..N: N space-separated integers

SAMPLE OUTPUT (file spiral.out):

1 2 3
8 9 4
7 6 5

**********************************************************************/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
using namespace std;
ifstream fin("spiral.in");
ofstream fout("spiral.out");
const int maxN = 752;
const int dir[4][2] = {0,1,1,0,0,-1,-1,0};
int c[maxN][maxN] = {0};
int n;

void init()
{
	fin >> n;
	for(int i = 1; i <= n; i ++)
		c[i][0] = c[0][i] = c[n + 1][i] = c[i][n + 1] = 1;
}

void expand(int x, int y, int t, int d)
{
	c[x][y] = t;
	if(t == n * n) return;
	while(c[x + dir[d][0]][y + dir[d][1]])
		d = (d + 1) % 4;
	expand(x + dir[d][0], y + dir[d][1], t + 1 , d);
}

int main()
{
	init();
	expand(1,1,1,0);
	int i, j;
	for(i = 1; i <= n; i ++)
	{
		for(j = 1; j < n; j ++)
			fout << c[i][j] << ' ';
		fout << c[i][n] << endl;
	}
	
	return 0;
}
