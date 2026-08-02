package gtiit.edu.cn.isp_reversi;

import java.util.ArrayList ;

class Board {

    Board(int n) {
        /* COMPLETE */
        board = new ArrayList<>( n ) ; // n stands for the initial capacity
        for ( int i = 0 ; i < n ; i ++ )
        {
            ArrayList<PlayerColor> row = new ArrayList<>( n ) ;
            for ( int j = 0 ; j < n ; j ++ )
            {
                row.add( null ) ;
            }
            board.add( row ) ;
        }
    }

    int getSize() {
        /* COMPLETE */
        return board.size() ;
    }

    boolean inRange(int i, int j) {
        /* COMPLETE */
        return i >= 0 && i < getSize() && j >= 0 && j < getSize() ;
    }

    boolean hasPieceAt(int i, int j) {
        /* COMPLETE */
        return board.get( i ).get( j ) != null ;
    }

    PlayerColor pieceAt(int i, int j) {
        /* COMPLETE */
        return board.get( i ).get( j ) ;
    }

    void removePieceFrom(int i, int j) {
        /* COMPLETE */
        board.get( i ).set( j , null ) ;
    }

    void putPieceAt(int i, int j, PlayerColor color) {
        /* COMPLETE */
        board.get( i ).set( j , color ) ;
    }

    private ArrayList<ArrayList<PlayerColor>> board ;
}