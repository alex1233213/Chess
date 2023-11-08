#pragma once
#include "board.h"

class DragAndDropHandler
{
private:
	bool dragEvent;
	ChessPiece* selectedPiece;
public: 
	ChessPiece* isPieceSelected(int, int, Board);
	void listenDragDropEvent(sf::Event event, Board&);
};