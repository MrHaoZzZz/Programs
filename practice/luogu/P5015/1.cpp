#include <iostream>
#include <string>

using namespace std ;

int main()
{
    string s ;
    getline( cin , s ) ;
    int len = s.length() , ans = 0 ;
    for ( int i = 0 ; i < len ; i++ )
    {
        if ( s[i] != ' ' ) ans++ ;
    }
    cout << ans << endl ;
    return 0 ;
}