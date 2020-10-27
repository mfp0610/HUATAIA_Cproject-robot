/*
    board.c

	Initial version: 2020.9.27
    Lastest update: 2020.9.27
    Author: mfp
*/

#include "headers.h"
#define lb 750
#define ub 0

void draw_control()
{

    bar(lb,ub,1024,768,MARINE_BLUE);

    //画返回主菜单
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"返回菜单",24,25,'K',BLACK);

    //画状态显示栏
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"欢迎用户",32,32,'S',BLACK);
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    puthz(lb+37,ub+160,"室内温度：",24,25,'K',BLACK);
    puthz(lb+37,ub+195,"室外温度：",24,25,'K',BLACK);
    puthz(lb+37,ub+230,"空气湿度：",24,25,'K',BLACK);
    puthz(lb+37,ub+265,"污染指数：",24,25,'K',BLACK);

    //画功能按钮
    fill_rect(lb+37,ub+350,lb+127,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+47,ub+354,"电量",32,35,'K',BLACK);
    fill_rect(lb+147,ub+350,lb+237,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+157,ub+354,"舒适",32,35,'K',BLACK);
    fill_rect(lb+37,ub+410,lb+127,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+47,ub+414,"环境",32,35,'K',BLACK);
    fill_rect(lb+147,ub+410,lb+237,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+157,ub+414,"控制",32,35,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"人机互动",32,32,'K',BLACK);

    //画遥控按钮
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_electr()
{
    bar(lb,ub,1024,768,MARINE_BLUE);  

    //画返回主菜单
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"返回菜单",24,25,'K',BLACK);

    //画状态显示栏
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"欢迎用户",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    //puthz(lb+37,ub+160,"室外温度：",24,25,'K',BLACK);
    ///puthz(lb+37,ub+195,"室内温度：",24,25,'K',BLACK);
    //puthz(lb+37,ub+230,"空气湿度：",24,25,'K',BLACK);
    //puthz(lb+37,ub+265,"空气质量：",24,25,'K',BLACK);

    //画功能按钮
    fill_rect(lb+57,ub+350,lb+217,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+354,"自动充电",32,32,'K',BLACK);
    fill_rect(lb+57,ub+410,lb+217,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+414,"手动充电",32,32,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"返回主页",32,32,'K',BLACK);

    //画遥控按钮
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_comfort()
{
    bar(lb,ub,1024,768,MARINE_BLUE);

    //画返回主菜单
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"返回菜单",24,25,'K',BLACK);

    //画状态显示栏
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"欢迎用户",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    puthz(lb+37,ub+160,"室内温度：",24,25,'K',BLACK);
    puthz(lb+37,ub+195,"室外温度：",24,25,'K',BLACK);
    puthz(lb+37,ub+230,"空气湿度：",24,25,'K',BLACK);
    puthz(lb+37,ub+265,"污染指数：",24,25,'K',BLACK);

    //画功能按钮
    puthz(lb+27,ub+354,"温度",32,32,'K',WHITE);

    fill_rect(lb+110,ub+355,lb+140,ub+385,MISTY_ROSE,MARINE_BLUE);

    fill_rect(lb+167,ub+360,lb+187,ub+380,MISTY_ROSE,MARINE_BLUE);
    fill_rect(lb+227,ub+360,lb+247,ub+380,MISTY_ROSE,MARINE_BLUE);
    outtextxy(lb+159,ub+353,"-",2,2,16,BLACK);
    outtextxy(lb+219,ub+353,"+",2,2,16,BLACK);
    
    fill_rect(lb+37,ub+410,lb+127,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+47,ub+414,"除湿",32,35,'K',BLACK);
    fill_rect(lb+147,ub+410,lb+237,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+157,ub+414,"除尘",32,35,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"返回主页",32,32,'K',BLACK);

    //画遥控按钮
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_move()
{
    bar(lb,ub,1024,768,MARINE_BLUE);

    //画返回主菜单
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"返回菜单",24,25,'K',BLACK);

    //画状态显示栏
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"欢迎用户",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    
    //画功能按钮
    fill_rect(lb+57,ub+350,lb+217,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+354,"定向巡逻",32,32,'K',BLACK);
    fill_rect(lb+57,ub+410,lb+217,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+414,"自动巡逻",32,32,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"返回主页",32,32,'K',BLACK);

    //画遥控按钮
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_clean()
{
    bar(lb,ub,1024,768,MARINE_BLUE);

    //画返回主菜单
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"返回菜单",24,25,'K',BLACK);

    //画状态显示栏
    fill_rect(lb+17,ub+60,lb+257,ub+320,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"欢迎用户",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    puthz(lb+37,ub+160,"地面垃圾：",24,25,'K',BLACK);
    puthz(lb+37,ub+195,"桶内垃圾：",24,25,'K',BLACK);
    //puthz(lb+37,ub+230,"空气湿度：",24,25,'K',BLACK);
    //puthz(lb+37,ub+265,"空气质量：",24,25,'K',BLACK);

    //画功能按钮
    fill_rect(lb+57,ub+350,lb+217,ub+390,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+354,"生成垃圾",32,32,'K',BLACK);
    fill_rect(lb+57,ub+410,lb+217,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+414,"拾取垃圾",32,32,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"返回主页",32,32,'K',BLACK);

    //画遥控按钮
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_react()
{
    bar(lb,ub,1024,768,MARINE_BLUE);  

    //画返回主菜单
    fill_rect(lb+140,ub+10,lb+250,ub+40,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+145,ub+12,"返回菜单",24,25,'K',BLACK);
    
    //画状态显示栏
    fill_rect(lb+17,ub+60,lb+257,ub+380,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+27,ub+95,"欢迎用户",32,32,'H',BLACK);
    
    outtextxy(lb+145,ub+95,"111",2,2,16,BLACK);
    //puthz(lb+37,ub+160,"室外温度：",24,25,'K',BLACK);
    //puthz(lb+37,ub+195,"室内温度：",24,25,'K',BLACK);
    //puthz(lb+37,ub+230,"空气湿度：",24,25,'K',BLACK);
    //puthz(lb+37,ub+265,"空气质量：",24,25,'K',BLACK);

    //画功能按钮
    fill_rect(lb+37,ub+410,lb+127,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+47,ub+414,"聊天",32,35,'K',BLACK);
    fill_rect(lb+147,ub+410,lb+237,ub+450,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+157,ub+414,"字谜",32,35,'K',BLACK);
    fill_rect(lb+57,ub+470,lb+217,ub+510,MISTY_ROSE,MARINE_BLUE);
    puthz(lb+71,ub+474,"返回主页",32,32,'K',BLACK);

    //画遥控按钮
    //midx-137 midy-700 
    fill_circle(lb+92,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+182,ub+630,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+585,30,MISTY_ROSE,MARINE_BLUE);
    fill_circle(lb+137,ub+675,30,MISTY_ROSE,MARINE_BLUE);
}

void draw_bactr(ROBOT *robot)
{
    char s[5];
    int len;
    bar(lb,ub,lb+130,ub+60,MARINE_BLUE);
    fill_rect(lb+21,ub+10,lb+70,ub+40,MISTY_ROSE,MARINE_BLUE);
    fill_rect(lb+70,ub+15,lb+75,ub+35,MISTY_ROSE,MISTY_ROSE);
    itoa((*robot).electr,s,10);
    len=strlen(s);
    s[len]='%';
    s[len+1]='\0';
    outtextxy(lb+80,ub+10,s,1,2,10,WHITE);
    if((*robot).electr<25) fill_rect(lb+23,ub+12,lb+32,ub+38,STRONG_RED,BRIGHT_GREEN);
    else fill_rect(lb+23,ub+12,lb+32,ub+38,BRIGHT_GREEN,BRIGHT_GREEN);
    if((*robot).electr>=25) fill_rect(lb+35,ub+12,lb+44,ub+38,BRIGHT_GREEN,BRIGHT_GREEN);
    if((*robot).electr>=50) fill_rect(lb+47,ub+12,lb+56,ub+38,BRIGHT_GREEN,BRIGHT_GREEN);
    if((*robot).electr>=75) fill_rect(lb+59,ub+12,lb+68,ub+38,BRIGHT_GREEN,BRIGHT_GREEN);
}

void write_statu(HOUSE *house, ROBOT *robot,int st)
{
    int lbx=lb+110, lby=ub+355;
    int color;
    if(st==1||st==2)
    {
        char s1[5],s2[5],s3[5],s4[8];
        itoa((*house).temp,s1,10);
        itoa((*house).tempout,s2,10);
        itoa((*house).wet,s3,10);
        itoa((*house).pm25,s4,10);
        
        bar(lb+150,ub+150,lb+210,ub+300,MISTY_ROSE);
        outtextxy(lb+150,ub+155,s1,2,2,16,BLACK);
        outtextxy(lb+150,ub+190,s2,2,2,16,BLACK);
        outtextxy(lb+150,ub+225,s3,2,2,16,BLACK);
        outtextxy(lb+150,ub+260,s4,2,2,16,BLACK);
        outtextxy(lb+190,ub+155,"C",2,2,16,BLACK);
        outtextxy(lb+190,ub+190,"C",2,2,16,BLACK);
        outtextxy(lb+190,ub+225,"%",2,2,16,BLACK);
        outtextxy(lb+190,ub+260,"%",2,2,16,BLACK);
        drcircle(lb+197,ub+155,3,BLACK);
        drcircle(lb+197,ub+190,3,BLACK);
        if(st==2)
        {
            char s5[3];
            itoa((*house).tempset,s5,10);
            bar(lb+190,ub+360,lb+230,ub+390,MARINE_BLUE);
            
            if((*house).set==1) color=STRONG_RED;
            else color=BLACK;
            //lb+110,ub+355,lb+140,ub+385,
            bar(lbx+14,lby+2,lbx+16,lby+15,color);
            bar(lbx+5,lby+5,lbx+12,lby+7,color);
            bar(lbx+18,lby+5,lbx+25,lby+7,color);
            bar(lbx+5,lby+5,lbx+7,lby+25,color);
            bar(lbx+23,lby+5,lbx+25,lby+25,color);
            bar(lbx+5,lby+23,lbx+25,lby+25,color);
            
            outtextxy(lb+182,ub+354,s5,2,2,16,WHITE);
        }
        return ;
    }
}