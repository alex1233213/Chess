#include "square.h"
#include <iostream>


Square::Square(sf::Vector2f position, sf::Color color, float size)
{
    square.setSize(sf::Vector2f(size, size));
    square.setPosition(position);
    square.setFillColor(color);
    chessPiece = nullptr;
}





Square::Square() {}




void Square::draw(sf::RenderWindow& window)
{
    //square
    window.draw(this->square);

    //piece
    if (this->chessPiece != nullptr)
    {
        if (!this->chessPiece->isBeingDragged()) {
            // Get the size of the square
            sf::Vector2f squareSize = this->square.getSize();

            // Calculate the position to center the piece within the square
            sf::Vector2f piecePosition;
            piecePosition.x = square.getPosition().x;
            piecePosition.y = square.getPosition().y;


            // Set the position of the chess piece's sprite
            this->chessPiece->getSprite().setPosition(piecePosition);
        }

        // Draw the chess piece
        this->chessPiece->draw(window);
    }
}




void Square::setPiece(ChessPiece* targetPiece)
{
    chessPiece = targetPiece;
}




ChessPiece* Square::getPiece()
{
    return chessPiece;
}