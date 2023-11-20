#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GUI/board.h"
#include "GUI/drag&drop.h"
#include "GUI/chess_game.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "CHESS");
    ChessGame chessGame(WINDOW_WIDTH, WINDOW_HEIGHT);
    chessGame.run(window);

    return 0;
}