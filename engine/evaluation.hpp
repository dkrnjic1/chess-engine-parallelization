#pragma once

#include "typedefs.hpp"

// Evaluation limits
extern int MAX_EVAL;
extern int MIN_EVAL;

// Initialize evaluation tables or constants
void initEvaluation();

// Evaluate a given board position
int evaluate(const Board& board, int result);
