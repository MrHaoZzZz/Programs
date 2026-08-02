#include <iostream>
#include <string>

using namespace std ;

int main()
{
    string s ;
    cin >> s ;
    int len = s.length() ;
    int boy = 0 , girl = 0 ;
    for ( int i = 0 ; i < len ; i++ )
    {
        if ( s[i] == 'b' || s[ i + 1 ] == 'o' || s[ i + 2 ] == 'y' ) boy ++ ;
        if ( s[i] == 'g' || s[ i + 1 ] == 'i' || s[ i + 2 ] == 'r' || s[ i + 3 ] == 'l' ) girl ++ ;
    }
    cout << boy << endl << girl << endl ;
    return 0 ;
}