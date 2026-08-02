#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    int a[3] ;
    char x , y , z ;
    cin >> a[0] >> a[1] >> a[2] ;
    cin >> x >> y >> z ;
    sort( a , a+3 ) ;
    cout << a[x-65] << ' ' << a[y-65] << ' ' << a[z-65] << endl ;
    return 0 ;
}