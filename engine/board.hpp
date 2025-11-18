#pragma once

#include "typedefs.hpp"
#include "bitboards.hpp"
#include <cstdint>
#include <iostream>

// Return whether the bit at index `square` is 1 or 0
#define getBit(bitboard, square) ((bitboard) & SQUARE_BITBOARDS[(square)])
// Return a Bitboard with the bit at index `square` cleared to 0
#define popBit(bitboard, square) ((bitboard) & ~SQUARE_BITBOARDS[(square)])
// Return a Bitboard with the bit at index `square` set to 1
#define setBit(bitboard, square) ((bitboard) | SQUARE_BITBOARDS[(square)])
// Return a Bitboard with the bit at index `square` toggled
#define toggleBit(bitboard, square) ((bitboard) ^ SQUARE_BITBOARDS[(square)])

// Function declarations
int result(Board board, Move pseudoLegal[], int length);
void computeOccupancyMasks(Board* board);
void printBoard(Board board);
void pushMove(Board* board, const Move& move);

// Global lookup tables and constants
extern char SQUARE_NAMES[64][3];
