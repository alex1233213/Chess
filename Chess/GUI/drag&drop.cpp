#include "drag&drop.h"
#include <iostream>
#include "board.h"
#include <utility>

using namespace std;


DragAndDropHandler::DragAndDropHandler() : selectedPiece(nullptr), dragEvent(false) {
    // Other constructor initialization if needed
}





std::pair<int, int> DragAndDropHandler::highlightedSquareXY(int mouseX, int mouseY, Board board)
{
    // Calculate the board coordinates (row and column) based on the mouse position
    int row = static_cast<int>((mouseY - 0) / board.getSquareSide());
    int col = static_cast<int>((mouseX - 0) / board.getSquareSide());

    return std::make_pair(row, col);
}




//returns piece if piece is selected, otherwise null pointer
ChessPiece* DragAndDropHandler::isPieceSelected(int mouseX, int mouseY, Board board)
{

    pair<int, int> squareCoordinates = highlightedSquareXY(mouseX, mouseY, board);
    Square targetSquare = board.getSquares()[squareCoordinates.first][squareCoordinates.second];
    ChessPiece* selectedPiece;

    if ( (selectedPiece = targetSquare.getPiece() ) != nullptr)
    {
        return selectedPiece;
    }

    return nullptr;
}




void DragAndDropHandler::listenDragDropEvent(sf::Event event, Board& board) {
    //left mouse click event
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            selectedPiece = isPieceSelected(event.mouseButton.x, event.mouseButton.y, board);

            if (selectedPiece != nullptr) {
                dragEvent = true;
                selectedPiece->toggleDraggedState();
            }
        }
    }

    //when mouse is released, assign place piece on target square
    else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left && dragEvent && selectedPiece != nullptr) {
            dragEvent = false;
            selectedPiece->toggleDraggedState(); // Reset the dragged state

            Square& oldSquare = board.getSquare( selectedPiece->getRank(), selectedPiece->getFile() );
            oldSquare.setPiece(nullptr);

            pair<int, int> squareCoordinates = highlightedSquareXY(event.mouseButton.x, event.mouseButton.y, board);
            selectedPiece->setRank(board.getRank(squareCoordinates.first));
            selectedPiece->setFile(squareCoordinates.second);
            Square& targetSquare = board.getSquares()[squareCoordinates.first][squareCoordinates.second];
            targetSquare.setPiece(selectedPiece);
            selectedPiece = nullptr;
        }
    }

    //when piece is dragged
    else if (event.type == sf::Event::MouseMoved && dragEvent) {
        selectedPiece->getSprite().setPosition(
            event.mouseMove.x - selectedPiece->getSprite().getGlobalBounds().width / 2,
            event.mouseMove.y - selectedPiece->getSprite().getGlobalBounds().height / 2
        );
    }
}
