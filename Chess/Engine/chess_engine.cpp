#include "chess_engine.h"
#include <vector>

using namespace std;

ChessEngine::ChessEngine()
{
    // Black pieces bitboards
    bPawns.setBoard(0b0000000000000000000000000000000000000000000000001111111100000000);
    bRooks.setBoard(0b0000000000000000000000000000000000000000000000000000000010000001);
    bBishops.setBoard(0b0000000000000000000000000000000000000000000000000000000000100100);
    bKnights.setBoard(0b0000000000000000000000000000000000000000000000000000000001000010);
    bKing.setBoard(1ULL << 3);
    bQueen.setBoard(1ULL << 4);

    // White pieces bitboards
    wPawns.setBoard(0b0000000011111111000000000000000000000000000000000000000000000000);
    wRooks.setBoard(0b1000000100000000000000000000000000000000000000000000000000000000);
    wBishops.setBoard(0b010010000000000000000000000000000000000000000000000000000000000);
    wKnights.setBoard(0b0100001000000000000000000000000000000000000000000000000000000000);
    wKing.setBoard(0b0000100000000000000000000000000000000000000000000000000000000000);
    wQueen.setBoard(0b0001000000000000000000000000000000000000000000000000000000000000);
}




vector<Bitboard> ChessEngine::getBitboards()
{
    vector<Bitboard> bitBoards;
    bitBoards.push_back(bPawns);
    bitBoards.push_back(bRooks);
    bitBoards.push_back(bBishops);
    bitBoards.push_back(bKnights);
    bitBoards.push_back(bQueen);
    bitBoards.push_back(wPawns);
    bitBoards.push_back(wRooks);
    bitBoards.push_back(wBishops);
    bitBoards.push_back(wKnights);
    bitBoards.push_back(wQueen);

    return bitBoards;
}