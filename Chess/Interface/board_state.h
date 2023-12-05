#pragma once
#include "../Engine/bitboard.h"
#include <map>
#include <string>

using namespace std;

class BoardState {
private: 
	map<string, Bitboard> pieceBitboards;

public:
	BoardState();
	void addBitboard(const std::string&, const Bitboard&);
	map<string, Bitboard> getBitboards();
};