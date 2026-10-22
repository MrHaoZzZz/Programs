#include <iostream>
#include <vector>
#include <algorithm>
#include "firefighter.h"
#include <string>

bool enoughBattery( std::vector<int> base , std::vector<int> target , int battery )
{
    // have no relation to plan
    int pathLength = ( target.at( 0 ) - base.at( 0 ) ) + ( target.at(1) - base.at( 1 ) ) ;
    int neededBattery = pathLength * 2 + 2 ; // reach and return + turn 180 degree(RR)
    return neededBattery <= battery ;
}

std::string firefighter( std::vector<int> base , std::vector<int> target , int battery , int distance , std::string plan )
{
    if ( !enoughBattery( base , target , battery ) )
    {
        
    }
}