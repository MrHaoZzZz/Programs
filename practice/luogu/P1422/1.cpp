#include <iostream>

using namespace std ;

int main()
{
    double n , res ;
    cin >> n ;
    if ( n <= 150 ) printf( "%.1lf\n" , n * 0.4463 ) ;
    else if ( n >= 401 ) printf( "%.1lf\n" , 150 * 0.4463 + 250 * 0.4663 + ( n - 400 ) * 0.5663 ) ;
    else printf( "%.1lf\n" , 150 * 0.4463 + ( n - 150 ) * 0.4663 ) ;
    return 0 ;
}