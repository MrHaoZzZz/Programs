#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

struct player
{
    string name , pos ;
    int dev , lv ;
} ;

void swap ( player &a , player &b )
{
    player temp = a ;
    a = b ;
    b = temp ;
}

int main()
{
    int n ;
    player p[115] ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        cin >> p[i].name >> p[i].pos >> p[i].dev >> p[i].lv ;
    }
    int temp = 1 ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        if ( p[i].pos == "BangZhu" ) swap( p[0] , p[i] ) ;
        if ( p[i].pos == "FuBangZhu" ) swap( p[temp ++] , p[i] ) ;
    }
    sort( p + 3 , p + n , []( player a , player b )
    {
        return a.dev < b.dev ;
    } ) ;
    for ( int i = 3 ; i < n ; i ++ )
    {
        if ( i >= 3 && i <= 4 ) p[i].pos = "HuFa" ;
        else if ( i >= 5 && i <= 8 ) p[i].pos = "ZhangLao" ;
        else if ( i >= 9 && i <= 15 ) p[i].pos = "TangZhu" ;
        else if ( i >= 16 && i <= 40 ) p[i].pos = "JingYing" ;
        else p[i].pos = "BangZhong" ;
    }
    for ( int i = 0 ; i < n ; i ++ )
    {
        cout << p[i].name << " " << p[i].pos << " " << p[i].lv << endl ;
    }
    return 0 ;
}