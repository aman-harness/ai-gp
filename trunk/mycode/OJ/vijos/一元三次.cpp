#include <stdio.h>
#include <math.h>
double sort(double a[])
{int i,j;
double temp;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
   if(a[i]<a[j]) {temp=a[i];a[i]=a[j];a[j]=temp;}
for(i=0;i<3;i++)
printf("%.2lf ",a[i]);
}
int main()
{int count=0;
float a,b,c,d;
double t,i,ans[3];
scanf("%f %f %f %f",&a,&b,&c,&d);
for(i=-100;count<3;i+=0.01)
{t=a*pow(i,3)+b*pow(i,2)+c*i+d;
 if(fabs(t)<=0.0001) {ans[count]=i;count++;}
}
sort(ans);
}
