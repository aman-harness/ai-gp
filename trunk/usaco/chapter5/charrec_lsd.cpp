/*
ID:interne4
LANG:C++
PROG:charrec
*/
#include <iostream>
#include <fstream>
using namespace std ;
int sum[2000][30][30] = {0} ;
string origin[2000] ;
string data[2000] ;
int F[2000] = {0} ;
int Ans[2000] = {0} ;
int Kind[2000] = {0} ;
int state[2000] = {0} ;

inline int differ( int x , int y )
{
    int sum = 0 ;
    for ( int i = 0 ; i < 20 ; ++ i )
        if ( origin[y][i] != data[x][i] )
           ++ sum ;
    return sum ;
}

int solve20( int i , int j )
{
         return sum[i][j][20] ;         
}
         
int solve19( int i , int j )
{
         int minn = 0x7fffffff ;   
         for ( int k = 1 ; k < 21 ; ++ k )
         {
             minn = min ( minn , sum[i][j][20] - sum[i-20+k][j][k] + sum[i-20+k][j][k-1] ) ;
         }
         return minn ;
}
         
int solve21( int i , int j )
{
         int minn = 0x7fffffff ;
         for ( int k = 0 ; k < 21 ; ++ k )
         {
             minn = min( minn , sum[i][j][20] - sum[i-20+k][j][k] + sum[i-21+k][j][k] ) ;
         }
         return minn ;
}
         
ifstream finfont("font.in") ;
ifstream fin("charrec.in") ;
ofstream fout("charrec.out") ;

int main()
{
    int n ;
    finfont >> n ;
    for ( int i = 1 ; i <= n ; ++ i )
          finfont >> origin[i] ;
    fin >> n ;
    for ( int i = 1 ; i <= n ; ++ i )
        fin >> data[i] ;
    for ( int i = 1 ; i <= n ; ++ i )
        for ( int j = 0 ; j < 27 ; ++ j )
            for ( int k = 1 ; k <= 20 ; ++ k )
            {
                int now = j*20+k ;
                sum[i][j][k] = differ( i , now ) ;
                sum[i][j][k] += sum[i-1][j][k-1] ;
            } 
    for ( int i = 0 ; i <= n ; ++ i )
        F[i] = 10000000 ;   
    F[0] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i )
    {
        for ( int  j = 0 ; j < 27 ; ++ j )
        {
            if ( i >= 19 )
            {
               int num19 = solve19( i , j ) ;         
               if ( F[i] > F[i-19] + num19 && num19 <=120 )
               {
                      F[i] = F[i-19] + num19 ;
                      Ans[i] = j ;
                      Kind[i] = 19 ;
               }
            }
            if (  i >= 20 ) 
            {  
                 int num20 = solve20( i , j ) ;  
                if ( F[i] > F[i-20] + num20 && num20 <= 120 )
                {
                      F[i] = F[i-20] + num20 ;
                      Ans[i] = j ;
                      Kind[i] = 20 ;
                }
            }
            if (  i >= 21 ) 
            {
                   int num21 = solve21( i , j ) ;
               if ( F[i] > F[i-21] + num21  && num21 <= 120)
               {
                      F[i] = F[i-21] + num21 ;
                      Ans[i] = j ;
                      Kind[i] = 21 ;
               }
            }
        }
        if ( Ans[i] == -1 ) 
        {
             fout << "?" << endl ;
             return 0 ;
        }
    }
    int search = n  ;
    int l = 0 ;
    do
    {
          state[l++] = Ans[search] ;
          search -= Kind[search] ;
     //     fout << search << ' ' << Ans[search] << ' ' << Kind[search] <<   endl ;
    }while( search!=0 ) ;
    for ( int i = l - 1  ; i >= 0 ; -- i )
    {
        if ( state[i] != 0 )
           fout << char(state[i]+'a'-1) ;
        else fout << ' ' ;
    }
    fout << endl ;
  //  while(1);
    return 0 ;
}
