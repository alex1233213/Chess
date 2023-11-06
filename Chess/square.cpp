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
        // Get the size of the square
        sf::Vector2f squareSize = this->square.getSize();

        // Calculate the position to center the piece within the square
        sf::Vector2f piecePosition;
        piecePosition.x = this->square.getPosition().x + (squareSize.x - this->chessPiece->getSprite().getGlobalBounds().width) / 2;
        piecePosition.y = this->square.getPosition().y + (squareSize.y - this->chessPiece->getSprite().getGlobalBounds().height) / 2;

        // Set the position of the chess piece's sprite
        this->chessPiece->getSprite().setPosition(piecePosition);

        // Draw the chess piece
        this->chessPiece->draw(window);
    }
}




void Square::setPiece(ChessPiece* targetPiece)
{
    chessPiece = targetPiece;
}