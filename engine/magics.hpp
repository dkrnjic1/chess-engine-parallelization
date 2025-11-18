#pragma once
#include "typedefs.hpp"

/**
 * Magics for the Magic Bitboard sliding-piece move generation technique.
 * Precomputed 64-entry tables for rooks and bishops.
 */

extern Bitboard ROOK_MAGICS[64];
extern Bitboard BISHOP_MAGICS[64];
