//
//  game_play.h
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//

#pragma once // include guard

// forward declarations
class GameContract;
class InteligenceContract;
class ViewContract;

class GamePlay {
    GameContract* game;
    InteligenceContract* inteligence;
    ViewContract* view;
public:
    GamePlay(ViewContract* view, InteligenceContract* inteligence, GameContract* game);
    void init();
};
