#include "chess_piece.h"
#include <iostream>



void ChessPiece :: setColor(sf :: Color color)
{
    this->color = color;
}



void ChessPiece::draw(sf::RenderWindow& window)
{
    // Draw the sprite on the window
    window.draw(sprite);
}





int ChessPiece ::  getRank() const
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
