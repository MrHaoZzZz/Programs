#include <iostream>

using namespace std ;

int solve( int day , int rest )
{
    if ( day == 1 ) return 1 ;
    if ( day == 2 ) return ( rest + 1 ) * 2 ;
    return solve( day - 1 , ( rest + 1 ) * 2 ) ;
}

int main()
{
    int day ;
    cin >> day ;
    cout << solve( day , 1 ) << endl ;
    return 0 ;
}