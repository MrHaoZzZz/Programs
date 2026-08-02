#include <iostream>
#include <stack>

using namespace std ;

int main()
{
    int input ;
    stack<int> s ;
    while ( cin >> input )
    {
        if ( input == 0 ) break ;
        s.push( input ) ;
    }
    while ( !s.empty() )
    {
        cout << s.top() << ' ' ;
        s.pop() ;
    }
    cout << endl ;
    return 0 ;
}

/*
int main()
{
    int a[105] , n = 0 ;
    while ( cin >> a[n] )
    {
        if ( a[n] == 0 ) break ;
        n ++ ;
    }
    for ( int i = n-1 ; i >= 0 ; i -- ) cout << a[i] << ' ' ;
    cout << endl ;
    return 0 ;
}
*/