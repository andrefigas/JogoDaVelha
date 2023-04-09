//
//  InteligenceTest.cpp
//  JogoDaVelhaTest
//
//  Created by André Figueiredo on 08/04/2023.
//

#include "view_contract.h"
#include "inteligence_contract.h"

ViewContract* createConsleView();
InteligenceContract* createInteligence();

class IntelligenceTest {

    const char PLAYER_ONE = 'X';
    const char PLAYER_TWO = 'O';
    const char UNDEFINED = ' ';
    
private:

    bool compare(const char (*expected)[3], const char (*result)[3]){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(expected[i][j] != result[i][j]){
                    std::cout << "\n\033[1;31mFAILURE\033[0m" << std::endl;
                    return false;
                }
            }
        }

        std::cout << "\n\033[1;32mSUCCESS\033[0m" << std::endl;
        return true;
    }

    bool simpleWin(){

        std::cout << "\nSIMPLE WIN: \n";

        char given[3][3] = {{PLAYER_ONE,PLAYER_ONE, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}};
        std::cout << "\nGIVEN: \n";
        createConsleView()->printGame(given);

        char expected[3][3] = {{PLAYER_ONE,PLAYER_ONE, PLAYER_ONE}, {UNDEFINED,UNDEFINED, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}};
        std::cout << "EXPECTED: \n";
        createConsleView()->printGame(expected);
        std::cout << "RESULT: \n";

        int* move = createInteligence()->generateMove('X', given);
        given[move[0]][move[1]] = PLAYER_ONE;
        createConsleView()->printGame(given);

        return compare(expected, given);
    }

    bool winOnNextMove(){

        std::cout << "\nWIN ON NEXT MOVE: \n";

        char given[3][3] = {{UNDEFINED,UNDEFINED, PLAYER_ONE}, {UNDEFINED,PLAYER_TWO, UNDEFINED}, {PLAYER_ONE,UNDEFINED, UNDEFINED}};
        std::cout << "\nGIVEN: \n";
        createConsleView()->printGame(given);

        char expected[3][3] = {{UNDEFINED,UNDEFINED, PLAYER_ONE}, {UNDEFINED,PLAYER_TWO, UNDEFINED}, {PLAYER_ONE,UNDEFINED, PLAYER_ONE}};
        std::cout << "EXPECTED: \n";
        createConsleView()->printGame(expected);
        std::cout << "RESULT: \n";

        int* move = createInteligence()->generateMove('X', given);
        given[move[0]][move[1]] = PLAYER_ONE;
        createConsleView()->printGame(given);

        return compare(expected, given);
    }

    bool avoidEnemyWin(){

        std::cout << "\nAVOID ENEMY WIN: \n";

        char given[3][3] = {{UNDEFINED,PLAYER_TWO, PLAYER_TWO}, {UNDEFINED,UNDEFINED, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}};
        std::cout << "\nGIVEN: \n";
        createConsleView()->printGame(given);

        char expected[3][3] = {{PLAYER_ONE,PLAYER_TWO, PLAYER_TWO}, {UNDEFINED,UNDEFINED, UNDEFINED}, {UNDEFINED,UNDEFINED, UNDEFINED}};
        std::cout << "EXPECTED: \n";
        createConsleView()->printGame(expected);
        std::cout << "RESULT: \n";

        int* move = createInteligence()->generateMove('X', given);
        given[move[0]][move[1]] = PLAYER_ONE;
        createConsleView()->printGame(given);

        return compare(expected, given);
    }

public:
    void test() {
        int total = 3;
        int success = 0;

        if(simpleWin()){
            success++;
        }

        if(winOnNextMove()){
            success++;
        }

        if(avoidEnemyWin()){
            success++;
        }

        std::cout << "\nTESTS: "<< total <<"\n";
        std::cout << "SUCCESS: "<< success <<"\n";
        std::cout << "FAILURE: "<< (total - success) <<"\n";
    }
};
