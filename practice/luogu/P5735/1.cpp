#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    double ans = 0 ;
    double x1 , y1 , x2 , y2 , x3 , y3 ;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
    ans += sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) ) ;
    ans += sqrt( ( x2 - x3 ) * ( x2 - x3 ) + ( y2 - y3 ) * ( y2 - y3 ) ) ;
    ans += sqrt( ( x3 - x1 ) * ( x3 - x1 ) + ( y3 - y1 ) * ( y3 - y1 ) ) ;
    printf( "%.2f\n" , ans ) ;
    return 0 ;
}