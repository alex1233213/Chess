//declaration for board class


#pragma once 

#include <SFML/Graphics.hpp>
#include "chess_piece.h"
#include "square.h"
#include <cstdint>
#include "../Engine/bitboard.h"

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

public:
    Board(int, int, map<string, Bitboard>);
    void draw(sf::RenderWindow& window);
    void loadSquares(int);
    void loadPieces(map<string, Bitboard>);
    std::vector<ChessPiece*> getPieces();
    void loadPiece(string texturePath, int, int);
    float getSquareSide();
    Square(&getSquares())[8][8];
    Square& getSquare(int rank, int file);
    int getRank(int row);
};
