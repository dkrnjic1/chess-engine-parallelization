#pragma once
#include "typedefs.hpp"

// UCI helperi (ovo NIJE klasični SAN poput "Nf3", nego koordinatna notacija: "e2e4", "e7e8q")

void pushSan(Board* board, const char* san);
void sanToMove(const Board& board, Move* move, const char* san);
void moveToSan(const Move& move, char san[]);
