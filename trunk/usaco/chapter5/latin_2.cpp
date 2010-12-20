/*
ID: interne4
PROG: latin
LANG: C++
DATA: 2010.12.17
ALGO: Depth First Search, Permutation group
*/
#include <fstream>
using namespace std;

int     N;
bool    row_used[7][7];
bool    col_used[7][7];
int     factorial[7];

int 
searchR (int r, int c)
{
    if (c == N) {
 		return searchR (r + 1, 1);
    }
    if (r == N - 1) {
 		return 1;
    }

    int     i, t = 0, sum = 0;
    int     s[2] = {-1, -1};

    for (i = 0; i < N; i++)
	{
		 if (row_used[r][i] || col_used[c][i])
   		 	 continue;
	 	if (i > c)
	 	    t = 1;
	 	if (r == 1 && s[t] != -1) {
	    	 sum += s[t];
	 	}
 		else {
    		row_used[r][i] = true;
    		col_used[c][i] = true;
   			s[t] = searchR (r, c + 1);
			sum += s[t];
    		row_used[r][i] = false;
   			col_used[c][i] = false;
 		}
    }
    return sum;
}

 
int main ()
{
    double  nLatin;
    int     i;

    ifstream fin ("latin.in");
    fin >> N;
    fin.close ();

    factorial[0] = 1;
    for (i = 0; i < N; i++) {
		col_used[i][i] = true;
		row_used[i][i] = true;
		if (i > 0)
    		factorial[i] = i * factorial[i - 1];
    }

    nLatin = (double) factorial[N - 1] * (double) searchR (1, 1);

    ofstream fout ("latin.out");
    fout.precision (0);
    fout.setf (ios::fixed);
    fout << nLatin << '\n';
    fout.close ();
}
