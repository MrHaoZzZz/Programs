#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    int n , m , a[105][25] ;
    double maxx = 0 ;
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < m ; j ++ )
        {
            cin >> a[i][j] ;
        }
        sort( a[i] , a[i] + m ) ;
        double score = 0 ;
        for ( int j = 1 ; j < m - 1 ; j ++ )
        {
            score += a[i][j] ;
        }
        score /= ( m - 2 ) ;
        if ( score > maxx ) maxx = score ;
    }
    printf( "%.2f\n" , maxx ) ;
    return 0 ;
}