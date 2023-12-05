#include "board_state.h"
#include "../Engine/chess_engine.h"
#include "../Engine/bitboard.h"
#include <map>

BoardState::BoardState()
{
	ChessEngine chessEngine;

	addBitboard("wPawns", chessEngine.wPawns);
	addBitboard("bPawns", chessEngine.bPawns);
	addBitboard("wBishops", chessEngine.wBishops);
	addBitboard("bBishops", chessEngine.bBishops);
	addBitboard("wRooks", chessEngine.wRooks);
	addBitboard("bRooks", chessEngine.bRooks);
	addBitboard("wKing", chessEngine.wKing);
	addBitboard("bKing", chessEngine.bKing);
	addBitboard("wKnights", chessEngine.wKnights);
	addBitboard("bKnights", chessEngine.bKnights);
	addBitboard("wQueen", chessEngine.wQueen);
	addBitboard("bQueen", chessEngine.bQueen);
}




void BoardState::addBitboard(const std::string& pieceType, const Bitboard& bitboard)
{
	pieceBitboards.emplace(pieceType, bitboard);
}



map<string, Bitboard> BoardState::getBitboards()
{
	return pieceBitboards;
}