#include <iostream>

using namespace std ;

int main()
{
    double s , tot , ans = 0 ;
    cin >> s ;
    for ( double i = 2 ; tot < s ; i *= 0.98 )
    {
        ans ++ ;
        tot += i ;
    }
    cout << ans << endl ;
    return 0 ;
}