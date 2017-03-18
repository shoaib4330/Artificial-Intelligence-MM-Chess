#ifndef CHESSSTATE_H
#define CHESSSTATE_H

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
public:
    ChessMove Moves[200];
    int playerToMove;
    int board[8][8];
    int movesCount;

    int makeValidMovesList();
    ChessState();
    void showState();
    void showMoves();
    bool makeMove(ChessMove pieceMove);
    bool isPlayerInCheck();

};
#endif // CHESSSTATE_H
