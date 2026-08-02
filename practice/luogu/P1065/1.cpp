#include <iostream>

using namespace std ;

int main()
{
    int n , m , list[405] , ans = 0 ;
    int a[25][25][2] , step[25] = { 0 } ;
    int processed[25] , mac[25][10005];
    cin >> n >> m ;
    for ( int i = 0 ; i < n*m ; i ++ )
    {
        cin >> list[i] ;
    }
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < m ; j ++ )
        {
            cin >> a[i][j][0] ;
        }
    }
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < m ; j ++ )
        {
            cin >> a[i][j][1] ;
        }
    }

    for ( int i = 0 ; i < m*n ; i ++ )
    {
        step[list[i]] ++ ;
        int id = a[list[i]][step[list[i]]][0] ;
        int cost = a[list[i]][step[list[i]]][1] ;
        int worked = 0 ;
        for ( int j = processed[list[i]] ; ; j ++ )
        {
            if ( mac[id][j] == 0 )
            {
                worked ++ ;
            }
            else
            {
                worked = 0 ;
            }
            if ( worked == cost )
            {
                for ( int k = j - cost ; k < j ; k ++ )
                {
                    mac[id][k] = 1 ;
                }
                if ( j > ans ) ans = j ;
                processed[list[i]] = j ;
                break ;
            }
        }
    }
    cout << ans << endl ;
    return 0 ;
}