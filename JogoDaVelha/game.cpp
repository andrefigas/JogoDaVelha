//
//  game.cpp
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//
#include <iostream>
#include "game_contract.h"

struct Game : public GameContract {

    private : char board[3][3] = {{UNDEFINED,UNDEFINED, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}};

    bool boardFull() override {
        for(int i = 0; i < 3 ; i++){
            for(int j = 0; j < 3 ; j++){
                if(board[i][j] == UNDEFINED){
                    return  false;
                }
            }
        }

        return true;
    }

    char winner() override {


        if(board[0][0] != UNDEFINED && board[0][0] == board[1][0] && board[0][0] == board[2][0]){
            return board[0][0];
        }

        if(board[0][1] != UNDEFINED && board[0][1] == board[1][1] && board[0][1] == board[2][1]){
            return board[1][0];
        }

        if(board[0][2] != UNDEFINED && board[0][2] == board[1][2]  && board[0][2] == board[2][2]){
            return board[2][0];
        }

        if(board[0][0] != UNDEFINED && board[0][0] == board[0][1] && board[0][0] == board[0][2]){
            return board[0][0];
        }

        if(board[1][0] != UNDEFINED && board[1][0] == board[1][1] && board[1][0] == board[1][2]){
            return board[1][0];
        }

        if(board[2][0] != UNDEFINED && board[2][0] == board[2][1]  && board[2][0] == board[2][2]){
            return board[2][0];
        }

        if(board[0][0] != UNDEFINED && board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            return board[0][0];
        }

        if(board[0][2] != UNDEFINED && board[0][2] == board[1][1] && board[0][0] == board[2][0]){
            return board[0][0];
        }

        return UNDEFINED;
    }

    bool validateMove(int line, int column) override {
        if (line > 2 || column > 2 || board[line][column] != UNDEFINED){
            return false;
        }

        return true;
    }

    int getCurrentPlayer(int round) override {
        if(round % 2 == 0){
            return PLAYER_TWO;
        } else{
            return PLAYER_ONE;
        }

        return 0;
    }

    char (*move(int player, int line, int column))[3] override {
            board[line][column] = player;
            return board;
        }

    char (*getBoard())[3] override {
        return board;
    }

};

GameContract* createGame(){
    return new Game();
}
