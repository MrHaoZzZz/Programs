#include <iostream>
#include <cmath>

#define pi 3.14

using namespace std ;

int main()
{
    double h , r , v ;
    cin >> h >> r ;
    v = pi * r/10 * r/10 * h/10 ;
    cout << ceil( 20 / v ) << endl ;
    return 0 ;
}