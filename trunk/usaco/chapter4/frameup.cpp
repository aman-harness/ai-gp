/*
ID: interne4
PROG: frameup
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("frameup.in");
ofstream fout("frameup.out");

const int maxN = 30 + 1;
char map[maxN][maxN];
bool vis[26] = {0}, sel[26] = {0};
int l[26],r[26],top[26],bottom[26];
bool under[26][26] = {0};
char letter[26] = {0};
int num = 0;
int n,m;

void print()
{
	int i;
	for(i=0;i<num;i++)
		fout << letter[i];
	fout << endl;
}

void Tsort(int s)
{
	if(s == num)
	{
		print();
		return;
	}
	int temp[26];
	int i,j;
	for(i=0;i<26;i++)
		if(vis[i] && !sel[i])
		{
			for(j=0;j<26;j++)
				if(under[j][i])
					break;
			if(j == 26)
			{
				for(j=0;j<26;j++)
					temp[j] = under[i][j],under[i][j] = 0;
				letter[s] = i + 'A';
				sel[i] = 1;
				Tsort(s + 1);
				sel[i] = 0;
				letter[s] = 0;
				for(j=0;j<26;j++)
					under[i][j] = temp[j];
			}
		}
}

int main()
{
	int i,j;
	fin >> n >> m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
    		fin >> map[i][j];
	for(i=0;i<26;i++)
	{
		l[i] = maxN;
		r[i] = 0;
		top[i] = maxN;
		bottom[i] = 0;
	}
    for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
    		if(map[i][j] != '.')
    		{
	    		int c = map[i][j] - 'A';
	    		if(j > r[c])
	    			r[c] = j;
	    		if(j < l[c])
	    			l[c] = j;
	    		if(i > bottom[c])
	    			bottom[c] = i;
	    		if(i < top[c])
	    			top[c] = i;
	    		if(!vis[c])
	    			vis[c] = 1,num ++;
			}
	
	for(i=0;i<26;i++)
		if(vis[i])
		{
			for(j=l[i];j<=r[i];j++)
			{
				if(map[top[i]][j] != i + 'A')
					under[i][map[top[i]][j] - 'A'] = true;
				if(map[bottom[i]][j] != i + 'A')
					under[i][map[bottom[i]][j] - 'A'] = true;
			}
			for(j=top[i];j<=bottom[i];j++)
			{
				if(map[j][l[i]] != i + 'A')
					under[i][map[j][l[i]] - 'A'] = true;
				if(map[j][r[i]] != i + 'A')
					under[i][map[j][r[i]] - 'A'] = true;
			}
		}
	/*for(i=0;i<26;i++)
	for(j=0;j<26;j++)
	if(under[i][j])
		fout << i << ' ' << j << endl;*/
	//memset(vis,0,sizeof(vis));
	Tsort(0);
	return 0;
}
/*
USER: Sun Zehao [interne4]
TASK: frameup
LANG: C++

Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 3016 KB]
   Test 2: TEST OK [0.000 secs, 3016 KB]
   Test 3: TEST OK [0.011 secs, 3016 KB]
   Test 4: TEST OK [0.000 secs, 3016 KB]
   Test 5: TEST OK [0.000 secs, 3016 KB]
   Test 6: TEST OK [0.011 secs, 3016 KB]
   Test 7: TEST OK [0.011 secs, 3016 KB]
   Test 8: TEST OK [0.130 secs, 3016 KB]
   Test 9: TEST OK [0.194 secs, 3016 KB]

All tests OK.
YOUR PROGRAM ('frameup') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.

Here are the test data inputs:

------- test 1 -------
9 8
.CCC....
ECBCBB..
DCBCDB..
DCCC.B..
D.B.ABAA
D.BBBB.A
DDDDAD.A
E...AAAA
EEEEEE..
------- test 2 -------
3 3
AAA
A.A
AAA
------- test 3 -------
5 7
AAA.CCC
A.A.C.C
AABBBCC
..B.B..
..BBB..
------- test 4 -------
11 8
UUUUU...
U...U...
U...EEEE
U...E..E
UMMMM..E
UMUUMEEE
.MJJJJJJ
.MJ.M..J
.MJ.M..J
.MJMM..J
..JJJJJJ
------- test 5 -------
6 9
AAABBBCCC
AQAQQQCQC
AAABBBCCC
XQXYYYZQZ
XQQYQYQQZ
XXXYYYZZZ
------- test 6 -------
20 20
AAABCDEFGHIJKLMNOPQR
A.ABCDEFGHIJKLMNOPQR
AAABCDEFGHIJKLMNOPQR
BBBBCDEFGHIJKLMNOPQR
CCCCCDEFGHIJKLMNOPQR
DDDDDDEFGHIJKLMNOPQR
EEEEEEEFGHIJKLMNOPQR
FFFFFFFFGHIJKLMNOPQR
GGGGGGGGGHIJKLMNOPQR
HHHHHHHHHHIJKLMNOPQR
IIIIIIIIIIIJKLMNOPQR
JJJJJJJJJJJJKLMNOPQR
KKKKKKKKKKKKKLMNOPQR
LLLLLLLLLLLLLLMNOPQR
MMMMMMMMMMMMMMMNOPQR
NNNNNNNNNNNNNNNNOPQR
OOOOOOOOOOOOOOOOOPQR
PPPPPPPPPPPPPPPPPPQR
QQQQQQQQQQQQQQQQQQQR
RRRRRRRRRRRRRRRRRRRR
------- test 7 -------
30 30
...............OOOOO..........
...............O...O..........
...............O...O..........
...............O...O..........
...............O...O..........
...............O...O..........
...............O...O..........
EEEEEEEEEEEEEEEOEEEOEEEEEEEEEE
E..............OOOOO.........E
E............................E
EEIIUUUUUUUUUUUUUUUUUUUUUUUUEE
..I.U...I..............AAAAUA.
..I.U...I..............A...UA.
..I.U...I..............A...UA.
..I.UUUUUUUUUUUUUUUUUUUUUUUUA.
..I.....I..............A....A.
..I.....I..............A....A.
..I.....I..............AAAAAA.
..I.....I.....................
..I.....I.....................
..I.....I.....................
..IIIIIII.....................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
------- test 8 -------
30 30
..............................
.OOOOOOOOOYYYYYOO.............
.O....PPPPYPPPYPOPP...........
.O....P...Y...Y.O.P...........
.O....P...Y...Y.O.P...........
.O....P...Y...Y.O.P...........
.O....P...Y...Y.O.P...........
.O....P...Y...Y.O.P...........
.O....P...Y...Y.O.P...........
.O....P...Y...Y.O.P...........
.OOOOOOOOOYOOOYOEEEEEEEEE.....
......PPPPYPPPYPEPP.....E.....
..........Y...Y.E.......E.....
..WWWWWWWWWWWWWWWWWTT...E.....
..W...T...Y...Y.E.W.T...E.....
..W...T...Y...Y.E.W.T...E.....
..W...T...Y...Y.E.W.T...E.....
..W...T...YYYYY.EEWEEEEEE.....
UUWWWWWWWWWWWWWWWWW.T.........
U.....TTTTTTTTTTTTQQQQQQQQQQQ.
U....RRRRRRRRRRRRRQRRRRR....Q.
U....R............Q....R....Q.
UIIIIRRRRRRRRRRRRRQRRRRRIIIIQ.
UI................QQQQQQQQQQQ.
UUUUUUUUUUUUUUUUUUU........I..
.IIIIIIIIIIIIIIIIIIIIIIIIIII..
..............................
..............................
..............................
..............................
------- test 9 -------
30 30
.DDDDRRRRQGGGGGGGGGGGGGQQQQQQ.
.DSSDRSSSQGSRSSSSS....G.....Q.
.D..DR...QG.R....SEEEEEEEEE.Q.
.D..DRTTOOGOOOOOOOEOOOGOOOEOOO
.D..DRT.OQG.R....SE...G...ETQO
.D..DRT.OIGFFFFFFFEFFFGIIIEIQO
.D..DRT.CCCCCCCCCSE..FG...EIQO
.D..DRT.CIGFR...CSE..FG...EIQO
.D..DRT.CIGFR...CMEMMFGMMMEIMO
.DBBBBBBBBBBBBBBBBBBBBBBBBEIMO
.DB.DRT.CIGFR...CSE..FG..BEIMO
.DBLDLLHCHGFHHLLCLELLFGLOBEIMO
.DBLDRTHCIGAAAA.CSE..FGL.BEIM.
.DBDDRTHCIGARHA.CSE..FGL.BEIM.
.SBL.RTHCIGARHA.CSE..FGL.BEIM.
.SBLLLLHCIGALHALCLEKKFGKKBEIM.
.SB..RTHCIGARHANCNENNFG.KBEIM.
.SB..RTHCIGARHANCSE..FG.KBEIM.
.SBBBBBBBBBABBABBBBBBBBBBBEIM.
.S...RTHCIGAFFAFCFEFFFG.K.EIM.
.S...RTHCIGAGGAGCGEGGGG.K.EIM.
.S...RTHCIJAJHANCQEEEEEEEEEIM.
.S...RTHCI.AJHANCSK..N..K..IM.
.PPPPPPHCIIAIHAICIIIIIIIIIIIM.
.P...RTHCHHAHHANCSKKKKKKKTTTM.
.P...R.JCCCAAAACCS...N......M.
.P...R.JJJJJJ..NMS...N......M.
.PSSSRSSSSSSRSSNMMMMMMMMMMMMM.
.P...RRRRRRRR..N.....N......P.
.PPPPPPPPPPPPPPNNNNNNNPPPPPPP.

Keep up the good work!


Thanks for your submission!
*/
