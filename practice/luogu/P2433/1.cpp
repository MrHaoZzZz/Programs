#include <iostream>
#include <cmath>

#define pi 3.141593

using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    switch ( t )
    {
        case 1 :
        {
            cout << "I love Luogu!" << endl ;
            break ;
        }
        case 2 :
        {
            cout << 6 << ' ' << 4 << endl ;
            break ;
        }
        case 3 :
        {
            cout << 14 / 4 << endl << 14 - 14%4 << endl << 14 % 4 << endl ;
            break ;
        }
        case 4 :
        {
            cout << 166.667 << endl ;
            break ;
        }
        case 5 :
        {
            cout << ( 260 + 220 ) / ( 12 + 20 ) << endl ;
            break ;
        }
        case 6 :
        {
            cout << sqrt( 6*6 + 9*9 ) << endl ;
            break ;
        }
        case 7 :
        {
            cout << 110 << endl << 90 << endl << 0 << endl ;
            break ;
        }
        case 8 :
        {
            cout << 2*pi*5 << endl << pi*5*5 << endl << 4/3.0 * pi * 5*5*5 << endl ;
            break ;
        }
        case 9 :
        {
            cout << 22 << endl ;
            break ;
        }
        case 10 :
        {
            cout << 9 << endl ;
            break ;
        }
        case 11 :
        {
            cout << 100 / 3.0 << endl ;
            break ;
        }
        case 12 :
        {
            cout << 13 << endl << 'R' << endl ;
            break ;
        }
        case 13 :
        {
            cout << int( pow( 4/3.0 * pi * 64 + 4/3.0 * pi * 1000 , 1/3.0 ) ) ;
            break ;
        }
        case 14 :
        {
            cout << 50 << endl ;
            break ;
        }
    }
    return 0 ;
}