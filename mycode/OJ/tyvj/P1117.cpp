#include <iostream>
using namespace std;
const int maxn = 100 + 2;
char map[maxn][maxn] = {0};
bool v[maxn][maxn] = {0};
int n,m,t;
int s[2],e[2];

void init()
{
	int i,j;
	cin >> t >> m >> n;
	for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 's')
            {
                s[0] = i;
                s[1] = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'm')
            {
                e[0] = i;
                e[1] = j;
                map[i][j] = '.';
            }
        }
	for(i=1;i<=n;i++)
        map[i][0] = map[i][m + 1] = 'o';
	for(i=1;i<=m;i++)
        map[0][i] = map[n + 1][i] = 'o';
}

const int dir[4][2] = {0,1,1,0,-1,0,0,-1};
int ans = 55555;

int main()
{
	int i,b,k,x,y;
	int head,tail,q[maxn * maxn][4] = {0};
	init();
	head = 1;
	tail = 0;
	q[0][0] = s[0];
	q[0][1] = s[1];
	v[s[0]][s[1]] = 1;
	q[0][2] = 0;
	q[0][3] = 0;
	do
	{
        x = q[tail][0];
        y = q[tail][1];
        b = q[tail][3];
        if(b >= t)
            break;
        if(q[tail][2] > 0)
        {
            q[head][0] = x;
            q[head][1] = y;
            q[head][2] = 0;
            q[head ++][3] = b + 1;
            tail ++;
            continue;
        }
        if(x == e[0] && y == e[1])
        {
            ans = b;
            break;
        }

        for(i = 0; i < 4; i ++)
        {
            if(map[x + dir[i][0]][y + dir[i][1]] != 'o' && !v[x + dir[i][0]][y + dir[i][1]])
            {
                if(map[x + dir[i][0]][y + dir[i][1]] == '#' )
                {
                    q[head][0] = x + dir[i][0];
                    q[head][1] = y + dir[i][1];
                    q[head][2] = 1;
                    q[head ++][3] = b + 1;
                }
                else
                {
                    q[head][0] = x + dir[i][0];
                    q[head][1] = y + dir[i][1];
                    q[head][2] = 0;
                    q[head ++][3] = b + 1;
                }
                v[x + dir[i][0]][y + dir[i][1]] = 1;
            }
        }
        tail ++;
	}while(tail < head);

	cout << ans << endl;
	//system("pause");
	return 0;
}
