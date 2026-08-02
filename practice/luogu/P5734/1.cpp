#include <iostream>
#include <string>

using namespace std ;

int main()
{
    int q ;
    string s ;
    cin >> q >> s ;
    for ( int i = 0 ; i < q ; i ++ )
    {
        int type ;
        cin >> type ;
        if ( type == 1 )
        {
            string t ;
            cin >> t ;
            s += t ;
            cout << s << endl ;
        }
        if ( type == 2 )
        {
            int l , r ;
            cin >> l >> r ;
            s = s.substr ( l , r ) ;
            cout << s << endl ;
        }
        if ( type == 3 )
        {
            int pos ;
            string t ;
            cin >> pos >> t ;
            s = s.insert ( pos , t ) ;
            cout << s << endl ;
        }
        if ( type == 4 )
        {
            string t ;
            int pos ;
            cin >> t ;
            pos = s.find ( t ) ;
            if ( pos == string::npos ) cout << -1 << endl ;
            else cout << pos << endl ;
        }
    }
    return 0 ;
}