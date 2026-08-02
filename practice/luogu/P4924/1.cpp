#include <iostream>

using namespace std ;

int map_pre[505][505] , map[505][505] ;
int n , m , ini = 1 ;

void clockwise( int x , int y , int r )
{
    for ( int i = x - r ; i <= x + r ; i ++ )
    {
        for ( int j = y - r ; j <= y + r ; j ++ )
        {
            if ( i >=1 && i <= n && j>= 1 && j <= n )
            {
                map[i][j] = map_pre[x - ( j - y )][y + ( i - x )] ;
            }
        }
    }
    for ( int i = x - r ; i <= x + r ; i ++ )
    {
        for ( int j = y - r ; j <= y + r ; j ++ )
        {
            if ( i >=1 && i <= n && j>= 1 && j <= n )
            {
                map_pre[i][j] = map[i][j] ;
            }
        }
    }
    return ;
}

void counterclockwise( int x , int y , int r )
{
    for ( int i = x - r ; i <= x + r ; i ++ )
    {
        for ( int j = y - r ; j <= y + r ; j ++ )
        {
            if ( i >=1 && i <= n && j>= 1 && j <= n )
            {
                map[i][j] = map_pre[x + ( j - y )][y - ( i - x )] ;
            }
        }
    }
    for ( int i = x - r ; i <= x + r ; i ++ )
    {
        for ( int j = y - r ; j <= y + r ; j ++ )
        {
            if ( i >=1 && i <= n && j>= 1 && j <= n )
            {
                map_pre[i][j] = map[i][j] ;
            }
        }
    }
    return ;
}

int main()
{
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        for ( int j = 1 ; j <= n ; j ++ )
        {
            map_pre[i][j] = ini ++ ;
            map[i][j] = map_pre[i][j] ;
        }
    }
    for ( int i = 0 ; i < m ; i ++ )
    {
        int x , y , r , z ;
        cin >> x >> y >> r >> z ;
        if ( z ==  0 ) clockwise( x , y , r ) ;
        else counterclockwise( x , y , r ) ;
    }
    for ( int i = 1 ; i <= n ; i ++ )
    {
        for ( int j = 1 ; j <= n ; j ++ )
        {
            cout << map[i][j] << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}