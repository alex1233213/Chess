#include "square.h"
#include <iostream>
#include "chess_piece.h"


Square::Square(sf::Vector2f position, sf::Color color, float size)
{
    square.setSize(sf::Vector2f(size, size));
    square.setPosition(position);
    square.setFillColor(color);
}



Square::Square() {}



void Square::draw(sf::RenderWindow& window)
{
    //square
    window.draw(this->square);
}




sf::Vector2f Square::getPosition()
{
    return square.getPosition();;
}




ChessPiece* Square::getPiece()
{
    return piece;
}



void Square::setPiece(ChessPiece* targetPiece)
{
    this->piece = targetPiece;
}