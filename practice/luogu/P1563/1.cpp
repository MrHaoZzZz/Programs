#include <iostream>

using namespace std ;

int main()
{
    int n , m , dir[100005] , current = 0 ;
    string name[100005] ;
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> dir[i] >> name[i] ;
    }
    for ( int i = 0 ; i < m ; i ++ )
    {
        int a , s ;
        cin >> a >> s ;
        if ( dir[current] == a ) current = ( current - s + n ) % n ;
        else current = ( current + s ) % n ;
        // cout << current << ' ' << name[current] << endl ;
    }
    cout /*<< "---------------------------------------\n"*/ << name[current] << endl ;
    return 0 ;
}