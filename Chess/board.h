//declaration for board class


#pragma once 

#include <SFML/Graphics.hpp>
#include "chess_piece.h"
#include "square.h"
#include <cstdint>

using namespace std;

class Board {
private:

    Square squares[8][8];
    int num_squares = 64;
    int rows = 8;
    int cols = 8;
    float square_side;
    sf::Color dark_square = sf::Color(181, 136, 99);
    sf::Color light_square = sf::Color(240, 217, 181);
    std::vector<ChessPiece*> pieces;

    //black pieces bitboards
    uint64_t bPawns;
    uint64_t bRooks;
    uint64_t bBishops;
    uint64_t bKnights;
    uint64_t bKing;
    uint64_t bQueen;

    //white pieces bitboards
    uint64_t wPawns;
    uint64_t wRooks;
    uint64_t wBishops;
    uint64_t wKnights;
    uint64_t wKing;
    uint64_t wQueen;


public:
    Board(int, int); // Constructor declaration
    void draw(sf::RenderWindow& window);
    void loadSquares(int);
    void loadPieces();
    std::vector<ChessPiece*> getPieces();
    void loadPiece(string texturePath, int, int);
    void addPiece(ChessPiece*, int, int);
    float getSquareSide();
    Square(&getSquares())[8][8];
};
