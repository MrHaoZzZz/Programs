#include <iostream>

using namespace std ;

int main()
{
    int p1 , p2 , p3 ;
    string s ;
    cin >> p1 >> p2 >> p3 >> s ;
    int len = s.size() ;
    for ( int i = 0 ; i < len ; i ++ )
    {
        if ( s[i] != '-' )
        {
            cout << s[i] ;
            continue ;
        }
        if ( ( s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z' ) || ( s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9' ) )
        {
            if ( s[i-1] >= s[i+1] )
            {
                cout << '-' ;
                continue ;
            }
            bool letter = false ;
            if ( s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z' ) letter = true ;
            if ( ( p3 == 1 && p1 == 1 ) || ( p3 == 1 && p1 == 2 && !letter ) )
            {
                for ( int j = s[i-1]+1 ; j < s[i+1] ; j ++ )
                {
                    for ( int k = 0 ; k < p2 ; k ++ )
                    {
                        cout << ( char ) ( j ) ;
                    }
                }
            }
            else if ( ( p3 == 2 && p1 == 1 ) || ( p3 == 2 && p1 == 2 && !letter ) )
            {
                for ( int j = s[i+1]-1 ; j > s[i-1] ; j -- )
                {
                    for ( int k = 0 ; k < p2 ; k ++ )
                    {
                        cout << ( char ) ( j ) ;
                    }
                }
            }
            else if ( p3 == 1 && p1 == 2 && letter )
            {
                for ( int j = s[i-1]+1 ; j < s[i+1] ; j ++ )
                {
                    for ( int k = 0 ; k < p2 ; k ++ )
                    {
                        cout << ( char ) ( j - 'a' + 'A' ) ;
                    }
                }
            }
            else if ( p3 == 2 && p1 == 2 && letter )
            {
                for ( int j = s[i+1]-1 ; j > s[i-1] ; j -- )
                {
                    for ( int k = 0 ; k < p2 ; k ++ )
                    {
                        cout << ( char ) ( j - 'a' + 'A' ) ;
                    }
                }
            }
            else if ( p1 == 3 )
            {
                for ( int j = s[i+1]-1 ; j > s[i-1] ; j -- )
                {
                    for ( int k = 0 ; k < p2 ; k ++ )
                    {
                        cout << '*' ;
                    }
                }
            }
        }
        else cout << '-' ;
    }
    cout << endl ;
    return 0 ;
}