/*
    board.c

	Initial version: 2020.9.27
    Lastest update: 2020.9.27
    Author: mfp
*/

#include "headers.h"
#define lb 750
#define ub 0

void draw_control(HOUSE *house, ROBOT *robot)
{

    bar(lb,ub,1024,768,MARINE_BLUE);

    //���������˵�
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"���ز˵�",24,25,'K',BLACK);

    //��״̬��ʾ��
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"��ӭ�û�",32,32,'S',BLACK);
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    puthz(lb+37,ub+160,"�����¶ȣ�",24,25,'K',BLACK);
    puthz(lb+37,ub+195,"�����¶ȣ�",24,25,'K',BLACK);
    puthz(lb+37,ub+230,"����ʪ�ȣ�",24,25,'K',BLACK);
    puthz(lb+37,ub+265,"����������",24,25,'K',BLACK);

    //�����ܰ�ť
    fill_rect(lb+37,ub+350,lb+127,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+47,ub+354,"����",32,35,'K',BLACK);
    fill_rect(lb+147,ub+350,lb+237,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+157,ub+354,"����",32,35,'K',BLACK);
    fill_rect(lb+37,ub+410,lb+127,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+47,ub+414,"����",32,35,'K',BLACK);
    fill_rect(lb+147,ub+410,lb+237,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+157,ub+414,"����",32,35,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"�˻�����",32,32,'K',BLACK);

    //��ң�ذ�ť
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_electr(HOUSE *house, ROBOT *robot)
{
    bar(lb,ub,1024,768,MARINE_BLUE);  

    //���������˵�
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"���ز˵�",24,25,'K',BLACK);
    
    //����ص���
    //draw_bactr(robot);

    //��״̬��ʾ��
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"��ӭ�û�",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    //puthz(lb+37,ub+160,"�����¶ȣ�",24,25,'K',BLACK);
    ///puthz(lb+37,ub+195,"�����¶ȣ�",24,25,'K',BLACK);
    //puthz(lb+37,ub+230,"����ʪ�ȣ�",24,25,'K',BLACK);
    //puthz(lb+37,ub+265,"����������",24,25,'K',BLACK);

    //�����ܰ�ť
    fill_rect(lb+57,ub+350,lb+217,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+354,"�Զ����",32,32,'K',BLACK);
    fill_rect(lb+57,ub+410,lb+217,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+414,"�ֶ����",32,32,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"������ҳ",32,32,'K',BLACK);

    //��ң�ذ�ť
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_comfort(HOUSE *house, ROBOT *robot)
{
    bar(lb,ub,1024,768,MARINE_BLUE);

    //���������˵�
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"���ز˵�",24,25,'K',BLACK);


    //��״̬��ʾ��
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"��ӭ�û�",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    puthz(lb+37,ub+160,"�����¶ȣ�",24,25,'K',BLACK);
    puthz(lb+37,ub+195,"�����¶ȣ�",24,25,'K',BLACK);
    puthz(lb+37,ub+230,"����ʪ�ȣ�",24,25,'K',BLACK);
    puthz(lb+37,ub+265,"����������",24,25,'K',BLACK);

    //�����ܰ�ť
    fill_rect(lb+37,ub+350,lb+127,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+47,ub+354,"�¶�",32,35,'K',BLACK);
    outtextxy(lb+157,ub+354,"-26+",2,2,16,BLACK);
    fill_rect(lb+37,ub+410,lb+127,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+47,ub+414,"��ʪ",32,35,'K',BLACK);
    fill_rect(lb+147,ub+410,lb+237,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+157,ub+414,"����",32,35,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"������ҳ",32,32,'K',BLACK);

    //��ң�ذ�ť
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_move(HOUSE *house, ROBOT *robot)
{
    bar(lb,ub,1024,768,MARINE_BLUE);

    //���������˵�
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"���ز˵�",24,25,'K',BLACK);

    //��״̬��ʾ��
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"��ӭ�û�",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    //puthz(lb+37,ub+160,"�����¶ȣ�",24,25,'K',BLACK);
    ///puthz(lb+37,ub+195,"�����¶ȣ�",24,25,'K',BLACK);
    //puthz(lb+37,ub+230,"����ʪ�ȣ�",24,25,'K',BLACK);
    //puthz(lb+37,ub+265,"����������",24,25,'K',BLACK);

    //�����ܰ�ť
    fill_rect(lb+57,ub+350,lb+217,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+354,"����Ѳ��",32,32,'K',BLACK);
    fill_rect(lb+57,ub+410,lb+217,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+414,"�Զ�Ѳ��",32,32,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"������ҳ",32,32,'K',BLACK);

    //��ң�ذ�ť
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_clean(HOUSE *house, ROBOT *robot)
{
    bar(lb,ub,1024,768,MARINE_BLUE);

    //���������˵�
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"���ز˵�",24,25,'K',BLACK);

    //��״̬��ʾ��
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"��ӭ�û�",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    puthz(lb+37,ub+160,"����������",24,25,'K',BLACK);
    puthz(lb+37,ub+195,"Ͱ��������",24,25,'K',BLACK);
    //puthz(lb+37,ub+230,"����ʪ�ȣ�",24,25,'K',BLACK);
    //puthz(lb+37,ub+265,"����������",24,25,'K',BLACK);

    //�����ܰ�ť
    fill_rect(lb+57,ub+350,lb+217,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+354,"ʰȡ����",32,32,'K',BLACK);
    fill_rect(lb+57,ub+410,lb+217,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+414,"�㵹����",32,32,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"������ҳ",32,32,'K',BLACK);

    //��ң�ذ�ť
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_bactr(ROBOT *robot)
{
    char *s;
    int len;
    bar(lb,ub,lb+140,ub+60,MARINE_BLUE);
    fill_rect(lb+21,ub+10,lb+70,ub+40,MISTY_ROSE,MARINE_BLUE);
    fill_rect(lb+70,ub+15,lb+75,ub+35,MISTY_ROSE,MISTY_ROSE);
    itoa(robot->electr,s,10);
    len=strlen(s);
    s[len]='%';
    s[len+1]='\0';
    outtextxy(lb+80,ub+10,s,1,2,10,WHITE);
    if(robot->electr<25) fill_rect(lb+23,ub+12,lb+32,ub+38,STRONG_RED,BRIGHT_GREEN);
    else fill_rect(lb+23,ub+12,lb+32,ub+38,BRIGHT_GREEN,BRIGHT_GREEN);
    if(robot->electr>=25) fill_rect(lb+35,ub+12,lb+44,ub+38,BRIGHT_GREEN,BRIGHT_GREEN);
    if(robot->electr>=50) fill_rect(lb+47,ub+12,lb+56,ub+38,BRIGHT_GREEN,BRIGHT_GREEN);
    if(robot->electr>=75) fill_rect(lb+59,ub+12,lb+68,ub+38,BRIGHT_GREEN,BRIGHT_GREEN);
}

void write_statu(HOUSE *house, ROBOT *robot)
{
    
    outtextxy(lb+150,ub+160,"�����¶ȣ�",24,25,'K',BLACK);
    outtextxy(lb+150,ub+195,"�����¶ȣ�",24,25,'K',BLACK);
    outtextxy(lb+150,ub+230,"����ʪ�ȣ�",24,25,'K',BLACK);
    outtextxy(lb+150,ub+265,"����������",24,25,'K',BLACK);
}