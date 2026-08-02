#include <iostream>
#include <cstdlib>
#include <string>

using namespace std ;

int main()
{
    int var[5] = {0} ;
    string s ;
    cin >> s ;
    while ( s != "" )
    {
        int pos = s.find( ';' ) ;
        if ( pos == string::npos ) break ;
        string op = s.substr( 0 , pos ) ;
        // cout << "op: " << op ;
        s = s.substr( pos + 1 ) ;
        // cout << " s: " << s << endl ;
        pos = op.find( ":=" ) ;
        string num_s = op.substr( pos + 2 ) ;
        if ( num_s[0] == 'a' || num_s[0] == 'b' || num_s[0] == 'c' )
        {
            num_s = to_string( var[ num_s[0] - 'a' ] ) ;
        }
        int num = atoi( num_s.c_str() ) ;
        var[ op[0] - 'a' ] = num ;
        pos = s.find( ';' ) ;
        if ( pos == string::npos ) break ;
    }
    cout << var[0] << ' ' << var[1] << ' ' << var[2] << endl ;
    return 0 ;
}