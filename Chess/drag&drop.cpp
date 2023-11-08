#include "drag&drop.h"
#include <iostream>
#include "board.h"

using namespace std;


//returns piece if piece is selected, otherwise null pointer
ChessPiece* DragAndDropHandler::isPieceSelected(int mouseX, int mouseY, Board board)
{
    // Calculate the board coordinates (row and column) based on the mouse position
    int row = static_cast<int>((mouseY - 0) / board.getSquareSide());
    int col = static_cast<int>((mouseX - 0) / board.getSquareSide());

    if (row >= 0 && row < 8 && col >= 0 && col < 8) {
        // Check if the square at (row, col) has a chess piece
        return board.getSquares()[row][col].getPiece();
    }

    return nullptr;
}




void DragAndDropHandler::listenDragDropEvent(sf::Event event, Board& board) {
    // Piece selected
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            selectedPiece = isPieceSelected(event.mouseButton.x, event.mouseButton.y, board);

            if (selectedPiece != nullptr) {
                dragEvent = true;
                selectedPiece->toggleDraggedState();
                // Store the selected piece and its original position for moving
                // ...
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left && dragEvent) {
            dragEvent = false;
            selectedPiece->toggleDraggedState(); // Reset the dragged state
            // Update the board with the new position of the piece, if necessary
            // ...
        }
    }
    else if (event.type == sf::Event::MouseMoved && dragEvent) {
        //set the center of the piece coordinates to be positioned over the mouse
        selectedPiece->getSprite().setPosition(
            event.mouseMove.x - selectedPiece->getSprite().getGlobalBounds().width / 2,
            event.mouseMove.y - selectedPiece->getSprite().getGlobalBounds().height / 2
        );
    }
}
