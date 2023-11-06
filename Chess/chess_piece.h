#pragma once 

#include <SFML/Graphics.hpp>
#include <string>


class ChessPiece
{
private:
    
    sf::Color color; 
    bool captured;
    int rank;
    int file;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    void draw(sf::RenderWindow& window);
    sf :: Sprite& getSprite();
    void setColor(sf :: Color);
    int getRank() const;
    int getFile() const;
    void setRank(int);
    void setFile(int);
    void setTexture(const sf::Texture texture);
};
