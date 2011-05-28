#include <iostream>
using namespace std;
const int maxn = 10000 + 1;
int n;
int a[maxn] = {0};

void init()
{
	int i,j;
	cin >> n;
	for(i=1;i<=n + 1;i++)
		cin >> a[i];
}

int main()
{
	int i,j;
	bool s;
	init();
	s = 1;
    for(i=1;i<=n + 1;i++)
    {
        if(a[i] != 0)
        {
            j = n - i + 1;
            if(a[i] > 0 && !s)
            {
                cout << '+';
            }
            if(a[i] != 0)
                s = 0;

            if(i <= n)
            {
                if(a[i] == -1)
                    cout << '-';
                else if(a[i] != 1)
                    cout << a[i];
            }
            else
                cout << a[i];
            if(j > 0)
            {
                cout << 'x';
                if(j > 1)
                {
                    cout << '^' << j;
                }
            }
        }
    }
	cout << endl;
	//system("pause");
	return 0;
}
