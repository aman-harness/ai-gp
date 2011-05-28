#include <iostream>
#include "math.h"
using namespace std;
#define PI 3.1415926
struct record
{
    float _x;
    float _y;
};
int main()
{struct record *p;
 int i,n;double sum,c,r;
 cin>>n>>r;
p=new struct record[101];
for(i=1;i<=n;i++)
  cin>>p[i]._x>>p[i]._y;
p[n+1]._x=p[1]._x;
p[n+1]._y=p[1]._y;
for(i=1;i<=n;i++)
  sum+=sqrt(pow((p[i]._x-p[i+1]._x),2)+pow((p[i]._y-p[i+1]._y),2));
c=2*PI*r;
sum+=c;
printf("%.2lf",sum);
return 0;
}
