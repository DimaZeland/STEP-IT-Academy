#include "XOclass.h"

void
XOclass::FillingField(void) { // filling the game field

    for (int i = 0; i < 4; ++i) // filling the game fields
        for (int j = 0; j < 4; ++j)
            if (i == 0 && j > 0) // rendering column names
                fieldGame[i][j] = j + 48;
            else if (j == 0 && i > 0) // rendering lines names
                fieldGame[i][j] = i + 48;
            else // filling empty fields
                fieldGame[i][j] = ' ';
}

void
XOclass::GameAlgorithm(void) { // internal algorithm of the game

    FillingField(); // the formation of an array for subsequent filling and mapping
    cout << endl;
    cin.get();
    cout << "\nWe are glad to welcome you in the game \"Tic - Tac - Toe!\"\n" <<
         "First player, you will play 'X'!\nPlease enter your name : ";
    std::getline(cin, Player1);
    cout << "Second player, you will play 'O'!\nPlease enter your name : ";
    std::getline(cin, Player2);

    int flagXO = 1;
    do {
        FieldMapping(); // display the game field in the console
        SetXO(flagXO); // initial installation of the filler 'X' by Player1
        MakeNextMove(XO); // take the next step
        flagXO *= -1; // change the flag from -1 to 1 in a cycle
        system("cls");
    } while (DeadHeat == false && WinCheck() == false); // to win or draw

    FieldMapping(); // display the game field in the console
    if (WinCheck() == true) {
        cout << "\nGame over! Congratulations to " << Winner << " on his victory!\n";
        return;
    }
    if (DeadHeat == true) {
        cout << "\nThe game ended in a draw!\n";
        return;
    }
}

void
XOclass::MakeNextMove(char &xo) { // populating a cell with a user

    std::string player;
    xo == 'X' ? player = Player1 : player = Player2; // definition of a player who makes a move
    do {
        cout << endl << player << " please select the location " << xo << " <1-3> <1-3>: ";
        cin >> Line >> Column;

        if (StrokeSelection(Line, Column, xo))
            break; // the move was successfully made
        else
            cout << "\nThe specified cell is already full. Please make a move by selecting an empty cell\n";
    } while (PowerReserve()); // check for empty cells
}

void
XOclass::FieldMapping(void) const { // display the game field in the console

    for (int i = 0; i < 4; ++i) { // display the game field
        for (int j = 0; j < 4; ++j)
            cout << fieldGame[i][j];
        cout << '\n';
    }
}

bool
XOclass::StrokeSelection(int &line, int &column, char &xo) { // selection of the cell to fill

    if (fieldGame[line][column] != 'X' && fieldGame[line][column] != 'O') {
        fieldGame[line][column] = xo;
        return true;
    } else return false;
}

bool
XOclass::PowerReserve() { // checking the game field for empty cells

    for (int i = 1; i < 4; ++i)
        for (int j = 1; j < 4; ++j)
            if (fieldGame[i][j] != 'X' && fieldGame[i][j] != 'O')
                return true;

    DeadHeat = true; // putting a stoppage flag in the results of a draw
    return false;
}

bool
XOclass::WinCheck(void) { // checking the field of the game for the victory of one of the participants

    for (int i = 1; i < 4; ++i) // checking the game field for having a victory horizontally and vertically
        if (fieldGame[i][1] != ' ' && fieldGame[i][1] == fieldGame[i][2] && fieldGame[i][2] == fieldGame[i][3] &&
            fieldGame[i][3] == fieldGame[i][1]) {
            fieldGame[i][1] == 'X' ? Winner = Player1 : Winner = Player2;
            return true;
        } else if (fieldGame[1][i] != ' ' && fieldGame[1][i] == fieldGame[2][i] && fieldGame[2][i] == fieldGame[3][i] &&
                   fieldGame[3][i] == fieldGame[1][i]) {
            fieldGame[1][i] == 'X' ? Winner = Player1 : Winner = Player2;
            return true;
        }

    // check the game field for a victory on the diagonals
    if (fieldGame[1][1] != ' ' && fieldGame[1][1] == fieldGame[2][2] && fieldGame[2][2] == fieldGame[3][3] &&
        fieldGame[3][3] == fieldGame[1][1]) {
        fieldGame[1][1] == 'X' ? Winner = Player1 : Winner = Player2;
        return true;
    } else if (fieldGame[3][1] != ' ' && fieldGame[3][1] == fieldGame[2][2] && fieldGame[2][2] == fieldGame[1][3] &&
               fieldGame[1][3] == fieldGame[3][1]) {
        fieldGame[3][1] == 'X' ? Winner = Player1 : Winner = Player2;
        return true;
    } else
        return false;
}