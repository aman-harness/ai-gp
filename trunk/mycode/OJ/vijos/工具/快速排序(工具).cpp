void quickSort(int* arr,int startPos, int endPos) 
{ 
int i,j; 
int ch; 
ch=arr[startPos]; 
i=startPos; 
j=endPos; 
while(i<j) 
{ 
while(arr[j]>=ch && i<j)--j; 
arr[i]=arr[j]; 
while(arr[i]<=ch && i<j)++i; 
arr[j]=arr[i]; 
} 
arr[i]=ch; 
if(i-1>startPos) quickSort(arr,startPos,i-1); 
if(endPos>i+1) quickSort(arr,i+1,endPos); 
}
