#include <iostream>

using namespace std ;

int n , m , k , ans = 0 ;
int map[105][105] = {0} ;

void match( int a , int b )
{
    map[a][b] = 1 ;
    for ( int i = 1 ; i <= 2 ; i ++ )
    {
        if ( a + i <= n )
        {
            map[a+i][b] = 1 ;
        }
        if ( a - i >= 1 )
        {
            map[a-i][b] = 1 ;
        }
        if ( b + i <= n )
        {
            map[a][b+i] = 1 ;
        }
        if ( b - i >= 1 )
        {
            map[a][b-i] = 1 ;
        }
    }
    if ( a + 1 <= n && b + 1 <= n ) map[a+1][b+1] = 1 ;
    if ( a + 1 <= n && b - 1 >= 1 ) map[a+1][b-1] = 1 ;
    if ( a - 1 >= 1 && b + 1 <= n ) map[a-1][b+1] = 1 ;
    if ( a - 1 >= 1 && b - 1 >= 1 ) map[a-1][b-1] = 1 ;
    return ;
}

void fluorite( int a , int b )
{
    map[a][b] = 1 ;
    for ( int i = -2 ; i <= 2 ; i ++ )
    {
        for ( int j = -2 ; j <= 2 ; j ++ )
        {
            if ( a+i >= 1 && a+i <= n && b+j >= 1 && b+j <= n )
            {
                map[a+i][b+j] = 1 ;
            }
        }
    }
    return ;
}

void count()
{
    for ( int i = 1 ; i <= n ; i ++ )
    {
        for ( int j = 1 ; j <= n ; j ++ )
        {
            if ( map[i][j] == 0 ) ans ++ ;
            //cout << map[i][j] << " " ;
        }
        //cout << endl ;
    }
    return ;
}

int main()
{
    cin >> n >> m >> k ;
    for ( int i = 0 ; i < m ; i ++ )
    {
        int x , y ;
        cin >> x >> y ;
        match( x , y ) ;
    }
    for ( int i = 0 ; i < k ; i ++ )
    {
        int o , p ;
        cin >> o >> p ;
        fluorite( o , p ) ;
    }

    count() ;
    cout << ans << endl ;
    return 0 ;
}