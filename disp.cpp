#include "bonjin_gui.hpp"

void disp(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //盤の描画
    draw_board();

    //リセットボタンの描画
    glColor3f(1,1,1);
    glRectf(500,25,575,75);
    glColor3f(0,0,0);
    draw_string(505,50,"Reset");

    //手番の表示
    glColor3f(0,0,0);
    draw_string(505,120,"sente");
    draw_string(505,135,"gote");
    glColor3f(0.8,0.8,0.8);
    glPointSize(5);
    glBegin(GL_POINTS);
        if(moves_count%2==1){
            glVertex2f(500,117);
        }else{
            glVertex2f(500,132);
        }
    glEnd();

    //戻るボタンの描画
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glCircle(18,516,168);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
        glVertex2f(502,168);
        glVertex2f(523,155);
        glVertex2f(523,181);
    glEnd();

    //進むボタンの表示
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glCircle(18,557,168);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
        glVertex2f(552,155);
        glVertex2f(552,181);
        glVertex2f(573,168);
    glEnd();

    //最後にどこに着手されたか表示
    if(moves_count>1){
        float last_x1=25*(float)(kif[moves_count-2][0]+1)-13;
        float last_y1=25*(float)(kif[moves_count-2][1]+1)-13;
        float last_x2=25*(float)(kif[moves_count-2][0]+1)+13;
        float last_y2=25*(float)(kif[moves_count-2][1]+1)+13;
        glColor3f(1,0,0);
        glRectf(last_x1,last_y1,last_x2,last_y2);
    }

    //局面の描画
    draw_phase();

    //マウスポインタを移動させた時のイベント
    if(X[0]>=25&&X[0]<=475&&X[1]>=25&&X[1]<=475){
        //マウスポインタが盤上にあるときどこに打つか表示
        glColor3f(1,0,0);
        glBegin(GL_LINE_LOOP);
            glCircle(stone_size,X[0],X[1]);
        glEnd();
    }else if(X[0]>=500&&X[0]<=575&&X[1]>=25&&X[1]<=75){
        //リセットボタンの色を反転させて再描画
        glColor3f(0,0,0);
        glRectf(500,25,575,75);
        glColor3f(1,1,1);
        draw_string(505,50,"Reset");
    }else if(powf(X[0]-515,2)+powf(X[1]-168,2)<=18*18){
        //戻るボタンの色を反転させて再描画
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
            glCircle(18,516,168);
        glEnd();
        glColor3f(1,1,1);
        glBegin(GL_TRIANGLES);
            glVertex2f(502,168);
            glVertex2f(523,155);
            glVertex2f(523,181);
        glEnd();
    }else if(powf(X[0]-560,2)+powf(X[1]-168,2)<=18*18){
        //進むボタンの色を反転させて再描画
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
            glCircle(18,557,168);
        glEnd();
        glColor3f(1,1,1);
        glBegin(GL_TRIANGLES);
            glVertex2f(552,155);
            glVertex2f(552,181);
            glVertex2f(573,168);
        glEnd();
    }

    if(clicked){
        move_X[0]=(int)(X[0]/25)-1;
        move_X[1]=(int)(X[1]/25)-1;
        if(move_X[0]>=0&&move_X[0]<19&&move_X[1]>=0&&move_X[1]<19){
            //クリックされたときに着手
            if(board[move_X[0]][move_X[1]]==0){
                move();
            }
        }else if(X[0]>=500&&X[0]<=575&&X[1]>=25&&X[1]<=75){
            //リセットボタンがクリックされたときに盤面・棋譜を削除
            Reset();
        }else if(powf(X[0]-515,2)+powf(X[1]-168,2)<=18*18){
            //戻るボタンがクリックされたときに盤面を1手戻す
            if(moves_count==2){
                for(int i=0;i<19;i++)for(int j=0;j<19;j++){
                    board[i][j]=0;
                }
                moves_count=1;
            }else if(moves_count>2){
                board=board_all[moves_count-3];
                moves_count--;
            }
        }else if(powf(X[0]-560,2)+powf(X[1]-168,2)<=18*18){
            //進むボタンがクリックされたときに盤面を1手進める
            if(moves_count-1<min(moves_max,361)){
                board=board_all[moves_count-1];
                moves_count++;
            }
        }
        clicked=false;
    }

    glutSwapBuffers();
}