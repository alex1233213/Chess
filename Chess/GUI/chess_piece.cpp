#include "chess_piece.h"
#include <iostream>
#include "board.h"


void ChessPiece :: setColor(sf :: Color color)
{
    this->color = color;
}



void ChessPiece::draw(sf::RenderWindow& window, Board* board)
{
    if (this->isBeingDragged()) {
        window.draw(sprite);
    }
    else
    {
        Square square = board->getSquare(rank, file);
        sprite.setPosition(square.getPosition());
        window.draw(sprite);
    }
    
}





int ChessPiece::getRank() const
{
    return rank;
}

int ChessPiece::getFile() const
{
    return file;
}



void ChessPiece :: setRank(int newRow)
{
    rank = newRow;
}




void ChessPiece :: setFile(int newCol)
{
    file = newCol;
}




sf::Sprite& ChessPiece::getSprite()
{
    return sprite;
}




void ChessPiece::setTexture(const sf::Texture targetTexture)
{
    texture = targetTexture;
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(0.1f, 0.1f);
}





bool ChessPiece::isBeingDragged()
{
    return isDragged;
}




void ChessPiece::toggleDraggedState()
{
    isDragged = !isDragged;
}