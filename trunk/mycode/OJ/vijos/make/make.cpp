#include <stdio.h> 
main()
{   int i;
    char c;
    freopen("make_file.txt","r",stdin);
    freopen("make_ok.txt","w",stdout);
    for(i=1;i<=100000;i++)
    {c=getchar();
     if(c=='$')break;
     if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9')putchar(c);
     else if(c=='{'||c=='}'||c=='['||c==']'||c=='('||c==')')putchar(c);
     else if(c=='\t'||c=='\\'||c=='|')putchar(c);
     else if(c>='\0'&&c<='\125')putchar(c);
    }
}
