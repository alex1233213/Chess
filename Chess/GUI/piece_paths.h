#pragma once
#include <map>
#include <string>

#define WHITE_PAWN "resources/wP.png"
#define BLACK_PAWN "resources/bP.png"
#define WHITE_KING "resources/wK.png"
#define BLACK_KING "resources/bK.png"
#define WHITE_ROOK "resources/wR.png"
#define BLACK_ROOK "resources/bR.png"
#define WHITE_BISHOP "resources/wB.png"
#define BLACK_BISHOP "resources/bB.png"
#define WHITE_QUEEN "resources/wQ.png"
#define BLACK_QUEEN "resources/bQ.png"
#define WHITE_KNIGHT "resources/wKn.png"
#define BLACK_KNIGHT "resources/bKn.png"


//mapping for bitboard to piece path
const std::map<std::string, std::string> imagePathMap = {
    {"wPawns", WHITE_PAWN},
    {"bPawns", BLACK_PAWN},
    {"wKing", WHITE_KING},
    {"bKing", BLACK_KING},
    {"wRooks", WHITE_ROOK},
    {"bRooks", BLACK_ROOK},
    {"wBishops", WHITE_BISHOP},
    {"bBishops", BLACK_BISHOP},
    {"wQueen", WHITE_QUEEN},
    {"bQueen", BLACK_QUEEN},
    {"wKnights", WHITE_KNIGHT},
    {"bKnights", BLACK_KNIGHT},
};