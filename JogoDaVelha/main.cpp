//
//  main.cpp
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//

#include <iostream>
#include "game_play.h"
#include "view_contract.h"
#include "inteligence_contract.h"

ViewContract* createConsleView();
InteligenceContract* createInteligence();
GameContract* createGame();

int main(int argc, const char * argv[]) {
    ViewContract* view = createConsleView();
    InteligenceContract* inteligence = createInteligence();
    GameContract* game = createGame();
    GamePlay* gamePlay = new GamePlay(view, inteligence, game);
    gamePlay->init();
    return 0;
}
