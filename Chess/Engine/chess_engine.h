#pragma once
#include "bitboard.h"
#include <vector>

using namespace std;

class ChessEngine {
public:
    //black pieces bitboards
    Bitboard bPawns;
    Bitboard bRooks;
    Bitboard bBishops;
    Bitboard bKnights;
    Bitboard bKing;
    Bitboard bQueen;

    //white pieces bitboards
    Bitboard wPawns;
    Bitboard wRooks;
    Bitboard wBishops;
    Bitboard wKnights;
    Bitboard wKing;
    Bitboard wQueen;

	ChessEngine();
    vector<Bitboard> getBitboards();
};