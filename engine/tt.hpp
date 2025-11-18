#pragma once

#include "typedefs.hpp"

struct TTEntry {
    Bitboard zobrist;
    int eval;
    int nodeType;
    int depth;
    Move move;
};

enum NODE_TYPE { EXACT, LOWER, UPPER };

extern TTEntry TT_TABLE[];
extern const int TT_SIZE;

TTEntry getTTEntry(Bitboard zobrist);
void addTTEntry(const Board& board, int eval, Move move, int depth, int beta, int alpha);
