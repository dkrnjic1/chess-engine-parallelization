#pragma once

#include "typedefs.hpp"
#include <string>
#include <cstdint>

void printMoves(Move moves[], int length);
void printBitboard(Bitboard bb);
void printBits(Bitboard bb);
int countTrailingZeros(uint64_t x);

