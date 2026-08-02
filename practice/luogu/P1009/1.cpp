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

string mul( string a , string b )
{
    if ( a == "0" || b == "0" ) return "0" ;

    int len1 = a.length() , len2 = b.length() , sum , carry ;
    string ans( len1+len2 , '0' ) ;

    for ( int i = len1-1 ; i >= 0 ; i -- )
    {
        carry = 0 ;
        for ( int j = len2-1 ; j >= 0 ; j -- )
        {
            sum = ( a[i] - '0' ) * ( b[j] - '0' ) + ans[i+j+1] - '0' + carry ;
            ans[i+j+1] = sum % 10 + '0' ;
            carry = sum / 10 ;
        }
        ans[i] += carry ;
    }

    //remove the leading zero
    size_t start = ans.find_first_not_of( '0' ) ;

    return ans.substr( start ) ;
}

int main()
{
    int n ;
    string ans = "0" , fac = "1" ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        string ii = to_string( i ) ;
        fac = mul( fac , ii ) ;
        ans = add( ans , fac ) ;
    }
    cout << ans << endl ;
    return 0 ;
}