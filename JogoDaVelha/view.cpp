//
//  view.cpp
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//
#include <iostream>
#include "game_contract.h"
#include "view_contract.h"

using namespace std;

class View : public ViewContract  {

    void printRound(int roundCounter) override {
        cout << "=================== Round" << roundCounter << " ===================\n";
    }

    void printPlayerTurn(int player) override {
        if(player == PLAYER_ONE) {
            cout << "Player 1 - X\n\n";
        } else {
            cout << "Player 2 - O\n\n";
        }
    }

    void printWinner(int player) override {
        if(player == PLAYER_ONE) {
            cout << "Player 1 Won\n\n";
        } else {
            cout << "Player 2 Won\n\n";
        }
    }

    void printGame(char game[3][3]) override {
        cout <<  "\t     |     |     \n";
        cout <<  "\t  " << game[0][0] <<"  |  " << game[0][1] <<"  |  " << game[0][2] << "  \n";
        cout <<  "\t_____|_____|_____\n";
        cout <<  "\t     |     |     \n";
        cout <<  "\t  " << game[1][0] <<"  |  " << game[1][1] <<"  |  " << game[1][2] << "  \n";
        cout <<  "\t_____|_____|_____\n";
        cout <<  "\t     |     |     \n";
        cout <<  "\t  " << game[2][0] <<"  |  " << game[2][1] <<"  |  " << game[2][2] << "  \n";
        cout <<  "\t     |     |     \n";
    }

    void printInvalidMove(int line, int column) override {
        cout << "Choice a valid position\n";
    }

    void printDraw() override {
        cout << "Draw\n";
    }

    int requestGameMode() override {
        char gameMode = ' ';
        while (gameMode != MODE_PLAYER_VS_PLAYER &&
              gameMode != MODE_PLAYER_VS_CPU &&
              gameMode != MODE_CPU_VS_PLAYER) {
           cout << "\n1 - PLAYER vs PLAYER\n";
           cout << "2 - PLAYER vs CPU\n";
           cout << "3 - CPU vs PLAYER\n";
           cin >> gameMode;
       }

       return gameMode;
    }

    int requestPlayAgain() override {
        int option;
        cout << "Press 0 exit or any other key to play again\n";
        cin >> option;
        return option;
    }

    int* requestMove() override {
        int* result = new int[2];
        cout << "Choice a line\n";
        cin >> result[0];
        cout << "Choice a column\n";
        cin >> result[1];
        return result;
    }

};

ViewContract* createConsleView(){
    return new View();
}
