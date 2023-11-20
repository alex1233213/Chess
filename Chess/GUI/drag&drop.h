#pragma once
#include "board.h"

class DragAndDropHandler
{
private:
	bool dragEvent = false;
	ChessPiece* selectedPiece;
public: 
	ChessPiece* isPieceSelected(int, int, Board);
	void listenDragDropEvent(sf::Event event, Board&);
	std::pair<int, int> highlightedSquareXY(int mouseX, int mouseY, Board board);
};