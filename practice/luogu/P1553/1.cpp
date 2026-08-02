#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

int main()
{
    string s ;
    cin >> s ;
    if ( s.find('.') != string::npos )
    {
        int pos = s.find('.') ;
        string left , right ;
        left = s.substr( 0 , pos ) ;
        right = s.substr( pos + 1 ) ;
        reverse( left.begin() , left.end() ) ;
        reverse( right.begin() , right.end() ) ;
        pos = left.find_first_not_of( '0' ) ;
        if ( pos != string::npos ) left = left.substr( pos ) ;
        pos = right.find_last_not_of( '0' ) ;
        if ( pos != string::npos ) right = right.substr( 0 , pos + 1 ) ;
        if ( left == "" ) left = "0" ;
        if ( right == "" ) right = "0" ;
        cout << left << '.' << right << endl ;
        return 0 ;
    }
    if ( s.find('/') != string::npos )
    {
        int pos = s.find('/') ;
        string left , right ;
        left = s.substr( 0 , pos ) ;
        right = s.substr( pos + 1 ) ;
        reverse( left.begin() , left.end() ) ;
        reverse( right.begin() , right.end() ) ;
        pos = left.find_first_not_of( '0' ) ;
        if ( pos != string::npos ) left = left.substr( pos ) ;
        pos = right.find_first_not_of( '0' ) ;
        if ( pos != string::npos ) right = right.substr( pos ) ;
        if ( left == "" ) left = "0" ;
        if ( right == "" ) right = "0" ;
        cout << left << '/' << right << endl ;
        return 0 ;
    }
    if ( s.find('%') != string::npos )
    {
        int pos = s.find('%') ;
        string left ;
        left = s.substr( 0 , pos ) ;
        reverse( left.begin() , left.end() ) ;
        pos = left.find_first_not_of( '0' ) ;
        if ( pos != string::npos ) left = left.substr( pos ) ;
        if ( left == "" ) left = "0" ;
        cout << left << '%' << endl ;
        return 0 ;
    }
    reverse( s.begin() , s.end() ) ;
    int pos = s.find_first_not_of( '0' ) ;
    if ( pos != string::npos ) s = s.substr( pos ) ;
    if ( s == "" ) s = "0" ;
    cout << s << endl ;
    return 0 ;
}