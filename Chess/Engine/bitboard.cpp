#include "bitboard.h"


void Bitboard::setBoard(uint64_t initialValue)
{
	board = initialValue;
}



uint64_t Bitboard::getBoard()
{
	return board;
}