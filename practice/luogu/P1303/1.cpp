#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

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
    string a , b ;
    cin >> a >> b ;
    cout << mul( a , b ) << endl ;
    return 0 ;
}