#pragma once 

#include <SFML/Graphics.hpp>
#include <string>

class Board;

class ChessPiece
{
private:
    
    sf::Color color; 
    bool captured;
    int rank;
    int file;
    sf::Texture texture;
    sf::Sprite sprite;
    bool isDragged = false;

public:
    void draw(sf::RenderWindow& window, Board* board);
    sf :: Sprite& getSprite();
    void setColor(sf :: Color);
    int getRank() const;
    int getFile() const;
    void setRank(int);
    void setFile(int);
    void setTexture(const sf::Texture texture);
    bool isBeingDragged();
    void toggleDraggedState();
};
