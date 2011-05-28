#include <iostream>
using namespace std;
int a[4000]={0},s,n,m;
short b[4000]={0};
void quickSort(int* arr,short* p,int startPos, int endPos) 
{ 
int i,j; 
int ch,c; 
ch=arr[startPos]; 
c=p[startPos];
i=startPos; 
j=endPos; 
while(i<j) 
{ 
while(arr[j]<=ch && i<j)--j; 
arr[i]=arr[j]; 
p[i]=p[j];
while(arr[i]>=ch && i<j)++i; 
arr[j]=arr[i];
p[j]=p[i]; 
} 
arr[i]=ch;
p[i]= c;
if(i-1>startPos) quickSort(arr,p,startPos,i-1); 
if(endPos>i+1) quickSort(arr,p,i+1,endPos); 
}

int main(){
    int i,j;
    cin>>n>>m;
    s=n;
    for(i=1;i<=n;i++){cin>>a[i];b[i]=1;}
    for(i=1;i<=m;i++){cin>>a[n+i];b[n+i]=2;}
    quickSort(a,b,1,n+m);
    for(i=1;i<=n+m && a[i]>0;i++){
        if(b[i]==1){
        j=i+1;
        while(j<=n+m && a[j]>0){
            if(b[j]==2 && a[i]>a[j]){
                s--;
                b[j]=0;
                break;
            }
            if(b[j]==0 && a[i]>a[j]) break;
            j++;
        }
        }
    }
    cout<<s;
    return 0;
}
