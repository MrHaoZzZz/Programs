package gtiit.edu.cn.isp_reversi;

import java.util.Arrays ;
import java.util.List;

class Reversi {

    Reversi(int n) {
        this.size = n;
        /* COMPLETE */
        // create the board
        this.board = new Board( n ) ;
        // set the initial player to Black
        this.currentPlayer = PlayerColor.Black ;
        // set the initial piece counts
        this.blackCount = 2 ;
        this.whiteCount = 2 ;
        // put the initial 4 pieces in the middle
        board.putPieceAt( n/2 , n/2 , PlayerColor.Black ) ;
        board.putPieceAt( n/2-1 , n/2-1 , PlayerColor.Black ) ;
        board.putPieceAt( n/2-1 , n/2 , PlayerColor.White ) ;
        board.putPieceAt( n/2 , n/2-1 , PlayerColor.White ) ;
    }

    int getSize() {
        return this.size ;
    }

    boolean hasPieceAt(int i, int j) {
        /* COMPLETE */
        return board.hasPieceAt( i , j ) ;
    }

    PlayerColor pieceAt(int i, int j) {
        /* COMPLETE */
        return board.pieceAt( i , j ) ;
    }

    PlayerColor currentTurn() {
        /* COMPLETE */
        return currentPlayer ;
    }

    void playAt(int i, int j) {
        /* COMPLETE */
        if ( gameEnded() ) return ; // game already ended, do nothing
        if ( !isValidMove( i , j ) ) return ; // invalid move, do nothing

        PlayerColor player = currentPlayer ;
        PlayerColor oppColor = player.equals( PlayerColor.Black ) ? PlayerColor.White : PlayerColor.Black ;
        List<List<Integer>> directions = 
        Arrays.asList( Arrays.asList( -1 , -1 ) , Arrays.asList( -1 , 0 ) , Arrays.asList( -1 , 1 ) ,
                       Arrays.asList( 0 , -1 )                            , Arrays.asList( 0 , 1 ) ,
                       Arrays.asList( 1 , -1 )  , Arrays.asList( 1 , 0 )  , Arrays.asList( 1 , 1 ) ) ;

        board.putPieceAt( i , j , player ) ; // put the piece at (i,j)
        if ( player.equals( PlayerColor.Black ) ) blackCount ++ ;
        else whiteCount ++ ;

        for ( int k = 0 ; k < 8 ; k ++ )
        {
            int x = i + directions.get( k ).get( 0 ) , y = j + directions.get( k ).get( 1 ) ;
            boolean hasOpponentPieceInBetween = false ;
            while ( board.inRange( x , y ) && board.hasPieceAt( x , y ) && board.pieceAt( x , y ) == oppColor )
            {
                hasOpponentPieceInBetween = true ;
                x += directions.get( k ).get( 0 ) ;
                y += directions.get( k ).get( 1 ) ;
            }
            if ( board.inRange( x , y ) && board.hasPieceAt( x , y ) && board.pieceAt( x , y ) == player && hasOpponentPieceInBetween )
            {
                x = i + directions.get( k ).get( 0 ) ;
                y = j + directions.get( k ).get( 1 ) ;
                while ( board.pieceAt( x ,y ) == oppColor )
                {
                    board.putPieceAt( x , y , player ) ; // flip the piece at (x,y)
                    if ( player.equals( PlayerColor.Black ) )
                    {
                        blackCount ++ ;
                        whiteCount -- ;
                    }
                    else
                    {
                        whiteCount ++ ;
                        blackCount -- ;
                    }
                    x += directions.get( k ).get( 0 ) ;
                    y += directions.get( k ).get( 1 ) ;
                }
            }
        }
        // switch the current player
        switchPlayer() ;
    }

    boolean gameEnded() {
        /* COMPLETE */
        return ended ;
    }

    int numberOfPieces(PlayerColor color) {
        /* COMPLETE */
        return color.equals( PlayerColor.Black ) ? blackCount : whiteCount ;
    }

    // helper method
    // to judge whether the move at (i,j) is valid for the current player
    private boolean isValidMove( int i , int j )
    {
        if ( !board.inRange( i , j ) ) return false ; // cell out of range
        if ( board.hasPieceAt( i , j ) ) return false ; // cell already occupied

        PlayerColor oppColor = currentPlayer.equals( PlayerColor.Black ) ? PlayerColor.White : PlayerColor.Black ;
        List<List<Integer>> directions = 
        Arrays.asList( Arrays.asList( -1 , -1 ) , Arrays.asList( -1 , 0 ) , Arrays.asList( -1 , 1 ) ,
                       Arrays.asList( 0 , -1 )                            , Arrays.asList( 0 , 1 ) ,
                       Arrays.asList( 1 , -1 )  , Arrays.asList( 1 , 0 )  , Arrays.asList( 1 , 1 ) ) ;

        for ( int k = 0 ; k < 8 ; k ++ )
        {
            int x = i + directions.get( k ).get( 0 ) , y = j + directions.get( k ).get( 1 ) ;
            boolean hasOpponentPieceInBetween = false ;
            while ( board.inRange( x , y ) && board.hasPieceAt( x , y ) && board.pieceAt( x , y ) == oppColor )
            {
                hasOpponentPieceInBetween = true ;
                x += directions.get( k ).get( 0 ) ;
                y += directions.get( k ).get( 1 ) ;
            }
            if ( board.inRange( x , y ) && board.hasPieceAt( x , y ) && board.pieceAt( x , y ) == currentPlayer && hasOpponentPieceInBetween )
            {
                return true ;
            }
        }
        return false ; // no valid direction, invalid move
    }

    private boolean hasAnyMove( PlayerColor player )
    {
        PlayerColor saved = currentPlayer ;
        currentPlayer = player ;
        for ( int i = 0 ; i < size ; i ++ )
        {
            for ( int j = 0 ; j < size ; j ++ )
            {
                if ( isValidMove( i , j ) )
                {
                    currentPlayer = saved ;
                    return true ;
                }
            }
        }
        currentPlayer = saved ;
        return false ;
    }

    private void switchPlayer()
    {
        PlayerColor next = currentPlayer.equals( PlayerColor.Black ) ? PlayerColor.White : PlayerColor.Black ;
        if ( hasAnyMove( next ) ) currentPlayer = next ; // switch to the next player if he/she has valid moves, otherwise current player continues to play
        else if ( !hasAnyMove( currentPlayer ) ) ended = true ; // if neither player has valid moves, set current player to null to indicate the game has ended
    }

    /* COMPLETE */
    private int size;
    private Board board ;
    private PlayerColor currentPlayer ;
    private int blackCount ;
    private int whiteCount ;
    private boolean ended ;

}
