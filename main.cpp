#include "bonjin_gui.hpp"

float X[2];
int move_X[2];

vector<int>kif_input(2);
vector<vector<int>>board(19,vector<int>(19)),kif(400,vector<int>(2));
vector<vector<vector<int>>>board_all(400,vector<vector<int>>(19,vector<int>(19)));

bool clicked=false;
int moves_count=1;
int moves_max=1;
int end_flg;

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("bonjin_gui");
    glClearColor(0.72,0.53,0.23,1);
    gluOrtho2D(0,600,600,0);
    glutDisplayFunc(disp);
    glutPassiveMotionFunc(mouse_motion);
    glutMouseFunc(mouse_clicked);
    glutMainLoop();
}