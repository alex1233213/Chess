#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "board.h"
#include "drag&drop.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "CHESS");
    Board board(WINDOW_WIDTH, WINDOW_HEIGHT);
    DragAndDropHandler dragDropHandler;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            dragDropHandler.listenDragDropEvent(event, board);
        }

        window.clear();
        board.draw(window);
        window.display();
    }


    for (ChessPiece* chessPiece : board.getPieces())
    {
        delete chessPiece;
    }

    return 0;
}
