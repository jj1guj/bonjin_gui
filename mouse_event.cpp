#include "bonjin_gui.hpp"

void mouse_motion(int x,int y){
    X[0]=(float)(25*(x/25));
    X[1]=(float)(25*(y/25));
    if(X[0]<25||X[0]>475||X[1]<25||X[1]>475){
        X[0]=(float)x;
        X[1]=(float)y;
    }
    glutPostRedisplay();
}

void mouse_clicked(int button,int state,int x,int y){
    if(button!=GLUT_LEFT_BUTTON||state!=GLUT_DOWN)return;
    clicked=true;
    X[0]=(float)(25*(x/25));
    X[1]=(float)(25*(y/25));

    if(X[0]<25||X[0]>475||X[1]<25||X[1]>475){
        X[0]=(float)x;
        X[1]=(float)y;
    }
    glutPostRedisplay();
}