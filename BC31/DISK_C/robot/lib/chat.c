/*
    chat.c
    
    Adapted by pervious version
    Initial version: 2020.10.27
    Lastest update: 2020.10.27
    Author: mfp
*/
#include "headers.h"

int func_react(HOUSE *house, ROBOT *robot, USER *usr)
{
    char value;
    int poscode;
    NODE mp,mto; //��������ж�����
    
    int mode=0;
    Coordinate currentlu={IX+5,IY+WIDTH1+WIDTH2+5}; //�ı���������Ͻ�����
	Area txt_area={{IX+5,IY+WIDTH1+WIDTH2+5},{IX+LENGTH-5,IY+WIDTH1+WIDTH2+WIDTH3-5}}; //�ı����������
	int *qhwh=(int*)malloc(sizeof(int)*MAXTXT); //����λ��
    int flag;

    draw_bactr(robot);
    write_statu(house,robot,3);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,usr,3);
        if(mode==0)
        {
            puthz(IX+25,IY-140,"��ã��������",24,25,'K',BLACK);
            puthz(IX+25,IY-110,"�Ҿӻ�����С�ơ�",24,25,'K',BLACK);
            puthz(IX+10,IY-70,"���ĵ�ʲô�أ�",32,32,'K',BLACK);
        }
        else if(mode==1)
        {
            flag=0;
            bar(IX,IY,IX+LENGTH,IY+WIDTH1,LIGHT_GRAY); //ƴ����ʾ��
            bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY); //���뷨������ʾ��
            bar(IX,IY+WIDTH1+WIDTH2,IX+LENGTH,IY+WIDTH1+WIDTH2+WIDTH3,LIGHT_GRAY); //�ı������
            Init_qhwh(qhwh);
            flag=ShowChTab(txt_area,currentlu,16,qhwh,house,robot,usr,&mode);
            if(flag==0) 
            {
                free(qhwh);
                return 1;
            }
            if(flag==1) c_reply1(qhwh);
            if(flag==2) continue ;
            if(flag==3)
            {
                nocombo();
                free(qhwh);
                return 0;
            }
        }
        else if(mode==2)
        {
            flag=0;
            bar(IX,IY,IX+LENGTH,IY+WIDTH1,LIGHT_GRAY); //ƴ����ʾ��
            bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY); //���뷨������ʾ��
            bar(IX,IY+WIDTH1+WIDTH2,IX+LENGTH,IY+WIDTH1+WIDTH2+WIDTH3,LIGHT_GRAY); //�ı������
            Init_qhwh(qhwh);
            flag=ShowChTab(txt_area,currentlu,16,qhwh,house,robot,usr,&mode);
            if(flag==0)
            {
                free(qhwh);
                return 1;
            }
            if(flag==1) c_reply1(qhwh);
            if(flag==2) continue ;
            if(flag==3)
            {
                nocombo();
                free(qhwh);
                return 0;
            }
        }
        if(mouse_press(LB+37,UB+410,LB+127,UB+450)==1) //��������ģʽ
        {
            nocombo();
            if(mode!=1) mode=1;
            else mode=0;
            clrmous(MouseX, MouseY);
            draw_react(usr,mode);
            draw_bactr(robot);
            write_statu(house,robot,3);
            continue;
        }
        if(mouse_press(LB+147,UB+410,LB+237,UB+450)==1) //��������ģʽ
        {
            nocombo();
            if(mode!=2) mode=2;
            else mode=0;
            clrmous(MouseX, MouseY);
            draw_react(usr,mode);
            draw_bactr(robot);
            write_statu(house,robot,3);
            continue;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //���ؿ������
        {
            nocombo();
            free(qhwh);
            return 0;
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
        {
            free(qhwh);
            return 1;
        }
    }
}

void c_reply1(int *qhwh/*,int */)
{
	int show_y;
	char *order=(char *)malloc(30*sizeof(char)); //֮���ǵ��ļ��е��ʾ䲿��
	char *reply=(char *)malloc(30*sizeof(char)); //֮���ǵ��ļ��еĴ�䲿��
	char *incode=(char *)malloc(30*sizeof(char)); //�û��������������
	char str1[30];
	char str2[30];

	if(order==NULL)
	{
        puthz(0,0,"�ڴ����ʧ��",16,16,'H',STRONG_RED);
		getch();
		exit(1);
	}
	if(reply==NULL)
	{
        puthz(0,0,"�ڴ����ʧ��",16,16,'H',STRONG_RED);
		getch();
		exit(1);
	}
	if(incode==NULL)
	{
        puthz(0,0,"�ڴ����ʧ��",16,16,'H',STRONG_RED);
		getch();
		exit(1);
	}
	
	get_str(qhwh,incode); //��qhwhת�������ִ���incode����
	strcpy(str1,incode);
	reply_match(incode,order,reply); //���û�����Ϣ���ļ���洢����Ϣ���жԱȲ��õ��ظ�
	strcpy(str2,reply);
	bar(IX,IY-WIDTH4,IX+LENGTH,IY,MISTY_ROSE); //�������ʾ����

	show_incode(str1,&show_y); //���û��������Ϣ��ӡ�������
	show_reply(str2,show_y);

	free(order), order=NULL;
	free(reply), reply=NULL;
	free(incode), incode=NULL; //�ͷſռ�
}

int reply_match(char *str,char *order,char *reply)
{
    FILE *fp; //�����ļ�ָ��
    int f=0; //��Ϊ�ж����ݣ�ƥ��ɹ���1��ʧ����0
    fp=fopen("chat\\match.txt","rt");
    if(fp==NULL)
    {
        puthz(0,0,"ƥ���ļ��򿪴���",32,32,'H',STRONG_RED);
        exit(1);
    }
    rewind(fp);
    while(feof(fp)==0)
    {
        fscanf(fp,"%s",order);
        fscanf(fp,"%s",reply);
        if(strcmp(order,str)==0)
        {
            f=1;
            fclose(fp);
            return;
        }
    }
    if(f==0)
        strcpy(reply,"��Ǹ���Ҳ�������˵����ʲô");
    fclose(fp);
}

/*int make_ques(char *question,char *answer)
{
    FILE *game;
    int tm; //����ȷ������ѡ������
    int i=0; //�����ʱѡ������

    srand((unsigned)(time(NULL))); //�����������
    tm=rand()%10;
    game=fopen("BGI\\game.txt","r");
    if(game==NULL)
    {
        printf("the file cant open \n");
        exit(1);
    }
    rewind(game); //ʹָ��ָ���ļ����Ŀ�ͷ
    while(feof(game)==0) //���ļ���ȡ��ϻ��������ѡ��������ʱ
    {	
        fscanf(game,"%s",question);
        fscanf(game,"%s",answer);
        if(i==tm) break;
        i++;
    }
    fclose(game);
    return tm;
}

int check_answer(char *incode,char *answer)
{
    if(strcmp(incode,answer)==0) return 1;
    return 0;
}

*/

void show_incode(char *incode,int *y)
{
	puthz(IX,IY-WIDTH4,"�û���",16,16,'K',BLACK);
	puthz(IX+48,IY-WIDTH4,incode,16,16,'K',BLACK);
	*y=IY-WIDTH4;
	*y=*y+20;
}

void show_reply(char *reply,int y)
{
	puthz(IX,y,"С�ƣ�",16,16,'K',BLACK);
	puthz(IX+48,y,reply,16,16,'K',BLACK);
}