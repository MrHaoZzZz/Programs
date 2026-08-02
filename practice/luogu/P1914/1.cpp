#include <iostream>
#include <string>

using namespace std ;

int main()
{
    int n , len ;
    string s ;
    cin >> n >> s ;
    len = s.length() ;
    for ( int i = 0 ; i < len ; i++ )
    {
        s[i] =  ( s[i] - 'a' + n ) % 26 + 'a' ;
    }
    cout << s << endl ;
    return 0 ;
}