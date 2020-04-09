#include"bonjin_gui.hpp"

//円の描画
void glCircle(float r,float rx,float ry){
    int i,n=100;
    float pi=3.14159265358979;
    float x,y,x0,y0;
    double rate;

    for(i=0;i<n;i++){
        rate=(double)i/n;
        x=r*cos(2.0*pi*rate)+rx;
        y=r*sin(2.0*pi*rate)+ry;
        glVertex2f(x,y);
    }
}

//盤の描画
void draw_board(){
    //盤面の線を描画
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    for(int i=1;i<=19;i++){
        glVertex2i(25*i,475);//縦線上端
        glVertex2i(25*i,25);//縦線下端
        glVertex2i(25,25*i);//横線左端
        glVertex2i(475,25*i);//横線右端
    }
    glEnd();

    //盤に星を打つ
    glColor3f(0,0,0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2i(100,400);
        glVertex2i(250,400);
        glVertex2i(400,400);
        glVertex2i(100,250);
        glVertex2i(250,250);
        glVertex2i(400,250);
        glVertex2i(100,100);
        glVertex2i(250,100);
        glVertex2i(400,100);
    glEnd();
}

//局面の描画
void draw_phase(){
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(board[i][j]==1){
                glColor3f(0,0,0);
                glBegin(GL_POLYGON);
                    glCircle(stone_size,(float)(25*(i+1)),(float)(25*(j+1)));
                glEnd();
            }else if(board[i][j]==-1){
                glColor3f(1,1,1);
                glBegin(GL_POLYGON);
                    glCircle(stone_size,(float)(25*(i+1)),(float)(25*(j+1)));
                glEnd();
            }
        }
    }
}

//文字列の挿入
void draw_string(float x,float y,string str){
    glRasterPos2f(x,y);
    for(int i=0;i<str.size();i++){
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,str[i]);
    }
}