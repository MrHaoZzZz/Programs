#include <iostream>
#include <algorithm>
#include <string>

using namespace std ;

int main()
{
    int maxx = 0 , cnt[26] = {0} ;
    string s1 , s2 , s3 , s4 ;
    getline( cin , s1 ) ;
    getline( cin , s2 ) ;
    getline( cin , s3 ) ;
    getline( cin , s4 ) ;
    for ( int i = 0 ; i < s1.length() ; i++ ) if ( s1[i] >= 'A' && s1[i] <= 'Z' ) cnt[ s1[i] - 'A' ] ++ ;
    for ( int i = 0 ; i < s2.length() ; i++ ) if ( s2[i] >= 'A' && s2[i] <= 'Z' ) cnt[ s2[i] - 'A' ] ++ ;
    for ( int i = 0 ; i < s3.length() ; i++ ) if ( s3[i] >= 'A' && s3[i] <= 'Z' ) cnt[ s3[i] - 'A' ] ++ ;
    for ( int i = 0 ; i < s4.length() ; i++ ) if ( s4[i] >= 'A' && s4[i] <= 'Z' ) cnt[ s4[i] - 'A' ] ++ ;
    for ( int i = 0 ; i < 26 ; i ++ ) if ( cnt[i] > maxx ) maxx = cnt[i] ;
    /*
    for ( int i = 0 ; i < 26 ; i++ ) {
        cout << char( 'A' + i ) << ": " << cnt[i] << endl ;
    }
    cout << "max: " << maxx << endl ;
    */
    for ( int i = maxx ; i >= 1 ; i-- )
    {
        for ( int j = 0 ; j < 26 ; j++ )
        {
            if ( cnt[j] >= i ) cout << "* " ;
            else if ( j != 25 ) cout << "  " ;
        }
        cout << endl ;
    }
    for ( int i = 0 ; i < 25 ; i++ )  cout <<  char( 'A' + i ) << " " ;
    cout << 'Z' ;
    cout << endl ;
    return 0 ;
}