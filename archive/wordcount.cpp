#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

std::string preprocess( std::string str )
{
    std::string result{} ;
    for ( char& c : str )
    {
        if ( std::isalnum( static_cast<unsigned char>( c ) ) ) result += std::tolower( c ) ;
    }
    return result ;
}

void count( std::string str , std::unordered_map<std::string,int>& freq )
{
    std::istringstream iss( str ) ;
    std::string word ;
    while ( iss >> word )
    {
        freq[preprocess( word )] ++ ;
    }
}

int main( int argc , char* argv[] )
{
    std::unordered_map<std::string , int> frequency ;
    if ( argc < 2 )
    {
        std::cerr << "Usage: " << argv[0] << "<filename>\n" ;
        return 1 ;
    }
    std::ifstream fin( argv[1] ) ;
    if ( !fin.is_open() )
    {
        std::cerr << "Cannot open the file!\n" ;
        return 1 ;
    }
    std::string line ;
    while ( std::getline( fin , line ) )
    {
        count( line , frequency ) ;
    }
    std::vector<std::pair<std::string , int>> data( frequency.begin() , frequency.end() ) ;
    std::sort( data.begin() , data.end() , []( const auto& a , const auto& b ) {
        return a.second != b.second ? a.second > b.second : a.first < b.first ;
    }) ;
    for ( size_t i = 0 ; i < data.size() && i < 10 ; i ++ )
    {
        std::cout << data[i].first << ": " << data[i].second << "\n" ;
    }
    return 0 ;
}