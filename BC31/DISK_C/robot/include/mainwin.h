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
} HOUSE;

void mainWindow(); //����������
void drawbasic(); //���������滭ͼ
void paintmp(HOUSE *house, ROBOT *robot); //������ͼ
void maininit(HOUSE *house, ROBOT *robot);
void func_electr(HOUSE *house, ROBOT *robot); //�����溯��
void func_comfort(HOUSE *house, ROBOT *robot); //���ʶȽ��溯��
void func_clean(HOUSE *house, ROBOT *robot); //��ڽ��溯��
void func_move(HOUSE *house, ROBOT *robot); //���ƽ��溯��
void timepass(HOUSE *house, ROBOT *robot,int st); //ʱ�����ź���

#endif