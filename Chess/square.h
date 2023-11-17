#pragma once
#include <SFML/Graphics.hpp>
#include "chess_piece.h"

class Square
{
private:
	sf::RectangleShape square;
	ChessPiece* piece;

public:
	Square(sf::Vector2f position, sf::Color color, float size);
	Square();
	void draw(sf :: RenderWindow& window);
	sf::Vector2f getPosition();
	ChessPiece* getPiece();
	void setPiece(ChessPiece*);
};