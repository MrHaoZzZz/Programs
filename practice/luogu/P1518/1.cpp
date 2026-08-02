#include <iostream>
#include <cstring>

using namespace std ;

int dr[4] = { -1 , 0 , 1 , 0 } ;
int dc[4] = { 0 , 1 , 0 , -1 } ;

int main()
{
    string map[10] ;
    int fr , fc , cr , cc ;
    for ( int i = 0 ; i < 10 ; i ++ ) cin >> map[i] ;
    for ( int i = 0 ; i < 10 ; i ++ )
    {
        for ( int j = 0 ; j < 10 ; j ++ )
        {
            if ( map[i][j] == 'F' )
            {
                fr = i ;
                fc = j ;
            }
            if ( map[i][j] == 'C' )
            {
                cr = i ;
                cc = j ;
            }
        }
    }

    int fdir = 0 , cdir = 0 , step = 0 ;
    bool visited[10][10][4][10][10][4] ;
    memset( visited , false , sizeof( visited ) ) ;
    while ( 1 )
    {
        if ( visited[fr][fc][fdir][cr][cc][cdir] )
        {
            cout << 0 << endl ;
            return 0 ;
        }

        visited[fr][fc][fdir][cr][cc][cdir] = true ;

        int nfr = fr + dr[fdir] ;
        int nfc = fc + dc[fdir] ;
        if ( nfr >= 0 && nfc >= 0 && nfr < 10 && nfc < 10 && map[nfr][nfc] != '*' )
        {
            fr = nfr ;
            fc = nfc ;
        }
        else fdir = ( fdir + 1 ) % 4 ;

        int ncr = cr + dr[cdir] ;
        int ncc = cc + dc[cdir] ;
        if ( ncr >= 0 && ncc >= 0 && ncr < 10 && ncc < 10 && map[ncr][ncc] != '*' )
        {
            cr = ncr ;
            cc = ncc ;
        }
        else cdir = ( cdir + 1 ) % 4 ;

        step ++ ;
        if ( fr == cr && fc == cc )
        {
            cout << step << endl ;
            return 0 ;
        }
    }
    return 0 ;
}