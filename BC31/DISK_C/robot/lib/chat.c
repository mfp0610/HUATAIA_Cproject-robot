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
    
    Coordinate currentlu={IX+5,IY+WIDTH1+WIDTH2+5}; //�ı���������Ͻ�����
    Area txt_area={{IX+5,IY+WIDTH1+WIDTH2+5},{IX+LENGTH-5,IY+WIDTH1+WIDTH2+WIDTH3-5}}; //�ı����������
    int *qhwh=(int*)malloc(sizeof(int)*MAXTXT); //����λ��
    char *incode=(char *)malloc(30*sizeof(char)); //�����������
    char *quest=(char *)malloc(30*sizeof(char)); //��������
    char *answer=(char *)malloc(30*sizeof(char)); //��������
    int flag, f1=2;
    int mode=0;
    int show_y=IY-245;

    FILE *fpde5;
    //fpde5=fopen("debug\\debug5.txt","w");

    draw_bactr(robot);
    write_statu(house,robot,3);
    clrmous(MouseX, MouseY);

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
            bar(IX,IY,IX+LENGTH,IY+WIDTH1,LIGHT_GRAY); //ƴ����ʾ��
            bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY); //���뷨������ʾ��
            bar(IX,IY+WIDTH1+WIDTH2,IX+LENGTH,IY+WIDTH1+WIDTH2+WIDTH3,LIGHT_GRAY); //�ı������
            //bar(IX,IY-WIDTH4,IX+LENGTH,IY,MISTY_ROSE); //�������ʾ����

            Init_qhwh(qhwh);
            flag=ShowChTab(txt_area,currentlu,16,qhwh,house,robot,usr,&mode);
            if(flag==0) 
            {
                free(qhwh);
                free(quest);
                free(answer);
                free(incode);
                return 1;
            }
            if(flag==1) 
                c_reply1(qhwh,&show_y);
            if(flag==2) continue ;
            if(flag==3)
            {
                nocombo();
                free(qhwh);
                free(quest);
                free(answer);
                free(incode);
                clrmous(MouseX, MouseY);
                return 0;
            }
        }
        else if(mode==2)
        {
            bar(IX,IY,IX+LENGTH,IY+WIDTH1,LIGHT_GRAY); //ƴ����ʾ��
            bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY); //���뷨������ʾ��
            bar(IX,IY+WIDTH1+WIDTH2,IX+LENGTH,IY+WIDTH1+WIDTH2+WIDTH3,LIGHT_GRAY); //�ı������
            //bar(IX,IY-WIDTH4,IX+LENGTH,IY,MISTY_ROSE); //�������ʾ����
            
            if(f1==2)
            {
                fpde5=fopen("debug\\debug5.txt","w");
                make_ques(quest,answer);
                fprintf(fpde5,"%s\n%s\n",quest,answer);
                fclose(fpde5);
                show_reply(quest,&show_y);
                Init_qhwh(qhwh);
                flag=ShowChTab(txt_area,currentlu,16,qhwh,house,robot,usr,&mode);
                if(flag==0)
                {
                    free(qhwh);
                    free(quest);
                    free(answer);
                    free(incode);
                    return 1;
                }
                if(flag==1)
                {
                    get_str(qhwh,incode);
                    show_incode(incode,&show_y);
                    f1=check_answer(incode,answer);
                    continue;
                }
                if(flag==2) continue ;
                if(flag==3)
                {
                    nocombo();
                    free(qhwh);
                    free(quest);
                    free(answer);
                    free(incode);
                    clrmous(MouseX, MouseY);
                    return 0;
                }
            }
            else if(f1==1)
            {
                show_reply("��ϲ�㣬�������",&show_y);
                f1=2;
                Delaytime(1000);
                continue;
            }
            else
            {
                show_reply("����ģ�����һ�Σ�",&show_y);
                show_reply("Ҳ�����롰��������һ��",&show_y);
                Init_qhwh(qhwh);
                flag=ShowChTab(txt_area,currentlu,16,qhwh,house,robot,usr,&mode);
                if(flag==0)
                {
                    free(qhwh);
                    free(quest);
                    free(answer);
                    free(incode);
                    return 1;
                }
                if(flag==1)
                {
                    get_str(qhwh,incode);
                    show_incode(incode,&show_y);
                    if(check_answer(incode,"����"))
                    {
                        f1=2;
                        continue;
                    }
                    f1=check_answer(incode,answer);
                    continue;
                }
                if(flag==2) continue ;
                if(flag==3)
                {
                    nocombo();
                    free(qhwh);
                    free(quest);
                    free(answer);
                    free(incode);
                    clrmous(MouseX, MouseY);
                    return 0;
                }
            }
        }
        if(mouse_press(LB+37,UB+410,LB+127,UB+450)==1) //��������ģʽ
        {
            nocombo();
            if(mode!=1)
            {
                bar(IX,IY-WIDTH4,IX+LENGTH,IY,MISTY_ROSE); //�������ʾ����
                show_y=IY-245;
                mode=1;
            }
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
            if(mode!=2)
            {
                bar(IX,IY-WIDTH4,IX+LENGTH,IY,MISTY_ROSE); //�������ʾ����
                show_y=IY-245;
                mode=2;
            }
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
            free(quest);
            free(answer);
            free(incode);
            clrmous(MouseX, MouseY);
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
                draw_cantgo();
            }
        }
        if(mouse_press(LB+140,UB+10,LB+250,UB+40)==1)
        {
            free(qhwh);
            free(quest);
            free(answer);
            free(incode);
            return 1;
        }
    }
}

void c_reply1(int *qhwh,int *show_y)
{
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
	
	show_incode(str1,show_y); //���û��������Ϣ��ӡ�������
	show_reply(str2,show_y); //�������˻ش����Ϣ��ӡ�������

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
        strcpy(reply,"��Ǹ���Ҳ�������˵ʲô");
    fclose(fp);
}

int make_ques(char *question,char *answer)
{
    FILE *game;
    int tm; //����ȷ������ѡ������
    int i=0; //�����ʱѡ������

    srand((unsigned)(time(NULL)));
    tm=rand()%100;
    game=fopen("chat\\zimi.txt","r");
    if(game==NULL)
    {
        puthz(0,0,"�ļ��򿪴���",32,32,'H',STRONG_RED);
        getch();
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

void show_incode(char *incode,int *y)
{
    int len=strlen(incode), line=1;
    int IY1=IY-5, WIDTHI=WIDTH4-10;
    unsigned int back[260][90];
    line=len/24+1;
    if(*y>=IY-5)
    {
        clrmous(MouseX, MouseY);
        get_image(IX,IY1-WIDTHI+line*20,IX+LENGTH,IY1-WIDTHI*2/3+line*20,*back);
        put_image(IX,IY1-WIDTHI,IX+LENGTH,IY1-WIDTHI*2/3,*back);
        get_image(IX,IY1-WIDTHI*2/3+line*20,IX+LENGTH,IY1-WIDTHI/3+line*20,*back);
        put_image(IX,IY1-WIDTHI*2/3,IX+LENGTH,IY1-WIDTHI/3,*back);
        get_image(IX,IY1-WIDTHI/3+line*20,IX+LENGTH,IY1,*back);
        put_image(IX,IY1-WIDTHI/3,IX+LENGTH,IY1-line*20,*back);
        bar(IX,IY1-line*20,IX+LENGTH,IY1,MISTY_ROSE);

        puthz1(IX,*y-line*20,"�û���");
	    puthz1(IX+48,*y-line*20,incode);
    }
    else
    {
        puthz1(IX,*y,"�û���");
	    puthz1(IX+48,*y,incode);
        *y+=(line*20);
    }
}

void show_reply(char *reply,int *y)
{
    int len=strlen(reply), line=1;
    int IY1=IY-5, WIDTHI=WIDTH4-10;
    unsigned int back[260][90];
    line=len/24+1;
    if(*y>=IY-5)
    {
        get_image(IX,IY1-WIDTHI+line*20,IX+LENGTH,IY1-WIDTHI*2/3+line*20,*back);
        put_image(IX,IY1-WIDTHI,IX+LENGTH,IY1-WIDTHI*2/3,*back);
        get_image(IX,IY1-WIDTHI*2/3+line*20,IX+LENGTH,IY1-WIDTHI/3+line*20,*back);
        put_image(IX,IY1-WIDTHI*2/3,IX+LENGTH,IY1-WIDTHI/3,*back);
        get_image(IX,IY1-WIDTHI/3+line*20,IX+LENGTH,IY1,*back);
        put_image(IX,IY1-WIDTHI/3,IX+LENGTH,IY1-line*20,*back);
        bar(IX,IY1-line*20,IX+LENGTH,IY1,MISTY_ROSE);

        puthz1(IX,*y-line*20,"С�ƣ�");
	    puthz1(IX+48,*y-line*20,reply);
    }
    else
    {
        puthz1(IX,*y,"С�ƣ�");
	    puthz1(IX+48,*y,reply);
        *y+=(line*20);
    }
}