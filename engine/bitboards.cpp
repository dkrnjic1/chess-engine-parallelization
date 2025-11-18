#include "bitboards.hpp"

// Array of 64 Bitboards — each representing a single square on the board
Bitboard SQUARE_BITBOARDS[64];

// Predefined masks for white and black pawns (rank 2 and rank 7)
Bitboard RANK_1 = 0xFF00ULL;
Bitboard RANK_7 = 0x00FF000000000000ULL;

// Initializes the 64 Bitboards so that each one has exactly one bit set (representing one square)
// This allows fast bitwise checks instead of memory lookups in loops
void initBitboards() {
    for (int i = 0; i < 64; ++i) {
        SQUARE_BITBOARDS[i] = (1ULL << i);
    }
}
