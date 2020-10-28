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

void mainWindow()
{
    HOUSE *house;
    ROBOT *robot;
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
    draw_control();
    draw_bactr(robot);
    write_statu(house,robot,1);

    /*fprintf(fpde,"\ninit\n");
    fprintf(fpde,"time %lld\n",(*house).time); 
    fprintf(fpde,"pm %d\n",(*house).pm25);
    fprintf(fpde,"out %d\n",(*house).tempout);
    fprintf(fpde,"in %d\n",(*house).temp);
    fprintf(fpde,"dian %d\n",(*robot).electr);*/

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,1);
        if(mouse_press(LB+37,UB+350,LB+127,UB+390)==1) //�����������
        {
            clrmous(MouseX, MouseY);
            draw_electr();
            nocombo();
            func_electr(house,robot);
            draw_control();
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(mouse_press(LB+147,UB+350,LB+237,UB+390)==1) //�������ʶȽ���
        {
            clrmous(MouseX, MouseY);
            draw_comfort();
            nocombo();
            func_comfort(house,robot);
            draw_control();
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(mouse_press(LB+37,UB+410,LB+127,UB+450)==1) //���뻷������
        {
            clrmous(MouseX, MouseY);
            draw_clean();
            nocombo();
            func_clean(house,robot);
            draw_control();
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(mouse_press(LB+147,UB+410,LB+237,UB+450)==1) //������ƽ���
        {
            clrmous(MouseX, MouseY);
            draw_move();
            nocombo();
            func_move(house,robot);
            draw_control();
            draw_bactr(robot);
            write_statu(house,robot,1);
            continue;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //���뻥������
        {
            clrmous(MouseX, MouseY);
            draw_react();
            nocombo();
            func_react(house,robot);
            draw_control();
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
        draw_floor_wood(cx1,cy1);
        switch((*house).mp1[i][j])
        {
            
            case 2:
                bar(cx1,cy1,cx2,cy2,BLACK);
                break;
            case 3:
                bar(cx1,cy1,cx2,cy2,BROWN);
                break;
            case 4:
                fill_circle((cx1+cx2)/2,(cy1+cy2)/2,20,PEACH_PUFF,BLACK);
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
                bar(cx1,cy1,cx2,cy2,YELLOW);     
                break;
            case 22:
                bar(cx1,cy1,cx2,cy2,GREEN);
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
        {3,2,6,6,2,6,6,6,2,6,6,6,2,0,0,0,0,0},
        {0,9,0,0,2,6,6,6,2,6,6,6,2,5,5,0,0,0},
        {0,9,0,0,9,0,0,6,2,0,0,6,2,5,5,18,0,0},
        {0,2,0,0,9,0,0,6,2,0,0,6,2,5,5,19,0,0},
        {2,2,0,0,9,0,0,6,2,0,0,6,2,5,5,0,0,0},
        {0,0,0,0,2,6,6,6,2,0,0,6,2,0,0,0,0,0},
        {4,4,0,0,2,2,2,2,2,10,11,2,2,0,0,0,0,6},
        {5,5,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,6},
        {5,5,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,6},
        {4,4,0,0,0,0,0,2,10,11,2,2,2,2,2,2,2,2},
        {0,0,0,4,4,0,6,2,0,0,0,0,0,6,6,6,6,6},
        {6,0,0,0,0,20,17,2,0,0,0,0,0,0,0,0,0,0},
        {6,0,0,5,5,15,16,2,0,0,0,0,0,0,0,0,0,6},
        {6,0,0,5,5,20,17,2,6,0,0,0,0,7,7,7,8,12},
        {6,0,0,5,5,15,16,2,6,0,0,0,0,7,7,7,8,13},
        {6,0,0,0,0,20,17,2,6,0,0,0,0,7,7,7,8,14},
        {0,0,0,4,4,0,6,2,0,0,0,0,0,0,0,0,0,6},
        {21,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0},
    };
    //0�ǵذ壬1�ǻ����ˣ�2��ǽ�ڣ�3������Ͱ��4�����ӣ�
    //5�����ӣ�6��һ��߶ȼҾߣ�7 8 12 13 14�Ǵ���9�����ţ�10�����ţ�11������
    //21�ǳ��׮��22������

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
    (*house).pm25=50; //��ʼ��������Ϣ

    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    {
        (*house).mp1[i][j]=mp1init[i][j];
        (*house).mpinit[i][j]=mp1init[i][j];
    }
}

void func_electr(HOUSE *house, ROBOT *robot)
{
    char value;
    int poscode;
    NODE mp,mto; //��������ж�����
    
    draw_bactr(robot);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,1);
        if(mouse_press(LB+57,UB+350,LB+217,UB+390)==1) //�Զ����
        {
            
            continue;
        }
        if(mouse_press(LB+57,UB+410,LB+217,UB+450)==1) //�ֶ����
        {
            nocombo();
            nocombo();
            charge(house,robot);
            continue;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //�������˵�
        {
            nocombo();
            return;
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
    }
}

void func_comfort(HOUSE *house, ROBOT *robot)
{
    char value;
    int poscode;
    NODE mp,mto; //��������ж�����

    draw_bactr(robot);
    write_statu(house,robot,2);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,2);
        if(mouse_press(LB+110,UB+355,LB+140,UB+385)==1) //�򿪹رտյ�����
        {
            if((*house).set) (*house).set=0;
            else (*house).set=1;
            nocombo();
            write_statu(house,robot,2);
            continue;
        }
        if(mouse_press(LB+167,UB+360,LB+187,UB+380)==1) //�����趨�¶�
        {
            if((*house).tempset<=10) continue;
            com_settemp(house,robot,-1);
            nocombo();
            write_statu(house,robot,2);
            continue;
        }
        if(mouse_press(LB+227,UB+360,LB+247,UB+380)==1) //����趨�¶�
        {
            if((*house).tempset>=40) continue;
            com_settemp(house,robot,1);
            nocombo();
            write_statu(house,robot,2);
            continue;
        }
        if(mouse_press(LB+37,UB+410,LB+127,UB+450)==1) //�������
        {
            com_dry(house,robot);
            continue;
        }
        if(mouse_press(LB+147,UB+410,LB+237,UB+450)==1) //���г���
        {
            com_clean(house,robot);
            continue;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //���ؿ������
        {
            nocombo();
            return;
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
    }
}

void func_clean(HOUSE *house, ROBOT *robot)
{
    NODE rubbish[4];
    char value;
    int *pnum=0;
    int poscode;
    NODE mp,mto; //��������ж�����

    draw_bactr(robot);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,1);
        if(mouse_press(LB+57,UB+350,LB+217,UB+390)==1) //��������
        {
            nocombo();
            nocombo();
            if(*pnum<3)
            {
                (*pnum)++;
                set_rub(pnum,rubbish,house);
                paintmp(house,robot);
            }
            continue;
        }
        if(mouse_press(LB+57,UB+410,LB+217,UB+450)==1) //ʰ������
        {
            nocombo();
            nocombo();
            while(1)
            {
                if(*pnum>0)
                {
                    col_rub(pnum,rubbish,house,robot);
                    paintmp(house,robot);
                    (*pnum)--;
                }
                else
                    break;
            }
            continue;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //����������
        {
            nocombo();
            return;
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
    }
}

void func_react(HOUSE *house, ROBOT *robot)
{
    char value;
    int poscode;
    NODE mp,mto; //��������ж�����

    draw_bactr(robot);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,3);
        if(mouse_press(LB+57,UB+350,LB+217,UB+390)==1) //�����������
        {
            
            continue;
        }
        if(mouse_press(LB+57,UB+410,LB+217,UB+450)==1) //�������ʶȽ���
        {
            
            continue;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //���ؿ������
        {
            nocombo();
            return;
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
    }
}

void func_move(HOUSE *house, ROBOT *robot)
{
    char value;
    int poscode;
    NODE mp,mto; //��������ж�����
    
    draw_bactr(robot);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,3);
        if(mouse_press(LB+57,UB+350,LB+217,UB+390)==1) //��������Ѳ�߹���
        {
            free_hang(house,robot);
            nocombo();
            continue;
        }
        if(mouse_press(LB+57,UB+410,LB+217,UB+450)==1) //�������ʶȽ���
        {
            
            continue;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //���뻷������
        {
            nocombo();
            return;
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
    }
}

void timepass(HOUSE *house, ROBOT *robot,int st)
{
    /*******�ϻ�����*******/
    char *s;
    /*bar(0,0,150,60,MARINE_BLUE);
    itoa(house).time,s,10);
    outtextxy(0,0,s,1,2,10,WHITE);*/
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
        charge(house,robot);
    }
    (*house).time%=timecut;
    ((*house).time)++; 
}