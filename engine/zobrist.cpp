#include "zobrist.hpp"
#include <cstdlib>
#include <random>
#include <cstdint>
#include "utils.hpp"


static Bitboard randomBitboard() {
    // rng is static so it is initialized once and reused.
    static std::mt19937_64 rng(std::random_device{}());
    return rng(); // generates a full 64-bit random number
}


Bitboard PIECES[12][64];
Bitboard EN_PASSANT[64];
Bitboard CASTLING[16];
Bitboard WHITE_TO_MOVE;

Bitboard hash(const Board& board) {
    Bitboard h = 0;

    // Castling rights
    h ^= CASTLING[board.castling];

    // Pieces
    for (int i = 0; i < 12; i++) {
        Bitboard bb = *(&(board.pawn_W) + i);  // assumes sequential piece members

        while (bb) {
            int square = countTrailingZeros(bb);
            h ^= PIECES[i][square];
            bb &= bb - 1;
        }
    }

    // En passant
    if (board.epSquare != -1) {
        h ^= EN_PASSANT[board.epSquare];
    }

    // Side to move
    if (board.turn) {
        h ^= WHITE_TO_MOVE;
    }

    return h;
}

void initZobrist() {
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 64; j++)
            PIECES[i][j] = randomBitboard();

    for (int i = 0; i < 64; i++)
        EN_PASSANT[i] = randomBitboard();

    for (int i = 0; i < 16; i++)
        CASTLING[i] = randomBitboard();

    WHITE_TO_MOVE = randomBitboard();
}
