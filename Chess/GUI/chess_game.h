#pragma once

#include "board.h"
#include "drag&drop.h"
#include "../Interface/board_state.h"


class ChessGame {
private:
    BoardState boardState;
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