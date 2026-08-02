#include <iostream>

using namespace std ;

int main()
{
    int a , b , max_day = 0 , max_num = 0 ;
    for ( int i = 0 ; i < 7 ; i ++ )
    {
        cin >> a >> b ;
        if ( a + b > 8 && a + b > max_num )
        {
            max_day = i + 1 ;
            max_num = a+b ;
        }
    }
    cout << max_day << endl ;
    return 0 ;
}