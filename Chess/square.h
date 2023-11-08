#pragma once
#include <SFML/Graphics.hpp>
#include "chess_piece.h"

class Square
{
private:
	sf::RectangleShape square;
	ChessPiece* chessPiece;

public:
	Square(sf::Vector2f position, sf::Color color, float size);
	Square();
	void draw(sf :: RenderWindow& window);
	void setPiece(ChessPiece* targetPiece);
	ChessPiece* getPiece();
};