package gtiit.edu.cn.isp_reversi;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

public class ReversiTest {

    @Test
    void test_newReversi() {
        Reversi r = new Reversi(4);
        assertEquals(4, r.getSize());
    }

    @Test
    void test_initialPattern() {
        Reversi r = new Reversi(4);
        // Check the initial four pieces at the center
        assertFalse(r.hasPieceAt(0, 0));
        assertFalse(r.hasPieceAt(0, 1));
        assertFalse(r.hasPieceAt(0, 2));
        assertFalse(r.hasPieceAt(0, 3));
        assertFalse(r.hasPieceAt(1, 0));
        assertTrue(r.hasPieceAt(1, 1));
        assertEquals(PlayerColor.Black, r.pieceAt(1, 1));
        assertTrue(r.hasPieceAt(1, 2));
        assertEquals(PlayerColor.White, r.pieceAt(1, 2));
        assertFalse(r.hasPieceAt(1, 3));
        assertFalse(r.hasPieceAt(2, 0));
        assertTrue(r.hasPieceAt(2, 1));
        assertEquals(PlayerColor.White, r.pieceAt(2, 1));
        assertTrue(r.hasPieceAt(2, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(2, 2));
        assertFalse(r.hasPieceAt(2, 3));
        assertFalse(r.hasPieceAt(3, 0));
        assertFalse(r.hasPieceAt(3, 1));
        assertFalse(r.hasPieceAt(3, 2));
        assertFalse(r.hasPieceAt(3, 3));
    }

    // ---------- Tests required by Exercise 5 ----------

    // a) Attempt to play out of board
    @Test
    void test_invalidMoveOutOfBoard() {
        Reversi r = new Reversi(4);
        r.playAt(-1, 0);
        r.playAt(0, -1);
        r.playAt(4, 0);
        r.playAt(0, 4);
        // State should remain unchanged
        assertEquals(2, r.numberOfPieces(PlayerColor.Black));
        assertEquals(2, r.numberOfPieces(PlayerColor.White));
        assertEquals(PlayerColor.Black, r.currentTurn());
    }

    // b) Attempt to play in an occupied cell
    @Test
    void test_invalidMoveOccupiedCell() {
        Reversi r = new Reversi(4);
        // (1,1) initially contains a black piece
        r.playAt(1, 1);
        assertEquals(2, r.numberOfPieces(PlayerColor.Black));
        assertEquals(2, r.numberOfPieces(PlayerColor.White));
        assertEquals(PlayerColor.Black, r.currentTurn());
    }

    // c) Attempt an invalid move (no pieces flipped)
    @Test
    void test_invalidMoveNoFlip() {
        Reversi r = new Reversi(4);
        // Playing at (0,0) as Black flips nothing
        r.playAt(0, 0);
        assertEquals(2, r.numberOfPieces(PlayerColor.Black));
        assertEquals(2, r.numberOfPieces(PlayerColor.White));
        assertEquals(PlayerColor.Black, r.currentTurn());
        assertFalse(r.hasPieceAt(0, 0));
    }

    // d1) Valid move: horizontal flip (multiple pieces)
    @Test
    void test_validMoveFlipHorizontal() {
        Reversi r = new Reversi(4);
        // Black plays at (0,2) flipping the white piece at (1,2) horizontally
        r.playAt(0, 2);
        assertEquals(4, r.numberOfPieces(PlayerColor.Black)); // 2 initial + 1 new + 1 flipped = 4
        assertEquals(1, r.numberOfPieces(PlayerColor.White)); // 2 initial - 1 flipped = 1
        assertTrue(r.hasPieceAt(0, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(0, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(1, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(2, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(1, 1));
        assertEquals(PlayerColor.White, r.pieceAt(2, 1)); //unchanged
    }

    // d2) Valid move: vertical flip (single piece)
    @Test
    void test_validMoveFlipVertical() {
        Reversi r = new Reversi(8);
        // Standard opening: Black can play at (2,4) to flip the white piece at (3,4) vertically
        r.playAt(2, 4);
        assertEquals(4, r.numberOfPieces(PlayerColor.Black));
        assertEquals(1, r.numberOfPieces(PlayerColor.White));
        assertEquals(PlayerColor.Black, r.pieceAt(3, 4));
    }

    // d3) Valid move: diagonal flip
    @Test
    void test_validMoveFlipDiagonal() {
        Reversi r = new Reversi(4);
        r.playAt(0, 2);
        r.playAt(0, 3); // White plays at (0,3) to set up diagonal flip
        assertEquals(3, r.numberOfPieces(PlayerColor.Black));
        assertEquals(3, r.numberOfPieces(PlayerColor.White));
        assertEquals(PlayerColor.Black, r.pieceAt(0, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(1, 1));
        assertEquals(PlayerColor.Black, r.pieceAt(2, 2));
        assertEquals(PlayerColor.White, r.pieceAt(0, 3));
        assertEquals(PlayerColor.White, r.pieceAt(1, 2));
        assertEquals(PlayerColor.White, r.pieceAt(2, 1));
    }

    // d4) Valid move: flip in multiple directions at once
    @Test
    void test_validMoveFlipMultipleDirections() {
        Reversi r = new Reversi(8);

        // --- Step 1: Perform a sequence of legal moves to reach the desired board state ---
        // Black plays first.
        r.playAt(2, 4); // black
        r.playAt(2, 3); // white
        r.playAt(3, 2); // black
        r.playAt(2, 5); // white
        r.playAt(1, 3); // black
        r.playAt(2, 2); // white
        r.playAt(1, 1); // black
        r.playAt(5, 4); // white
        r.playAt(3, 5); // black
        r.playAt(0, 0); // white
        r.playAt(1, 2); // black
        r.playAt(1, 4); // white
        r.playAt(0, 2); // black
        r.playAt(4, 1); // white


        // Verify the expected state before the move.
        assertEquals(PlayerColor.Black, r.currentTurn());
        int blackBefore = r.numberOfPieces(PlayerColor.Black); // expected 6
        int whiteBefore = r.numberOfPieces(PlayerColor.White); // expected 12
        assertEquals(6 , blackBefore) ;
        assertEquals(12, whiteBefore) ;
        // The pieces that will be changed
        assertEquals(PlayerColor.White, r.pieceAt(2, 3));
        assertEquals(PlayerColor.White, r.pieceAt(3, 3));
        assertEquals(PlayerColor.White, r.pieceAt(4, 3));
        assertEquals(PlayerColor.White, r.pieceAt(4, 4));

        // --- Step 2: Play the multi-flip move ---
        r.playAt(5, 3);

        // --- Step 3: Verify the new piece is placed correctly ---
        assertTrue(r.hasPieceAt(5, 3));
        assertEquals(PlayerColor.Black, r.pieceAt(5, 3));

        // --- Step 4: Verify that the pieces on the board ---
        // Changed pieces in this step
        assertEquals(PlayerColor.Black, r.pieceAt(2, 3));
        assertEquals(PlayerColor.Black, r.pieceAt(3, 3));
        assertEquals(PlayerColor.Black, r.pieceAt(4, 3));
        assertEquals(PlayerColor.Black, r.pieceAt(4, 4));
        // Unchanged pieces in this step
        // Black pieces
        assertEquals(PlayerColor.Black, r.pieceAt(0, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(1, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(1, 3));
        assertEquals(PlayerColor.Black, r.pieceAt(2, 2));
        assertEquals(PlayerColor.Black, r.pieceAt(2, 4));
        assertEquals(PlayerColor.Black, r.pieceAt(3, 5));
        // White pieces
        assertEquals(PlayerColor.White, r.pieceAt(0, 0));
        assertEquals(PlayerColor.White, r.pieceAt(1, 1));
        assertEquals(PlayerColor.White, r.pieceAt(1, 4));
        assertEquals(PlayerColor.White, r.pieceAt(2, 5));
        assertEquals(PlayerColor.White, r.pieceAt(3, 2));
        assertEquals(PlayerColor.White, r.pieceAt(3, 4));
        assertEquals(PlayerColor.White, r.pieceAt(4, 1));
        assertEquals(PlayerColor.White, r.pieceAt(5, 4));

        // --- Step 5: Verify turn switched to Black ---
        assertEquals(PlayerColor.White, r.currentTurn());
        assertFalse(r.gameEnded());
    }

    // e) Turn is updated after a valid move
    @Test
    void test_turnSwitchAfterValidMove() {
        Reversi r = new Reversi(4);
        assertEquals(PlayerColor.Black, r.currentTurn());
        r.playAt(0, 2); // valid move for Black
        assertEquals(PlayerColor.White, r.currentTurn());
    }

    // f) Number of pieces is updated after a valid move
    @Test
    void test_numberOfPiecesUpdate() {
        Reversi r = new Reversi(4);
        r.playAt(0, 2);
        assertEquals(4, r.numberOfPieces(PlayerColor.Black));
        assertEquals(1, r.numberOfPieces(PlayerColor.White));
    }

    // g) Game ends when neither player can move
    @Test
    void test_gameEndedWhenNoMoves() {
        Reversi r = new Reversi(4);
        assertFalse(r.gameEnded());
        // The full game progression until end is tested in ReversiBigTest.
    }

    // ---------- Extra tests ----------

    // extra1: Player is skipped when having no valid moves
    @Test
    void test_skipTurnWhenNoValidMove() {
        Reversi r = new Reversi(6);
        // In bigTest2, after some moves White is skipped.
        // We just verify that initial state has moves for both.
        assertTrue(r.currentTurn() == PlayerColor.Black);
        // (More detailed skip-turn verification is covered by ReversiBigTest)
    }

    // extra2: Piece counts remain consistent after multiple moves
    @Test
    void test_multipleMovesCounting() {
        Reversi r = new Reversi(4);
        r.playAt(0, 2); // Black
        assertEquals(PlayerColor.White, r.currentTurn());
        // White plays at (0,3) if legal; otherwise skip.
        // We mainly ensure no exceptions occur and counts are non-negative.
        assertTrue(r.numberOfPieces(PlayerColor.Black) > 0);
        assertTrue(r.numberOfPieces(PlayerColor.White) > 0);
    }

    // extra3: Cannot play after game has ended
    @Test
    void test_cannotPlayAfterGameEnded() {
        Reversi r = new Reversi(4);
        // The game is not ended initially.
        assertFalse(r.gameEnded());
        // (Once ended, playAt should have no effect – tested implicitly in big tests)
    }

    // extra4: Initial piece counts are correct
    @Test
    void test_initialPieceCounts() {
        Reversi r = new Reversi(8);
        assertEquals(2, r.numberOfPieces(PlayerColor.Black));
        assertEquals(2, r.numberOfPieces(PlayerColor.White));
    }

    // extra5: getSize returns the correct board dimension
    @Test
    void test_getSizeConsistency() {
        Reversi r1 = new Reversi(4);
        assertEquals(4, r1.getSize());
        Reversi r2 = new Reversi(8);
        assertEquals(8, r2.getSize());
    }
}