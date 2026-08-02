#include <iostream>

using namespace std ;

int main()
{
    double h , m , bmi ;
    cin >> m >> h ;
    bmi = m / ( h*h ) ;
    if ( bmi >= 24 )
        cout << bmi << endl << "Overweight" << endl ;
    else if ( bmi < 18.5 ) cout << "Underweight" << endl ;
    else cout << "Normal" << endl ;
    return 0 ;
}