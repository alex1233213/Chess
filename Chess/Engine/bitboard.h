#pragma once
#include <cstdint>

class Bitboard {
private:
    uint64_t board;

public:
    void setBoard(uint64_t);
    uint64_t getBoard();
};