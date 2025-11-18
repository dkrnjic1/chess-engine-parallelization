#pragma once

#include "typedefs.hpp"

// Declaration of global bitboards and initialization function
extern Bitboard SQUARE_BITBOARDS[64];
extern Bitboard RANK_1;
extern Bitboard RANK_7;

void initBitboards();
