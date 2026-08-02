#include <iostream>
#include <string>

using namespace std ;

string num[10][5] = { "XXX" , "X.X" , "X.X" , "X.X" , "XXX" ,
				  	"..X" , "..X" , "..X" , "..X" , "..X" ,
				 	"XXX" , "..X" , "XXX" , "X.." , "XXX" ,
				   	"XXX" , "..X" , "XXX" , "..X" , "XXX" ,
				   	"X.X" , "X.X" , "XXX" , "..X" , "..X" ,
				   	"XXX" , "X.." , "XXX" , "..X" , "XXX" ,
				  	"XXX" , "X.." , "XXX" , "X.X" , "XXX" ,
				   	"XXX" , "..X" , "..X" , "..X" , "..X" ,
				  	"XXX" , "X.X" , "XXX" , "X.X" , "XXX" ,
				  	"XXX" , "X.X" , "XXX" , "..X" , "XXX" } ;

int main()
{
    int n ;
    string need ;
    cin >> n >> need ;
    for ( int i = 0 ; i < 5 ; i ++ )
    {
        for ( int j = 0 ; j < n ; j ++ )
        {
            cout << num[need[j]-'0'][i] ;
            if ( j < n - 1 ) cout << '.' ;
        }
        cout << endl ;
    }
    return 0 ;
}