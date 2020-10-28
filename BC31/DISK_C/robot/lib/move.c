/*
    move.c

	Initial version: 2020.10.24
    Lastest update: 2020.10.24
    Author: mfp
*/
#include "headers.h"

void move(HOUSE *house, ROBOT *robot,char dir) //移动机器人
{
    int dx,dy,nx,ny;
    switch(dir) //判断移动方向
    {
        case 'u': dx=-1; dy=0; break;
        case 'd': dx=1; dy=0; break;
        case 'l': dx=0; dy=-1; break;
        case 'r': dx=0; dy=1; break;
        default: break;
    }
    nx=(*robot).px+dx, ny=(*robot).py+dy;
    //fprintf(fpde,"1 %d %d\n",nx,ny);
    if(nx>=0 && nx<N && ny>=0 && ny<N && 
        pd_pass((*house).mp1[nx][ny]))
    {
        (*house).mp1[(*robot).px][(*robot).py]=
            (*house).mpinit[(*robot).px][(*robot).py];
        (*robot).px=nx, (*robot).py=ny;
        (*house).mp1[(*robot).px][(*robot).py]=1;
    }
    (*robot).rt=dir;
}

void moveupdate(HOUSE *house,ROBOT *robot,char value) //移动更新函数
{
    if(value=='W'||value=='w') //向上运动
    {
        move(house,robot,'u'); //移动机器人
        paintmp(house,robot); //重新绘制地图
        clrmous(MouseX, MouseY);
        return;
    }    
    else if(value=='S'||value=='s') //向下运动
    {
        move(house,robot,'d');
        paintmp(house,robot);
        clrmous(MouseX, MouseY);
        return;
    }
    else if(value=='A'||value=='a') //向左运动
    {
        move(house,robot,'l');
        paintmp(house,robot);
        clrmous(MouseX, MouseY);
        return;
    }
    else if(value=='D'||value=='d') //向右运动
    {
        move(house,robot,'r');
        paintmp(house,robot);
        clrmous(MouseX, MouseY);
        return;
    }
}

int getposition(int x,int y)
{
    int by=24,bx=15,len=40,sn=18;
    int retcode;
    retcode=((y-by)/len)*sn+(x-bx)/len;
    return retcode;
}

int pd_pass(int mp)
{
    if(mp==0) return 1;
    if(mp==3) return 1;
    /*if(mp==9) return 1;
    if(mp==10) return 1;
    if(mp==11) return 1;*/
    if(mp==21) return 1;
    if(mp==22) return 1;
    if(mp==23) return 1;
    if(mp==24) return 1;
    if(mp==25) return 1;
    if(mp==26) return 1;
    return 0;
}

void free_hang(HOUSE *house, ROBOT *robot)
{
    NODE pos0, pos1, pos2, pos3, pos4, pos5, pos6, pos7;
    FILE *fpde3;
    fpde3=fopen("debug\\debug3.txt","w");
    pos0.x=(*robot).px, pos0.y=(*robot).py;
    pos1.x=1, pos1.y=0;
    pos2.x=7, pos2.y=2;
    pos3.x=15, pos3.y=2;
    pos4.x=3, pos4.y=6;
    pos5.x=5, pos5.y=10;
    pos6.x=1, pos6.y=16;
    pos7.x=15, pos7.y=10;
    fill_rect(LB+17,UB+150,LB+257,UB+320,MISTY_ROSE,MISTY_ROSE);
    puthz(LB+37,UB+160,"自动巡逻中。。。",24,25,'K',BLACK);
    Astarmove(pos0,pos1,robot,house);
    Delaytime(1000);
    Astarmove(pos1,pos2,robot,house);
    Delaytime(1000);
    Astarmove(pos2,pos3,robot,house);
    Delaytime(1000);
    Astarmove(pos3,pos4,robot,house);
    Delaytime(1000);
    Astarmove(pos4,pos5,robot,house);
    Delaytime(1000);
    Astarmove(pos5,pos6,robot,house);
    Delaytime(1000);
    Astarmove(pos6,pos7,robot,house);
    Delaytime(1000);
    Astarmove(pos7,pos0,robot,house);
    Delaytime(1000);
    fill_rect(LB+32,UB+60,LB+257,UB+320,MISTY_ROSE,MISTY_ROSE);
    fclose(fpde3);
}

void get_conbot(HOUSE *house, ROBOT *robot)
{
    char value;
    if(mouse_press_circle(LB+137,UB+585,30)==1)
    {
        Delaytime(50);
        value='W';
        moveupdate(house,robot,value);
        return ;
    }
    if(mouse_press_circle(LB+137,UB+675,30)==1)
    {
        Delaytime(50);
        value='S';
        moveupdate(house,robot,value);
        return ;
    }
    if(mouse_press_circle(LB+92,UB+630,30)==1)
    {
        Delaytime(50);
        value='A';
        moveupdate(house,robot,value);
        return ;
    }
    if(mouse_press_circle(LB+182,UB+630,30)==1)
    {
        Delaytime(50);
        value='D';
        moveupdate(house,robot,value);
        return ;
    }
    return ;
}

void ope_door(HOUSE *house, ROBOT *robot)
{
    if(mouse_press(LB+80,UB+400,LB+100,UB+420)==1)
    {
        nocombo();
        if((*house).dor[0]) 
        {
            (*house).dor[0]=0;
            house->mp1[1][1]=23;
            house->mpinit[1][1]=23;
            house->mp1[2][1]=24;
            house->mpinit[2][1]=24;
            paintmp(house,robot);
        }
        else 
        {
            (*house).dor[0]=1;
            house->mp1[1][1]=9;
            house->mpinit[1][1]=9;
            house->mp1[2][1]=9;
            house->mpinit[2][1]=9;
            paintmp(house,robot);
        }
        clrmous(MouseX, MouseY);
        write_statu(house,robot,4);
    }
    if(mouse_press(LB+110,UB+400,LB+130,UB+420)==1)
    {
        nocombo();
        if((*house).dor[1]) 
        {
            (*house).dor[1]=0;
            house->mp1[2][4]=23;
            house->mpinit[2][4]=23;
            house->mp1[3][4]=24;
            house->mpinit[3][4]=24;
            paintmp(house,robot);
        }
        else 
        {
            (*house).dor[1]=1;
            house->mp1[2][4]=9;
            house->mpinit[2][4]=9;
            house->mp1[3][4]=9;
            house->mpinit[3][4]=9;
            paintmp(house,robot);
        }
        clrmous(MouseX, MouseY);
        write_statu(house,robot,4);
    }
    if(mouse_press(LB+140,UB+400,LB+160,UB+420)==1)
    {
        nocombo();
        if((*house).dor[2]) 
        {
            (*house).dor[2]=0;
            house->mp1[6][9]=25;
            house->mpinit[6][9]=25;
            house->mp1[6][10]=26;
            house->mpinit[6][10]=26;
            paintmp(house,robot);
        }
        else 
        {
            (*house).dor[2]=1;
            house->mp1[6][9]=10;
            house->mpinit[6][9]=10;
            house->mp1[6][10]=11;
            house->mpinit[6][10]=11;
            paintmp(house,robot);
        }
        clrmous(MouseX, MouseY);
        write_statu(house,robot,4);
    }
    if(mouse_press(LB+170,UB+400,LB+190,UB+420)==1)
    {
        nocombo();
        if((*house).dor[3]) 
        {
            (*house).dor[3]=0;
            house->mp1[7][13]=23;
            house->mpinit[7][13]=23;
            house->mp1[8][13]=24;
            house->mpinit[8][13]=24;
            paintmp(house,robot);
        }
        else 
        {
            (*house).dor[3]=1;
            house->mp1[7][13]=9;
            house->mpinit[7][13]=9;
            house->mp1[8][13]=9;
            house->mpinit[8][13]=9;
            paintmp(house,robot);
        }
        clrmous(MouseX, MouseY);
        write_statu(house,robot,4);
    }
    if(mouse_press(LB+200,UB+400,LB+220,UB+420)==1)
    {
        nocombo();
        if((*house).dor[4]) 
        {
            (*house).dor[4]=0;
            house->mp1[9][8]=25;
            house->mpinit[9][8]=25;
            house->mp1[9][9]=26;
            house->mpinit[9][9]=26;
            paintmp(house,robot);
        }
        else 
        {
            (*house).dor[4]=1;
            house->mp1[9][8]=10;
            house->mpinit[9][8]=10;
            house->mp1[9][9]=11;
            house->mpinit[9][9]=11;
            paintmp(house,robot);
        }
        clrmous(MouseX, MouseY);
        write_statu(house,robot,4);
    } 
}
void ope_wins(HOUSE *house, ROBOT *robot)
{
/*fill_rect(LB+80,UB+435,LB+100,UB+455,MISTY_ROSE,MARINE_BLUE);
        fill_rect(LB+110,UB+435,LB+130,UB+455,MISTY_ROSE,MARINE_BLUE);
        fill_rect(LB+140,UB+435,LB+160,UB+455,MISTY_ROSE,MARINE_BLUE);
        fill_rect(LB+170,UB+435,LB+190,UB+455,MISTY_ROSE,MARINE_BLUE);
        fill_rect(LB+200,UB+435,LB+220,UB+455,MISTY_ROSE,MARINE_BLUE);
*/
}
        