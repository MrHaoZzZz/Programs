#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

string word[30] = { "" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" ,
                        "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" ,
                        "seventeen" , "eighteen" , "nineteen" , "twenty" , "a" , "both" , "another" ,
                        "first" , "second" , "third" } ;

int num[30] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 ,
                      10 , 11 , 12 , 13 , 14 , 15 , 16 ,
                      17 , 18 , 19 , 20 , 1 , 2 , 1 ,
                      1 , 2 , 3 } ;

int main()
{
    string s ;
    int cnt = 0 , ans[1005] ;
    for ( int i = 0 ; i < 6 ; i ++ )
    {
        cin >> s ;
        for ( int j = 0 ; j <= 26 ; j++ )
        {
            if ( s == word[j] )
            {
                ans[cnt ++] = num[j]*num[j] % 100 ;
            }
        }
    }
    sort( ans , ans + cnt ) ;
    if ( cnt == 0 )
    {
        cout << "0" << endl ;
        return 0 ;
    }
    if ( ans[0] != 0 ) cout << ans[0] ;
    for ( int i = 1 ; i < cnt ; i++ )
    {
        if ( ans[i] < 10 ) cout << "0" ;
        cout << ans[i] ;
    }
    cout << endl ;
    return 0 ;
}