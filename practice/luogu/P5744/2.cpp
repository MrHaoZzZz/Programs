#include <iostream>

using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        string name ;
        int age , score ;
        cin >> name >> age >> score ;
        if ( score * 1.2 > 600 ) cout << name << ' ' << age + 1 << ' ' << 600 << endl ;
        else cout << name << ' ' << age + 1 << ' ' << ( int ) ( score * 1.2 ) << endl ;
    }
    return 0 ;
}