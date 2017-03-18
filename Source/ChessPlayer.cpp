#include "../Headers/ChessPlayer.h"

ChessPlayer::ChessPlayer(int playerColor)
{
    //ctor
    this->playerColor = playerColor;
//    this->playerName = "Default Player";
}

void ChessPlayer::gameResult(int winner)
{
    // This function will be called by the main once the game is over
    // The integer argument winner will be either -1 or 1 depending upon
    // the player who wins the game.
    // You might use this function to call your functions to learning/enhance
    // your evaluation function.
}
