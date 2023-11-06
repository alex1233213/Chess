#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "board.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "CHESS");
    Board board(WINDOW_WIDTH, WINDOW_HEIGHT);

    /*ChessPiece piece;
    sf::Texture texture;
    texture.loadFromFile("resources/w_king.png");
    piece.getSprite().setTexture(texture);*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        board.draw(window);
        window.display();
    }


    for (ChessPiece* chessPiece : board.getPieces())
    {
        delete chessPiece;
    }

    return 0;
}
