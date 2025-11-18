#pragma once
// Single include guard

#include <cstdint>

// -----------------------------------------------------------------------------
// Boje (konzistentno sa ostatkom koda)
// -----------------------------------------------------------------------------
constexpr int BLACK = 0;
constexpr int WHITE = 1;

// -----------------------------------------------------------------------------
// Osnovni tip
// -----------------------------------------------------------------------------
using Bitboard = std::uint64_t;

// -----------------------------------------------------------------------------
// Enum-i koje ostatak koda očekuje (NE koristimo enum class)
// -----------------------------------------------------------------------------

// Tip figure (redoslijed važan jer se koristi pointer aritmetika na Board!)
enum Piece {
    PAWN_W, KNIGHT_W, BISHOP_W, ROOK_W, QUEEN_W, KING_W,
    PAWN_B, KNIGHT_B, BISHOP_B, ROOK_B, QUEEN_B, KING_B
};

// Ploča H1..A8 (redoslijed zadržan jer se koristi mapiranje 'h' - fileCh)
enum Square {
    H1, G1, F1, E1, D1, C1, B1, A1,
    H2, G2, F2, E2, D2, C2, B2, A2,
    H3, G3, F3, E3, D3, C3, B3, A3,
    H4, G4, F4, E4, D4, C4, B4, A4,
    H5, G5, F5, E5, D5, C5, B5, A5,
    H6, G6, F6, E6, D6, C6, B6, A6,
    H7, G7, F7, E7, D7, C7, B7, A7,
    H8, G8, F8, E8, D8, C8, B8, A8
};

enum MoveValidation { NOT_VALIDATED, LEGAL, ILLEGAL };

// Usklađeno s board.cpp (koristi UN_DETERMINED)
enum GameResult { UN_DETERMINED, WHITE_WIN, BLACK_WIN, DRAW };

// Rokade kao bit-maska
enum Castling { K = 1, Q = 2, k = 4, q = 8 };

// File-ovi (H..A) – odgovara postojećem mapiranju
enum File { H, G, F, E, D, C, B, A };

// -----------------------------------------------------------------------------
// Board state
// -----------------------------------------------------------------------------
struct Board {
    Bitboard pawn_W;
    Bitboard knight_W;
    Bitboard bishop_W;
    Bitboard rook_W;
    Bitboard queen_W;
    Bitboard king_W;

    Bitboard pawn_B;
    Bitboard knight_B;
    Bitboard bishop_B;
    Bitboard rook_B;
    Bitboard queen_B;
    Bitboard king_B;

    int turn;               // WHITE ili BLACK
    int castling;           // bitmask (K|Q|k|q)
    int epSquare;           // en passant cilj (-1 ako nema)
    int halfmoves;          // za 50-move rule
    int fullmoves;          // broj punih poteza
    int whiteKingSq;        // Square bijelog kralja
    int blackKingSq;        // Square crnog kralja

    Bitboard occupancy;         // svi zauzeti
    Bitboard occupancyWhite;    // zauzeti bijelih
    Bitboard occupancyBlack;    // zauzeti crnih
    Bitboard hash;              // Zobrist hash
    Bitboard attacks;           // maske napada protivnika
};

// -----------------------------------------------------------------------------
// Move
// -----------------------------------------------------------------------------

// VAŽNO: redoslijed polja usklađen sa makroom
//   getMove(from, to, promo, castling, pType)
// → {fromSquare, toSquare, promotion, castle, pieceType, ...}
struct Move {
    int fromSquare;     // početno polje
    int toSquare;       // ciljno polje
    int promotion;      // -1 ako nema; inače Piece (QUEEN_W/… zavisno od boje)
    int castle;         // Castling flags (K/Q/k/q) ili 0
    int pieceType;      // Piece tip koji se kreće
    int validation;     // MoveValidation (LEGAL/ILLEGAL/NOT_VALIDATED)
    int score;          // za move ordering
    bool exhausted;     // pomoćno u pretrazi
};

// -----------------------------------------------------------------------------
// Pomoćne tabele
// -----------------------------------------------------------------------------

// Npr. "e2", "h8" … 2+null
extern char SQUARE_NAMES[64][3];
