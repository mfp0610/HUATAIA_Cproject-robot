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
    int px, py; //������λ��
    char rt; //�����˳���
} ROBOT;

typedef struct{
    long int time; //��������ʱ��
    int set,setd,setc; //�˹��趨��ǩ
    int tempset; //�¶��趨�¶�
    int tempout; //�����¶�
    int temp; //�����¶�
    int wet; //����ʪ��
    int pm25; //�����pm2.5ָ��
    int mp1[N][N]; //�����ͼ
    int mpinit[N][N]; //�����ʼ��ͼ 
    int dor[5];
    int rubnum;
} HOUSE;

typedef struct {
    int x,y;
} NODE;

void mainWindow(USER *usr); //����������
void drawbasic(); //���������滭ͼ
void maininit(HOUSE *house, ROBOT *robot);
void timepass(HOUSE *house, ROBOT *robot, USER *usr, int st); //ʱ�����ź���
void fin(FILE *fp, char *rd, int x1,int y1,int x2,int y2);
void fout(FILE *fp, char *rd, int x1,int y1,int x2,int y2);

#endif