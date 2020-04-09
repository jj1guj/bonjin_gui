#include "bonjin_gui.hpp"

//着手して局面と棋譜を記録する
void move(){
    if(moves_count%2==1){
        //先手のとき
        glColor3f(0,0,0);
        glBegin(GL_LINE_LOOP);
            glCircle(stone_size,X[0],X[1]);
        glEnd();
        board[(int)(X[0]/25)-1][(int)(X[1]/25)-1]=1;
    }else{
        //後手のとき
        glColor3f(1,1,1);
        glBegin(GL_LINE_LOOP);
            glCircle(stone_size,X[0],X[1]);
        glEnd();
        board[(int)(X[0]/25)-1][(int)(X[1]/25)-1]=-1;
    }

    kif_input={(int)(X[0]/25)-1,(int)(X[1]/25)-1};

    //進むボタンを押すときにどこまで進めていいか更新
    if(board_all[moves_count-1]!=board||
        kif[moves_count-1]!=kif_input){
        moves_max=moves_count;
    }else{
        moves_max=max(moves_count,moves_max);
    }

    //打った後の局面を追加
    board_all[moves_count-1]=board;

    //棋譜に追加
    kif[moves_count-1]=kif_input;
    moves_count++;
}

//全て初期化する
void Reset(){
    //盤面の初期化
    for(int i=0;i<19;i++)for(int j=0;j<19;j++){
        board[i][j]=0;
    }
    //記録している盤面の初期化
    //board_all.clear();
    //棋譜の初期化
    //kif.clear();

    moves_count=1;
    moves_max=1;
}