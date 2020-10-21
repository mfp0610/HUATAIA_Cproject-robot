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

typedef struct{
    int electr; //�����˵���
} ROBOT;

typedef struct{
    int time; //��������ʱ��
    int temp; //�����¶�
    int wet; //����ʪ��
    int pm25; //�����pm2.5ָ��
} HOUSE;

void mainWindow(); //����������
void drawbasic(); //���������滭ͼ
void paintmp(int (*mp)[N],int px,int py,char pdir); //������ͼ
void move(int *px,int *py,char dir,int (*mp)[N]); //�ƶ�������
void maininit(HOUSE *house, ROBOT *robot);
void func_electr(HOUSE *house, ROBOT *robot); //�����溯��
void func_comfort(HOUSE *house, ROBOT *robot); //���ʶȽ��溯��
void func_clean(HOUSE *house, ROBOT *robot); //��ڽ��溯��
void func_move(HOUSE *house, ROBOT *robot); //���ƽ��溯��
void timepass(HOUSE *house, ROBOT *robot); //ʱ�����ź���

#endif