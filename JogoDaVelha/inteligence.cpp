//
//  inteligence.cpp
//  JogoDaVelha
//
//  Created by André Figueiredo on 07/04/2023.
//
#include <iostream>
#include "inteligence_contract.h"

const char UNDEFINED = ' ';
const int AI_IMPOSSIBLE_WIN = -1;
const int AI_WIN = 0;

class Inteligence : public InteligenceContract
{

    int moveScore(int player, int valueA, int valueB, int valueC){
        if(valueA != UNDEFINED && valueA == valueB && valueB == valueC){
            return AI_WIN;
        }

        if (valueA != player && valueA != UNDEFINED){
            return AI_IMPOSSIBLE_WIN;
        }

        if (valueB != player && valueB != UNDEFINED){
            return AI_IMPOSSIBLE_WIN;
        }

        if (valueC != player && valueC != UNDEFINED){
            return AI_IMPOSSIBLE_WIN;
        }

        int movesToWin = 3;

        if(valueA == player){
            movesToWin--;
        }

        if(valueB == player){
            movesToWin--;
        }

        if(valueC == player){
            movesToWin--;
        }

        return movesToWin;
    }

    int getEnemy(int player, const char (*game)[3]){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int symbol = game[i][j];
                if(symbol != player && symbol != UNDEFINED){
                    return symbol;
                }
            }
        }

        return UNDEFINED;
    }

    void populateLines(const char (*game)[3], int (&allLines)[8][3]) {
        //c0
        allLines[0][0] = game[0][0];
        allLines[0][1] = game[1][0];
        allLines[0][2] = game[2][0];
        //c1
        allLines[1][0] = game[0][1];
        allLines[1][1] = game[1][1];
        allLines[1][2] = game[2][1];
        //c2
        allLines[2][0] = game[0][2];
        allLines[2][1] = game[1][2];
        allLines[2][2] = game[2][2];
        //l0
        allLines[3][0] = game[0][0];
        allLines[3][1] = game[0][1];
        allLines[3][2] = game[0][2];
        //l1
        allLines[4][0] = game[1][0];
        allLines[4][1] = game[1][1];
        allLines[4][2] = game[1][2];
        //l2
        allLines[5][0] = game[2][0];
        allLines[5][1] = game[2][1];
        allLines[5][2] = game[2][2];
        //d0
        allLines[6][0] = game[0][0];
        allLines[6][1] = game[1][1];
        allLines[6][2] = game[2][2];
        //d1
        allLines[7][0] = game[0][2];
        allLines[7][1] = game[1][1];
        allLines[7][2] = game[2][0];
    }

    int* avaliateMove(int player, const char (*game)[3], int line, int column){
        int* result = new int[2];

        if(game[line][column] != UNDEFINED){
            result[0] = UNDEFINED;
            return result;
        }

        char game_copy[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                game_copy[i][j] = game[i][j];
            }
        }


        game_copy[line][column] = player;

        int allLines[8][3];
        populateLines(game_copy, allLines);

        int bestScore = INT_MAX;
        int possibleWinCounter = 0;

        int enemy = getEnemy(player, game);

        for(int i = 0; i < 8 ; i++){
            int valueA = 0;
            int valueB = 0;
            int valueC = 0;
            for(int j = 0; j < 3 ; j++){
                switch (j) {
                    case 0:
                        valueA = allLines[i][j];
                       break;
                    case 1:
                        valueB = allLines[i][j];
                       break;
                    case 2:
                        valueC = allLines[i][j];
                       break;
                }
            }

            if(enemy != UNDEFINED){
                int enemyOccurrences = 0;
                if(valueA == enemy){
                    enemyOccurrences++;
                }

                if(valueB == enemy){
                    enemyOccurrences++;
                }

                if(valueC == enemy){
                    enemyOccurrences++;
                }

                if(enemyOccurrences > 1){
                    result[0] = AI_WIN;
                    return result;
                }
            }

            int score = moveScore(player, valueA, valueB, valueC);

            switch (score) {
                case AI_WIN:
                    result[0] = AI_WIN;
                    return result;
                    break;
                case AI_IMPOSSIBLE_WIN:
                    break;
                default:
                    if(bestScore > score){
                        bestScore = score;
                    }
                    possibleWinCounter++;
                    break;
            }
        }

        result[0] = bestScore;
        result[1] = possibleWinCounter;
        return result;
    }

    int* generateMove(int player, const char (*game)[3]) override {
        int* comparator = new int[2];
        comparator[0] = INT_MIN;
        comparator[1] = INT_MAX;

        int* result = new int[2];

        for(int i = 0; i < 3 ; i++){
            for(int j = 0; j < 3 ; j++){
                int line = i;
                int column = j;

                int* score = avaliateMove(player, game, line, column);

                switch (score[0]) {
                    case UNDEFINED:
                        continue;
                        break;
                    case AI_WIN:
                        result[0] = line;
                        result[1] = column;
                        return result;
                        break;
                    default:
                        if(score[0] < comparator[0] || score[0] || (score[0] == comparator[0] && score[1] > comparator[1])){
                            comparator[0] = score[0];
                            comparator[1] = score[1];
                            result[0] = line;
                            result[1] = column;
                        }
                        break;
                }
            }
        }

        return result;
    }

};

InteligenceContract* createInteligence(){
    return new Inteligence();
}

