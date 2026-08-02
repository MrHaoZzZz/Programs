#include <iostream>

using namespace std ;

int n , a[105] ;

int main()
{
	cin >> n ;
	for ( int i = 0 ; i < n ; i ++ )
	{
		cin >> a[i] ;
	}
	
	int flag = 1 ;
	for ( int i = 0 ; i < n ; i ++ )
	{
		flag = 1 ;
		if ( a[i] == 1 ) continue ;
		for ( int j = 2 ; j*j <= a[i] ; j ++ )
		{
			if ( a[i] % j == 0 )
			{
				flag = 0 ;
				break ;
			}
		}
		if ( flag )
		{
			cout << a[i] << ' ' ;
		}
	}
	return 0 ;
}