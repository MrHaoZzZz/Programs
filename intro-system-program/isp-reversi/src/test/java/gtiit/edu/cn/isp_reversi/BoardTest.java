package gtiit.edu.cn.isp_reversi;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

public class BoardTest {

    @Test
    void test_newBoard() {
        Board b = new Board(4);
        assertEquals(4, b.getSize());
    }

    @Test
    void test_inRange() {
        Board b = new Board(3);
        assertTrue(b.inRange(0, 0));
        assertTrue(b.inRange(0, 1));
        assertTrue(b.inRange(0, 2));
        assertTrue(b.inRange(1, 0));
        assertTrue(b.inRange(1, 1));
        assertTrue(b.inRange(1, 2));
        assertTrue(b.inRange(2, 0));
        assertTrue(b.inRange(2, 1));
        assertTrue(b.inRange(2, 2));
        assertFalse(b.inRange(-1, 1));
        assertFalse(b.inRange(3, 1));
        assertFalse(b.inRange(1, -1));
        assertFalse(b.inRange(1, 3));
    }

    @Test
    void test_allPositionsEmpty_a()
    {
        Board b = new Board( 100 ) ;
        for ( int i = 0 ; i < 100 ; i ++ )
        {
            for ( int j = 0 ; j < 100 ; j ++ )
            {
                assertFalse( b.hasPieceAt( i , j ) ) ;
            }
        }
    }

    @Test
    void test_putAndHasPiece_b() {
        Board b = new Board(3);
        b.putPieceAt(1, 1, PlayerColor.Black);
        assertTrue(b.hasPieceAt(1, 1));
        // other cells still empty
        assertFalse(b.hasPieceAt(0, 0));
        assertFalse(b.hasPieceAt(1, 2));
        assertFalse(b.hasPieceAt(2, 1));
    }

    @Test
    void test_putAndGetColor_c() {
        Board b = new Board(3);
        b.putPieceAt(1, 1, PlayerColor.Black);
        assertEquals(PlayerColor.Black, b.pieceAt(1, 1));
        b.putPieceAt(2, 2, PlayerColor.White);
        assertEquals(PlayerColor.White, b.pieceAt(2, 2));
    }

    @Test
    void test_multiplePieces_d() {
        Board b = new Board(4);
        b.putPieceAt(0, 0, PlayerColor.Black);
        b.putPieceAt(0, 3, PlayerColor.White);
        b.putPieceAt(3, 0, PlayerColor.Black);
        b.putPieceAt(3, 3, PlayerColor.White);
        assertEquals(PlayerColor.Black, b.pieceAt(0, 0));
        assertEquals(PlayerColor.White, b.pieceAt(0, 3));
        assertEquals(PlayerColor.Black, b.pieceAt(3, 0));
        assertEquals(PlayerColor.White, b.pieceAt(3, 3));
        // check other cells are empty
        assertFalse(b.hasPieceAt(1, 1));
        assertFalse(b.hasPieceAt(1, 2));
        assertFalse(b.hasPieceAt(2, 1));
        assertFalse(b.hasPieceAt(2, 2));
    }

    @Test
    void test_removePiece_e() {
        Board b = new Board(3);
        b.putPieceAt(1, 1, PlayerColor.Black);
        assertTrue(b.hasPieceAt(1, 1));
        b.removePieceFrom(1, 1);
        assertFalse(b.hasPieceAt(1, 1));
    }

    @Test
    void test_removeFromEmptyCell_f() {
        Board b = new Board(3);
        // cell (1,1) is empty
        b.removePieceFrom(1, 1);
        assertFalse(b.hasPieceAt(1, 1)); // still empty
    }

    @Test
    void test_putSameColorOverwrites_g() {
        Board b = new Board(3);
        b.putPieceAt(1, 1, PlayerColor.Black);
        b.putPieceAt(1, 1, PlayerColor.Black);
        assertEquals(PlayerColor.Black, b.pieceAt(1, 1));
    }

    @Test
    void test_putDifferentColorOverwrites_h() {
        Board b = new Board(3);
        b.putPieceAt(1, 1, PlayerColor.Black);
        b.putPieceAt(1, 1, PlayerColor.White);
        assertEquals(PlayerColor.White, b.pieceAt(1, 1));
    }

    @Test
    void test_extraTest1()
    {
        Board b = new Board( 100 ) ;
        b.putPieceAt( 0 , 0 , PlayerColor.Black ) ;
        assertTrue( b.hasPieceAt( 0 , 0 ) ) ;
        assertEquals( PlayerColor.Black , b.pieceAt( 0 , 0 ) ) ;
        b.putPieceAt( 0 , 0 , PlayerColor.White ) ;
        assertTrue( b.hasPieceAt( 0 , 0 ) ) ;
        assertEquals( PlayerColor.White , b.pieceAt( 0 , 0 ) ) ;
        assertFalse( b.hasPieceAt( 0 , 1 ) ) ; // The other cells should be empty
        assertFalse( b.hasPieceAt( 1 , 0 ) ) ;

        b.putPieceAt( 91 , 78 , PlayerColor.Black ) ;
        assertTrue( b.hasPieceAt( 91 , 78 ) ) ;
        assertEquals( PlayerColor.Black , b.pieceAt( 91 , 78 ) ) ;
        b.putPieceAt( 91 , 78 , PlayerColor.White ) ;
        assertTrue( b.hasPieceAt( 91 , 78 ) ) ;
        assertEquals( PlayerColor.White , b.pieceAt( 91 , 78 ) ) ;
        assertFalse( b.hasPieceAt( 91 , 79 ) ) ;
        assertFalse( b.hasPieceAt( 91 , 77 ) ) ;
        assertFalse( b.hasPieceAt( 92 , 78 ) ) ;
        assertFalse( b.hasPieceAt( 90 , 78 ) ) ;

        b.putPieceAt( 78 , 91 , PlayerColor.Black ) ;
        assertTrue( b.hasPieceAt( 78 , 91 ) ) ;
        assertEquals( PlayerColor.Black , b.pieceAt( 78 , 91 ) ) ;
        b.putPieceAt( 78 , 91 , PlayerColor.White ) ;
        assertTrue( b.hasPieceAt( 78 , 91 ) ) ;
        assertEquals( PlayerColor.White , b.pieceAt( 78 , 91 ) ) ;
        assertFalse( b.hasPieceAt( 78 , 90 ) ) ;
        assertFalse( b.hasPieceAt( 78 , 92 ) ) ;
        assertFalse( b.hasPieceAt( 77 , 91 ) ) ;
        assertFalse( b.hasPieceAt( 79 , 91 ) ) ;
    }
}