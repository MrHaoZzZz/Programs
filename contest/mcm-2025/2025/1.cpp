/*
每个分叉点是3m*4m矩形，突点水流速度30 m^3/min，则水流速度为30/12 = 2.5 m/min
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std ;

struct Point
{
    double x , y , z ;
}

struct Edge
{
    int v1 , v2 ;
    double length ;
    double fillTime ;
    double slope ;
}

struct Node
{
    Point pos ;
    double waterArr = INF ;
}

void adjIni( int E , vector<Node> nodes , vector<Edge> edges , vector<vector<int>>& adj )
{
    for ( Edge e : edges )
    {
        adj[e.v1][e.v2] = 1 ;
        adj[e.v2][e.v1] = 1 ;
    }
}


int main()
{
    int N , E ; // numbers of Node and Edge
    vector<Node> nodes( N ) ;
    vector<Edge> edges( E ) ;
    vector<vector<int>> adj( N ) ;
    cin >> N >> E ;
    adjIni() ;
    // ...
    return 0 ;
}