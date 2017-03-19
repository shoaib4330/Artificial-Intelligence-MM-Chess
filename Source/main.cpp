#include <iostream>
#include "../Headers/ChessState.h"
#include "../Headers/ChessMove.h"
#include "../Headers/ChessBoard.h"
#include "../Headers/ChessProblem.h"

using namespace std;

int main()
{
    cout << "..........Chess Starts........" << endl;
    ChessProblem chessProblem;
    chessProblem.Init();

    chessProblem.showCurrentState();
    //chessProblem.generateNextPossibleMoves();
    //chessProblem.showMovesForCurrentState();
    chessProblem.StartGamePlay();
    //chessProblem.generateNextPossibleMoves();
    //chessProblem.showMovesForCurrentState();

    //    chessState game;
//    game.showState();
//    chessMove PlayerMove;
//
//    playerGROUP_NAME player(1);
//    int totalMoves = game.makeValidMovesList();
//    player.decideMoveUsingMINIMAX(game, PlayerMove, 3);
//    game.makeMove(PlayerMove);
//    game.showState();

    return 0;
}
