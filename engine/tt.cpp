#include "tt.hpp"

const int TT_SIZE = 100000;
TTEntry TT_TABLE[TT_SIZE];

TTEntry getTTEntry(Bitboard zobrist) {
    return TT_TABLE[zobrist % TT_SIZE];
}

void addTTEntry(const Board& board, int eval, Move move, int depth, int beta, int alpha) {
    TTEntry entry;

    if (eval <= alpha)
        entry.nodeType = UPPER;
    else if (eval >= beta)
        entry.nodeType = LOWER;
    else 
        entry.nodeType = EXACT;

    entry.eval = eval;
    entry.move = move;
    entry.depth = depth;
    entry.zobrist = board.hash;  // assumes Board has a `hash` member

    TT_TABLE[entry.zobrist % TT_SIZE] = entry;
}
