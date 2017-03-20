// Created by shoaib Anwar on 3/14/17.
#ifndef PLAYERCHESSCUSTOM_H
#define PLAYERCHESSCUSTOM_H

#include "ChessPlayer.h"
#include <iostream>

using namespace std;

class PlayerChessCustom : public ChessPlayer {
private:
    //Has integer for player color already.

    double evaluateState(ChessState gChessState)
    {
        //Higher values returned by this function indicate that State being evaluated is
        //good for White/Max and
        //Lower values returned indicate that State is bad for White/Max. Function works in terms of Max..
        int queensDiff=gChessState.getQueensNum(+1)-gChessState.getQueensNum(-1);
        int pawnsDiff=gChessState.getPawnsNum(+1)-gChessState.getPawnsNum(-1);
        int bishopDiff=gChessState.getBishopsNum(+1)-gChessState.getBishopsNum(-1);
        int rookDiff=gChessState.getRooksNum(+1)-gChessState.getRooksNum(-1);
        int knightDiff=gChessState.getKnightsNum(+1)-gChessState.getRooksNum(-1);

        int cumulativeUtilityValue = 5*queensDiff+ 4*rookDiff + 3*bishopDiff + 2*knightDiff + 1*pawnsDiff;
        return cumulativeUtilityValue;
        //return 9.11;
    }

    int max (int a, int b){
        if (a>b)
            return a;
        else
            return b;
    }

    int min (int a, int b){
        if (a<b)
            return a;
        else
            return b;
    }

    ChessMove minimax(ChessState gChessState,int playerColor,int depthMax)
    {
        //cout<<endl<<"------------MiniMax Prints----------------"<<endl;
        int chessMovesTotal = gChessState.makeValidMovesList();
        ChessMove best_move = gChessState.Moves[0];

        int best_score;
        int score;
        if (this->playerColor==+1)
        {
            best_score=-999;
        }
        else if(this->playerColor==-1)
        {
            best_score=+999;
        }

        //For each move in list do following
        for (int moveIndex = 0; moveIndex < chessMovesTotal ; ++moveIndex) {
            ChessState nextState_By_Current_Move = gChessState.nextState(gChessState.Moves[moveIndex]);
            if (this->playerColor==+1)
            {
                score = min_value(nextState_By_Current_Move,-999,999,1,depthMax);

                if (score > best_score)
                {
                    best_move = gChessState.Moves[moveIndex];
                    best_score = score;
                }

            }
            else if (this->playerColor==-1)
            {
                score = max_value(nextState_By_Current_Move,-999,999,1,depthMax);
                if (score < best_score)
                {
                    best_move = gChessState.Moves[moveIndex];
                    best_score = score;
                }
            }
        }
        return best_move;
    }

    int max_value(ChessState gChessState, int alpha, int beta ,int depthYet,int depthMax){
        //cout<<endl<<"------------MaxVal Prints----------------"<<endl;
        if(depthYet==depthMax)
        {
            //Call evaluation function here....
            return evaluateState(gChessState);
        }
        int chessMovesTotal = gChessState.makeValidMovesList();
        ChessMove best_move = gChessState.Moves[0];
        int best_score = -999;
        int score;
        //Since we have not reached Max-Depth so lets continue
        for (int moveIndex = 0; moveIndex < chessMovesTotal ; ++moveIndex) {
            ChessState nextState_By_Current_Move = gChessState.nextState(gChessState.Moves[moveIndex]);
            score = min_value(nextState_By_Current_Move,alpha,beta,depthYet+1,depthMax);

            best_score = max(best_score, score);
            alpha = max(alpha, best_score);

            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best_score;
    }

    int min_value(ChessState gChessState, int alpha, int beta, int depthYet,int depthMax){
        //cout<<endl<<"------------MinVal Prints----------------"<<endl;
        if(depthYet==depthMax)
        {
            //Call evaluation function here....
            return evaluateState(gChessState);
        }
        int chessMovesTotal = gChessState.makeValidMovesList();
        ChessMove best_move = gChessState.Moves[0];
        int best_score = +999;
        int score;
        //Since we have not reached Max-Depth so lets continue
        for (int moveIndex = 0; moveIndex < chessMovesTotal ; ++moveIndex) {
            ChessState nextState_By_Current_Move = gChessState.nextState(gChessState.Moves[moveIndex]);
            score = max_value(nextState_By_Current_Move,alpha,beta,depthYet+1,depthMax);

            best_score = min(best_score, score);
            beta = min(beta, best_score);

            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best_score;
    }

public:
    void setPlayerColor(int gPlayerColor) {
        this->playerColor = gPlayerColor;
        if (this->playerColor == 1)
            cout << endl << "White Player";
        else
            cout << endl << "Black Player";
    }


    ChessMove decideMoveUsingMINIMAX(ChessState &gameState, ChessMove &returnMove, unsigned int depth = 1) {
        //Implement this method further.......
        //Current Code is copied from groupName cpp's same fucntion...further implementation required...
        //gameState.setPlayerToMove(this->playerColor);

        int totalMoves = gameState.makeValidMovesList();

        if(totalMoves <=0 )
        {
            return returnMove;
        }

        // Your code goes here
        ChessMove moveSuggested = minimax(gameState,this->playerColor,depth);
        cout<<endl<<"MOVE SUGGESTED BY MINIMAX: From "<<moveSuggested.From[0]<<moveSuggested.From[1]<<" to "
            <<moveSuggested.To[0]<<moveSuggested.To[1]<<endl;

        //returnMove.From[0] = moveSuggested.From[0];
        //returnMove.From[1] = moveSuggested.From[1];
        //returnMove.To[0] = moveSuggested.To[0];
        //returnMove.To[1] = moveSuggested.To[1];

        return moveSuggested;
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
