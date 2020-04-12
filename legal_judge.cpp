#include"bonjin_gui.hpp"

//合法手かどうか判定する
bool judge_legal(int i,int j){
    bool legal_flg=true;
    if(moves_count==1){
        if(i!=9||j!=9)legal_flg=false;
    }else if(moves_count==2){
        if((i==8 && j==8)||(i==8 && j==9)||(i==8 && j==10)||
            (i==9 && j==8)||(i==9 && j==10)||(i==10 && j==8)||
            (i==10 && j==9)||(i==10 && j==10)){
                legal_flg=true;
        }else{
            legal_flg=false;
        }
    }else if(moves_count==3){
        if(abs(i-9)<3 && abs(j-9)<3)legal_flg=false;
    }

    if(legal_flg==true && (board[i][j]==sente_stone||board[i][j]==gote_stone))legal_flg=false;

    return legal_flg;
}