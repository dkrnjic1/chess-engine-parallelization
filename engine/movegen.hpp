#pragma once

#include <cstdint>
#include "typedefs.hpp"
#include "magics.hpp"

// Global Bitboard variables for move generation
extern Bitboard PAWN_START_WHITE;
extern Bitboard PAWN_START_BLACK;
extern Bitboard PAWN_W_ATTACKS_EAST[64];
extern Bitboard PAWN_W_ATTACKS_WEST[64];
extern Bitboard PAWN_B_ATTACKS_EAST[64];
extern Bitboard PAWN_B_ATTACKS_WEST[64];
extern Bitboard KNIGHT_MOVEMENT[64];
extern Bitboard BISHOP_MOVEMENT[64];
extern Bitboard ROOK_MOVEMENT[64];
extern Bitboard KING_MOVEMENT[64];

// Initialization
void initMoveGeneration();

// Move generation
int legalMoves(Board* board, Move moves[]);

// Attack checking
bool isSquareAttacked(const Board& board, int square);

// Sliding piece attacks
Bitboard getRookAttacks(int square, Bitboard occupancy);
Bitboard getBishopAttacks(int square, Bitboard occupancy);
