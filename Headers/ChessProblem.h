// Created by shoaib Anwar on 3/14/17.
#ifndef CHESSPROBLEM_H
#define CHESSPROBLEM_H

#include "ChessBoard.h"
#include "ChessState.h"
#include "PlayerChessCustom.h"

class ChessProblem {
private:
    ChessBoard chessBoard;
    ChessState* current_ChessBoard_State;
    PlayerChessCustom playerWhite;
    PlayerChessCustom playerBlack;
public:

    void Init(){
        //Chess Board Initialized
        chessBoard.InitBoard();
        this->current_ChessBoard_State = new ChessState();
        current_ChessBoard_State->playerToMove = -1; //sets turn for White by default...

    }

    void showCurrentState(){
        this->current_ChessBoard_State->showState();
    }

    void showMovesForCurrentState(){
        this->current_ChessBoard_State->showMoves();
    }

    void generateNextPossibleMoves(){
        this->current_ChessBoard_State->makeValidMovesList();
    }

    void setStateForChess(ChessState gState){
        //Method to Initialize some Intermediate State for Chess....
        *this->current_ChessBoard_State = gState;
    }

};

#endif //CHESS_CHESSPROBLEM_H
