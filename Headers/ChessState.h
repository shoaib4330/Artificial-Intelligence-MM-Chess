#ifndef CHESSSTATE_H
#define CHESSSTATE_H

#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>
#include "ChessMove.h"

class ChessState {
private:
    void showPiece(int pieceCode);
    void addValidCorresspondingMoveForPiece(int pieceRow,int pieceColumn, int originalBoard[][8]);
    int getPlayerColorAtIndex(int aBoard[][8],int,int);
    bool isTraversalPossible (int currentPieceInteger,int toRow,int toCol,int fromRow,int fromCol);
    bool checkForPawn(int currentPieceInteger,int toRow,int toCol,int fromRow,int fromCol);
    bool checkForRook(int currentPieceInteger,int toRow,int toCol,int fromRow,int fromCol);
    bool checkForBishop(int currentPieceInteger, int toRow, int toCol, int fromRow, int fromCol);
    bool checkForKnight(int currentPieceInteger, int toRow, int toCol, int fromRow, int fromCol);
    bool checkForKing(int currentPieceInteger, int toRow, int toCol, int fromRow, int fromCol);
    bool checkForQueen(int currentPieceInteger, int toRow, int toCol, int fromRow, int fromCol);

    int playerToMove;

public:
    //std::array<ChessMove,200> Moves;
    ChessMove Moves[200];
    int board[8][8];
    int movesCount;

    ChessState();
    int getPlayerToMove();
    void setPlayerToMove(int);
    int makeValidMovesList();
    void showState();
    void showMoves();
    bool makeMove(ChessMove pieceMove);
    ChessState nextState(ChessMove gChessMove);
    bool isPlayerInCheck();
    bool isPlayerCheckedMate();

    int getQueensNum(int);
    int getRooksNum(int);
    int getBishopsNum(int);
    int getPawnsNum(int);
    int getKnightsNum(int);

};
#endif // CHESSSTATE_H
