#include <cstdlib>
#include <iostream>
using namespace std;
const int BlockXY[9][9][2] = 
{
0,0, 0,1, 0,2, 1,0, 1,1, 1,2, 2,0, 2,1, 2,2,
0,3, 0,4, 0,5, 1,3, 1,4, 1,5, 2,3, 2,4, 2,5,
0,6, 0,7, 0,8, 1,6, 1,7, 1,8, 2,6, 2,7, 2,8,
3,0, 3,1, 3,2, 4,0, 4,1, 4,2, 5,0, 5,1, 5,2,
3,3, 3,4, 3,5, 4,3, 4,4, 4,5, 5,3, 5,4, 5,5,
3,6, 3,7, 3,8, 4,6, 4,7, 4,8, 5,6, 5,7, 5,8,
6,0, 6,1, 6,2, 7,0, 7,1, 7,2, 8,0, 8,1, 8,2,
6,3, 6,4, 6,5, 7,3, 7,4, 7,5, 8,3, 8,4, 8,5,
6,6, 6,7, 6,8, 7,6, 7,7, 7,8, 8,6, 8,7, 8,8
};
int Data[9][9];
int N;
bool bLegal;

int main()
{
int iQuestionID;
cin >> N;

int i, j, k;

for (iQuestionID=0; iQuestionID<N; iQuestionID++)
{
bLegal = true;
for (i=0; i<81; i++)
cin >> Data[i / 9][i % 9];

for (i=0; i<9; i++)
for (j=0; j<9; j++)
for (k=j+1; k<9; k++)
if (Data[i][j] == Data[i][k])
{
bLegal = false;
goto superterminate;
}

for (i=0; i<9; i++)
for (j=0; j<9; j++)
for (k=j+1; k<9; k++)
if (Data[j][i] == Data[k][i])
{
bLegal = false;
goto superterminate;
}

for (i=0; i<9; i++)
for (j=0; j<9; j++)
for (k=j+1; k<9; k++)
if (Data[BlockXY[i][j][0]][BlockXY[i][j][1]] == Data[BlockXY[i][k][0]][BlockXY[i][k][1]])
{
bLegal = false;
goto superterminate;
}

superterminate:

if (bLegal)
cout << "Right" << endl;
else
cout << "Wrong" << endl;
}
return 0;
}
