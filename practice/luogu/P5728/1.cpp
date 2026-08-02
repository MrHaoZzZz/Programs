#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    int n , ans = 0 , chi[1005] , math[1005] , eng[1005] , tot[1005] ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> chi[i] >> math[i] >> eng[i] ;
        tot[i] = chi[i] + math[i] + eng[i] ;
    }
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = i + 1 ; j < n ; j ++ )
        {
            if ( abs( chi[i] - chi[j] ) <= 5 && abs( math[i] - math[j] ) <= 5 && 
                 abs( eng[i] - eng[j] ) <= 5 && abs( tot[i] - tot[j] ) <= 10 ) ans ++ ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}