// Created by shoaib Anwar on 3/14/17.
#ifndef CHESSPROBLEM_H
#define CHESSPROBLEM_H

#include "ChessBoard.h"
#include "ChessState.h"
#include "PlayerChessCustom.h"

class ChessProblem {
private:
    ChessBoard chessBoard;
    ChessState current_ChessBoard_State;
    PlayerChessCustom playerWhite;
    PlayerChessCustom playerBlack;
    int evaluationDepth;
public:

    void Init(){
        //Chess Board Initialized
        evaluationDepth = 4;
        chessBoard.InitBoard();
        playerWhite.setPlayerColor(+1);
        playerBlack.setPlayerColor(-1);
        current_ChessBoard_State.setPlayerToMove(+1); //sets turn for White by default...

    }

    void StartGamePlay(){
        cout<<endl<<"To take a step in Chess Press 4 and hit Enter"<<endl;
        int contnum;
        cin>>contnum;
        if (contnum!=4)
        {
            return;
        }
        else
        {

        }

        ChessMove wese;
        ChessMove chessMoveObtained;
        if (current_ChessBoard_State.makeValidMovesList()==0){
            cout<<endl<<"Chess has no more possible moves from its current state.."<<endl;
            return;
        }
        if (current_ChessBoard_State.getPlayerToMove()==+1)
        {
            chessMoveObtained = playerWhite.decideMoveUsingMINIMAX(this->current_ChessBoard_State,wese,this->evaluationDepth);
        }
        else{
            chessMoveObtained = playerBlack.decideMoveUsingMINIMAX(this->current_ChessBoard_State,wese,this->evaluationDepth);
        }
        this->current_ChessBoard_State.makeMove(chessMoveObtained);
        cout<<endl<<"Move Made: New Chess State follows: "<<endl;
        this->current_ChessBoard_State.showState();

        StartGamePlay();
    }

    void showCurrentState(){
        this->current_ChessBoard_State.showState();
    }

    void showMovesForCurrentState(){
        this->current_ChessBoard_State.showMoves();
    }

    void generateNextPossibleMoves(){
        this->current_ChessBoard_State.makeValidMovesList();
    }

    void setStateForChess(ChessState gState){
        //Method to Initialize some Intermediate State for Chess....
        this->current_ChessBoard_State = gState;
    }

};

#endif //CHESS_CHESSPROBLEM_H
