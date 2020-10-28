/*
    drawmap.c

	Initial version: 2020.7.21
    Lastest update: 2020.10.8
    Author: hhw
*/
#include "headers.h"

#define SIZE 40
#define WIDE 2
#define WALL_WIDE 4

void draw_floor_wood(int x,int y)
{
    fill_rect(x,y,x+SIZE,y+SIZE,BROWN,BLACK);
}

void draw_floor_ceramic(int x,int y)
{
    bar(x+WIDE,y+WIDE,x+SIZE-WIDE,y+SIZE-WIDE,LIGHT_BLUE);
    bar(x,y,x+SIZE,y+WIDE,BULE);
    bar(x,y+WIDE,x+WIDE,y+SIZE,BULE);
    bar(x+SIZE-WIDE,y+WIDE,x+SIZE,y+SIZE,BULE);
    bar(x+WIDE,y+SIZE-WIDE,x+SIZE-WIDE,y+SIZE,BULE);
}

void draw_table(int x,int y)
{
    bar(x,y,x+SIZE,y+SIZE,WHEAT);
}

void draw_chair(int x,int y)
{
    fill_circle(x+20,y+20,19,WHEAT,BLACK);
}

void draw_door_left(int x,int y)
{
    fill_rect(x,y,x+SIZE,y+SIZE,PINK,BLACK);
    fill_circle(x+30,y+20,4,BLACK,BLACK);
}

void draw_door_right(int x,int y)
{
    fill_rect(x,y,x+SIZE,y+SIZE,PINK,BLACK);
    fill_circle(x+8,y+20,4,BLACK,BLACK);
}

void draw_door_vertical(int x,int y,int n)
{
    fill_rect(x,y,x+2*WALL_WIDE,y+n*SIZE,PINK,BLACK);
}

void draw_else(int x,int y)
{
    bar(x,y,x+SIZE,y+SIZE,BLACK);
}

void draw_bin(int x,int y)
{
    bar(x,y,x+SIZE,y+SIZE,BLACK);
    bar(x+13,y,x+27,y+5,DARK_GRAY);
    bar(x,y+5,x+SIZE,y+15,DARK_GRAY);
    bar(x+5,y+15,x+35,y+SIZE,LIGHT_GRAY);
    bar(x+7,y+20,x+13,y+SIZE-5,DARK_GRAY);
    bar(x+17,y+20,x+23,y+SIZE-5,DARK_GRAY);
    bar(x+27,y+20,x+33,y+SIZE-5,DARK_GRAY);
    fill_circle(x+10,y+20,3,DARK_GRAY,DARK_GRAY);
    fill_circle(x+20,y+20,3,DARK_GRAY,DARK_GRAY);
    fill_circle(x+30,y+20,3,DARK_GRAY,DARK_GRAY);
}

void draw_charge(int x,int y)
{
    bar(x,y,x+SIZE,y+SIZE,LIGHT_GRAY);
    bar(x+18,y+5,x+22,y+15,BLACK);
    bar(x+5,y+27,x+13,y+30,BLACK);
    bar(x+27,y+27,x+35,y+30,BLACK);
}

void open_left_door(int x,int y)
{
    fill_rect(x,y,x+SIZE,y+SIZE,BROWN,BLACK);
    fill_rect(x,y,x+2*WALL_WIDE,y+SIZE,PINK,BLACK);
}

void open_right_door(int x,int y)
{
    fill_rect(x,y,x+SIZE,y+SIZE,BROWN,BLACK);
    fill_rect(x+SIZE-2*WALL_WIDE,y,x+SIZE,y+SIZE,PINK,BLACK);
}

void open_up_door(int x,int y)
{
    fill_rect(x,y,x+SIZE,y+SIZE,BROWN,BLACK);
    fill_rect(x,y,x+SIZE,y+2*WALL_WIDE,PINK,BLACK);
}

void open_down_door(int x,int y)
{
    fill_rect(x,y,x+SIZE,y+SIZE,BROWN,BLACK);
    fill_rect(x,y+SIZE-2*WALL_WIDE,x+SIZE,y+SIZE,PINK,BLACK);
}