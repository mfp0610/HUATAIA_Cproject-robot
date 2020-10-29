/*
    login.c

    Initial version: 2020.7.13
    Lastest update: 2020.9.12 
    Author: mfp & hhw
*/
#include "headers.h"

void start_func()
{
    USER *usr;
    //start_page();//������ʼ����
    
    while(1)
    {
        login_page(); //������¼����
        if(login_func(usr)) //�����¼����
            mainWindow(usr); //��������������
        else return;
    }
    return;
}

int login_func(USER *us)
{
    int flag;
    USER usr; //�û���Ϣ
    usr.user[0]='\0';
    usr.code[0]='\0';
    mouseinit();
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(180,350,500,400)==1) //�����˺�
            input(180,350,500,400,usr.user,15,0,0,WHITE);
        if(mouse_press(180,450,500,500)==1) //��������
            input(180,450,500,500,usr.code,15,1,0,WHITE);
        
        if(mouse_press(200,550,400,600)==1)
        {
			if (login_comp(usr.user, usr.code)) //��Ϣ��ȷ
            {
                clrmous(MouseX, MouseY);
                strcpy((*us).user,usr.user);
                return 1;
            }    
            else continue;
        }
        if(mouse_press(100,615,220,655)==1)
        {
            clrmous(MouseX, MouseY);
            register_page();
            nocombo();
            user_register();
            nocombo();
            continue;
        }
        if(mouse_press(380,615,500,655)==1)
        {
            clrmous(MouseX, MouseY);
            findback_page();
            nocombo();
            user_findback();
            nocombo();
            continue;
        }
        if(mouse_press(240,650,360,700)==1)
        {
            clrmous(MouseX, MouseY);
            exit_window();
            if(exit_pro()==1) return 0;
            nocombo();
            continue;
        }  
    }
}


void user_register()
{
    int f1=1, f2=1;
    USER usr; //�û���Ϣ
    char ver_cod[5]; //������֤��
    char ver_cod1[5]; //�����֤��
    usr.user[0]='\0';
    usr.code[0]='\0';
    usr.tel[0]='\0';
    ver_cod[0]='\0';
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(180,300,500,350)==1&&f2) //�����˺�
            input(180,300,500,350,usr.user,15,0,0,WHITE);
        if(mouse_press(180,375,500,425)==1&&f2) //��������
            input(180,375,500,425,usr.code,15,1,0,WHITE);
        if(mouse_press(220,450,500,500)==1&&f2) //����绰
            input(220,450,500,500,usr.tel,15,0,1,WHITE);
        if(mouse_press(220,525,360,575)==1&&f2) //������֤��
            input(220,525,360,575,ver_cod,15,0,1,WHITE);
        if(mouse_press(360,525,500,575)==1&&f1&&f2)
        {
            f1=0;
            random_vc(ver_cod1); //���������
            outtextxy(370,575,ver_cod1,2,2,32,BLACK); //��������
        }
        if(mouse_press(120,625,240,675)==1&&f2) //ע���ж�
        {
            if(register_func(usr.user,usr.code,usr.tel,ver_cod,ver_cod1))
            {
                f2=0;
                continue;
            }
            else continue;
        }
        if(mouse_press(360,625,480,675)==1)
        {
            clrmous(MouseX, MouseY);
            login_page();
            nocombo();
            return;
        }
    }
}

void user_findback()
{
    int f1=1, f2=1;
    USER usr; //�û���Ϣ
    char ver_cod[5]; //��֤��
    char ver_cod1[5]; //�����֤��
    char code[15]; //�һص�����
    usr.user[0]='\0';
    usr.code[0]='\0';
    usr.tel[0]='\0';
    ver_cod[0]='\0';
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(180,300,500,350)==1&&f2) //�����˺�
            input(180,300,500,350,usr.user,15,0,0,WHITE);
        if(mouse_press(220,375,500,425)==1&&f2) //����绰
            input(220,375,500,425,usr.tel,15,0,1,WHITE);
        if(mouse_press(220,450,360,500)==1&&f2) //������֤��
            input(220,450,360,500,ver_cod,15,0,1,WHITE);
        if(mouse_press(360,450,500,500)==1&&f1&&f2)
        {
            if (findback_func(usr.user,code,usr.tel)) //��֤�˺ź��ֻ���
            {
                f1=0;
                random_vc(ver_cod1); //���������
                bar(510,459,650,509,MISTY_ROSE);
                bar(230,510,450,590,MISTY_ROSE);
                outtextxy(510,459,ver_cod1,2,2,32,BLACK); //��������
            }
        }
        if(mouse_press(120,600,240,650)==1&&f2) //�һ������ж�
        {
            if (strcmp(ver_cod,ver_cod1)==0) //�ж���֤��
            {
                bar(230,510,450,590,MISTY_ROSE);
                outtextxy(230,535,code,2,2,20,BLACK);
                f2=0;
                continue;
            }
            else 
            {
                bar(230,510,450,590,MISTY_ROSE);
                puthz(230,535,"�������֤�����",24,25,'H',BLACK);   
                /*outtextxy(230,535,"error",2,2,20,BLACK);*/
                continue;
            }
        }
        if(mouse_press(360,600,480,650)==1)
        {
            clrmous(MouseX, MouseY);
            login_page();
            nocombo();
            return;
        }
    }
}

int exit_pro()
{
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(300,450,330,480)==1)
            return 1;
        if(mouse_press(470,450,500,480)==1)
        {
            clrmous(MouseX, MouseY);
            login_page();
            nocombo();
            return 0;
        }
    }
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

int login_comp(char *user, char *code)
{
	int state1 = 1;//�Ƿ�����ı���
	int state2 = 1;
	while (1)
	{
		judge(user, &state1);
		judge(code, &state2);
		if (state1 == 1 || state2 == 1)
			break;
		else if (state1 == 0 && state2 == 0)
		{
			if (judge_rightpassword(user, code))
				return 1;
			else
				break;
		}
	}
	return 0;
}

int judge_rightpassword(char *user, char *code)	
{
	int len;
	int i;
	FILE *fp;
	USER *u;
	if ((fp = fopen("data\\user.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserData.dat");
		Delaytime(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);//�ȶ��ļ�����
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			Delaytime(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(user, u->user) == 0)//�û���ƥ��
		{
			if (strcmp(code, u->code) != 0)//���벻��
			{
				bar(405,558,505,608,MISTY_ROSE);
                puthz(405,558,"�������",24,25,'H',BLACK);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(code, u->code) == 0)//����ƥ��
			{
				bar(405,558,505,608,MISTY_ROSE);
                puthz(405,558,"��¼�ɹ�",24,25,'H',BLACK);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				Delaytime(1000);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close Database");
					Delaytime(3000);
					exit(1);
				}
				return 1;
				//�л�����
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(405,558,"���˺Ų�����",24,25,'H',BLACK);//�ߵ����һλ
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		Delaytime(3000);
		exit(1);
	}
	return 0;
}

void judge(char *str, int *p)
{
    if (strlen(str) != 0)
    {
        *p = 0;
    }
}
