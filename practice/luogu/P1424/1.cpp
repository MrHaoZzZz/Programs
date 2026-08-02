#include <iostream>

using namespace std ;

int main()
{
    int x , n , day , ans = 0 ;
    cin >> x >> n ;
    for ( int i = x-1 ; i < n+x-1 ; i ++ )
    {
        day = i % 7 ;
        if ( !( day == 5 || day == 6 ) ) ans += 250 ;
    }
    cout << ans << endl ;
    return 0 ;
}