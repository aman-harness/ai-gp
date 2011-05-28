#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef struct
{
    char op;
    long long v;
    bool ok;
}node1;

typedef struct
{
    int cnt;
    node1 I[1010];
}node2;

node2 E[30],H[30];
int w[255];
int N;

bool big(char o1,char o2)
{
    if (o1=='(') return true;
    if (o2=='(') return true;
    return w[o1]>w[o2];
}
void postfix(int Q)
{
    char stack1[1010];
    int top=0,p=0;
    stack1[0]='@';
    for (int i=1;i<=E[Q].cnt;i++)
    {
        if (E[Q].I[i].op==0)
        {
            H[Q].I[++p].v=E[Q].I[i].v;
            H[Q].I[p].ok=E[Q].I[i].ok;
        }
        else
        {
            if (E[Q].I[i].op==')')
            {
                while (stack1[top]!='(')
                {
                    H[Q].I[++p].op=stack1[top];
                    stack1[top--]=0;
                }
                stack1[top--]=0;
            }
            else if (big(E[Q].I[i].op,stack1[top]))
                stack1[++top]=E[Q].I[i].op;
            else
            {
                while (!big(E[Q].I[i].op,stack1[top]) && top>0)
                {
                    H[Q].I[++p].op=stack1[top];
                    stack1[top--]=0;
                }
                stack1[++top]=E[Q].I[i].op;
            }
        }
    }
    H[Q].cnt=p;
}

long long power(long long a,long long b)
{
    long long Q=1;
    for (int i=1;i<=b;i++) Q*=a;
    return Q;
}
long long evaluate(int Q)
{
    int top=-1;
    long long stack1[1010],a,b;
    for (int i=1;i<=H[Q].cnt;i++)
    {
        if (H[Q].I[i].op==0)
        {
            stack1[++top]=H[Q].I[i].v;
        }
        else
        {
            b=stack1[top--]; a=stack1[top--];
            switch(H[Q].I[i].op)
            {
                case '+':
                    stack1[++top]=a+b;
                    break;
                case '-':
                    stack1[++top]=a-b;
                    break;
                case '*':
                    stack1[++top]=a*b;
                    break;
                case '/':
                    stack1[++top]=a/b;
                    break;
                case '^':
                    stack1[++top]=power(a,b);
                    break;
            }
        }
    }
    return stack1[0];
}
bool is_operator(char c)
{
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' ||c==')');
}

void readf(int Q)
{
    int i=0; char c;
    while (!cin.eof())
    {
        while ((c=cin.get())==' ');
            if (c==10 || c==13 || cin.eof()) break;
        i++;
        if (is_operator(c)) E[Q].I[i].op=c;
        else if (c=='a') E[Q].I[i].ok=true;
        else
        {
            cin.putback(c);
            E[Q].I[i].op=0;
            cin >> E[Q].I[i].v;
        }
    }
    E[Q].I[ E[Q].cnt=i+1 ].op='@';
}
void replace_letter(int P)
{
    int i,j;
    for (i=0;i<=N;i++)
        for (j=1;j<=H[i].cnt;j++)
            if (H[i].I[j].ok) H[i].I[j].v=P;
}

void solve()
{
    long long A,B,C;
    bool right[30];
    for (int i=1;i<=N;i++) right[i]=true;
    for (int i=1;i<=10;i++)
    {
        replace_letter(rand()%100);
        A=evaluate(0);
        for (int j=1;j<=N;j++)
        {
            B=evaluate(j); C=A-B;
            if (C<0) C=-C;
            if (C>0.1) right[j]=false;
        }
    }
    for (int i=1;i<=N;i++)
        if (right[i]) printf("%c",i-1+'A');
    printf("\n");
}

int main()
{
    w['@']=0; w['^']=3;
    w['+']=w['-']=1;
    w['*']=w['/']=2;
    readf(0); postfix(0);
    cin>>N; getchar();
    for (int i=1;i<=N;i++)
    {
        readf(i); postfix(i);
    }
    solve();
    system("pause");
    return 0;
}
