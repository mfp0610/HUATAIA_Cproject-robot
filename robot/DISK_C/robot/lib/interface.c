/*
    interface.c

    Initial version: 2020.7.13
    Lastest update: 2020.8.12
    Author: 
*/
#include "headers.h"

void start_page()
{
    int i,f1=1;
    setbkcol(MISTY_ROSE);
    for(i=15;i<=80;i++)
    {
        drawrobot_right(i*10,500,5);
        Delaytime(100);
        clearrobot(i*10,500,5);
        if(i%10<5) puthz(220,90,"�����У������ĵȴ�������",48,50,'K',BLACK);
        else puthz(220,90,"�����У������ĵȴ�������",48,50,'K',STRONG_RED);
    }
    setbkcol(MISTY_ROSE);
    drawrobot_front(800,500,5);
    Delaytime(1000);
    clearrobot(800,500,5);
    drawrobot_front_hello(800,500,5);
    puthz(187,90,"��ӭʹ�þӼһ�����ģ��ϵͳ",48,50,'H',BLACK);
    puthz(120,500,"�������ɻ��пƼ���ѧ�Զ���ѧԺ",24,28,'K',BLACK);
    puthz(120,550,"һ��������Ϸ���������Ĺ�ͬ����",24,28,'K',BLACK);
    puthz(200,300,"�����������",32,35,'K',BLACK);
    while(1)
    {
        Delaytime(500);
        if(f1) puthz(200,300,"�����������",32,35,'K',BLACK), f1=0;
        else puthz(200,300,"�����������",32,35,'K',STRONG_RED), f1=1;
        if(bioskey(1)) break;
    }
}

void login_page()
{
    setbkcol(MISTY_ROSE);
    drawrobot_front_hello(800,500,5);
    puthz(187,90,"��ӭʹ�þӼһ�����ģ��ϵͳ",48,50,'H',BLACK);
    outtextxy(175,250,"LOGIN",3,3,50,MARINE_BLUE);
    
    fill_rect(100,350,500,400,WHITE,BLACK);
    fill_rect(100,450,500,500,WHITE,BLACK);
    fill_rect(100,350,180,400,MARINE_BLUE,BLACK);
    fill_rect(100,450,180,500,MARINE_BLUE,BLACK);
    puthz(108,359,"�˺�",32,35,'K',WHITE);
    puthz(108,459,"����",32,35,'K',WHITE); //����¼��ͼ

    fill_rect(120,550,240,600,MARINE_BLUE,BLACK);
    fill_rect(360,550,480,600,MARINE_BLUE,BLACK);
    puthz(130,563,"����ע��",24,25,'K',WHITE);
    puthz(370,563,"�һ�����",24,25,'K',WHITE); //���һغ�ע�����

    fill_rect(240,630,360,680,MARINE_BLUE,BLACK);
    puthz(250,643,"�˳�����",24,25,'K',WHITE);

}

void register_page()
{
    int begposi=300; 

    setbkcol(MISTY_ROSE);
    drawrobot_front_hello(800,500,5);
    puthz(187,90,"��ӭʹ�þӼһ�����ģ��ϵͳ",48,50,'H',BLACK);
    puthz(200,200,"����ע��",48,50,'K',MARINE_BLUE);
    
    fill_rect(100,begposi,500,begposi+50,WHITE,BLACK);
    fill_rect(100,begposi+75,500,begposi+125,WHITE,BLACK);
    fill_rect(100,begposi+150,500,begposi+200,WHITE,BLACK);
    fill_rect(100,begposi+225,500,begposi+275,WHITE,BLACK);
    fill_rect(100,begposi,180,begposi+50,MARINE_BLUE,BLACK);
    fill_rect(100,begposi+75,180,begposi+125,MARINE_BLUE,BLACK);
    fill_rect(100,begposi+150,220,begposi+200,MARINE_BLUE,BLACK);
    fill_rect(100,begposi+225,220,begposi+275,MARINE_BLUE,BLACK);
    puthz(108,begposi+9,"�˺�",32,35,'K',WHITE);
    puthz(108,begposi+84,"����",32,35,'K',WHITE);
    puthz(108,begposi+159,"�ֻ���",32,35,'K',WHITE); 
    puthz(108,begposi+234,"��֤��",32,35,'K',WHITE); //��ע���ͼ

    fill_rect(120,begposi+325,240,begposi+375,MARINE_BLUE,BLACK);
    fill_rect(360,begposi+325,480,begposi+375,MARINE_BLUE,BLACK);
    puthz(130,begposi+338,"ȷ��ע��",24,25,'K',WHITE);
    puthz(370,begposi+338,"���ز˵�",24,25,'K',WHITE); //���һغ�ע�����
}

void findback_page()
{
    int begposi=300; 

    setbkcol(MISTY_ROSE);
    drawrobot_front_hello(800,500,5);
    puthz(187,90,"��ӭʹ�þӼһ�����ģ��ϵͳ",48,50,'H',BLACK);
    puthz(200,200,"�һ�����",48,50,'K',MARINE_BLUE);
    
    fill_rect(100,begposi,500,begposi+50,WHITE,BLACK);
    fill_rect(100,begposi+75,500,begposi+125,WHITE,BLACK);
    fill_rect(100,begposi+150,500,begposi+200,WHITE,BLACK);
    fill_rect(100,begposi,180,begposi+50,MARINE_BLUE,BLACK);
    fill_rect(100,begposi+75,220,begposi+125,MARINE_BLUE,BLACK);
    fill_rect(100,begposi+150,220,begposi+200,MARINE_BLUE,BLACK);
    puthz(108,begposi+9,"�˺�",32,35,'K',WHITE);
    puthz(108,begposi+84,"�ֻ���",32,35,'K',WHITE); 
    puthz(108,begposi+159,"��֤��",32,35,'K',WHITE); //���һ������ͼ

    puthz(108,begposi+235,"�������룺",24,25,'K',MARINE_BLUE);

    fill_rect(120,begposi+300,240,begposi+350,MARINE_BLUE,BLACK);
    fill_rect(360,begposi+300,480,begposi+350,MARINE_BLUE,BLACK);
    puthz(130,begposi+313,"�һ�����",24,25,'K',WHITE);
    puthz(370,begposi+313,"���ز˵�",24,25,'K',WHITE); //���һغ�ע�����
}

void exit_window()
{
    fill_rect(200,200,500,500,MARINE_BLUE,BLACK);
}