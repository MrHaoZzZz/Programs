#include <iostream>

using namespace std ;

int main()
{
    int x , y , cnt = 0 , leapyear[1500] ;
    cin >> x >> y ;
    for ( int i = x ; i <= y ; i ++ )
    {
        if ( i % 4 == 0 && i % 100 != 0 || i % 400 == 0 ) leapyear[ cnt ++ ] = i ;
    }
    cout << cnt << endl ;
    for ( int i = 0 ; i < cnt ; i ++ )
    {
        cout << leapyear[i] << " " ;
    }
    cout << endl ;
    return 0 ;
}