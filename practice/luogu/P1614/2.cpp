//Segment Tree
#include <iostream>

using namespace std ;

int n , m , a[3005] , minn = 300005 ;

struct tree
{
    int l , r ;
    int laze , pre ;
} t[12005] ;

void build( int p , int left , int right )
{
    t[p].l = left ; t[p].r = right ;
    if ( left == right )
    {
        t[p].pre = a[left] ;
        return ;
    }
    int mid = ( left + right ) / 2 ;
    build( p*2 , left , mid ) ;
    build( p*2 + 1 , mid + 1 , right ) ;
    t[p].pre = t[p*2].pre + t[p*2+1].pre ;
    return ;
}

void spread( int p )
{
    int mid = ( t[p].l + t[p].r ) / 2 ;
    if ( t[p].laze )
    {
        t[p*2].laze = t[p].laze ;
        t[p*2+1].pre = t[p].pre * ( mid - t[p].l + 1 ) ;

        t[p*2+1].laze = t[p].laze ;
        t[p*2+1].pre = t[p].pre * ( t[p].r - mid ) ;

        t[p].laze = 0 ;
    }
    return ;
}

int query( int p , int left , int right )
{
    if ( t[p].l >= left && t[p].r <= right ) return t[p].pre ;
    
    spread( p ) ;

    int res = 0 , mid = ( t[p].l + t[p].r ) / 2 ;

    if ( left <= mid ) res += query( p * 2 , left , right ) ;
    if ( right > mid ) res += query( p*2+1 , left , right ) ;

    return res ;
}

int main()
{
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;

    if ( n == 0 || m == 0 )
    {
        cout << 0 << endl ;
        return 0 ;
    }
    build( 1 , 1 , n ) ;

    for ( int i = 1 ; i <= n-m+1 ; i ++ )
    {
        int cur = query( 1 , i , i+m-1 ) ;
        if ( cur < minn ) minn = cur ;
    }

    cout << minn << endl ;
    return 0 ;
}