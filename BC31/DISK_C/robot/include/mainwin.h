/*
    mainwin.h
    
    Initial version: 2020.7.13
    Lastest update: 2020.9.12
    Author: mfp
*/
#ifndef _MAINWIN_H_
#define _MAINWIN_H_
#define N 18

#include "headers.h"

void mainWindow(); //����������
void drawbasic(); //���������滭ͼ
void paintmp(int (*mp)[N],int px,int py,char pdir); //������ͼ
void move(int *px,int *py,char dir,int (*mp)[N]); //�ƶ�������

#endif