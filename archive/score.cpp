#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main( int argc , char* argv[] )
{
    std::string line ;

    if ( argc < 2 )
    {
        std::cerr << "Usage: " << argv[0] << " <filename>\n" ;
        return 1 ;
    }
    std::ifstream fin( argv[1] ) ;
    if ( !fin.is_open() )
    {
        std::cerr << "Cannot open the file: " << argv[1] << '\n' ;
        return 1 ;
    }

    while ( std::getline( fin , line ) )
    {
        count( *line , *score ) ;
    }
    return 0 ;
}