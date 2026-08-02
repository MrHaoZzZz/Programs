#include <iostream>
#include <queue>
#include <vector>

using namespace std ;

int main()
{
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<vector<int>> adj( n ) ;
    for ( int i = 0 ; i < m ; i ++ )
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        adj[v1][v2] = 1 ;
        adj[v2][v1] = 1 ;
    }
    return 0 ;
}