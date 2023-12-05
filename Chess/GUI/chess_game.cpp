#include "board.h"
#include "drag&drop.h"
#include "chess_game.h"

ChessGame::ChessGame(int windowWidth, int windowHeight) : board(windowWidth, windowHeight, boardState.getBitboards()), currentPlayer("white") {}




ChessGame::~ChessGame() {
    for (ChessPiece* chessPiece : board.getPieces()) {
        delete chessPiece;
    }
}




void ChessGame::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        dragDropHandler.listenDragDropEvent(event, board);
    }
}





void ChessGame::switchTurn() {
    currentPlayer = (currentPlayer == "white") ? "black" : "white";
}




void ChessGame::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        handleEvents(window);

        window.clear();
        board.draw(window);
        window.display();
    }
}
