/*
ID: interne4
PROG: cowcycle
LANG: C++
*/
#include <iostream>
#include <cstring>  
#include <algorithm> 
#include <map> 
#include <vector> 
using   namespace  std; 

const   int  N = 60; 

int  f[N], r[N], F, R, f1, f2, r1, r2; 
int  ans[2][N]; 
double  a[N], mini=1e15; 


void  update() 
{ 
     double  mean=0, vari=0, t; 
     int  i, j, k=0, p; 
     for (i = 1; i <= F; ++i) 
     for (j = R; j >= 1; --j) 
    { 
        t = ( double )f[i]/r[j]; 
        a[++k] = t; 
    } 
    sort(a+1,a+k+1); 

    --k; 
     for (i = 1; i <= k; ++i) 
    { 
        a[i]=a[i+1]-a[i]; 
        mean += a[i]; 
        vari += a[i]*a[i]; 
    } 
    mean /= k; 
    vari = vari/k - mean*mean; 

     if (vari < mini) 
    { 
        mini = vari; 

        memcpy(ans[0], f+1, F* sizeof ( int )); 
        memcpy(ans[1], r+1, R* sizeof ( int )); 


    } 
} 

void  dfs_rear( int  k,  int  low) 
{ 
     if (k > R) 
    { 
         int  i, j; 
         if ( f[F]*r[R] < 3*f[1]*r[1] )  return ; 

       update(); 
   } 
    else 
   { 
        for (r[k] = low; r[k]-R+k <= r2; ++r[k]) 
        { 
            dfs_rear(k+1,r[k]+1); 
        } 
    } 
} 

void  dfs_front( int  k,  int  low) 
{ 
     if (k > F) 
    { 
        dfs_rear(1, r1); 
    } 
     else 
    { 
         for (f[k] = low; f[k]-F+k <= f2; ++f[k]) 
        { 
            dfs_front(k+1, f[k]+1); 
        } 
    } 
} 

int  main() 
{ 
    int  i, j, k, t, h;
    
    freopen("cowcycle.in", "r", stdin);
    freopen( "cowcycle.out" , "w" ,stdout); 
    
    scanf( "%d%d%d%d%d%d" , &F,&R,&f1,&f2,&r1,&r2); 
    
    dfs_front(1, f1); 
    
    printf( "%d" , ans[0][0]); 
     for (i = 1; i < F; ++i) printf( " %d" , ans[0][i]); 
    puts( "" ); 
    printf( "%d" , ans[1][0]); 
     for (i = 1; i < R; ++i) printf( " %d" , ans[1][i]); 
    puts( "" ); 
     return  0; 
} 
