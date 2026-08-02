#include <iostream>
#include <stack>

using namespace std ;

int main()
{
    stack<int> s ;
    int n ;
    cin >> n ;
    s.push( n ) ;
    while ( n != 1 )
    {
        if ( n % 2 == 0 ) n /= 2 ;
        else n = n*3 + 1 ;
        s.push( n ) ;
    }
    while ( !s.empty() )
    {
        cout << s.top() << ' ' ;
        s.pop() ;
    }
    cout << endl ;
    return 0 ;
}