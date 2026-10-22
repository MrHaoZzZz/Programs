#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "firefighter.h"

int main( int argc , char* argv[] )
{
    std::vector<int> base , target ;
    int battery , distance ;
    std::string plan ;

    // input
    base.push_back( atoi( argv[1] ) ) ;
    base.push_back( atoi( argv[2] ) ) ;
    target.push_back( atoi( argv[3] ) ) ;
    target.push_back( atoi( argv[4] ) ) ;
    battery = atoi( argv[5] ) ;
    distance = atoi( argv[6] ) ;
    plan = argv[7] ;

    std::cout << firefighter( base , target , battery , distance , plan ) << std::endl ;

    return 0 ;
}