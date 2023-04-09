//
//  inteligence.hpp
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//

#pragma once

#include <iostream>

class InteligenceContract{

public:
    virtual int* generateMove(int player, const char (*game)[3]) = 0;

};

