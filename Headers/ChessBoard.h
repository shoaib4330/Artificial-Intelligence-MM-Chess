#ifndef CHESSBOARD_H
#define CHESSBOARD_H


class ChessBoard {
public:
    int board[8][8];

    ChessBoard(){

    }
    void InitBoard(){
        //Init all the board with zeros atm.....
        for (int i = 0; i < 8 ; ++i) {
            for (int j = 0; j < 8 ; ++j) {
                board[i][j]=0;
            }
        }

        //Initing for Black goats.....
        board[0][0]=board[0][7]=-4;
        board[0][1]=board[0][6]=-2;
        board[0][2]=board[0][5]=-3;
        board[0][3]= -5;
        board[0][4]= -6;
        for (int i = 0; i <8 ; ++i) {
            board[1][i] = -1;
        }

        //Initing for White goats.....
        board[7][0]=board[0][7]= 4;
        board[7][1]=board[0][6]= 2;
        board[7][2]=board[0][5]= 3;
        board[7][3]= 5;
        board[7][4]= 6;
        for (int i = 0; i <8 ; ++i) {
            board[6][i] = 1;
        }
    }

};

#endif // CHESSBOARD_H