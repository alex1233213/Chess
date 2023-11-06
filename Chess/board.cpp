#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "board.h"



#define WHITE_PAWN "resources/wP.png"
#define BLACK_PAWN "resources/bP.png"
#define WHITE_KING "resources/wK.png"
#define BLACK_KING "resources/bK.png"
#define WHITE_ROOK "resources/wR.png"
#define BLACK_ROOK "resources/bR.png"
#define WHITE_BISHOP "resources/wB.png"
#define BLACK_BISHOP "resources/bB.png"
#define WHITE_QUEEN "resources/wQ.png"
#define BLACK_QUEEN "resources/bQ.png"
#define WHITE_KNIGHT "resources/wKn.png"
#define BLACK_KNIGHT "resources/bKn.png"




// board constructor
Board::Board(int window_width, int window_height)
{
    // Black pieces bitboards
    bPawns = 0b0000000000000000000000000000000000000000000000001111111100000000;
    bRooks = 0b0000000000000000000000000000000000000000000000000000000010000001;
    bBishops = 0b0000000000000000000000000000000000000000000000000000000000100100;
    bKnights = 0b0000000000000000000000000000000000000000000000000000000001000010;
    bKing = 1ULL << 3;
    bQueen = 1ULL << 4;

    // White pieces bitboards
    wPawns = 0b0000000011111111000000000000000000000000000000000000000000000000;
    wRooks = 0b1000000100000000000000000000000000000000000000000000000000000000;
    wBishops = 0b010010000000000000000000000000000000000000000000000000000000000;
    wKnights = 0b0100001000000000000000000000000000000000000000000000000000000000;
    wKing = 0b0000100000000000000000000000000000000000000000000000000000000000;
    wQueen = 0b0001000000000000000000000000000000000000000000000000000000000000;

    float window_area = window_width * window_height;
    float square_area = window_area / num_squares;
    float square_side = sqrt(square_area);
    loadSquares(square_side);
    loadPieces();
}




void Board :: loadSquares(int squareSide)
{
    //load the squares
    for (int i = 0; i < rows; ++i)
    {
        bool is_dark_square = ((i % 2) == 0) ? true : false;

        for (int j = 0; j < cols; ++j)
        {

            sf::Color square_color = is_dark_square ? dark_square : light_square;
            sf::Vector2f square_position = sf::Vector2f(j * squareSide, i * squareSide);
            squares[i][j] = Square(square_position, square_color, squareSide);

            is_dark_square = !is_dark_square;
        }
    }
}






void Board :: draw(sf::RenderWindow& window)
{
    //squares
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            squares[i][j].draw(window);
        }
    }
}




void Board::loadPieces()
{
    for (int i = 0; i < num_squares; ++i)
    {
        //squares are iterated from h8, i.e. least significant bit
        int file = 7 - (i % 8);
        int rank = 7 - (i / 8);

        if (wPawns & (1ULL << i))
        {
            loadPiece(WHITE_PAWN, file, rank);
        }

        if (bPawns & (1ULL << i))
        {
            loadPiece(BLACK_PAWN, file, rank);
        }

        if (wKnights & (1ULL << i))
        {
            loadPiece(WHITE_KNIGHT, file, rank);
        }

        if (bKnights & (1ULL << i))
        {
            loadPiece(BLACK_KNIGHT, file, rank);
        }

        if (wRooks & (1ULL << i))
        {
            loadPiece(WHITE_ROOK, file, rank);
        }

        if (bRooks & (1ULL << i))
        {
            loadPiece(BLACK_ROOK, file, rank);
        }

        if (wKing & (1ULL << i))
        {
            loadPiece(WHITE_KING, file, rank);
        }

        if (bKing & (1ULL << i))
        {
            loadPiece(BLACK_KING, file, rank);
        }

        if (wQueen & (1ULL << i))
        {
            loadPiece(WHITE_QUEEN, file, rank);
        }

        if (bQueen & (1ULL << i))
        {
            loadPiece(BLACK_QUEEN, file, rank);
        }

        if (bBishops & (1ULL << i))
        {
            loadPiece(BLACK_BISHOP, file, rank);
        }

        if (wBishops & (1ULL << i))
        {
            loadPiece(WHITE_BISHOP, file, rank);
        }
    }
}




std::vector<ChessPiece*> Board:: getPieces() {
    return pieces;
}



void Board::loadPiece(string texturePath, int file, int rank)
{
    ChessPiece* piece = new ChessPiece;
    sf::Texture texture; // Create a new texture for each piece
    
    if (!texture.loadFromFile(texturePath))
    {
        std::cout << "Failed to load piece" << std::endl;
    }
    else
    {
        piece->setTexture(texture);
        pieces.push_back(piece);
        piece->setRank(rank);
        piece->setFile(file);
        addPiece(piece, rank, file);
    }
}




void Board::addPiece(ChessPiece* piece, int rank, int file)
{
    int row = 7 - rank;
    squares[row][file].setPiece(piece);
}