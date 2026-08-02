#include <iostream>

using namespace std ;

const int pow2[11] = { 1 , 2 , 4 , 8 , 16 , 32 , 64 , 128 , 256 , 512 , 1024 } ;
int map[1025][1025] ;

void solve( int x1 , int y1 , int x2 , int y2 )
{
    // cout << '(' << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ')' << endl ;
    // system("read -n1 -s") ;
    if ( x1 == x2 && y1 == y2 ) return ;

    int n = x2 - x1 + 1 ;
    for ( int i = 0 ; i < n / 2 ; i ++ )
    {
        for ( int j = 0 ; j < n / 2 ; j ++ )
        {
            map[ i + x1 ][ j + y1 ] = 0 ;
        }
    }

    /*
(1, 1) (2, 1) (3, 1) (4, 1) (5, 1) (6, 1) (7, 1) (8, 1) 
(1, 2) (2, 2) (3, 2) (4, 2) (5, 2) (6, 2) (7, 2) (8, 2) 
(1, 3) (2, 3) (3, 3) (4, 3) (5, 3) (6, 3) (7, 3) (8, 3) 
(1, 4) (2, 4) (3, 4) (4, 4) (5, 4) (6, 4) (7, 4) (8, 4) 
(1, 5) (2, 5) (3, 5) (4, 5) (5, 5) (6, 5) (7, 5) (8, 5) 
(1, 6) (2, 6) (3, 6) (4, 6) (5, 6) (6, 6) (7, 6) (8, 6) 
(1, 7) (2, 7) (3, 7) (4, 7) (5, 7) (6, 7)|(7, 7) (8, 7)|
(1, 8) (2, 8) (3, 8) (4, 8) (5, 8) (6, 8)|(7, 8) (8, 8)|
trace:
(5, 5) to (8, 8) n = 4
(n/2+x1, n/2+y1) to (x2, y2)
    */
    
    // solve right top
    solve( n/2 + x1 , y1 , x2 , n/2 + y1 - 1 ) ;
    // solve left bottom
    solve( x1 , n/2 + y1 , n/2 + x1 - 1 , y2 ) ;
    // solve right bottom
    solve( n/2 + x1 , n/2 + y1 , x2 , y2 ) ;
    return ;
}

int main()
{
    int n ;
    cin >> n ;
    //initialization
    for ( int i = 1 ; i <= pow2[n] ; i ++ )
    {
        for ( int j = 1 ; j <= pow2[n] ; j ++ )
        {
            map[i][j] = 1 ;
        }
    }
    solve( 1 , 1 , pow2[n] , pow2[n] ) ;
    for ( int i = 1 ; i <= pow2[n] ; i ++ )
    {
        for ( int j = 1 ; j <= pow2[n] ; j ++ )
        {
            cout << map[i][j] << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}