/*
ID:interne4
LANG:C++
PROG:charrec
*/
#include <iostream>
#include <stdio.h>
using namespace std ;

const	int INT_MAX = 0x7fffffff;
const   char letter[28] = " abcdefghijklmnopqrstuvwxyz" ;
int     n ;

int     font[28  ][21][21  ] ,
        data[1201][21]       ,
        dif [28  ][21][1201] ,
        cost[1201][4 ]       ;
int     from[1201][4] ,
        f   [1201]    ,
        g   [1201]    ,
        ans [1201]    ;

void    Input_font()
{
        freopen( "font.in" , "r" , stdin ) ;
        
        scanf( "%d" , &n ) ;
        getchar() ;
        
        for ( int i = 1 ; i <= 27 ; i ++ )
            for ( int j = 1 ; j <= 20 ; getchar() , j ++ )
                for ( int k = 1 ;  k <= 20 ; k ++ )
                    font[i][j][k] = getchar() ;
        
        return ;
}

void    Input_charrec()
{
        freopen( "charrec.in"  , "r" , stdin  ) ;
        freopen( "charrec.out" , "w" , stdout ) ;
        
        scanf( "%d" , &n ) ;
        getchar() ;
        
        for ( int i = 1 ; i <= n ; getchar() , i ++ )
            for ( int j = 1 ; j <= 20 ; j ++ )
                data[i][j] = getchar() ;
        
        for ( int i = 1 ; i <= 27 ; i ++ )
            for ( int j = 1 ; j <= 20 ; j ++ )
                for ( int k = 1 ; k <= n ; k ++ )
                {
                    dif[i][j][k] = 0 ;
                    for ( int p = 1 ; p <= 20 ; p ++ )
                        dif[i][j][k] += int( data[k][p] != font[i][j][p] ) ;
                }
        
        return ;
}

void    Init()
{
        for ( int i = 1 ; i <= n ; i ++ )
        {
            cost[i][1] = cost[i][2] = cost[i][3] = INT_MAX ;
            
            if ( i + 18 <= n )
            {
                 for ( int j = 1 ; j <= 27 ; j ++ )
                 {
                     int total = 0 ;
                     for ( int k = 2 ; k <= 20 ; k ++ ) total += dif[j][k][i+k-2] ;
                     if  ( total < cost[i][1] )
                     {
                         cost[i][1] = total ;
                         from[i][1] = j ;
                     }
                     for ( int k = 2 ; k <= 20 ; k ++ )
                     {
                         total += dif[j][k-1][i+k-2] ;
                         total -= dif[j][k  ][i+k-2] ;
                         if ( total < cost[i][1] )
                         {
                              cost[i][1] = total ;
                              from[i][1] = j ;
                         }
                     }
                 }
            }
            
            if ( i + 19 <= n )
            {
                 for ( int j = 1 ; j <= 27 ; j ++ )
                 {
                     int total = 0 ;
                     for ( int k = 1 ; k <= 20 ; k ++ ) total += dif[j][k][i+k-1] ;
                     if  ( total < cost[i][2] )
                     {
                         cost[i][2] = total ;
                         from[i][2] = j ;
                     }
                 }
            }
            
            if ( i + 20 <= n )
            {
                 for ( int j = 1 ; j <= 27 ; j ++ )
                 {
                     int total = dif[j][1][i] ;
                     for ( int k = 2 ; k <= 20 ; k ++ )
                         total += dif[j][k][i+k] ;
                     if  ( total < cost[i][3] )
                     {
                         cost[i][3] = total ;
                         from[i][3] = j ;
                     }
                     for ( int k = 2 ; k <= 20 ; k ++ )\
                     {
                         total += dif[j][k][i+k-1] ;
                         total -= dif[j][k][i+k  ] ;
                         if ( total < cost[i][3] )
                         {
                              cost[i][3] = total ;
                              from[i][3] = j ;
                         }
                     }
                 }
            }
        }
        
        return ;
}

void    Solve()
{
        f[0] = 0 ;
        for ( int i = 1 ; i <= n ; i ++ ) f[i] = INT_MAX ;
        for ( int i = 19 ; i <= n ; i ++ )
        {
            if ( i >= 19 && f[i-19] < INT_MAX && f[i-19] + cost[i-18][1] < f[i] )
            {
                 f[i] = f[i-19] + cost[i-18][1] ;
                 g[i] = 19 ;
            }
            if ( i >= 20 && f[i-20] < INT_MAX && f[i-20] + cost[i-19][2] < f[i] )
            {
                 f[i] = f[i-20] + cost[i-19][2] ;
                 g[i] = 20 ;
            }
            if ( i >= 21 && f[i-21] < INT_MAX && f[i-21] + cost[i-20][3] < f[i] )
            {
                 f[i] = f[i-21] + cost[i-20][3] ;
                 g[i] = 21 ;
            }
        }
        
        return ;
}

void    Output()
{
        int total = 0 ;
        for ( int i = n ; i ; i -= g[i] ) ans[ ++ total ]  = from[i-g[i]+1][g[i]-18] ;
        for ( int i = total ; i; i --) printf( "%c" , letter[ans[i]-1] ) ;
        printf("\n") ;
        
        return ;
}

int     main()
{
        Input_font() ;
        Input_charrec() ;
        Init() ;
        Solve() ;
        Output() ;
        
        return 0 ;
}
