/*
    headers.h
    
    Initial version: 2020.7.12
    Lastest update: 2020.8.8
    Author: mfp
*/
#ifndef _HEADERS_H_
#define _HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#include <bios.h>
#include <time.h>

#include "svga.h" //svga头文件
#include "hzk.h" //汉字库头文件
#include "mouse.h" //鼠标函数库头文件
#include "drawbas.h" //基础画图头文件
#include "mysys.h" //自己写的系统函数
#include "drawrobot.h" //画机器人头文件
#include "interface.h" //登陆界面绘图头文件
#include "login.h" //登陆界面头文件
#include "register.h" //注册界面头文件
#include "mainwin.h" //程序主界面头文件
#include "drawmap.h" //绘制程序主界面头文件


//定义颜色宏
#define BLACK 0
#define MARINE_BLUE 559
#define DARK_GRAY 44373
#define WALL_GREEN 27748
#define STRONG_RED 57344
#define DARK_ORANGE 64608
#define MISTY_ROSE 65340
#define WHITE 65535
#define BROWN 41605
#define LIGHT_BROWN 64518
#define LIGHT_BLUE 59391
#define BULE 24985
#define PEACH_PUFF 65239
#define WHEAT 63222
#define LIGHT_CORAL 62480
#define GREEN 26603
#define PINK 58572

//必要的参数
#define ROBOT_SIZE 20 //定义基础机器人大小

#endif