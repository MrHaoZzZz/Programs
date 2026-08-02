#include <iostream>

using namespace std ;

int main()
{
    int est[15] , cur = 0 , save = 0 ;
    for ( int i = 0 ; i < 12 ; i ++ ) cin >> est[i] ;
    //cout << "----------------------" << endl ;
    for ( int i = 0 ; i < 12 ; i ++ )
    {
        cur += 300 ;
        cur -= est[i] ;
        if ( cur < 0 )
        {
            cout << '-' << i+1 << endl ;
            return 0 ;
        }
        save += cur / 100 * 100 ;
        cur -= cur / 100 * 100 ;
        //cout << "cur: " << cur << " save: " << save << endl ;
    }
    cout << save * 1.2 + cur << endl ;
    return 0 ;
}