//
//  game.h
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//

#pragma once

const char PLAYER_ONE = 'X';
const char PLAYER_TWO = 'O';
const char UNDEFINED = ' ';

const char MODE_PLAYER_VS_PLAYER = '1';
const char MODE_PLAYER_VS_CPU = '2';
const char MODE_CPU_VS_PLAYER = '3';

class GameContract {
public:
    virtual bool boardFull() = 0;

    virtual char winner() = 0;

    virtual bool validateMove(int line, int column) = 0;

    virtual int getCurrentPlayer(int round) = 0;

    virtual char (*move(int player, int line, int column))[3] = 0;

    virtual char (*getBoard())[3] = 0;

};

