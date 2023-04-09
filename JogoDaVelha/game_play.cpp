//
//  game_play.cpp
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//

#include "game_play.h"
#include "game_contract.h"
#include "inteligence_contract.h"
#include "view_contract.h"

const char OPTION_EXIT = '0';

GamePlay::GamePlay(ViewContract* view, InteligenceContract* inteligence, GameContract* game) {
    this->game = game;
    this->inteligence = inteligence;
    this->view = view;
}

void GamePlay::init() {

    char option = ' ';

    while (option != OPTION_EXIT) {

        char board[3][3] = {{UNDEFINED,UNDEFINED, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}};

        view->printGame(board);

        char gameMode = view->requestGameMode();

        int roundCounter = 1;

        bool gameEnded = false;
        while (!gameEnded) {
            int currentPlayer = game->getCurrentPlayer(roundCounter);

            view->printRound(roundCounter);
            view->printPlayerTurn(currentPlayer);

            int line = -1;
            int column = -1;

            bool validMove = false;
            while (!validMove) {
                int* gameRound;

                if(currentPlayer == PLAYER_TWO && gameMode == MODE_PLAYER_VS_CPU){
                    gameRound = inteligence->generateMove(currentPlayer, game->getBoard());
                } else  if(currentPlayer == PLAYER_ONE && gameMode == MODE_CPU_VS_PLAYER){
                    gameRound = inteligence->generateMove(currentPlayer, game->getBoard());
                } else {
                    gameRound = view->requestMove();
                }

                line = gameRound[0];
                column = gameRound[1];

                validMove = game->validateMove(line, column);
                if(!validMove){
                    view->printInvalidMove(line, column);
                }

            }

            view->printGame(game->move(currentPlayer, line,column));

            if(game->winner() != UNDEFINED){
                gameEnded = true;
                view->printWinner(currentPlayer);
            } else if (game->boardFull()){
                gameEnded = true;
                view->printDraw();
            }

            roundCounter++;
        }

        option = view->requestPlayAgain();
    }
}

