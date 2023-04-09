//
//  view_contract.hpp
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//

#pragma once

class ViewContract {
public:
    virtual void printRound(int roundCounter) = 0;
    virtual void printPlayerTurn(int player) = 0;
    virtual void printWinner(int player) = 0;
    virtual void printGame(char game[3][3]) = 0;
    virtual int requestGameMode() = 0;
    virtual  int* requestMove() = 0;
    virtual void printInvalidMove(int line, int column) = 0;
    virtual void printDraw() = 0;
    virtual int requestPlayAgain() = 0;
};
