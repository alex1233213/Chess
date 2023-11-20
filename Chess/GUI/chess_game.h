#pragma once

#include "board.h"
#include "drag&drop.h"


class ChessGame {
private:
    Board board;
    DragAndDropHandler dragDropHandler;
    std::string currentPlayer;

public:
    ChessGame(int windowWidth, int windowHeight);
    ~ChessGame();
    void handleEvents(sf::RenderWindow& window);
    void switchTurn();
    void run(sf::RenderWindow& window);
};