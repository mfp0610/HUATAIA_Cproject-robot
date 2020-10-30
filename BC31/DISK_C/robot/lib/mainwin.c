/*
    mainwin.c

    Initial version: 2020.9.12
    Lastest update: 2020.9.12 
    Author: mfp
*/
#include "headers.h"

#define timeupdate 100000 //���½���ʱ��
#define timeset 50000 //��Ⱦʪ�Ȱ���Ҫ�����
#define timedirt 500000 //��Ⱦ��ʪ�ȳ̶ȸ���ʱ��
#define timetmpset 500000 //�趨�¶ȸ���ʱ��
#define timetmp 1000000 //�¶ȸ���ʱ��
#define timeele 500000 //��������ʱ��
#define timecut 10000000 //ʱ�������������
#define setclean 20
#define setwet 20

void mainWindow(USER *usr)
{
    HOUSE *house;
    ROBOT *robot;
    NODE rubbish[4];
    char value, value1;
    int i,j;
    int poscode;
    NODE mp,mto; //��������ж�����

    drawbasic();  //��������װ�
    clrmous(MouseX, MouseY);
    
    house=(HOUSE *)malloc(sizeof(HOUSE));
    robot=(ROBOT *)malloc(sizeof(ROBOT));
    maininit(house,robot); //���岢��ʼ������ͻ�����
    
    paintmp(house,robot);
    draw_control(usr);
    draw_bactr(robot);
    write_statu(house,robot,1);
    house->rubnum=0;

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,usr,1);
        if(mouse_press(LB+37,UB+350,LB+127,UB+390)==1) //�����������
        {
            clrmous(MouseX, MouseY);
            draw_electr(usr);
            nocombo();
            if(func_electr(house,robot,usr))
                return ;
            draw_control(usr);
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(mouse_press(LB+147,UB+350,LB+237,UB+390)==1) //�������ʶȽ���
        {
            clrmous(MouseX, MouseY);
            draw_comfort(usr);
            nocombo();
            if(func_comfort(house,robot,usr))
                return ;
            draw_control(usr);
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(mouse_press(LB+37,UB+410,LB+127,UB+450)==1) //���뻷������
        {
            clrmous(MouseX, MouseY);
            draw_clean(usr);
            nocombo();
            if(func_clean(rubbish,house,robot,usr))
                return ;
            draw_control(usr);
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(mouse_press(LB+147,UB+410,LB+237,UB+450)==1) //������ƽ���
        {
            clrmous(MouseX, MouseY);
            draw_move(usr);
            nocombo();
            if(func_move(house,robot,usr))
                return ;
            draw_control(usr);
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //���뻥������
        {
            clrmous(MouseX, MouseY);
            draw_react(usr,0);
            nocombo();
            if(func_react(house,robot,usr))
                return ;
            draw_control(usr);
            nocombo();
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(kbhit())
        {
            Delaytime(50);
            value=getch();
            moveupdate(house,robot,value);   
        }
        get_conbot(house,robot);
        if(mouse_press(15,24,735,744)==1)
        {
            nocombo();
            poscode=getposition(MouseX, MouseY);
            mto.x=poscode/18;
            mto.y=poscode%18;
            mp.x=(*robot).px;
            mp.y=(*robot).py;
            if(!Astarmove(mp,mto,robot,house))
            {
                draw_cantgo();
            }
        }
        if(mouse_press(LB+140,UB+10,LB+250,UB+40)==1)
            return ;
    }
    return;
}

void drawbasic()
{
    setbkcol(MISTY_ROSE);
    bar(750,0,1024,768,MARINE_BLUE);
    bar(800,200,900,300,MISTY_ROSE);
}

void maininit(HOUSE *house, ROBOT *robot)
{
    int i,j;
    int mp1init[N][N]={
        {3,2,0,0,2,6,6,6,2,6,6,6,2,0,0,0,0,0},
        {0,9,0,0,2,6,6,6,2,6,6,6,2,5,5,0,0,0},
        {0,9,0,0,9,0,0,6,2,0,0,6,2,5,5,18,0,0},
        {0,2,0,0,9,0,0,6,2,0,0,6,2,5,5,19,0,0},
        {2,2,0,0,2,0,0,6,2,0,0,6,2,5,5,0,0,0},
        {0,0,0,0,2,6,6,6,2,0,0,6,2,0,0,0,0,0},
        {4,4,0,0,2,2,2,2,2,10,11,2,2,0,0,0,0,29},
        {5,5,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,29},
        {5,5,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,29},
        {30,30,0,0,0,0,0,2,10,11,2,2,2,2,2,2,2,2},
        {0,0,0,31,32,0,6,2,0,0,0,0,0,29,29,29,29,29},
        {28,0,0,0,0,20,17,2,0,0,0,0,0,0,0,0,0,0},
        {28,0,0,5,5,15,16,2,0,0,0,0,0,0,0,0,0,27},
        {28,0,0,5,5,20,17,2,28,0,0,0,0,7,7,7,8,12},
        {28,0,0,5,5,15,16,2,28,0,0,0,0,7,7,7,8,13},
        {28,0,0,0,0,20,17,2,28,0,0,0,0,7,7,7,8,14},
        {0,0,0,33,34,0,6,2,0,0,0,0,0,0,0,0,0,27},
        {21,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0},
    };
    //0�ǵذ壬1�ǻ����ˣ�2��ǽ�ڣ�3������Ͱ��4 30�����ӣ�
    //5�����ӣ�6��һ��߶ȼҾߣ�7 8 12 13 14�Ǵ���9�����ţ�10�����ţ�11������
    //21�ǳ��׮��22��������23 24 25 26�ǿ���״̬��27�Ǵ�ͷ��28�ǵ��ӣ�29�����

    (*robot).electr=100; //��ʼ����������Ϣ
    (*robot).px=10, (*robot).py=0;
    (*robot).rt='d';
    
    (*house).time=0;

    (*house).set=0;
    (*house).setd=0;
    (*house).setc=0;

    (*house).tempset=26;
    (*house).tempout=20;
    (*house).temp=26;
    (*house).wet=50;
    (*house).pm25=50; 
    
    for(i=0;i<5;i++)
        (*house).dor[i]=1;
    //��ʼ��������Ϣ

    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    {
        (*house).mp1[i][j]=mp1init[i][j];
        (*house).mpinit[i][j]=mp1init[i][j];
    }
}

void timepass(HOUSE *house, ROBOT *robot, USER *usr, int st)
{
    char *s;
    unsigned int *back[240][90];
    FILE *fpsv;

    if((*house).time%timeupdate==0)
    {
        draw_bactr(robot); //����ص���
        write_statu(house,robot,st); //����״̬��
    }
    if((*house).time%timeset==0)
    {
        //pm25�仯
        if((*house).pm25>=setclean&&(*house).setc)
            (*house).pm25--;
        else if((*house).time%timedirt==0)
        {
            (*house).setc=0;
            (*house).pm25++;
        }
        //ʪ�ȱ仯
        if((*house).wet>=setwet&&(*house).setd)
            (*house).wet--;
        else if((*house).time%timedirt==0)
        {
            (*house).setd=0;
            (*house).wet++;
        }
    }
    if((*house).time%timetmpset==0)
    {
        if((*house).set)
            (*house).temp-=sign((*house).temp-(*house).tempset);
        else if((*house).time%timetmp==0)
            (*house).temp-=sign((*house).temp-(*house).tempout);
    }
    if((*house).time%timeele==0) 
        (*robot).electr--;
    if((*robot).electr<=10) //�����Զ����ģ��
    {
        fin(fpsv,"data\\mpsv.txt",LB+17,UB+60,LB+257,UB+510);
        
        draw_electr(usr);
        write_statu(house,robot,5);
        charge(house,robot,usr);

        fout(fpsv,"data\\mpsv.txt",LB+17,UB+60,LB+257,UB+510);
    }
    (*house).time%=timecut;
    ((*house).time)++; 
}

void fin(FILE *fp, char *rd, int x1,int y1,int x2,int y2)
{
    int i,j;
    fp=fopen(rd,"w");
    for(i=x1;i<=x2;i++)
    for(j=y1;j<=y2;j++)
        fprintf(fp,"%u\n",Getpixel64k(i,j));
    fclose(fp);
    return ;
}

void fout(FILE *fp, char *rd, int x1,int y1,int x2,int y2)
{
    int i,j;
    unsigned int px;
    fp=fopen(rd,"r");
    for(i=x1;i<=x2;i++)
    for(j=y1;j<=y2;j++)
    {
        fscanf(fp,"%u",&px);
        Putpixel64k(i,j,px);
    }
    fclose(fp);
    return ;
}