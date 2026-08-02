#include <stdio.h>
#include <array.h>
#include <strlib.h>

int size(str array)
{
    return str2nat(array, 0, search(array, 0, ' '));
}

arr(int) build(arr(str) array, int n)
{
    // create the container for the elements of the array
    arr(int) a = new(int, n);
    
    for(int i = 0; i < n; i++)
    {
        a[i] = atoi(array[i+1]);
    };

    return a;
}

void swap(arr(int) a, int i, int j)
{
    int t = a[i];
    a[i]  = a[j];
    a[j]  = t;
}

arr(int) bubblesort(arr(int) a, int n)
{
    arr(int) r = a;

    for ( int i = 0 ; i < n-1 ; i ++ )
    {
        for ( int j = 0 ; j < n - i - 1 ; j ++ )
        {
            if ( r[j] > r[j+1] ) swap( r , j , j + 1 ) ;
        }
    }

    return r;
}

void insert( arr( int ) a , int n , int i )
{
    while ( i > 0 && a[i-1] > a[i] )
    {
        swap( a , i , i - 1 ) ;
        i -- ;
    }
    return ;
}

arr( int ) insertionsort( arr( int ) a , int n )
{
    arr( int ) r = a ;

    for ( int i = 1 ; i < n ; i ++ )
    {
        insert( r , n , i ) ;
    }

    return r ;
}

arr( int ) selectionsort( arr( int ) a , int n )
{
    arr( int ) r = a ;

    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = i + 1 ; j < n ; j ++ )
        {
            if ( r[i] > r[j] ) swap( r , i , j ) ;
        }
    }

    return r ;
}

arr( int ) futchflag( arr( int ) a , int n )
{
    if ( n <= 1 ) return a ;

    int povit = a[0] ;
    int low , mid , high = n - 1 ;

    while ( mid <= high )
    {
        if ( a[mid] < povit )
        {
            swap( a , low , mid ) ;
            low ++ ;
            mid ++ ;
        }
        else if ( a[mid] == povit ) mid ++ ;
        else
        {
            swap( a , mid , high ) ;
            high -- ;
        }
    }

    return a ;
}

arr( int ) merge( arr( int ) a , int n , arr( int ) b , int m )
{
    if ( n == 0 ) return b ;
    if ( m == 0 ) return a ;
    arr( int ) c = new(int, n+m);
    int i = 0 , j = 0 , k = 0 ;
    while ( i < n && j < m )
    {
        if ( a[i] < b[j] )
        {
            c[k ++] = a[i ++] ;
        }
        else
        {
            c[k ++] = b[j ++] ;
        }
    }
    while ( i < n ) c[k ++] = a[i ++] ;
    while ( j < m ) c[k ++] = b[j ++] ;
    return c ;
}

void printa(arr(int) a, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    };
    
    printf("\n");
}