#include <iostream>
#include <stack>
#include <queue>
#include <vector>

void dfs_adj( int start , vector<vector<int>> adj , vector<int>& visited )
{
    if ( visited[start] ) return ;
    visited[start] = 1 ;

    for ( int i = 0 ; i < adj.size() ; i ++ )
    {
        if ( adj[start][i] && !visited[i] )
        {
            visited[i] = 1 ;
            dfs_adj( i , adj , N , visited ) ;
        }
    }
}

void bfs_adj( int start , vector<vector<int>> adj )
{
    vector<int> visited( adj.size() ) ;
    queue<int> q ;
    q.push( start ) ;
    visited[start] = 1 ;
    while ( !q.empty() )
    {
        int v = q.front() ; q.pop() ;
        visited[v] = 1 ;
        for ( int i = 0 ; i < adj.size() ; i ++ )
        {
            if ( adj[v][i] && !visited[i] )
            {
                q.push( i ) ;
            }
        }
    }
}

int main()
{
    int N , E ;
    vector<vector<bool>> adj( N ) ;

}