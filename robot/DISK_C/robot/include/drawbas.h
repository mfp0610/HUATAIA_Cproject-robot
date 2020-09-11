/*
    drawbas.h
    
    Initial version: 2020.7.13
    Lastest update: 2020.7.21
    Author: Mengfp
*/
#ifndef _DRAWBAS_H_
#define _DRAWBAS_H_

#include "headers.h"

void setbkcol(int color); //���ñ�����ɫ
void line(int x1,int y1,int x2,int y2,int color); //����ֱ��
void thick_line(int x1,int y1,int x2,int y2,int thick,int color); //���ƴ�ֱ��
void bar(int x1,int y1,int x2,int y2,int color); //����������
void rect(int x1,int y1,int x2,int y2,int color); //���ƿ��ľ���
void fill_rect(int x1,int y1,int x2,int y2,int color,int edgecolor); //����ʵ�ľ��Σ����߿�
void fill_circle(int xc,int yc,int r,int color); //����ʵ��Բ

#endif