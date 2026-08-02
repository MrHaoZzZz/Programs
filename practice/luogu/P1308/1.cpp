#include <iostream>
#include <string>

using namespace std ;

int main()
{
    string word , centence ;
    getline( cin , word ) ;
    getline( cin , centence ) ;
    for ( int i = 0 ; i < word.length() ; i ++ ) word[i] = tolower( word[i] ) ;
    for ( int i = 0 ; i < centence.length() ; i ++ ) centence[i] = tolower( centence[i] ) ;
    word = ' ' + word + ' ' ;
    centence = ' ' + centence + ' ' ;
    int pos = centence.find( word ) ;
    if ( pos == string::npos )
    {
       cout << -1 << endl ;
       return 0 ;
    }
    int cnt = 0 ;
    for ( int i = 0 ; i <= centence.length() - word.length() ; i ++ )
    {
        if ( centence.substr( i , word.length() ) == word ) cnt ++ ;
    }
    cout << cnt << ' ' << pos << endl ;
    return 0 ;
}