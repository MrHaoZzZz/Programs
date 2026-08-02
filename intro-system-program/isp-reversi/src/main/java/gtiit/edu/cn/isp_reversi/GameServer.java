package gtiit.edu.cn.isp_reversi;

import java.util.ArrayList;

class GameServer {

    GameServer() {
        /* COMPLETE */
        player1List = new ArrayList<>() ;
        player2List = new ArrayList<>() ;
        games = new ArrayList<>() ;
    }

    int startNewGame(String player1, String player2, int n) {
        /* COMPLETE */
        player1List.add( player1 ) ;
        player2List.add( player2 ) ;
        games.add( new Reversi( n ) ) ;
        return games.size() - 1 ; // return the game ID of the newly started game
    }

    Reversi getGame(int gameId) {
        /* COMPLETE */
        return games.get( gameId ) ;
    }

    ArrayList<String> ranking() {
        /* COMPLETE */
        ArrayList<PlayerData> data = new ArrayList<>() ;

        for ( int i = 0 ; i < games.size() ; i ++ )
        {
            Reversi game = games.get( i ) ;
            if ( game.gameEnded() ) // only count those games in the server that have ended
            {
                // cliam the variable and initiallize them
                int blackCount = game.numberOfPieces( PlayerColor.Black ) ;
                int whiteCount = game.numberOfPieces( PlayerColor.White ) ;
                String winner = null ;
                
                // judge the winner by the number of pieces
                if ( blackCount > whiteCount ) winner = player1List.get( i ) ;
                if ( whiteCount > blackCount ) winner = player2List.get( i ) ;

                // if there is a winner, document him/her in PlayerData
                if ( winner != null )
                {
                    boolean found = false ;
                    for ( int j = 0 ; j < data.size() ; j ++ )
                    {
                        if ( data.get( j ).name.equals( winner ) )
                        {
                            data.get( j ).wins ++ ;
                            found = true ;
                            break ;
                        }
                    }
                    if ( !found ) data.add( new PlayerData( winner , 1 ) ) ;
                }
            }
        }
        // sort the data by the number of wins in descending order
        for ( int i = 0 ; i < data.size() ; i ++ )
        {
            for ( int j = 0 ; j < data.size() - 1 - i ; j ++ )
            {
                if ( data.get( j ).wins < data.get( j + 1 ).wins )
                {
                    PlayerData temp = data.get( j ) ;
                    data.set( j , data.get( j + 1 ) ) ;
                    data.set( j + 1 , temp ) ;
                }
            }
        }
        // extract the player names in the sorted order
        ArrayList<String> ranking = new ArrayList<>() ;
        for ( PlayerData d : data ) ranking.add( d.name ) ;
        return ranking ;
    }

    // helper method
    class PlayerData
    {
        PlayerData( String name , int wins )
        {
            this.name = name ;
            this.wins = wins ;
        }
        String name ;
        int wins ;
    }

    //private scores() Map<player_id, score>;

    //private unfinished games = set<games_id>

    // every time a game starts, you can add it to unfinished games
    // every time the method startNewGame is used

    // every time you are asked for the ranking, you can just check the unfinished games.
    // if a game has finished, you remove it from unfinished games (so that you do not check it again)
    // also, add the winner to the scores
    
    private ArrayList<String> player1List ;
    private ArrayList<String> player2List ;
    private ArrayList<Reversi> games ;
}
