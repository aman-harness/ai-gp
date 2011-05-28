#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;
#define fin cin
#define fout cout
const int N = 9;
const int POSSIBLE = 1; 
const int IMPOSSIBLE = 0; 
struct NODE{
int data[N+1]; 
bool only; 
} ;
void ShowBlock(struct NODE lib[][N]);
void Input(struct NODE lib[][N]);
void Build(struct NODE lib[][N]);
void TheSameRow(struct NODE lib[][N], int row, int cel);
void TheSameCel(struct NODE lib[][N], int row, int cel);
void TheSameBlock(struct NODE lib[][N], int row, int cel);
int ChooseOnly(struct NODE lib[][N], int & count);
bool IsOnly(int pos[], int & num);
bool IsRepeated(struct NODE lib[][N], int row, int cel, int n);
int AnalyseNumber(struct NODE lib[][N], int & count);
int JudgeRow(struct NODE lib[][N], int n, int & count);
int JudgeCel(struct NODE lib[][N], int n, int & count);
int JudgeBlock(struct NODE lib[][N], int n, int & count);
bool DoubleNumble(struct NODE lib[][N]);
bool RowDouble(struct NODE lib[][N], int row);
bool CelDouble(struct NODE lib[][N], int cel);
bool BlockDouble(struct NODE lib[][N], int row, int cel);
int BlockPosition(int row, int cel);
bool IsTwo(struct NODE lib[][N], int row, int cel);
bool Equal(const struct NODE & a, const struct NODE & b);
void DoTheRow(struct NODE lib[][N], int row, int cel1, int cel2);
void DoTheCel(struct NODE lib[][N], int cel, int row1, int row2);
void DoTheBlock(struct NODE lib[][N], int row, int cel, int row1, int cel1, int row2, int cel2);
void Solve(struct NODE lib[][N]);
int main()  
{
int xx,yy;
string ss;
getline(fin,ss);
istringstream sin(ss);
sin>>xx;
for(yy=1;yy<=xx;yy++)
{struct NODE lib[N][N];
Input(lib); 
for (int i=0; i<N; i++)
{
for (int j=0; j<N; j++)
{
if (lib[i][j].only)
{
if (IsRepeated(lib, i, j, lib[i][j].data[0]))
{
fout << "error"<< endl;
return 0;
} 
}
}
}
Build(lib);
int count = 0;
int flag1 = 1, flag2 = 1, i=0;
bool flag = true;
while (flag || (flag1 == 1 || flag2 == 1))
{
flag1 = ChooseOnly(lib, count);
flag2 = AnalyseNumber(lib, count);//1-9
if (flag1 == -1 || flag2 == -1 ) 
{
fout << "error" << endl;
return 0;
} 
flag = DoubleNumble(lib); 
if (flag1 == 0 && flag2 == 0 && !flag) 
break;
}
Solve(lib);
ShowBlock(lib); 
}
}

void ShowBlock(struct NODE lib[][N])// 
{
for (int i=0; i<N; i++)
{
for (int j=0; j<N; j++)
{
fout << lib[i][j].data[0] ;
}
}
fout<<endl;
}
bool f1[10][10],f2[10][10],f3[10][10];
struct node{
int x,y,k;
};
node z[82];
int h[82][10];
int ht[82];
int jc[82];
int q[10][10];
int zt,i,j,k,s;
bool jh[10];
inline int ju(int x,int y)
{
return ((x-1)/3)*3+(y+2)/3;
}
void horj(int x,int y,int k,int z,bool l)
{
f1[x][z]=l;f2[y][z]=l;f3[k][z]=l;
}
void Solve(struct NODE lib[][N])
{
memset(f1,1,sizeof(f1));
memset(f2,1,sizeof(f2));
memset(f3,1,sizeof(f3));
memset(ht,0,sizeof(ht));
memset(jc,0,sizeof(jc));
zt=0;z[0].x=1;z[0].y=1;z[0].k=1;
h[0][1]=1;jc[0]=1;
for(i=1;i<10;i++)
for(j=1;j<10;j++)
q[i][j]=lib[i-1][j-1].data[0];
for(i=1;i<10;i++)
for(j=1;j<10;j++)
if(q[i][j]!=0){
if(f1[i][q[i][j]]) f1[i][q[i][j]]=0;
if(f2[j][q[i][j]]) f2[j][q[i][j]]=0;
if(f3[ju(i,j)][q[i][j]]) f3[ju(i,j)][q[i][j]]=0; 
}
for(i=1;i<10;i++)
for(j=1;j<10;j++)
if(q[i][j]==0){
memset(jh,1,sizeof(jh));
s=0;
for(k=1;k<10;k++){
if((!(f1[i][k]))&&(jh[k])) jh[k]=0;
if((!(f2[j][k]))&&(jh[k])) jh[k]=0;
if((!(f3[ju(i,j)][k]))&&(jh[k])) jh[k]=0;
}
for(k=1;k<10;k++)
if(jh[k]) s++;
if(s==1)
for(k=1;k<10;k++)
if(jh[k]){
q[i][j]=k;

f1[i][k]=false;

f2[j][k]=false;

f3[ju(i,j)][k]=false;

}

}

for(i=1;i<10;i++)

for(j=1;j<10;j++)

if(!q[i][j]){

zt++;

z[zt].x=i;z[zt].y=j;

z[zt].k=ju(i,j);

}

for(i=1;i<=zt;i++)

for(k=1;k<10;k++)

if((f1[z[i].x][k])&&(f2[z[i].y][k])&&(f3[z[i].k][k])){

ht[i]++;

h[i][ht[i]]=k;

}

k=1;

label:

while((k<=zt)&&(k>0))

if(jc[k]>=ht[k]){

jc[k]=0;k--;

horj(z[k].x,z[k].y,z[k].k,h[k][jc[k]],true);

}else{

do{

jc[k]++;

if(jc[k]>ht[k]) goto label;

}while(!((f1[z[k].x][h[k][jc[k]]])&&(f2[z[k].y][h[k][jc[k]]])

&&(f3[z[k].k][h[k][jc[k]]])));

horj(z[k].x,z[k].y,z[k].k,h[k][jc[k]],false);

k++;

}

if(k==0){

fout << "error" << endl;

exit(0);

}else{

k=0;

for(i=1;i<10;i++){

for(j=1;j<9;j++)

if(q[i][j]!=0) lib[i-1][j-1].data[0]=q[i][j];

else{

k++;

lib[i-1][j-1].data[0]=h[k][jc[k]];

}

if(q[i][9]!=0) lib[i-1][8].data[0]=q[i][9];

else{

k++;

lib[i-1][8].data[0]=h[k][jc[k]];

}

}

}

}







void Input(struct NODE lib[][N])// 

{

int num;string s;

getline(fin,s);

for (int i=0; i<N; i++)// 

{

for (int j=0; j<N; j++)

{

char c=s[i*9+j];

num=(int)c-48;// 



if (num == 0)//0 

{

lib[i][j].only = false;// 

lib[i][j].data[0] = IMPOSSIBLE;

for (int k=1; k<=N; k++)// 

lib[i][j].data[k] = POSSIBLE; //k

}

else//data[0] 

{

lib[i][j].only = true;

lib[i][j].data[0] = num;

}

}

}



}



void Build(struct NODE lib[][N])// 

{

for (int i=0; i<N; i++)

{

for (int j=0; j<N; j++)

{

if (lib[i][j].only)// 

{

TheSameRow(lib, i, j);//lib[i][j].data[0] 

TheSameCel(lib, i, j);//lib[i][j].data[0] 

TheSameBlock(lib, i, j);//lib[i][j].data[0]  

}

}

}

}



void TheSameRow(struct NODE lib[][N], int row, int cel)//lib[row][cel].data[0]

{

int n;

for (int k=0; k<N; k++)

{

n = lib[row][cel].data[0];

lib[row][k].data[n] = IMPOSSIBLE;//n

}

}



void TheSameCel(struct NODE lib[][N], int row, int cel)//lib[row][cel].data[0]

{

int n;

for (int k=0; k<N; k++)

{

n = lib[row][cel].data[0];

lib[k][cel].data[n] = IMPOSSIBLE;//n

}

}



void TheSameBlock(struct NODE lib[][N], int row, int cel)//lib[row][cel].data[0]

{

int top = row - row % 3;// 

int left = cel - cel % 3;// 

int n;

for (int i=top; i<top+3; i++)

{

for (int j=left; j<left+3; j++)

{

n = lib[row][cel].data[0];

lib[i][j].data[n] = IMPOSSIBLE;//n

}

}

}



int ChooseOnly(struct NODE lib[][N], int & count)//0 

{

int sum = 0;

int num;

for (int i=0; i<N; i++)

{

for (int j=0; j<N; j++)

{

if (lib[i][j].only)// 

continue;

//  

num = 0;

if (IsOnly(lib[i][j].data, num))

{

if (IsRepeated(lib, i, j, num))// 

return -1;



lib[i][j].data[0] = num;

lib[i][j].only = true;

sum = 1;// 



TheSameRow(lib, i, j);//lib[i][j].data[0] 

TheSameCel(lib, i, j);//lib[i][j].data[0] 

TheSameBlock(lib, i, j);//lib[i][j].data[0]  



// 

i = 0;

j = -1;

}

}

}



return sum;

}



bool IsOnly(int pos[], int & num)// 

{

int sum = 0;

for (int i=1; i<=N; i++)

{

if (pos[i] == POSSIBLE)//ii 

{

num = i;

sum++;

}



if (sum > 1)//1 

return false;

}



return (sum == 1);

}



bool IsRepeated(struct NODE lib[][N], int row, int cel, int n)//n 

{

// 

for (int i=0; i<N; i++)

{

if (lib[row][i].data[0] == n && i != cel)

return true;

}

// 

for (int i=0; i<N; i++)

{

if (lib[i][cel].data[0] == n && i != row)

return true;

}

// 

int top = row - row % 3;// 

int left = cel - cel % 3;// 

for (int i=top; i<top+3; i++)

{

for (int j=left; j<left+3; j++)

{

if (lib[i][j].data[0] == n && i != row && j != cel)

return true;

}

}

return false;

}



int AnalyseNumber(struct NODE lib[][N], int & count)//1-9 

{

int sum = 0;

int t;

for (int n=1; n<=N; n++)

{

t = JudgeRow(lib, n, count);// 

if (t == -1)

return -1;

else if (1 == t)

sum++;



t = JudgeCel(lib, n, count);// 

if (t == -1)

return -1;

else if (1 == t)

sum++;



t = JudgeBlock(lib, n, count);// 

if (t == -1)

return -1;

else if (1 == t)

sum++;

}



return (sum > 0);

}



//nnn 

int JudgeRow(struct NODE lib[][N], int n, int & count)

{

int s = 0;

int i, j;

for (i=0; i<N; i++)

{

bool flag = true;//n 

int sum = 0;//n 

int cel;//n 

for (j=0; j<N; j++)

{

if (lib[i][j].only)

{

if (lib[i][j].data[0] == n)// 

{

sum++;

flag = false;

break;

}

else// 

continue;

}



if (lib[i][j].data[n] == POSSIBLE)//n 

{

cel = j;// 

sum++;//n 

}



if (sum > 1)// 

{

flag = false;

break;

}

}



if (sum == 0)//n 

return -1;



if (flag && sum == 1)//nn 

{

if (IsRepeated(lib, i, cel, n))// 

return -1;



lib[i][cel].data[0] = n;

lib[i][cel].only = true;





TheSameCel(lib, i, cel);//lib[i][j].data[0] 

TheSameBlock(lib, i, cel);//lib[i][j].data[0] 



s = 1; 

}

}

return s;

}



//nnn 

int JudgeCel(struct NODE lib[][N], int n, int & count)

{

int s = 0;

int i, j;

for (j=0; j<N; j++)

{

bool flag = true;//n 

int sum = 0;//n 

int row;//n  

for (i=0; i<N; i++)

{

if (lib[i][j].only)

{

if (lib[i][j].data[0] == n)

{

sum++;

flag = false;

break;

}

else

continue;

}



if (lib[i][j].data[n] == POSSIBLE)

{

row = i;// 

sum++;//n 

}



if (sum > 1)

{

flag = false;

break;

}

}



if (sum == 0)//n 

return -1;



if (flag && sum == 1)//nn 

{

if (IsRepeated(lib, row, j, n))// 

return -1;



lib[row][j].data[0] = n;

lib[row][j].only = true;





TheSameRow(lib, row, j);//lib[i][j].data[0] 

TheSameBlock(lib, row, j);//lib[i][j].data[0] 

 

s = 1; 

}

}

return s;

}



//nnn 

int JudgeBlock(struct NODE lib[][N], int n, int & count)

{

int s = 0;

for (int i=0; i<N; i+=3)// 

{

for (int j=0; j<N; j+=3)

{

bool flag = true;

int sum = 0;

int row, cel;

int x, y;

for (x=i; flag && x<i+3; x++)// 

{

for (y=j; y<j+3; y++)

{

if (lib[x][y].only)

{

if (lib[x][y].data[0] == n)

{

sum++;

flag = false;

break;

}

else

continue;

}



if (lib[x][y].data[n] == POSSIBLE)//n 

{

row = x;// 

cel = y;// 

sum++;//n 

}



if (sum > 1)

{

flag = false;

break;

}

}

}

if (sum == 0)//n 

return -1;



if (flag && sum == 1)//nn 

{

if (IsRepeated(lib, row, cel, n))// 

return -1;



lib[row][cel].data[0] = n;

lib[row][cel].only = true;





TheSameRow(lib, row, cel);//lib[i][j].data[0] 

TheSameCel(lib, row, cel);//lib[i][j].data[0] 



s = 1; 

}

}

}

return s;

}



/*



 

*/

bool DoubleNumble(struct NODE lib[][N])// 

{

int sum = 0;



for (int i=0; i<N; i++)

{

if (RowDouble(lib, i))

sum++;

}

for (int i=0; i<N; i++)

{

if (CelDouble(lib, i))

sum++;

}

for (int i=0; i<N; i+=3)// 

{

for (int j=0; j<N; j+=3)

{

if (BlockDouble(lib, i, j))

sum++;

}

}

return (sum > 0);

}



bool RowDouble(struct NODE lib[][N], int row)//

{

static int store[N][N+1] = {0};// 

bool flag = false;

int buf[N+1][2]= {0};// 

for (int n=1; n<=N; n++)//1-9 

{

if (store[row][n] == 1)// 

continue;



int stack[N] = {0};// 

int top = 0;

for (int i=0; i<N; i++)

{

if (lib[row][i].only)

{

if (lib[row][i].data[0] == n)

break;

else

continue;

}



if (lib[row][i].data[n] == POSSIBLE)

{

stack[top++] = i;

}

}

if (top == 2)//buf 

{

buf[n][0] = stack[0] + 1;//0 

buf[n][1] = stack[1] + 1;

}

}

for (int m=1; m<N; m++)

{

if (buf[m][0] != 0)// 

{ 

for (int n=m+1; n<=N; n++)//,,  

{

if (buf[m][0]==buf[n][0] && buf[m][1]==buf[n][1]) 

{//,

for (int r=1; r<=N; r++)

{

if (r != m && r != n)

{

lib[row][buf[m][0]-1].data[r] = IMPOSSIBLE;

lib[row][buf[m][1]-1].data[r] = IMPOSSIBLE;

}

}

store[row][m] = store[row][n] = 1;// 

flag = true;

}

}

}

} 



// 

int cbuf[N] = {0};

int k = 0;

for (int i=0; i<N; i++)//row

{

bool tf = true;

for (int j=1; j<=N; j++)

{//  

if (store[row][j] == 1 && lib[row][i].data[j] == POSSIBLE)

{

tf = false;

break;

}

}

if (tf && !lib[row][i].only && IsTwo(lib, row, i)) 

{

cbuf[k++] = i;

}

}



for (int i=0; i<k-1; i++)

{

for (int j=i+1; j<k; j++)

{

if (Equal(lib[row][cbuf[i]], lib[row][cbuf[j]]))// 

{

DoTheRow(lib, row, cbuf[i], cbuf[j]);



for (int n=1; n<=N; n++)// 

{

if (lib[row][cbuf[i]].data[n] == POSSIBLE)

{

store[row][n] = 1;

}

}

flag = true;

}

}

}



return flag;

}



bool IsTwo(struct NODE lib[][N], int row, int cel)// 

{

int sum = 0;

for (int i=1; i<=N; i++)

{

if (lib[row][cel].data[i] == 1)

sum++;

}

return (sum == 2);

}



bool Equal(const struct NODE & a, const struct NODE & b)// 

{

for (int i=1; i<=N; i++)

{

if (a.data[i] != b.data[i])

return false;

}

return true;

}



// 

void DoTheRow(struct NODE lib[][N], int row, int cel1, int cel2)

{

int buf[2] = {0};

int t = 0;

for (int i=1; i<=N; i++)// 

{

if (lib[row][cel1].data[i] == POSSIBLE)

{

buf[t++] = i;

}

}



for (int i=0; i<N; i++)//  

{

if (i != cel1 && i != cel2)

{

lib[row][i].data[buf[0]] = IMPOSSIBLE;

lib[row][i].data[buf[1]] = IMPOSSIBLE;

}

}

}



bool CelDouble(struct NODE lib[][N], int cel)// 

{   

static int store[N][N+1] = {0};// 

bool flag = false;

int buf[N+1][2]= {0};// 

for (int n=1; n<=N; n++)//1-9 

{

if (store[cel][n] == 1)// 

continue;



int stack[N] = {0};// 

int top = 0;

for (int i=0; i<N; i++)

{

if (lib[i][cel].only)

{

if (lib[i][cel].data[0] == n)

break;

else

continue;

}



if (lib[i][cel].data[n] == POSSIBLE)

{

stack[top++] = i;

}

}

if (top == 2)//buf 

{

buf[n][0] = stack[0] + 1;//0 

buf[n][1] = stack[1] + 1;

}

}

for (int m=1; m<N; m++)

{

if (buf[m][0] != 0)// 

{ 

for (int n=m+1; n<=N; n++)//,, 

{

if (buf[m][0]==buf[n][0] && buf[m][1]==buf[n][1]) 

{//,

for (int r=1; r<=N; r++)

{

if (r != m && r != n)

{

lib[buf[m][0]-1][cel].data[r] = IMPOSSIBLE;

lib[buf[m][1]-1][cel].data[r] = IMPOSSIBLE;

}

}

store[cel][m] = store[cel][n] = 1;// 

flag = true;

}

}

}

}

// 

int cbuf[N] = {0};

int k = 0;

for (int i=0; i<N; i++)//cel

{

bool tf = true;

for (int j=1; j<=N; j++)

{//  

if (store[cel][j] == 1 && lib[i][cel].data[j] == POSSIBLE)

{

tf = false;

break;

}

}

if (tf && !lib[i][cel].only && IsTwo(lib, i, cel)) 

{

cbuf[k++] = i;

}

}



for (int i=0; i<k-1; i++)

{

for (int j=i+1; j<k; j++)

{

if (Equal(lib[cbuf[i]][cel], lib[cbuf[j]][cel]))// 

{

DoTheCel(lib, cel, cbuf[i], cbuf[j]);



for (int n=1; n<=N; n++)// 

{

if (lib[cbuf[i]][cel].data[n] == POSSIBLE)

{

store[cel][n] = 1;

}

}

flag = true;

}

}

}



return flag;

}

// 

void DoTheCel(struct NODE lib[][N], int cel, int row1, int row2)

{

int buf[2] = {0};

int t = 0;

for (int i=1; i<=N; i++)// 

{

if (lib[row1][cel].data[i] == POSSIBLE)

{

buf[t++] = i;

}

}



for (int i=0; i<N; i++)//  

{

if (i != row1 && i != row2)

{

lib[i][cel].data[buf[0]] = IMPOSSIBLE;

lib[i][cel].data[buf[1]] = IMPOSSIBLE;

}

}

}



bool BlockDouble(struct NODE lib[][N], int row, int cel)// 

{

static int store[N][N+1] = {0};//

bool flag = false;

int buf[N+1][4]= {0};// 



int number = BlockPosition(row, cel);// 

for (int n=1; n<=N; n++)//1-9 

{

if (store[number][n] == 1) 
continue;
int stack[N][2] = {0}; 
int top = 0;

int x, y;

for (x=row; x<row+3; x++)
{
for (y=cel; y<cel+3; y++)
{
if (lib[x][y].only)
{
if (lib[x][y].data[0] == n)
break;
else
continue;
}
if (lib[x][y].data[n] == POSSIBLE)
{
stack[top][0] = x;
stack[top][1] = y;
top++;
}
}
}
if (top == 2)

{
buf[n][0] = stack[0][0] + 1;
buf[n][1] = stack[0][1] + 1;
buf[n][2] = stack[1][0] + 1;
buf[n][3] = stack[1][1] + 1;
}
}
for (int m=1; m<N; m++)
{
if (buf[m][0] != 0)
{ 
for (int n=m+1; n<=N; n++)
{
if (buf[m][0]==buf[n][0] && buf[m][1]==buf[n][1] 
 && buf[m][2]==buf[n][2] && buf[m][3]==buf[n][3]) 
{
for (int r=1; r<=N; r++)

{

if (r != m && r != n)

{

lib[buf[m][0]-1][buf[m][1]-1].data[r] = IMPOSSIBLE;

lib[buf[m][2]-1][buf[m][3]-1].data[r] = IMPOSSIBLE;

}

}

store[number][m] = store[number][n] = 1;// 

flag = true;

}

}

}

}

// 

int cbuf[N][2] = {0};

int k = 0;

int x, y;

for (x=row; x<row+3; x++)//,

{

for (y=cel; y<cel+3; y++)

{

bool tf = true;

for (int j=1; j<=N; j++)

{
if (store[number][j] == 1 && lib[x][y].data[j] == POSSIBLE)
{
tf = false;
break;
}
}
if (tf && !lib[x][y].only && IsTwo(lib, x, y)) 
{
cbuf[k][0] = x;
cbuf[k][1] = y;
k++;
}
}
}
for (int i=0; i<k-1; i++)
{
for (int j=i+1; j<k; j++)
{
if (Equal(lib[cbuf[i][0]][cbuf[i][1]], lib[cbuf[j][0]][cbuf[j][1]]))// 
{
DoTheBlock(lib, row, cel, cbuf[i][0], cbuf[i][1], cbuf[j][0], cbuf[j][1]);
for (int n=1; n<=N; n++)
{
if (lib[cbuf[i][0]][cbuf[i][1]].data[n] == POSSIBLE)
{
store[number][n] = 1;
}
}
flag = true;
}
}
}
return flag;
}
int BlockPosition(int row, int cel)// 
{
int n = 0;
if (row >= 0 && row < 3)
{
if ( cel >= 0 && cel < 3)
n = 0;
else if (cel >= 3 && cel < 6)
n = 1;
else 
n = 2; 
}
else if (row >= 3 && row < 6)
{
if ( cel >= 0 && cel < 3)
n = 3;
else if (cel >= 3 && cel < 6)
n = 4;
else 
n = 5; 
}
else
{
if ( cel >= 0 && cel < 3)
n = 6;
else if (cel >= 3 && cel < 6)
n = 7;
else 
n = 8; 
}
return n;
}
void DoTheBlock(struct NODE lib[][N], int row, int cel, int row1, int cel1, int row2, int cel2)
{
int buf[2] = {0};
int t = 0;
for (int i=1; i<=N; i++)
{
if (lib[row1][cel1].data[i] == POSSIBLE)
{
buf[t++] = i;
}
}
int x, y;
for (x=row; x<row+3; x++)
{
for (y=cel; y<cel+3; y++)
{
if (x != row1 && x != row2 && y != cel1 && y != cel2)
{
lib[x][y].data[buf[0]] = IMPOSSIBLE;
lib[x][y].data[buf[1]] = IMPOSSIBLE;
}
}
}
}
