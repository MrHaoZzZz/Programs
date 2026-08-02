#include <iostream>
#include <string>

using namespace std ;

int main()
{
    string s ;
    cin >> s ;
    int len = s.length() ;
    for ( int i = 0 ; i < len ; i++ )
    {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            s[i] = s[i] - 'a' + 'A' ;
    }
    cout << s << endl ;
    return 0 ;
}