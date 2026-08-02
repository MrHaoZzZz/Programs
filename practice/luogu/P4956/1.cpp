#include <iostream>

using namespace std ;

int main()
{
    int n , money_week , x , k ;
    cin >> n ;
    money_week = n / 52 ;
    //money_week = 7X + 21K
    for ( int i = 1 ; i <= 100 ; i ++ )
    {
        for ( int j = 100 ; j > 0 ; j -- )
        {
            if ( money_week == 7*i + 21* j )
            {
                x = i ;
                k = j ;
            }
        }
    }
    cout << x << endl << k << endl ;
    return 0 ;
}