/*
    mainwin.c

    Initial version: 2020.9.12
    Lastest update: 2020.9.12 
    Author: mfp
*/
#include "headers.h"
#define lb 750
#define ub 0
#define timeupdate 100000 //更新界面时间
#define timedirt 50000 //污染程度更新时间
#define timetmp 5000000 //温度更新时间
#define timeele 500000 //电量更新时间
#define timecut 10000000 //时间计数器请清零

FILE *fpde;

void mainWindow()
{
    HOUSE *house;
    ROBOT *robot;
    char value, value1;
    int i,j;
    

    drawbasic();  //画出画面底板
    clrmous(MouseX, MouseY);
    
    house=(HOUSE *)malloc(sizeof(HOUSE));
    robot=(ROBOT *)malloc(sizeof(ROBOT));
    maininit(house,robot); //定义并初始化房间和机器人

    fpde=fopen("debug\\debug.txt","w");
    
    paintmp(house,robot);
    draw_control(house,robot);
    draw_bactr(robot);
    
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //timepass(house,robot,1);
        if(mouse_press(lb+37,ub+350,lb+127,ub+390)==1) //进入电量界面
        {
            clrmous(MouseX, MouseY);
            draw_electr(house,robot);
            nocombo();
            func_electr(house,robot);
            draw_control(house,robot);
            continue;
        }
        if(mouse_press(lb+147,ub+350,lb+237,ub+390)==1) //进入舒适度界面
        {
            clrmous(MouseX, MouseY);
            draw_comfort(house,robot);
            nocombo();
            func_comfort(house,robot);
            draw_control(house,robot);
            continue;
        }
        if(mouse_press(lb+37,ub+410,lb+127,ub+450)==1) //进入环境界面
        {
            clrmous(MouseX, MouseY);
            draw_clean(house,robot);
            nocombo();
            func_clean(house,robot);
            draw_control(house,robot);
            continue;
        }
        if(mouse_press(lb+147,ub+410,lb+237,ub+450)==1) //进入控制界面
        {
            clrmous(MouseX, MouseY);
            draw_move(house,robot);
            nocombo();
            func_move(house,robot);
            draw_control(house,robot);
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //进入互动界面
        {
            /*clrmous(MouseX, MouseY);
            draw_electr();
            nocombo();
            func_electr();
            draw_control();*/
            fclose(fpde);
            continue;
        }
        if(kbhit())
        {
            value=getch();
            moveupdate(house,robot,value);
            fprintf(fpde,"1 %d %d\n",(*robot).px,(*robot).py);
        }
    }
    return;
}

void drawbasic()
{
    setbkcol(MISTY_ROSE);
    bar(750,0,1024,768,MARINE_BLUE);
    bar(800,200,900,300,MISTY_ROSE);
}

void paintmp(HOUSE *house, ROBOT *robot)
{
    int i,j;
    int flag_bed=0;
    int tx=24,ty=15,sz=40;
    int cx1,cy1,cx2,cy2;
    
    for(i=0;i<N;i++)    
    for(j=0;j<N;j++)
    {
        cy1=tx+i*sz, cx1=ty+j*sz;
        cy2=cy1+sz, cx2=cx1+sz;
        switch((*house).mp1[i][j])
        {
            case 0: case 1:
                draw_floor_wood(cx1,cy1);
                break;
            case 2:
                bar(cx1,cy1,cx2,cy2,BLACK);
                break;
            case 3:
                bar(cx1,cy1,cx2,cy2,BROWN);
                break;
            case 4:
                bar(cx1,cy1,cx2,cy2,PEACH_PUFF);
                break;
            case 5:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                break;
            case 6:
                bar(cx1,cy1,cx2,cy2,GREEN);
                break;
            case 7:
                draw_bed(cx1,cx2);
                break;
            default: break;
        }
    }
    bar(0,0,15,768,MISTY_ROSE);
    bar(735,0,750,768,MISTY_ROSE);
    bar(0,0,750,24,MISTY_ROSE);
    bar(0,744,750,768,MISTY_ROSE);
    cy1=tx+(*robot).px*sz, cx1=ty+(*robot).py*sz;
    cy2=cy1+sz, cx2=cx1+sz;
    fprintf(fpde,"%c\n",(*robot).rt);
    switch((*robot).rt)
    {
        case 'u': drawrobot_back((cx1+cx2)/2,(cy1+cy2)/2,1); break;
        case 'd': drawrobot_front((cx1+cx2)/2,(cy1+cy2)/2,1); break;
        case 'l': drawrobot_left((cx1+cx2)/2,(cy1+cy2)/2,1); break;
        case 'r': drawrobot_right((cx1+cx2)/2,(cy1+cy2)/2,1); break;
        default: break;
    }
}

void maininit(HOUSE *house, ROBOT *robot)
{
    int i,j;
    int mp1init[N][N]={
        {0,2,6,6,2,6,6,6,2,6,6,6,2,0,0,0,0,0},
        {0,9,0,0,2,6,6,6,2,6,6,6,2,5,5,0,0,0},
        {0,9,0,0,9,0,0,6,2,0,0,6,2,5,5,4,0,0},
        {0,2,0,0,9,0,0,6,2,0,0,6,2,5,5,4,0,0},
        {2,2,0,0,9,0,0,6,2,0,0,6,2,5,5,0,0,0},
        {0,0,0,0,2,6,6,6,2,0,0,6,2,0,0,0,0,0},
        {4,4,0,0,2,2,2,2,2,10,11,2,2,0,0,0,0,6},
        {5,5,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,6},
        {5,5,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,6},
        {12,4,0,0,0,0,0,2,10,11,2,2,2,2,2,2,2,2},
        {0,0,0,4,4,0,6,2,0,0,0,0,0,6,6,6,6,6},
        {6,0,0,0,0,4,4,2,0,0,0,0,0,0,0,0,0,0},
        {6,0,0,5,5,4,4,2,0,0,0,0,0,0,0,0,0,6},
        {6,0,0,5,5,4,4,2,6,0,0,0,0,7,7,7,7,7},
        {6,0,0,5,5,4,4,2,6,0,0,0,0,7,7,7,7,7},
        {6,0,0,0,0,4,4,2,6,0,0,0,0,7,7,7,7,7},
        {0,0,0,4,4,0,6,2,0,0,0,0,0,0,0,0,0,6},
        {0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0},
    };

    (*robot).electr=100; //初始化机器人信息
    (*robot).px=9, (*robot).py=0;
    (*robot).rt='d';
    
    (*house).time=0;
    (*house).temp=26;
    (*house).wet=50;
    (*house).pm25=100; //初始化房间信息

    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        ((*house).mp1)[i][j]=mp1init[i][j];
    
    //1是地板，2是墙壁，3是门，4是椅子，
    //5是桌子，6是一般高度家具，78是床，9是竖门，10是左门，11是右门
}

void func_electr(HOUSE *house, ROBOT *robot)
{
    char value;
    
    draw_bactr(robot);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,1);
        if(mouse_press(lb+57,ub+350,lb+217,ub+390)==1) //进入电量界面
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+410,lb+217,ub+450)==1) //进入舒适度界面
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //返回主菜单
        {
            nocombo();
            return;
        }
        if(kbhit())
        {
            value=getch();
            moveupdate(house,robot,value);
        }
    }
}


void func_comfort(HOUSE *house, ROBOT *robot)
{
    char value;
    
    draw_bactr(robot);
    while(1)
    {
        
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,1);
        if(mouse_press(lb+57,ub+350,lb+217,ub+390)==1) //进入电量界面
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+410,lb+217,ub+450)==1) //进入舒适度界面
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //进入环境界面
        {
            nocombo();
            return;
        }
        if(kbhit())
        {
            value=getch();
            moveupdate(house,robot,value);
        }
    }
}

void func_clean(HOUSE *house, ROBOT *robot)
{
    char value;
    
    draw_bactr(robot);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,1);
        if(mouse_press(lb+57,ub+350,lb+217,ub+390)==1) //进入电量界面
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+410,lb+217,ub+450)==1) //进入舒适度界面
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //进入环境界面
        {
            nocombo();
            return;
        }
        if(kbhit())
        {
            value=getch();
            moveupdate(house,robot,value);
        }
    }
}

void func_move(HOUSE *house, ROBOT *robot)
{
    char value;
    
    draw_bactr(robot);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,1);
        if(mouse_press(lb+57,ub+350,lb+217,ub+390)==1) //进入电量界面
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+410,lb+217,ub+450)==1) //进入舒适度界面
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //进入环境界面
        {
            nocombo();
            return;
        }
        if(kbhit())
        {
            value=getch();
            moveupdate(house,robot,value);
        }
    }
}

void timepass(HOUSE *house, ROBOT *robot,int st)
{
    /*******上机调试*******/
    char *s;

    /*bar(0,0,150,60,MARINE_BLUE);
    itoa(house).time,s,10);
    outtextxy(0,0,s,1,2,10,WHITE);*/

    if((*house).time%timeupdate==0)
    {
        draw_bactr(robot); //画电池电量
        /*switch(st)
        {
            case 1:
                write_statu(house,robot);
                break;
            default: break;
        } //写出房间环境*/
    }
    if((*house).time%timedirt==0) (*house).pm25++;
    if((*house).time%timetmp==0) (*house).temp++;
    if((*house).time%timeele==0) (*robot).electr--;
    if((*robot).electr==0) (*robot).electr=100; //触发自动充电模块
    (*house).time%=timecut;
    ((*house).time)++; 
}