#include <stdio.h>

int main()
{
    int n , a[1000] ;
    // input n and a[] ;

    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < n ; j ++ )
        {
            if ( a[i] > a[j] )
            {
                int temp = a[i] ;
                a[i] = a[j] ;
                a[j] = temp ;
            }
        }
    }
    return 0 ;
}