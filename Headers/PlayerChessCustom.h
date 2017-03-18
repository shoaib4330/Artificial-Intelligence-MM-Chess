// Created by shoaib Anwar on 3/14/17.
#ifndef PLAYERCHESSCUSTOM_H
#define PLAYERCHESSCUSTOM_H

#include "ChessPlayer.h"
#include <iostream>

using namespace std;

class PlayerChessCustom : public ChessPlayer {
private:
    //Has integer for player color already.
public:
    void setPlayerColor(int gPlayerColor) {
        this->playerColor = gPlayerColor;
        if (this->playerColor == 1)
            cout << endl << "White Player";
        else
            cout << endl << "Black Player";
    }

    int decideMoveUsingMINIMAX(ChessState &gameState, ChessMove &returnMove, unsigned int depth = 1) {
        //Implement this method further.......
        //Current Code is copied from groupName cpp's same fucntion...further implementation required...
        gameState.playerToMove = this->playerColor;
        int totalMoves = gameState.makeValidMovesList();

        returnMove.From[0]=returnMove.From[1]=0;
        returnMove.To[0] = returnMove.To[0] = 0;
        if(totalMoves <=0 )
        {
            return -1;
        }


        int selectedMove = totalMoves -1;

        // Your code goes here

        returnMove.From[0] = gameState.Moves[selectedMove].From[0];
        returnMove.From[1] = gameState.Moves[selectedMove].From[1];
        returnMove.To[0] = gameState.Moves[selectedMove].To[0];
        returnMove.To[1] = gameState.Moves[selectedMove].To[1];

        return selectedMove;
    }

    void gameResult(int winner)
    {
        // This function will be called by the main once the game is over
        // The integer argument winner will be either -1 or 1 depending upon
        // the player who wins the game.
        // You might use this function to call your functions to learning/enhance
        // your evaluation function.
    }
};

#endif //CHESS_PLAYERWHITE_CHESS_H
