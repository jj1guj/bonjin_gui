#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;
#define stone_size 10

extern float X[];//マウスポインタの座標
extern int move_X[];//実際に打つときの配列上の座標

extern vector<int> kif_input;
extern vector<vector<int>>board,kif;
extern vector<vector<vector<int>>>board_all;

extern bool clicked;
extern int moves_count,moves_max;

#pragma once
//disp.cpp
void disp(void);

//draw.cpp
void glCircle(float r,float rx,float ry);
void draw_board();
void draw_phase();
void draw_string(float x,float y,string str);

//event.cpp
void move();
void Reset();

//mouse_event.cpp
void mouse_motion(int x,int y);
void mouse_clicked(int button,int state,int x,int y);