/*
    drawrobot.c

	Initial version: 2020.7.21
    Lastest update: 2020.7.22
    Author: Mengfp
*/
#include "headers.h"

void drawrobot_front(int x,int y,int size)
{
    int sb=ROBOT_SIZE*size;
    fill_rect(x-sb,y-sb,x+sb,y+sb,MARINE_BLUE,BLACK); //������������
    
    fill_rect(x+sb,y-sb,x+sb/2*3,y+sb/2,MARINE_BLUE,BLACK);
    fill_rect(x-sb,y-sb,x-sb/2*3,y+sb/2,MARINE_BLUE,BLACK);
    fill_rect(x+sb,y+sb/4,x+sb/2*3,y+sb/2,WHITE,BLACK);
    fill_rect(x-sb,y+sb/4,x-sb/2*3,y+sb/2,WHITE,BLACK); //�������˸첲
    
    fill_rect(x+sb,y+sb,x+sb/4,y+sb/2*3,MARINE_BLUE,BLACK);
    fill_rect(x-sb,y+sb,x-sb/4,y+sb/2*3,MARINE_BLUE,BLACK);
    fill_rect(x+sb,y+sb/4*5,x+sb/4,y+sb/2*3,WHITE,BLACK);
    fill_rect(x-sb,y+sb/4*5,x-sb/4,y+sb/2*3,WHITE,BLACK); //����������

    fill_circle(x+sb,y-sb/2*3,sb/5,WHITE);
    fill_circle(x-sb,y-sb/2*3,sb/5,WHITE);
    fill_rect(x-sb,y-sb,x+sb,y-2*sb,MARINE_BLUE,BLACK);
    fill_circle(x+sb/2,y-sb/2*3,sb/5,WHITE);
    fill_circle(x-sb/2,y-sb/2*3,sb/5,WHITE);
    fill_circle(x+sb/2,y-sb/2*3,sb/20,BLACK);
    fill_circle(x-sb/2,y-sb/2*3,sb/20,BLACK);
    
    thick_line(x+sb/2,y-sb/2*5,x+sb/2,y-2*sb,sb/20,BLACK);
    thick_line(x-sb/2,y-sb/2*5,x-sb/2,y-2*sb,sb/20,BLACK);
    fill_circle(x+sb/2,y-sb/2*5-sb/20*3,sb/20*3,WHITE);
    fill_circle(x-sb/2,y-sb/2*5-sb/20*3,sb/20*3,WHITE); //������������
    
    outtextxy(x-sb,y-sb/2,"HUST",sb/20,sb/20,sb/10*4,WHITE); //��ǰд��

    return;
}

void drawrobot_front_hello(int x,int y,int size)
{
    int sb=ROBOT_SIZE*size;
    fill_rect(x-sb,y-sb,x+sb,y+sb,MARINE_BLUE,BLACK); //������������
    
    fill_rect(x+sb,y+sb,x+sb/4,y+sb/2*3,MARINE_BLUE,BLACK);
    fill_rect(x-sb,y+sb,x-sb/4,y+sb/2*3,MARINE_BLUE,BLACK);
    fill_rect(x+sb,y+sb/4*5,x+sb/4,y+sb/2*3,WHITE,BLACK);
    fill_rect(x-sb,y+sb/4*5,x-sb/4,y+sb/2*3,WHITE,BLACK); //����������

    fill_circle(x+sb,y-sb/2*3,sb/5,WHITE);
    fill_circle(x-sb,y-sb/2*3,sb/5,WHITE);
    fill_rect(x-sb,y-sb,x+sb,y-2*sb,MARINE_BLUE,BLACK);
    fill_circle(x+sb/2,y-sb/2*3,sb/5,WHITE);
    fill_circle(x-sb/2,y-sb/2*3,sb/5,WHITE);
    fill_circle(x+sb/2,y-sb/2*3,sb/20,BLACK);
    fill_circle(x-sb/2,y-sb/2*3,sb/20,BLACK);
    
    thick_line(x+sb/2,y-sb/2*5,x+sb/2,y-2*sb,sb/20,BLACK);
    thick_line(x-sb/2,y-sb/2*5,x-sb/2,y-2*sb,sb/20,BLACK);
    fill_circle(x+sb/2,y-sb/2*5-sb/20*3,sb/20*3,WHITE);
    fill_circle(x-sb/2,y-sb/2*5-sb/20*3,sb/20*3,WHITE); //������������
    
    outtextxy(x-sb,y-sb/2,"HUST",sb/20,sb/20,sb/10*4,WHITE); //��ǰд��
    
    fill_rect(x+sb,y-sb,x+sb/2*3,y+sb/2,MARINE_BLUE,BLACK);
    fill_rect(x-sb,y,x-sb/2*3,y-sb*3/2,MARINE_BLUE,BLACK);
    fill_rect(x+sb,y+sb/4,x+sb/2*3,y+sb/2,WHITE,BLACK);
    fill_rect(x-sb,y-sb*5/4,x-sb/2*3,y-sb*3/2,WHITE,BLACK); //�������˸첲
    
    fill_rect(x-sb*7/4,y-sb*3/2,x-sb*3/4,y-sb*9/4,DARK_ORANGE,BLACK);
    puthz(x-sb*7/4,y-sb*17/8,"���",48,48,'K',WHITE); //������

    return;
}

void drawrobot_left(int x,int y,int size)
{
    int sb=ROBOT_SIZE*size;
    fill_rect(x-sb,y-sb,x+sb,y+sb,MARINE_BLUE,BLACK); //������������
    
    fill_rect(x-sb/2,y-sb,x+sb/2,y+sb/2,MARINE_BLUE,BLACK);
    fill_rect(x-sb/2,y+sb/4,x+sb/2,y+sb/2,WHITE,BLACK); //�������˸첲
    
    fill_rect(x-sb/4*3,y+sb,x+sb/4*3,y+sb/2*3,MARINE_BLUE,BLACK);
    fill_rect(x-sb/4*3,y+sb/4*5,x+sb/4*3,y+sb/2*3,WHITE,BLACK); //����������

    fill_circle(x-sb/4*3,y-sb/2*3,sb/5,WHITE);
    fill_circle(x-sb/4*3-sb/5,y-sb/2*3,sb/20,BLACK); 
    fill_rect(x-sb/4*3,y-sb,x+sb/4*3,y-2*sb,MARINE_BLUE,BLACK); 
    fill_circle(x,y-sb/2*3,sb/5,WHITE); //��������ͷ
    
    thick_line(x,y-sb/2*5,x,y-2*sb,sb/20,BLACK);
    fill_circle(x,y-sb/2*5-sb/20*3,sb/20*3,WHITE); //������������

    return;
}

void drawrobot_right(int x,int y,int size)
{
    int sb=ROBOT_SIZE*size;
    fill_rect(x-sb,y-sb,x+sb,y+sb,MARINE_BLUE,BLACK); //������������
    
    fill_rect(x-sb/2,y-sb,x+sb/2,y+sb/2,MARINE_BLUE,BLACK);
    fill_rect(x-sb/2,y+sb/4,x+sb/2,y+sb/2,WHITE,BLACK); //�������˸첲
    
    fill_rect(x-sb/4*3,y+sb,x+sb/4*3,y+sb/2*3,MARINE_BLUE,BLACK);
    fill_rect(x-sb/4*3,y+sb/4*5,x+sb/4*3,y+sb/2*3,WHITE,BLACK); //����������

    fill_circle(x+sb/4*3,y-sb/2*3,sb/5,WHITE);
    fill_circle(x+sb/4*3+sb/5,y-sb/2*3,sb/20,BLACK); 
    fill_rect(x-sb/4*3,y-sb,x+sb/4*3,y-2*sb,MARINE_BLUE,BLACK); 
    fill_circle(x,y-sb/2*3,sb/5,WHITE); //��������ͷ
    
    thick_line(x,y-sb/2*5,x,y-2*sb,sb/20,BLACK);
    fill_circle(x,y-sb/2*5-sb/20*3,sb/20*3,WHITE); //������������

    return;
}

void drawrobot_back(int x,int y,int size)
{
    int sb=ROBOT_SIZE*size;
    fill_rect(x-sb,y-sb,x+sb,y+sb,MARINE_BLUE,BLACK); //������������
    
    fill_rect(x+sb,y-sb,x+sb/2*3,y+sb/2,MARINE_BLUE,BLACK);
    fill_rect(x-sb,y-sb,x-sb/2*3,y+sb/2,MARINE_BLUE,BLACK);
    fill_rect(x+sb,y+sb/4,x+sb/2*3,y+sb/2,WHITE,BLACK);
    fill_rect(x-sb,y+sb/4,x-sb/2*3,y+sb/2,WHITE,BLACK); //�������˸첲
    
    fill_rect(x+sb,y+sb,x+sb/4,y+sb/2*3,MARINE_BLUE,BLACK);
    fill_rect(x-sb,y+sb,x-sb/4,y+sb/2*3,MARINE_BLUE,BLACK);
    fill_rect(x+sb,y+sb/4*5,x+sb/4,y+sb/2*3,WHITE,BLACK);
    fill_rect(x-sb,y+sb/4*5,x-sb/4,y+sb/2*3,WHITE,BLACK); //����������

    fill_circle(x+sb,y-sb/2*3,sb/5,WHITE);
    fill_circle(x-sb,y-sb/2*3,sb/5,WHITE);
    fill_rect(x-sb,y-sb,x+sb,y-2*sb,MARINE_BLUE,BLACK); //��������ͷ
    
    thick_line(x+sb/2,y-sb/2*5,x+sb/2,y-2*sb,sb/20,BLACK);
    thick_line(x-sb/2,y-sb/2*5,x-sb/2,y-2*sb,sb/20,BLACK);
    fill_circle(x+sb/2,y-sb/2*5-sb/20*3,sb/20*3,WHITE);
    fill_circle(x-sb/2,y-sb/2*5-sb/20*3,sb/20*3,WHITE); //������������

    return;
}

void clearrobot(int x,int y,int size)
{
    int sb=ROBOT_SIZE*size*3;
    bar(x-sb,y-sb,x+sb,y+sb,MISTY_ROSE);
}