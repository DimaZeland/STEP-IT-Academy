#pragma once

#include "Menu.h"

class XOclass
{
public:
	// constructor & destructor
	XOclass() : Line(0), Column(0), XO(' '), Player1{}, Player2{}, DeadHeat{ false }, Winner{} {}
	~XOclass() {}
	// public data
	std::string Player1; // name of the first player
	std::string Player2; // name of the second player
	std::string Winner; // winner's name

						// class methods
	void FillingField(void); // filling the game field
	void FieldMapping(void) const; // display the game field in the console
	void GameAlgorithm(void); // internal algorithm of the game
	void MakeNextMove(char&); // populating a cell with a user
	inline void SetXO(int flag) { (flag == 1) ? XO = 'X' : XO = 'O'; }
	bool StrokeSelection(int&, int&, char&); // selection of the cell to fill
	bool PowerReserve(); // checking the game field for empty cells
	bool WinCheck(void); // Checking the field of the game for the victory of one of the participants
private:
	char fieldGame[4][4]; //field game
	int Line;
	int Column;
	char XO; // filler
	bool DeadHeat; // check to stop the game in a draw at the end of moves
};
