/*
    interface.c

    Initial version: 2020.7.13
    Lastest update: 2020.9.12
    Author: hhw
*/
#include "headers.h"

void start_func()
{
    USER *usr;
    start_page();//������ʼ����
    
    while(1)
    {
        login_page(); //������¼����
        if(login_func(usr)) //�����¼����
            mainWindow(usr); //��������������
        else return;
    }
    return;
}

void input(int x1,int y1,int x2,int y2, char *s, int max_len, int fp, int fn,int backcolor)
{
	char value;
	int length=strlen(s);
	int width=16;  //�ַ����
    int flag;
	line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, BLACK);//���ƹ��
	while(1)
	{
        int flag;
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press_out(x1,y1,x2,y2)==1)
        {
            s[length]='\0';
			line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, backcolor);	//���ǹ��
			break;
        }
        if(kbhit())
        {
            value=getch();
            if(value=='\n'||value=='\r') //�жϵ����»س�
            {
                s[length]='\0';
			    line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, backcolor);	//���ǹ��
			    break;
            }
		    else if(value=='\b')
		    {
			    clrmous(MouseX, MouseY);
                newmouse(&MouseX, &MouseY, &press);
                if(length==0) continue;
                line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, BLACK);	
			    bar(x1+5+width*(length-1), y1+3, x2, y2-3, backcolor);	//���ǹ������һ���ַ�
			    s[--length]='\0';
			    if(length+1<max_len) s[length+1]='\0';
			    line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, BLACK);  //���»��ƹ��
		    }
            //������ӿ�ͨ���������̬�޸Ĺ��ܣ�������
            /*else if(value==224)
            {
                value1=getch();
                if(value1==72||value1==80) continue;
                else if(value1==75) 
                else if(value1==77) 
            }*/
		    else if(length<max_len)
		    {
			    if(fn&&(value>'9'||value<'0')) continue; //�ж��Ƿ�Ҫ��ȫ����
                clrmous(MouseX, MouseY);
                newmouse(&MouseX, &MouseY, &press);
                line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, backcolor);	//���ǹ��
			    //�ж��Ƿ�Ϊ���룬����ǣ�����Ҫ����
                if(!fp) putEngletter(x1-4+width*length, y1+8, (int)(value), 2,2,BLACK);  //��ʾ�ַ�
			    else fill_circle(x1+16+width*length, (y1+y2)/2, 4,BLACK,BLACK); //��ʾСԲ��
			    s[length++]=value;
			    line(x1+5+width*length, y1+3, x1+5+width*length, y2-3, BLACK);	//���»��ƹ��
		    }
        }
	}
}

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
    puthz(187,90,"��ӭʹ�üҾӻ�����ģ��ϵͳ",48,50,'H',BLACK);
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
    puthz(108,459,"����",32,35,'K',WHITE);

    fill_rect(200,550,400,600,MARINE_BLUE,BLACK);
    puthz(254,558,"��¼",32,60,'K',WHITE); //����¼��ͼ

    fill_rect(100,615,220,655,MARINE_BLUE,BLACK);
    fill_rect(380,615,500,655,MARINE_BLUE,BLACK);
    puthz(110,623,"����ע��",24,25,'K',WHITE);
    puthz(390,623,"�һ�����",24,25,'K',WHITE);
    
    fill_rect(240,650,360,700,MARINE_BLUE,BLACK);
    puthz(250,663,"�˳�����",24,25,'K',WHITE); //���һغ�ע�����

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
    fill_rect(360,begposi+225,500,begposi+275,MARINE_BLUE,BLACK);
    puthz(108,begposi+9,"�˺�",32,35,'K',WHITE);
    puthz(108,begposi+84,"����",32,35,'K',WHITE);
    puthz(108,begposi+159,"�ֻ���",32,35,'K',WHITE); 
    puthz(108,begposi+234,"��֤��",32,35,'K',WHITE); 
    puthz(370,begposi+234,"����",32,35,'K',WHITE);//��ע���ͼ

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
    fill_rect(360,begposi+150,500,begposi+200,MARINE_BLUE,BLACK);
    puthz(108,begposi+9,"�˺�",32,35,'K',WHITE);
    puthz(108,begposi+84,"�ֻ���",32,35,'K',WHITE); 
    puthz(108,begposi+159,"��֤��",32,35,'K',WHITE);
    puthz(370,begposi+159,"����",32,35,'K',WHITE); //���һ������ͼ

    puthz(108,begposi+235,"�������룺",24,25,'K',MARINE_BLUE);

    fill_rect(120,begposi+300,240,begposi+350,MARINE_BLUE,BLACK);
    fill_rect(360,begposi+300,480,begposi+350,MARINE_BLUE,BLACK);
    puthz(130,begposi+313,"�һ�����",24,25,'K',WHITE);
    puthz(370,begposi+313,"���ز˵�",24,25,'K',WHITE); //���һغ�ע�����
}

void exit_window()
{
    int begposi=200;

    fill_rect(200,begposi,600,begposi+300,WHITE,BLACK);
    fill_rect(300,begposi+250,330,begposi+280,MARINE_BLUE,BLACK);
    fill_rect(470,begposi+250,500,begposi+280,MARINE_BLUE,BLACK);
    puthz(267,begposi+100,"ȷ���˳���������",32,35,'K',BLACK);
    puthz(305,begposi+255,"��",24,25,'K',WHITE);
    puthz(475,begposi+255,"��",24,25,'K',WHITE); //���˳�����
}