#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void playerturn (int rowStartingLocation, int colStartingLocation, int rowEndingLocation, int colEndingLocation, std::string board[8][8]) {

   if (board[rowStartingLocation][colStartingLocation] == "  ") {
        std::cout << "Invalid move. No piece at starting location.\n" << std::endl;
        return;
    }

    //Figyre out what piece is being moved
    std::string piece = board[rowStartingLocation][colStartingLocation];

    // Check if the move is valid
    if (rowEndingLocation < 0 || rowEndingLocation > 7 || colEndingLocation < 0 || colEndingLocation > 7) {
        std::cout << "Invalid move. Out of bounds.\n" << std::endl;
        return;
    }

    //If the piece can move to the ending location, i.e does the space have a piece of the same color or can the piece move there. Like rooks can only move in straight lines, bishops can only move diagonally, etc.

    if (piece == "♙ ") { // Pawn
        
        if (rowEndingLocation != rowStartingLocation + 1 || colEndingLocation != colStartingLocation) {
            std::cout << "Invalid move for Pawn.\n" << std::endl;
            return;
        }
        
    } else if (piece == "♖ ") { // Rook
        if (rowEndingLocation != rowStartingLocation && colEndingLocation != colStartingLocation) {
            std::cout << "Invalid move for Rook.\n" << std::endl;
            return;
        }
    } else if (piece == "♘ ") { // Knight
        if (!((abs(rowEndingLocation - rowStartingLocation) == 2 && abs(colEndingLocation - colStartingLocation) == 1) ||
              (abs(rowEndingLocation - rowStartingLocation) == 1 && abs(colEndingLocation - colStartingLocation) == 2))) {
            std::cout << "Invalid move for Knight.\n" << std::endl;
            return;
        }
    } else if (piece == "♗ ") { // Bishop
        if (abs(rowEndingLocation - rowStartingLocation) != abs(colEndingLocation - colStartingLocation)) {
            std::cout << "Invalid move for Bishop.\n" << std::endl;
            return;
        }
    } else if (piece == "♔ ") { // King
        if (abs(rowEndingLocation - rowStartingLocation) > 1 || abs(colEndingLocation - colStartingLocation) > 1) {
            std::cout << "Invalid move for King.\n" << std::endl;
            return;
        }
    } else if (piece == "♕ ") { // Queen
        if (!(rowEndingLocation == rowStartingLocation || colEndingLocation == colStartingLocation ||
              abs(rowEndingLocation - rowStartingLocation) == abs(colEndingLocation - colStartingLocation))) {
            std::cout << "Invalid move for Queen.\n" << std::endl;
            return;
        }
    } else {
        std::cout << "Unknown piece type.\n" << std::endl;
        return;
    }

    board[rowEndingLocation][colEndingLocation] = board[rowStartingLocation][colStartingLocation];
    board[rowStartingLocation][colStartingLocation] = "  ";

    std::cout << "Moved piece from (" << rowStartingLocation + 1 << ", " << colStartingLocation + 1 << ") to (" << rowEndingLocation + 1 << ", " << colEndingLocation + 1 << ")." << std::endl;

}

void displayBoard(std::string board[8][8]) {
    cout << "Current board:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << board[i][3] << " | " << board[i][4] << " | " << board[i][5] << " | " << board[i][6] << " | " << board[i][7] << endl;
        if (i < 7) {
            cout << "—-——|—-——|—-——|—-——|—-——|—-——|—-——|—-——" << endl;}  
        }
        cout << "\n";
}

int main () {

    int rowStartingLocation, colStartingLocation;
    int rowEndingLocation, colEndingLocation;

    bool pawnfirstMove = true;
    bool gameOver = false;
   
    std::string board[8][8] = {
        {"♖ ","♘ ","♗ ","♔ ","♕ ","♗ ","♘ ","♖ "},
        {"♙ ","♙ ","♙ ","♙ ","♙ ","♙ ","♙ ","♙ "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"♟ ","♟ ","♟ ","♟ ","♟ ","♟ ","♟ ","♟ "},
        {"♜ ","♞ ","♝ ","♚ ","♛ ","♝ ","♞ ","♜ "}
    };

    displayBoard(board);

    while (gameOver == false) {
        
        std::cout << "What piece do you want to move? (row and column): \n";

        cin >> rowStartingLocation >> colStartingLocation;
        rowStartingLocation--; colStartingLocation--;

        std::cout << "Where do you want to move it? (row and column): ";

        cin >> rowEndingLocation >> colEndingLocation;
        rowEndingLocation--; colEndingLocation--;

        playerturn(rowStartingLocation, colStartingLocation, rowEndingLocation, colEndingLocation, board);

        displayBoard(board);

    }

}


