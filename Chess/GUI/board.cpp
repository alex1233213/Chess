#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "board.h"
#include "piece_paths.h"



// board constructor
Board::Board(int window_width, int window_height, map<string, Bitboard> bitboards)
{
    float window_area = window_width * window_height;
    float square_area = window_area / num_squares;
    square_side = sqrt(square_area);
    loadSquares(square_side);
    loadPieces(bitboards);
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

    //pieces
    for (int i = 0; i < pieces.size(); ++i)
    {
        pieces[i]->draw(window, this);
    }
}




void Board::loadPieces(map<string, Bitboard> bitboards)
{
    for (int i = 0; i < num_squares; ++i)
    {
        //squares are iterated from h8, i.e. least significant bit
        int file = 7 - (i % 8);
        int rank = 7 - (i / 8);

        for (auto const& pieceBitboard : bitboards)
        {
            string piece = pieceBitboard.first;
            Bitboard bitboard = pieceBitboard.second;

            auto it = imagePathMap.find(piece);
            if (it != imagePathMap.end() && (bitboard.getBoard() & 1ULL << i))
            {
                loadPiece(it->second, file, rank);
            }
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
        piece->setRank(rank);
        piece->setFile(file);
        pieces.push_back(piece);
        Square& targetSquare = getSquare(rank, file);
        targetSquare.setPiece(piece);
    }
}




float Board::getSquareSide()
{
    return square_side;
}




Square(&Board::getSquares())[8][8]{
    return squares;
}





Square& Board::getSquare(int rank, int file)
{
    //the board is displayed as white pieces at the bottom, therefore first rank is the last row in 2d array
    int row = 7 - rank;

    return squares[row][file];
}



//convert row from 2d array to rank notation, rank start at the bottom of the 2d array
int Board::getRank(int row)
{
    return 7 - row;
}