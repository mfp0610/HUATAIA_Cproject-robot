/*
    move.h
    
    Initial version: 2020.10.24
    Lastest update: 2020.10.24
    Author: mfp
*/
#ifndef _MOVE_H_
#define _MOVE_H_

#include "headers.h"
#define M 1010

typedef struct {
    int x,y;
} NODE;

typedef struct {
    int x,y;
    int dis,val; //记录当前节点的bfs距离和估价函数
    int last; //记录路径
    int id;
} NODE1;

void move(HOUSE *house, ROBOT *robot,char dir); //移动机器人
void moveupdate(HOUSE *house,ROBOT *robot,char value); //移动更新函数
int getposition(int x,int y); //获取鼠标点击位置函数
int pd_pass(int mp); //判段能否通过

#endif