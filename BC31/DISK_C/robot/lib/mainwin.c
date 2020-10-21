/*
    mainwin.c

    Initial version: 2020.9.12
    Lastest update: 2020.9.12 
    Author: mfp
*/
#include "headers.h"

FILE *fpde;

void mainWindow()
{
    HOUSE *house;
    ROBOT *robot;

    int px, py;
    int mp1[N][N]; /*= {{0,2,6,6,2,6,6,6,2,6,6,6,2,0,0,0,0,0},
                     {0,9,0,0,2,6,6,6,2,6,6,6,2,5,5,0,0,0},
                     {0,9,0,0,9,0,0,6,2,0,0,6,2,5,5,4,0,0},
                     {0,2,0,0,9,0,0,6,2,0,0,6,2,5,5,4,0,0},
                     {2,2,0,0,9,0,0,6,2,0,0,6,2,5,5,0,0,0},
                     {0,0,0,0,2,6,6,6,2,0,0,6,2,0,0,0,0,0},
                     {4,4,0,0,2,2,2,2,2,10,11,2,2,0,0,0,0,6},
                     {5,5,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,6},
                     {5,5,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,6},
                     {4,4,0,0,0,0,0,2,10,11,2,2,2,2,2,2,2,2},
                     {0,0,0,4,4,0,6,2,0,0,0,0,0,6,6,6,6,6},
                     {6,0,0,0,0,4,4,2,0,0,0,0,0,0,0,0,0,0},
                     {6,0,0,5,5,4,4,2,0,0,0,0,0,0,0,0,0,6},
                     {6,0,0,5,5,4,4,2,6,0,0,0,0,7,7,7,7,7},
                     {6,0,0,5,5,4,4,2,6,0,0,0,0,7,7,7,7,7},
                     {6,0,0,0,0,4,4,2,6,0,0,0,0,7,7,7,7,7},
                     {0,0,0,4,4,0,6,2,0,0,0,0,0,0,0,0,0,6},
                     {0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0}};*/
                        //1�ǵذ壬2��ǽ�ڣ�3���ţ�4�����ӣ�
                        //5�����ӣ�6��һ��߶ȼҾߣ�78�Ǵ���9�����ţ�10�����ţ�11������
    char value, value1;
    int lb=750,ub=0;

    house=(HOUSE *)malloc(sizeof(HOUSE));
    robot=(ROBOT *)malloc(sizeof(ROBOT));

    maininit(house,robot);
    
    fpde=fopen("debug\\debug.txt","w");

    clrmous(MouseX, MouseY);
    memset(mp1,0,sizeof(mp1));
    drawbasic();
    
    //����ʹ��
    
    mp1[4][1]=2;
    mp1[4][2]=2;
    mp1[6][3]=2;
    mp1[6][4]=2;
    mp1[9][11]=2;
    mp1[9][12]=2;
    mp1[8][13]=2;
    mp1[8][14]=2;
    mp1[16][6]=2;
    mp1[16][7]=2;
    mp1[16][8]=2;
    mp1[16][9]=2;
    mp1[13][13]=7;
    mp1[13][14]=8;
    mp1[13][15]=8;
    mp1[13][16]=8;
    mp1[13][17]=8;
    mp1[14][13]=8;
    mp1[14][14]=8;
    mp1[14][15]=8;
    mp1[14][16]=8;
    mp1[14][17]=8;
    mp1[15][13]=8;
    mp1[15][14]=8;
    mp1[15][15]=8;
    mp1[15][16]=8;
    mp1[15][17]=8;
    
    px=9, py=0;

    paintmp(mp1,px,py,'d');
    draw_control();
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot);
        if(mouse_press(lb+37,ub+350,lb+127,ub+390)==1) //�����������
        {
            clrmous(MouseX, MouseY);
            draw_electr();
            nocombo();
            func_electr(house,robot);
            draw_control();
            continue;
        }
        if(mouse_press(lb+147,ub+350,lb+237,ub+390)==1) //�������ʶȽ���
        {
            clrmous(MouseX, MouseY);
            nocombo();
            draw_comfort();
            func_comfort(house,robot);
            draw_control();
            continue;
        }
        if(mouse_press(lb+37,ub+410,lb+127,ub+450)==1) //���뻷������
        {
            clrmous(MouseX, MouseY);
            nocombo();
            draw_clean();
            func_clean(house,robot);
            draw_control();
            continue;
        }
        if(mouse_press(lb+147,ub+410,lb+237,ub+450)==1) //������ƽ���
        {
            clrmous(MouseX, MouseY);
            nocombo();
            draw_move();
            func_move(house,robot);
            draw_control();
            continue;
        }
        /*if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //���뻥������
        {
            clrmous(MouseX, MouseY);
            draw_electr();
            nocombo();
            func_electr();
            draw_control();
            continue;
        }*/
        if(kbhit()) //moveupdate(value);
        {
            value=getch();
            if(value=='W'||value=='w') //�����˶�
            {
                fprintf(fpde,"1 %d %d\n",px,py);
                move(&px,&py,'u',mp1); //�ƶ�������
                paintmp(mp1,px,py,'u'); //���»��Ƶ�ͼ
                clrmous(MouseX, MouseY);
                continue;
            }    
            else if(value=='S'||value=='s') //�����˶�
            {
                fprintf(fpde,"1 %d %d\n",px,py);
                move(&px,&py,'d',mp1);
                paintmp(mp1,px,py,'d');
                clrmous(MouseX, MouseY);
                continue;
            }
            else if(value=='A'||value=='a') //�����˶�
            {
                fprintf(fpde,"1 %d %d\n",px,py);
                move(&px,&py,'l',mp1);
                paintmp(mp1,px,py,'l');
                clrmous(MouseX, MouseY);
                continue;
            }
            else if(value=='D'||value=='d') //�����˶�
            {
                fprintf(fpde,"1 %d %d\n",px,py);
                move(&px,&py,'r',mp1);
                paintmp(mp1,px,py,'r');
                clrmous(MouseX, MouseY);
                continue;
            }
        }
    }
    fclose(fpde);
    return;
}

void drawbasic()
{
    setbkcol(MISTY_ROSE);
    bar(750,0,1024,768,MARINE_BLUE);
    bar(800,200,900,300,MISTY_ROSE);
}

void paintmp(int (*mp)[N],int px,int py,char pdir)
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
        switch(mp[i][j])
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
    cy1=tx+px*sz, cx1=ty+py*sz;
    cy2=cy1+sz, cx2=cx1+sz;
    switch(pdir)
    {
        case 'u': drawrobot_back((cx1+cx2)/2,(cy1+cy2)/2,1); break;
        case 'd': drawrobot_front((cx1+cx2)/2,(cy1+cy2)/2,1); break;
        case 'l': drawrobot_left((cx1+cx2)/2,(cy1+cy2)/2,1); break;
        case 'r': drawrobot_right((cx1+cx2)/2,(cy1+cy2)/2,1); break;
        default: break;
    }
}

void move(int *px,int *py,char dir,int (*mp)[N])
{
    int dx,dy,nx,ny;
    switch(dir) //�ж��ƶ�����
    {
        case 'u': dx=-1; dy=0; break;
        case 'd': dx=1; dy=0; break;
        case 'l': dx=0; dy=-1; break;
        case 'r': dx=0; dy=1; break;
        default: break;
    }
    nx=(*px)+dx, ny=(*py)+dy;
    //fprintf(fpde,"2 %d %d\n",nx,ny);
    if(nx>=0 && nx<N && ny>=0 && ny<N && mp[nx][ny]!=2)
    {
        mp[*px][*py]=0;
        *px=nx, *py=ny;
        mp[*px][*py]=2;
    }
}

void maininit(HOUSE *house, ROBOT *robot)
{
    robot->electr=100;
    
    house->time=0;
    house->temp=26;
    house->wet=50;
    house->pm25=100;
}

void func_electr(HOUSE *house, ROBOT *robot)
{
    int lb=750, ub=0;
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(lb+57,ub+350,lb+217,ub+390)==1) //�����������
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+410,lb+217,ub+450)==1) //�������ʶȽ���
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //�������˵�
        {
            nocombo();
            return;
        }
    }
}


void func_comfort(HOUSE *house, ROBOT *robot)
{
    int lb=750, ub=0;
    while(1)
    {
        
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(lb+57,ub+350,lb+217,ub+390)==1) //�����������
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+410,lb+217,ub+450)==1) //�������ʶȽ���
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //���뻷������
        {
            nocombo();
            return;
        }
    }
}

void func_clean(HOUSE *house, ROBOT *robot)
{
    int lb=750, ub=0;
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(lb+57,ub+350,lb+217,ub+390)==1) //�����������
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+410,lb+217,ub+450)==1) //�������ʶȽ���
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //���뻷������
        {
            nocombo();
            return;
        }
    }
}

void func_move(HOUSE *house, ROBOT *robot)
{
    int lb=750, ub=0;
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(lb+57,ub+350,lb+217,ub+390)==1) //�����������
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+410,lb+217,ub+450)==1) //�������ʶȽ���
        {
            
            continue;
        }
        if(mouse_press(lb+57,ub+470,lb+217,ub+510)==1) //���뻷������
        {
            nocombo();
            return;
        }
    }
}

void timepass(HOUSE *house, ROBOT *robot)
{
    (house->time)++;
    (house->time)%=100000;
    if((house->time)%1000==0)
    {
        house->pm25++;
        robot->electr--;
    }
}