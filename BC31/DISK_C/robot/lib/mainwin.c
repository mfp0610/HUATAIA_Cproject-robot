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

FILE *fpde;
FILE *fpde5;

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

    //fpde=fopen("debug\\debug.txt","w");
    
    paintmp(house,robot);
    draw_control(usr);
    draw_bactr(robot);
    write_statu(house,robot,1);
    house->rubnum=0;

    /*fprintf(fpde,"\ninit\n");
    fprintf(fpde,"time %lld\n",(*house).time); 
    fprintf(fpde,"pm %d\n",(*house).pm25);
    fprintf(fpde,"out %d\n",(*house).tempout);
    fprintf(fpde,"in %d\n",(*house).temp);
    fprintf(fpde,"dian %d\n",(*robot).electr);*/

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
            fclose(fpde);
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
                bar(1000,750,1024,768,BLACK);
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
            case 0:
                draw_floor_wood(cx1,cy1);
                break;
            case 2:
                bar(cx1,cy1,cx2,cy2,BLACK);
                break;
            case 3:
                draw_bin(cx1,cy1);
                break;
            case 4:
                draw_floor_wood(cx1,cy1);
                fill_circle((cx1+cx2)/2,(cy1+cy2)/2,20,PEACH_PUFF,BLACK);
                bar(cx1,cy1,cx2,cy1+8,DARK_GRAY);
                break;
            case 5:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                break;
            case 6:
                draw_floor_ceramic(cx1,cy1);
                break;
            case 7:
                bar(cx1,cy1,cx2,cy2,PINK);
                break;
            case 8:
                bar(cx1,cy1,cx1+2,cy2,BLACK);
                bar(cx1+2,cy1,cx2,cy2,PINK);
                break;
            case 9:
                draw_floor_wood(cx1,cy1);
                draw_door_vertical(cx1,cy1,1);
                break;
            case 10:
                draw_door_left(cx1,cy1);
                break;
            case 11:
                draw_door_right(cx1,cy1);
                break;
            case 12:
                bar(cx1,cy1,cx2,cy2,PINK);
                bar(cx1,cy1+8,cx2-8,cy2,WHEAT);
                break;
            case 13:
                bar(cx1,cy1,cx2,cy2,PINK);
                bar(cx1,cy1,cx2-8,cy1+12,WHEAT);
                bar(cx1,cy1+28,cx2-8,cy2,WHEAT);
                break;
            case 14:
                bar(cx1,cy1,cx2,cy2,PINK);
                bar(cx1,cy1,cx2-8,cy2-8,WHEAT);
                break;
            case 15:
                bar(cx1,cy1,cx2,cy2,PINK);
                bar(cx1,cy1+19,cx2,cy2-19,BLACK);
                bar(cx1,cy1,cx1+2,cy2,BLACK);
                break;
            case 16:
                bar(cx1,cy1,cx2,cy2,PINK);
                bar(cx1+21,cy1,cx2,cy2,WHEAT);
                bar(cx1,cy1+19,cx2,cy2-19,BLACK);
                bar(cx1+19,cy1,cx2-19,cy2,BLACK);
                break;
            case 17:
                bar(cx1,cy1,cx2,cy2,PINK);
                bar(cx1+19,cy1,cx2-19,cy2,BLACK);
                bar(cx1+21,cy1,cx2,cy2,WHEAT);
                break;
            case 18:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                bar(cx1,cy1+8,cx2-8,cy1+10,BLACK);
                bar(cx2-10,cy1+10,cx2-8,cy2,BLACK);
                bar(cx1,cy1+10,cx2-10,cy2,PINK);
                bar(cx1,cy1,cx1+2,cy2,BLACK);
                break;
            case 19:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                bar(cx2-10,cy1,cx2-8,cy2-8,BLACK);
                bar(cx1,cy2-10,cx2-10,cy2-8,BLACK);
                bar(cx1,cy1,cx2-10,cy2-10,PINK);
                bar(cx1,cy1,cx1+2,cy2,BLACK);
                break;
            case 20:
                bar(cx1,cy1,cx2,cy2,PINK);
                bar(cx1,cy1,cx1+2,cy2,BLACK);
                break;
            case 21:
                draw_charge(cx1,cy1);    
                break;
            case 22:
                draw_floor_wood(cx1,cy1);
                draw_rub(cx1,cy1);
                break;
            case 23:
                draw_floor_wood(cx1,cy1);
                open_up_door(cx1,cy1);
                break;
            case 24:
                draw_floor_wood(cx1,cy1);
                open_down_door(cx1,cy1);
                break;
            case 25:
                draw_floor_wood(cx1,cy1);
                open_left_door(cx1,cy1);
                break;
            case 26:
                draw_floor_wood(cx1,cy1);
                open_right_door(cx1,cy1);
                break;
            case 27:
                draw_floor_wood(cx1,cy1);
                fill_circle(cx1+20,cy1+20,20,WHEAT,BLACK);
                break;
            case 28:
                draw_floor_wood(cx1,cy1);
                bar(cx1,cy1,cx1+10,cy2,DARK_GRAY);
                bar(cx1+10,cy1,cx1+20,cy2,BLACK);
                break;
            case 29:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                break;
            case 30:
                draw_floor_wood(cx1,cy1);
                fill_circle((cx1+cx2)/2,(cy1+cy2)/2,20,PEACH_PUFF,BLACK);
                bar(cx1,cy2-8,cx2,cy2,DARK_GRAY);
                break;
            case 31:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                bar(cx1+8,cy1+8,cx1+10,cy2,BLACK);
                bar(cx1+10,cy1+8,cx2,cy1+10,BLACK);
                bar(cx1+10,cy1+10,cx2,cy2,PINK);
                bar(cx1,cy2-1,cx2,cy2,BLACK);
                break;
            case 32:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                bar(cx1,cy1+8,cx2-8,cy1+10,BLACK);
                bar(cx2-10,cy1+8,cx2-8,cy2,BLACK);
                bar(cx1,cy1+10,cx2-10,cy2,PINK);
                bar(cx1,cy2-1,cx2,cy2,BLACK);
                break;
            case 33:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                bar(cx1+8,cy1,cx1+10,cy2-8,BLACK);
                bar(cx1+8,cy2-10,cx2,cy2-8,BLACK);
                bar(cx1+10,cy1,cx2,cy2-10,PINK);
                bar(cx1,cy1,cx2,cy1+1,BLACK);
                break;
            case 34:
                bar(cx1,cy1,cx2,cy2,WHEAT);
                bar(cx1,cy2-10,cx2-8,cy2-8,BLACK);
                bar(cx2-10,cy1,cx2-8,cy2-10,BLACK);
                bar(cx1,cy1,cx2-10,cy2-10,PINK);
                bar(cx1,cy1,cx2,cy1+1,BLACK);
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
    {
        (*house).dor[i]=1;
        (*house).win[i]=1;
    }   
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
    if((*house).time%timeupdate==0)
    {
        draw_bactr(robot); //����ص���
        write_statu(house,robot,st); //����״̬��
        /*fprintf(fpde,"\naaaa\n");
        fprintf(fpde,"time %lld\n",(*house).time); 
        
        fprintf(fpde,"flag %d\n",(*house).set);
        fprintf(fpde,"out %d\n",(*house).tempout);
        fprintf(fpde,"in %d\n",(*house).temp);
        fprintf(fpde,"set %d\n",(*house).tempset);*/
        
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
        charge(house,robot,usr);
    }
    (*house).time%=timecut;
    ((*house).time)++; 
}