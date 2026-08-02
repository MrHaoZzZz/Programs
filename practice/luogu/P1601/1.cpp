#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

string add( string a , string b )
{
    int len1 = a.length() , len2 = b.length() , carry = 0 , d1 , d2 , sum ;
    string ans ;
    if ( len1 > len2 )
    {
        swap( a , b ) ;
        swap( len1 , len2 ) ;
    }

    for ( int i = len1 - 1 , j = len2 - 1 ; i >= 0 || j >= 0 || carry ; i -- , j -- )
    {
        d1 = ( i >= 0 ) ? a[i] - '0' : 0 ;
        d2 = ( j >= 0 ) ? b[j] - '0' : 0 ;
        sum = d1 + d2 + carry ;
        ans = char( sum%10 + '0' ) + ans ;
        carry = sum / 10 ;
    }

    return ans ;
}

int main()
{
    string a , b ;
    cin >> a >> b ;
    cout << add( a , b ) << endl ;
    return 0 ;
}