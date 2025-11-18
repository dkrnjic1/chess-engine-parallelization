#pragma once

#include "typedefs.hpp"

#define START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

void setFen(Board* board, const char* fen);
Bitboard* pieceBitboard(Board* board, int pieceType);
Bitboard computeAttacks(Board board);
void reset(Board* board);
