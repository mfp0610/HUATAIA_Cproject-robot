/*
    pinyin.c
    
    Adapted by pervious version
    Initial version: 2020.10.27
    Lastest update: 2020.10.27
    Author: mfp
*/
#include "headers.h"

int Init_qhwh(int *qhwh)
{
	int i;
	for(i=0;i<MAXTXT;i++)
	{
		qhwh[i]=0;
	}
	return 0;
}


void SaveEnQhwh(FILE *fp,EN *en)//2
{
    int i=0;
    while(!feof(fp)&&i<120)
    {
        fscanf(fp,"%s",&(en[i].str));//��ȡ�ַ�??

        fscanf(fp,"%d",&(en[i].qhwh));//��ȡ����λ��

        i++;
    }
    fclose(fp);
}
void SaveChQhwh(FILE *fp,CH * ch)
{
    int i=0;
    while(!feof(fp)&&i<463)
    {
        fscanf(fp,"%s", ch[i].str );//��ȡ�ַ�
        fscanf(fp,"%d",&(ch[i].qhwh));//��ȡ����λ��
        i++;
    }
    fclose(fp);
}


int FindChQhwh(CH *ch,char *temp,int num_tab,int qhwh)//3
{
    int  i;
    //���ַ����бȶԣ��ҵ�����и�ֵ
    for(i=0;i<463;i++)
    {
        if(strncmp(temp,ch[i].str,num_tab)==0)
            {
                qhwh=ch[i].qhwh;
                break;
            }
    }
    return qhwh;
}

int FindEnQhwh(EN *en,char temp)//4
{
    int i,qhwh;
    //���ַ����бȶԣ��ҵ�����и�ֵ
    for(i=0;i<120;i++)
    {
        if(strncmp( &temp,en[i].str,1)==0)
            {
                qhwh=en[i].qhwh;
                break;
            }
    }
    return qhwh;
}

int CheckQhwhNum(int *qhwh)//11
{
    int num_qhwh=0,i=MAXTXT;
    while(i >= 1)
    {
        if(qhwh[i-1]== 0)
        {
            ++num_qhwh;
            --i;

        }
        else break;
    }

    return (MAXTXT-num_qhwh);
}

//��ɫ��LIGHT_GRAY�����
void CursorWhite
(
	Coordinate current_show_position,int show_size){
	bar(current_show_position.x,current_show_position.y,current_show_position.x+2,current_show_position.y+show_size,LIGHT_GRAY);
}

//��ɫ���
void CursorBlack
(
	Coordinate current_show_position,int show_size){
	bar(current_show_position.x,current_show_position.y,current_show_position.x+2,current_show_position.y+show_size,0);
}

void ClearKey(void)//2
{
	union REGS key;

	key.h.ah = 0x0c;
	key.h.al = 0x00;
	int86(0x21, &key, &key);
}

void DeleteShow(Area show_area,Coordinate * current_show_position,int show_size )//1
{	
	
	//��ʼ��real_rb_x��ʹ��ָ��λ
    int real_rb_x=((show_area.rb.x - show_area.lt.x)/show_size)*show_size + show_area.lt.x;
    //int real_rb_y=((show_area.rb.y - show_area.lt.y)/show_size)*show_size + show_area.lt.y;
    if(current_show_position->x>show_area.lt.x || current_show_position->y > show_area.lt.y)//�����Ƿ����ֵļ��
    {
		//��������������ٹ�겻������༴������ַ��ڹ��������൫���ڵ�һ�м��������ַ�
        if(current_show_position->x > show_area.lt.x )					//��
            current_show_position->x =current_show_position->x-show_size;	//��λ��ǰ��һ��
        else	//��
        {
            current_show_position->x = real_rb_x- show_size;		//x�Ƶ������ڶ�λ
            current_show_position->y = current_show_position->y- show_size;		//y�Ƶ���һ��
        }
    }
    ShowWhite( current_show_position, show_size);
}

int ShowPerCharacter(int qhwh,Area show_area,Coordinate * current_position,int color,int size,char *hzk_dir)//2
{
    int i=0,j=0,k=0;
    int x=current_position->x;
    int y=current_position->y;
    int real_rb_x= ((show_area.rb.x - show_area.lt.x)/size)*size + show_area.lt.x;

    FILE *hzk;//���庺�ֿ��ļ�ָ��
    char *hzk_file;//���庺�ֻ�������
    int width_byte=0;//�����ֽڳ���
    int qh=0,wh=0;//��������λ��
    unsigned char *bitmap;//����bmpָ�룬��������������
    long offset;//����ƫ����
    int size_read=0;//���庺�ֶ�ȡ��Ч����
    if(x==real_rb_x) x=x-size;

    if((hzk_file=(char *)malloc(sizeof(char)*512))==NULL)//�����̬����bmpָ���ڴ�ʧ�ܣ���ֱ�ӷ���
    {
		bar(0,0,1024,768,STRONG_RED);
		getch();
        exit(1);
    }

    if(size%4!=0&&size<=8)//�������̫С���߲���4�ı�������ֱ�ӷ���
    {
        bar(0,0,1024,768,STRONG_RED);
        exit(1);
    }
    else
    {
        size_read=((size+4)/8)*size;//��ʼ�����ֶ�ȡ��Ч����
    }

    sprintf(hzk_file,"%s\\HZK%dK",hzk_dir,size);//�Ѻ��ֿ������д�뺺�ֻ���������

    if((hzk=fopen(hzk_file,"rb"))==NULL)//������ֿ��ļ���Ϊ�գ���ֱ�ӷ���
    {
		puthz(0,0,"���ֿ��ȡʧ��",32,32,'H',STRONG_RED);
		getch();
        exit(1);
    }

    if((bitmap=(char *) malloc(sizeof(char)*size_read))==NULL)//�����̬����bmpָ���ڴ�ʧ�ܣ���ֱ�ӷ���
    {
		puthz(0,0,"�ڴ����ʧ��",32,32,'H',STRONG_RED);
		getch();
        exit(1);
    }

    qh=qhwh/100;//��ʼ������
    wh=qhwh%100;//��ʼ��λ��
    offset=(long) (94*((int) qh-1)+((int) wh-1))*size_read;//��ʼ��ƫ����

    fseek(hzk,offset,SEEK_SET);//����ƫ����Ѱ�Һ��ֿ�ĸú��ֵ�������
    fread(bitmap,sizeof(char),size_read,hzk);//��ȡ���ֿ��еĸú��ֵ�������

    width_byte=(size+4)/8;//�����ֽ������

    for(i=0;i<size;i+=1)
    {
        for(j=0;j<width_byte;j+=1)
        {
            for(k=0;k<8;k+=1)
            {
                if(GetBit(k+1,bitmap[i*width_byte+j])==1)//��������ص���Ҫ��ӡ
                {

                    Putpixel64k(x+j*8+k, y+i, color);

                }
            }
        }
    }
    CheckArea(show_area,current_position, size);
    free(hzk_file);
    free(bitmap);
	hzk_file = NULL;
	bitmap = NULL;
    fclose(hzk);
    return 0;
}

int CheckArea(Area area,Coordinate *current_position,int size)//4
{
    if( (current_position->x+size*2) <=area.rb.x)//�����ǰλ��x�᲻Խ���߽磬���ʼλ�ú���
    {
        current_position->x+=size;
    }

    else if( (current_position->y+size*2)<= area.rb.y )//�����ǰλ��y�᲻Խ���߽磬���ʼλ�û���
    {
        current_position->y+=size;
        current_position->x=area.lt.x;
    }
    else 
	{	
		current_position->x=((area.rb.x - area.lt.x)/size)*size + area.lt.x;	//stay where you are
	}
	return 0;
}

void DeleteTab(Coordinate * current_en_position,CH* ch,EN* en,char *temp ,int * num_tab,int *ch_qhwh)//3
{
    int en_qhwh,i;

    Area show_ch_area={ {IX,IY+WIDTH1} , {IX+LENGTH,IY+WIDTH1+WIDTH2} };
    Area show_en_area={ {IX,IY} , {IX+LENGTH,IY+WIDTH1} };
    Coordinate current_ch_position ={IX+5,IY+WIDTH1+5};
	bar(IX+5+16*(*num_tab-1),IY+5,IX+5+7*16,IY+5+30,LIGHT_GRAY);//ɾ���õ�bar

    --(*num_tab);		//ƴ������һ
	
    *ch_qhwh = FindChQhwh(ch,temp, *num_tab, *ch_qhwh);		//��num_tab����һ��֮�������ں��ֿ���Ѱ��ƥ��ֵ
    current_en_position->x=IX+5;		//
    current_en_position->y=IY+5;		//����Ӣ��������ʼλ��

	bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY);	//������뷨�����������
	//�������������Ϣ
    for(i=0;i<*num_tab;i++)
    {
        en_qhwh = FindEnQhwh(en,temp[i]);
        ShowPerCharacter(en_qhwh,show_en_area, current_en_position ,0x000000,16,"HZK");
    }

    for(i=0;i<5;i++)
    {
        ShowPerCharacter(217+i,show_ch_area,&current_ch_position,0x000000,16,"HZK");
        ShowPerCharacter((*ch_qhwh)+i,show_ch_area,&current_ch_position,0x000000,16,"HZK");
    }
}

int ShowChTab(Area show_area,Coordinate current_show_position/*�ı�����ĳ�ʼλ�õ����Ͻ�*/, 
    int show_size/*��48��36��28*/,int *qhwh, HOUSE *house, ROBOT *robot, USER *usr, int *mode)//7
{
    union
    {
        int key;
        char c[2];
    }u;
	Coordinate first_show_position = current_show_position;
    CH * ch=NULL;//���庺�ַ��Žṹ��
    EN * en=NULL;//����Ӣ�ķ��Žṹ��
    char temp[500],temp1;          //������ʱ��������
    int i,ch_qhwh,en_qhwh,num_tab=0,num_qhwh=0;
    FILE *hanzi;            //���庺�ַ����ļ�ָ��
    FILE *fuhao;            //����Ӣ�ķ����ļ�ָ��

    int poscode;
    NODE mp,mto; //��������ж�����

   Area show_ch_area={ {IX,IY+WIDTH1} , {IX+LENGTH,IY+WIDTH1+WIDTH2} };
    Area show_en_area={ {IX,IY} , {IX+LENGTH,IY+WIDTH1} };
    Coordinate current_ch_position ={IX+5,IY+WIDTH1+5};
    Coordinate current_en_position ={IX+5,IY+5};


    int real_rb_x= ((show_area.rb.x - show_area.lt.x)/show_size)*show_size + show_area.lt.x;	
	//��ʼ��real_rb_x�����ҵ����꣩��֮��������ֵ���ô�

    if( ( ch=(CH *)malloc(sizeof(CH)*463) )==NULL )//�����̬�����ڴ�ʧ�ܣ���ֱ�ӷ���
    {
		puthz(0,0,"�ڴ����ʧ��",32,32,'H',STRONG_RED);
		getch();
        return(1);
    }
    if( ( en=(EN *)malloc(sizeof(EN)*120) )==NULL )//�����̬�����ڴ�ʧ�ܣ���ֱ�ӷ���
    {
		puthz(0,0,"�ڴ����ʧ��",32,32,'H',STRONG_RED);
		getch();
        return(1);
    }

    if((hanzi = fopen("chat\\hanzi.txt","r")) == NULL)//hanzi��fuhao���ļ����
    {
		puthz(0,0,"�����ļ��򿪴���",32,32,'H',STRONG_RED);
		getch();
        return (1) ;
    }
    if((fuhao = fopen("chat\\fuhao.txt","r")) == NULL)
    {
		puthz(0,0,"�����ļ��򿪴���",32,32,'H',STRONG_RED);
		getch();
        return (1) ;
    }

    

    SaveChQhwh(hanzi,ch);	//	��ʼ����������⣬��hanzi.txt��ĺ�����Ϣȫ��һ����ת�Ƶ�ch����ṹ����ȥ
    SaveEnQhwh(fuhao,en);	//	��ʼ��Ӣ������⣬��fuhao.txt���Ӣ����ϢҲȫ��һ����ת�Ƶ�en����ṹ����ȥ

    num_qhwh=CheckQhwhNum(qhwh);//���㵱ǰ�ַ��������ܹ��м���qhwh������ַ������þ���֮�������������ӡ��ʱ����Ҫ
	//��ʼ�Ĺ��λ�ã����ı������λ��
    CursorBlack(current_show_position,show_size);//���Ϳ�ڣ��൱�ڳ��ֹ�꣩
    delay(400);
    CursorWhite(current_show_position,show_size);//���Ϳ�ף����ع�꣩���׼�BRIGHR_GREEN

    ClearKey();//������̻���

    draw_bactr(robot);
    write_statu(house,robot,3);
    while(1)//���밴��ѭ��
    {
        newmouse(&MouseX, &MouseY, &press);
        timepass(house,robot,usr,3);
        if(mouse_press(LB+37,UB+410,LB+127,UB+450)==1) //����Ĭ��ģʽ
        {
            nocombo();
            free(ch);
            free(en);
            fclose(hanzi);
            fclose(fuhao);
            ClearKey();
            if(*mode!=1) *mode=1;
            else *mode=0;
            clrmous(MouseX, MouseY);
            draw_react(usr,*mode);
            return 2;
        }
        if(mouse_press(LB+147,UB+410,LB+237,UB+450)==1) //��������ģʽ
        {
            nocombo();
            free(ch);
            free(en);
            fclose(hanzi);
            fclose(fuhao);
            ClearKey();
            if(*mode!=2) *mode=2;
            else *mode=0;
            clrmous(MouseX, MouseY);
            draw_react(usr,*mode);
            return 2;
        }
        if(mouse_press(LB+57,UB+470,LB+217,UB+510)==1) //���ؿ������
        {
            free(ch);
            free(en);
            fclose(hanzi);
            fclose(fuhao);
            ClearKey();
            return 3;
        }
        if(mouse_press(LB+140,UB+10,LB+250,UB+40)==1) //�������˵�
        {
            free(ch);
            free(en);
            fclose(hanzi);
            fclose(fuhao);
            ClearKey();
            return 0;
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
        
        if(!kbhit()) continue;
        u.key=bioskey(0);//��ȡ������Ϣ��key��int��

        /*if(u.c[1]==0x1) //����esc�˳�
        {
			//��λ
            free(ch);
            free(en);
            fclose(hanzi);
            fclose(fuhao);
            ClearKey();
            CursorWhite(current_show_position,show_size);//���Ϳ��
            return 3;
        }*/

		/**********
		��num_tab==0ʱ��
		������������
		����
		**********/
        if(u.c[1]==0x1c&& num_tab==0)//����س�������Ϣ
        {
            //归位
            free(ch);
            free(en);
			ch = NULL;
			en = NULL;
            fclose(hanzi);
            fclose(fuhao);
            ClearKey();
            CursorWhite(current_show_position,show_size);
            return 1;
        }

		
        else if(u.c[1]==0x48 && num_tab==0)//���� ������ϣ�UP�ϼ�
        {
            if(current_show_position.y>show_area.lt.y )		//	�ж�֮���Ƿ�����
            {
                num_qhwh=num_qhwh-(real_rb_x- show_area.lt.x)/show_size;	//num_qhwh��ȥ����һ�е��ַ���
                CursorWhite(current_show_position,show_size);
                current_show_position.y-=show_size;
                CursorBlack(current_show_position,show_size);
            }

        }

		
        else if(u.c[1]==0x50 && num_tab==0)//���� ������£�DOWN�¼���
        {
            if((current_show_position.y+2*show_size)<=show_area.rb.y)	//����*2����Ϊcurrent_show_position��λ��ʱ���Ͻǣ��ʵ��ж϶����������У�������һ�У��Ĳ���֮�󲻻����
            {
				num_qhwh=num_qhwh+(real_rb_x- show_area.lt.x)/show_size;	//num_qhwh��������һ�е��ַ���
                CursorWhite(current_show_position,show_size);
                current_show_position.y+=show_size;
                CursorBlack(current_show_position,show_size);
            }

        }

		
        else if(u.c[1]==0x4b&& num_tab==0)//���� �������LEFT��
        {
            if( current_show_position.x > show_area.lt.x || current_show_position.y>show_area.lt.y)//�ж���һ���������
            {
                CursorWhite(current_show_position,show_size);
                if(current_show_position.x > show_area.lt.x )//ȷ�Ϲ�겻�����Ƴ������
                    current_show_position.x = current_show_position.x-show_size;//��λ����һ����λ
                else
                {
					//�����Ƴ��������λ����һ���ַ���β
                    current_show_position.x =real_rb_x;
                    current_show_position.y =current_show_position.y-show_size;

                }
                --num_qhwh;//�������������num_qhwh����Ҫ��1���ɼ���LEFT��������
                CursorBlack(current_show_position,show_size);//��ʾ�����ڶ�λ�ĺ���
            }

        }
		//��y����Ҫ*2Ҳ��current)_show_position��λ�����Ͻ��ǵĻ��������ж���һ���ڲ��ڽ���
        else if(u.c[1]==0x4d&& num_tab==0)//���� ������ң�RIGHT��
		{
            if((current_show_position.x+show_size)<=real_rb_x|| (current_show_position.y+2*show_size)<=show_area.rb.y)//�?认现在定位在正确框�??
            {
                CursorWhite(current_show_position,show_size);
                if(current_show_position.x <= real_rb_x - show_size)//ȷ�ϻ������������ֵĶ�λ������һ�������ϵĿռ�
                    current_show_position.x =current_show_position.x+show_size;//��λ����һ����λ
                else
                {
					//�����Ƴ��������λ����һ���ַ����ף��ƺ�ֻ���������ϵ����뷽ʽ��Ч	//���ƣ�
                    current_show_position.x = show_area.lt.x;
                    current_show_position.y =current_show_position.y+show_size;

                }
                ++num_qhwh;
                CursorBlack(current_show_position,show_size);
            }

        }

        else if(u.c[1]==0xe && num_tab==0)//����ɾ������backspace����ɾ����λǰһ���ַ�
        {
            if(current_show_position.x>first_show_position.x || current_show_position.y>first_show_position.y)//如果不在�?一�?字的位置才可以进�?
			{
				CursorWhite(current_show_position,show_size);
				DeleteShow( show_area,& current_show_position, show_size );//������ڵ�һ���ֵ�λ�òſ��Խ���
				qhwh[num_qhwh-1]=0;//��ǰ�ַ�����λ����0
				--num_qhwh;//�ַ�������ȥ1
            }
			CursorBlack(current_show_position,show_size);
        }

        else if(u.c[1]==0x39&& num_tab==0&&num_qhwh<15)//����ո�
        {
            if((current_show_position.x+show_size)<=real_rb_x || (current_show_position.y+2*show_size)<=show_area.rb.y)
            {
                CursorWhite(current_show_position,show_size);
                if(current_show_position.x <= real_rb_x - show_size)//ȷ�ϻ������������ֵĶ�λ������һ�������ϵĿռ�
                    current_show_position.x =current_show_position.x+show_size;//ͼ���ϵĿո񣬵����ַ�����ƾ�ռ�һ
                else
                {
					//���˾ͳ�ʼ����������
                    current_show_position.x = show_area.lt.x;
                    current_show_position.y =current_show_position.y+show_size;

                }
                ++num_qhwh;//�ַ�����+1
                CursorBlack(current_show_position,show_size);
            }
        }


        else if(u.c[0]>='a'&& u.c[0]<='z'&&num_tab<6&&num_qhwh<15)//������ĸ��ע�� ������ƴ������ĸ
        {
            num_tab++;
            temp[num_tab-1]=(char) (u.c[0]);	//temp��������500���϶�����
            ch_qhwh = FindChQhwh(ch,temp, num_tab,ch_qhwh);		
			//ȥ�����������֮ǰ����õ�ch��������к������Ƚϣ��ҵ�Ŀ�꺺�֣�
			//����ʱ�кܶ�ƥ��ֵ�������ں����ȫ��put����
            en_qhwh = FindEnQhwh(en,temp[num_tab-1]);	//��Ӣ�Ŀ����ҵ��������ĸ��ֱ����ʾ����
            if(num_tab<=6)	//������ƴ���������6λ
            ShowPerCharacter(en_qhwh,show_en_area, &current_en_position ,0x000000,16,"HZK");	//�����Ȱ�ƴ������ĸ�����
            //Putbmp64k(589,633,"bmp\\part.bmp");		//���������뷨��ʾ��֮ǰ����������
			bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY);	
			
			
            current_ch_position.x = IX+5;	//�����λ���������ƥ��ĺ���
            current_ch_position.y = IY+WIDTH1+5;
            for(i=0;i<5;i++)	//һҳ��ʾ�������ֵ
            {
				//��ʾ���12345
                ShowPerCharacter(217+i,show_ch_area,&current_ch_position,0x000000,16,"HZK");
                //��ʾ���֣�ƴ����ͬ������������λ�����1
				ShowPerCharacter(ch_qhwh+i,show_ch_area,&current_ch_position,0x000000,16,"HZK");
            }

        }


        else if(u.c[1]==0xe && num_tab!=0)//tab�� ����ɾ������ɾ�����뷨tab��
        {
            DeleteTab(& current_en_position, ch, en, temp ,& num_tab,& ch_qhwh);
        }
		
	/* 	else if(u.c[1]==0x1c && num_tab!=0)
		{
			u.c[0]='1';
		}
		
		else if(u.c[1]==0x39&&num_tab!=0)
		{
			u.c[0]='1';
		} */


        else if(((u.c[1]==0x39||u.c[1]==0x1c)||(u.c[0]>='1'&&u.c[0]<='5'))&& num_tab!=0&&num_qhwh<15)//����1-5  ѡ���ַ�??
        {
			if(u.c[1]==0x39||u.c[1]==0x1c)
			{
				u.c[0]='1';
			}
            CursorWhite(current_show_position,show_size);
            ++num_qhwh;
            qhwh[num_qhwh-1]=ch_qhwh + u.c[0]-'1';	
			/***********************
			u.c[0]-'1'��ȡ�����͵��������֣�������ascii�룩��		//����ascii��ֵ���
			����ch_qhwh֮�����ָ�������뷨���еĵڼ���������
			***********************/

            ShowPerCharacter(qhwh[num_qhwh-1],show_area, &current_show_position,0x000000 , show_size,"HZK");	//����Ǵ�ӡ�����������
		    bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY);	
		    bar(IX,IY,IX+LENGTH,IY+WIDTH1,LIGHT_GRAY);	
			
			num_tab=0;	//ƴ����ĸ������
            current_ch_position.x = IX+5;	//���ֳ���λ�ù�λ
            current_ch_position.y = IY+WIDTH1+5;	
            current_en_position.x=IX+5;		//ƴ������λ�ù�λ
            current_en_position.y=IY+5;
            CursorBlack(current_show_position,show_size);	//��ɫ������³���

        }

        else if((u.c[1]==0x48/*UP*/||u.c[1]==0x4b||u.c[0]=='+'/*LEFT*/)&& num_tab!=0)//���� ���ϻ����� ��ҳ
        {
            ch_qhwh=ch_qhwh-5;		//���ֿ�����ǰ��������պ÷�ҳ
  			bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY);	
			
			current_ch_position.x = IX+5;	//���뷨������ʾ�����Ͻǵ�λ��
            current_ch_position.y = IY+WIDTH1+5;	
            for(i=0;i<5;i++)
            {
                ShowPerCharacter(217+i,show_ch_area,&current_ch_position,0x000000,16,"HZK");
                ShowPerCharacter(ch_qhwh+i,show_ch_area,&current_ch_position,0x000000,16,"HZK");
            }

        }

        else if((u.c[1]==0x50/*DOWN*/||u.c[1]==0x4d/*RIGHT*/||u.c[0]=='-') && num_tab!=0)//���� ���·�ҳ
        {
            ch_qhwh=ch_qhwh+5;		//���ֿ���������������պ÷�ҳ
            
            bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY);	
			
			current_ch_position.x = IX+5;
            current_ch_position.y = IY+WIDTH1+5;	
            for(i=0;i<5;i++)
            {
                ShowPerCharacter(217+i,show_ch_area,&current_ch_position,0x000000,16,"HZK");
                ShowPerCharacter(ch_qhwh+i,show_ch_area,&current_ch_position,0x000000,16,"HZK");
            }
        }
		
		else if(((u.c[0]==','||u.c[0]=='.'||u.c[0]=='?')||(u.c[0]>='0'&&u.c[0]<='9'))&&num_tab==0&&num_qhwh<15)//���ı���������0-9���ֻ��ߣ�����
        {
            temp1=(char) (u.c[0]);
            en_qhwh = FindEnQhwh(en,temp1);
            CursorWhite(current_show_position,show_size);
            ++num_qhwh;
            qhwh[num_qhwh-1]=en_qhwh;
            ShowPerCharacter(qhwh[num_qhwh-1],show_area, &current_show_position ,0x000000,show_size,"HZK");
            CursorBlack(current_show_position,show_size);

        }
		
		if(num_tab==0)
		{
			bar(IX,IY+WIDTH1,IX+LENGTH,IY+WIDTH1+WIDTH2,LIGHT_GRAY);
		}
    }
}

void ShowWhite(Coordinate * current_show_position,int show_size)
{
    int x,y,i,j,k;
    int width_byte=0;//�����ֽڳ���
    x=current_show_position->x;
    y=current_show_position->y;

    width_byte=(show_size+4)/8;//�����ֽ������

    for(i=0;i<show_size;i+=1)
    {
        for(j=0;j<width_byte;j+=1)
        {
            for(k=0;k<8;k+=1)
            {
               Putpixel64k(x+j*8+k, y+i, LIGHT_GRAY);
            }
        }
    }
}

int GetBit(int num,char ch)
{
    int i;
    int temp=1;
    for(i=0;i<8-num;i++)
    {
        temp*=2;
    }
    return (temp&ch)&&1;
}

void get_str(int *qhwh, char *incode)
{
	char *p=incode;	//incode��λ��ָ��
	int num_qhwh = CheckQhwhNum(qhwh);
	int i;
	
	for(i=0;i<num_qhwh;i++)
	{
		qhwh2incode(*qhwh,p);
		p+=2;
		qhwh++;
	}
	*p = '\0';
	
}

void qhwh2incode(int qwh,char *incode)
{
	char qh,wh;
	qh = (char)(qwh/100);
	wh = (char)(qwh%100);
	incode[0] = qh+0xa0;
	incode[1] = wh+0xa0;
}