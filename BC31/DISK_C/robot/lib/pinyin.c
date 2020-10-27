#include "headers.h"

/*=======================
/*�������뷨*/
//�������뷨������ 
void hz_input(int x1,int y1,int x2,int y2,char *s,int len, int backcolor) 
{
	//int btnow,mark=1,i;
	int mark = 1, i;
	int ST=-1;//���뷨���ط�ʽ��1.��SPACE���������뺺�� 2.��ENTER����������Ӣ�� 3.�˸�����ز����� 
	char *image;
	char *p=s+len;
	int value=0;
	int asc;
	int xx1=x1+2,xx2=x2-2;//��ֹ������� 
	int L_maxwords=(xx2-xx1)/8,maxline=(y2-y1)/30;
	int Line=len/L_maxwords+1,L_len=len%L_maxwords,pylen;    //��ǰ��������Line����0�п�ʼ������ ���г��� L_len  pylenƴ������ //�п�30���� 
	int barx1,barx2,bary1,bary2;
	char str[3]={'\0','\0','\0'};//һ������װ�� 
	char py[20]={'\0','\0','\0','\0','\0','\0','\0','\0',
	            '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};//ƴ���ַ���(�����ַ���)
	
	MouseS = 2;
	while(bioskey(1))//������̻�����  ��ֹ������ 
		bioskey(0);        
	//Add_frame(xnow,ynow,x1,y1,x2,y2);
	if((image=malloc(8241))==NULL)
	{
		printf("error!");
		getch();
		exit(1);
	}
	while(1)
	{
		//mouse_control(xnow,ynow,&btnow,&mark);
		newmouse(&MouseX, &MouseY, &press);
		if(kbhit())
		{
			//redraw(*xnow,*ynow); 
			newmouse(&MouseX, &MouseY, &press);
			mark=0;
			value=bioskey(0);
			/*���������*/ 
		    switch(value)
			{
				case BACK_SPACE:
					if(L_len==0&&Line>1)//���д��� 
					{
						L_len=L_maxwords;
						Line--;
					}
					else if(L_len<=0&&Line==1) break;//ɾ������ �޷�ɾ�� 
					if(*(p-1)>31&&*(p-1)<127)
					{
						
						setfillstyle(1, backcolor);
						bar(xx1+L_len*8-8,y1+Line*30-28,xx1+L_len*8,y1+Line*30-2);
						p--;
						*p='\0';
						len--;
						L_len--;
					}
					else
					{
						setfillstyle(1, backcolor);
						bar(xx1+L_len*8-16,y1+Line*30-28,xx1+L_len*8,y1+Line*30-2);
						p-=2;
						p[0]='\0';
						p[1]='\0';
						len-=2;
						L_len-=2; 
					}
					break;
				case ENTER:
					//Add_frame(xnow,ynow,x1,y1,x2,y2);
					*p='\0';
					free(image);
					MouseS = 0;
					return;	//�������� 
				/*case TAB:
					//Add_frame(xnow,ynow,x1,y1,x2,y2);
					*p='\0';
					*tab=1;
					free(image);
					return len;	//��������*/
			}
			/*���뺺�����뷨*/ 
			asc=value&0xff;
			if(asc>=97&&asc<=122)
			{
				barx1=(x1+L_len*8-50>0)?(x1+L_len*8-50):0;       //�������뷨λ��  �����������Ͻ��Ҳ������Ļ 
	    		barx2=(barx1+200<640)?(barx1+200):(barx1=440,640);
				bary1=y1+Line*30+10;
				bary2=(bary1+40<480)?(bary1+40):(bary1=y1+Line*30-80,bary1+40);
				clrmous(MouseX, MouseY);
				getimage(barx1,bary1,barx2,bary2,image);
				pyFrm(barx1,bary1,barx2,bary2);
				//ST=input_method(barx1,bary1,xnow,ynow,str,value,py);
				ST=input_method(barx1,bary1,str,value,py);
				switch(ST)
				{
					case 1://�����ּ���ո���˳����뷨  ���뺺��
					    if(strlen(str))//�����ַ�������Ϊ�� 
						{
							if(L_len+1>=L_maxwords&&Line<maxline)//�������� 
							{
								/*�ÿո��������λ����ת����һ��*/
								if(L_len+1==L_maxwords)
								{
									*p=' ';
									p++;
									len++;
								}	
								Line++;
								L_len=0;
							}
							else if((L_len+1>=L_maxwords&&Line==maxline)||Line>maxline)//�޷����� 
							{
								putimage(barx1, bary1, image, COPY_PUT);//putimage(barx1,bary1,barx2,bary2,image);
								break;
							}
							strcpy(p,str);
							puthz(xx1+L_len*8,y1+Line*30-23,str,16,16,WHITE);
							p+=2;
					    	len+=2;
							L_len+=2;
						}
						putimage(barx1, bary1, image, COPY_PUT);//putimage(barx1,bary1,barx2,bary2,image); 
					    break;
					case 2://�ɻس����˳����뷨 ���������ģ� 
						pylen=strlen(py); 
					    if((L_len+pylen>L_maxwords&&Line==maxline)||(Line>maxline))//λ������ 
						{
							putimage(barx1, bary1, image, COPY_PUT);//putimage(barx1,bary1,barx2,bary2,image);
							break;
						}
						else if(L_len+pylen>L_maxwords&&Line<maxline)//�������� ���� 
						{
							for(i=0;i<L_maxwords-L_len;i++)
							{
								p[i]=' ';
							}
							p+=L_maxwords-L_len;
							len+=L_maxwords-L_len;
							Line++;
							L_len=0;
						}
						putimage(barx1, bary1, image, COPY_PUT);//putimage(barx1,bary1,barx2,bary2,image);
						setcolor(backcolor);
						outtextxy(xx1+L_len*8,y1+Line*30-21,py); 
						strcpy(p,py);
						len+=pylen;
						p+=pylen;
						L_len+=pylen;
					    break;
					case 3://����ɾ��Ϊ0�Զ��˳����뷨  ������
						putimage(barx1, bary1, image, COPY_PUT);//putimage(barx1,bary1,barx2,bary2,image); 
					    break;	 
				} 
				value=0;
				ST=-1;
			}
			else if(asc>31&&asc<127)//�ַ����� 
			{
				py[0]=asc;
				if(L_len+1<=L_maxwords&&Line<=maxline)//�������� 
				{
					*p=asc;
				}
				else if(Line+1<=maxline)//��������
				{
					*p=' ';
					Line++;
					L_len=0;
				}
				else
				{
					continue;
				}
				p++;
				len++;
				setcolor(WHITE);
				outtextxy(xx1+L_len*8,y1+Line*30-21,py);
				L_len++;
			}
			memset(py,'\0',20);
			memset(str,'\0',3);
		}
		//if((*xnow<x1||*xnow>x2||*ynow<y1||*ynow>y2)&&btnow)
		if((MouseX<x1||MouseX>x2||MouseY<y1||MouseY>y2)&&press == 1)
		{
			//Add_frame(xnow,ynow,x1,y1,x2,y2);
			*p='\0';
			free(image);
			MouseS = 0;
			return;
		}
	}
}

/*�������뷨���뺯��*/
int input_method(int x,int y,char *str,int value,char *py) 
{
	FILE *fp=NULL,*oldfp=NULL;
	//int btnow,mark,fJudge=FAIL;
	int mark,fJudge=0;
	char *p=py;
	int trigger=1;//����ʱ���������־ 
	char temphz[5][3]={{'\0','\0','\0'},{'\0','\0','\0'},
	                   {'\0','\0','\0'},{'\0','\0','\0'},
					   {'\0','\0','\0'}},temp[3];
	int fposition=0;
	int hznow=0,hznum=0;
	int asc,i;
	int PyStartx=x+8,PyStarty=y+4;
	int HzStartx=x+8,HzStarty=y+22;
	char *ABpath="pinyin\\";//����ƴ��������׼·�� 
	char pypath[45]={"pinyin\\"};//����ƴ���������·�� 
	while(1)
	{
		//mouse_control(xnow,ynow,&btnow,&mark);
		newmouse(&MouseX, &MouseY, &press);
		if(trigger||kbhit())//��һ�ν����Զ����� �Ժ������� 
		{
			//redraw(*xnow,*ynow); 
			mark=0;
			trigger=0;
			if(kbhit()) value=bioskey(0);
			asc=value&0xff;
			/*���ⰴ������*/
			switch(value)
			{
				case BACK_SPACE:
					p--;
					*p='\0';
					if(py[0]=='\0')
					{
						if(oldfp) fclose(oldfp);
						if(fp) fclose(fp);
						return 3;
					}
					break;
				case SPACE:
					strcpy(str,temphz[hznow]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case ENTER:
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 2;
				case LASTLINE:
					if(fposition>=8)//�������ض�λ�ļ�ָ��ǰ�˸��ֽڣ��ĸ����֣� 
					{
						fposition-=8;
					}
					break;
				case NEXTLINE:
					if(!feof(fp))//�������ض�λ�ļ�ָ���˸��ֽڣ��ĸ����֣�
					{
						fposition+=8;
					} 
					break;
				case LEFT://���ƶ�һ�� 
					if(hznow)
					{ 
						hznow--;
					}
					else if(fposition>=8)//��Ҫ��ҳ 
					{
						fposition-=8;
						hznow=3;
					}
					break;
				case RIGHT:
					if(hznow<hznum-1)//ͬ�� 
					{
						hznow++;
					}
					else if(!feof(fp))
					{
						fposition+=8;
						hznow=0;
					}
					break;
					/*�����ּ�ѡ�����뺺��*/ 
				case FIRST:
					strcpy(str,temphz[0]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case SECOND:
					strcpy(str,temphz[1]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case THIRD:
					strcpy(str,temphz[2]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case FOURTH:
					strcpy(str,temphz[3]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
			}
			/*�����ַ�����*/ 
			if(asc>31&&asc<127&&strlen(py)<20&&asc!='['&&asc!=']')    //��Ч����ʱ��λ 
			{ 
				*p=asc;
				p++;
				fposition=0;
				hznow=0;
			}
			pyFrm(x,y,x+200,y+40);
		    outtextxy(PyStartx,PyStarty-5,py);
		    strcat(pypath,py);
		    strcat(pypath,".txt");
		    if(fJudge) //����ǰ�ļ�ָ�뱣�� ͬʱ�ر���һ���ļ�  Ϊ���������ַ�׼�� 
			{
				if(oldfp)
				{
					fclose(oldfp);
				}
				oldfp=fp;
			}
		    if((fp=fopen(pypath,"r"))==NULL)//�����ַ�����  ������һ���ļ�������� 
		    {
		    	fJudge=0;
		    	fp=oldfp;
			}
			else 
			{
				fJudge=1;
			}
			if(fp)
			{
				fseek(fp,fposition,SEEK_SET);
		  		for(i=0;i<5;i++) 
		    	{
		    		fread(temphz[i],2,1,fp);//����һ������ 
		    		if(feof(fp))//�����ļ�β 
		    		{
		    			hznum=i;//������˴��ļ�β���һ�� ��Ҫ��һ  Ȼ���˴�����һ��Ч������ 
		    			break; 
					}
				}
				if(!feof(fp))//δ�����ļ�β ȫ�Ժ��� 
				{
					hznum=4;
				}
				for(i=0;i<hznum;i++)
				{
					setcolor(WHITE);
		   		    outtextxy(HzStartx+i*50,HzStarty-5,addnum(i+1,temp));
    				puthz(HzStartx+i*50+16,HzStarty,temphz[i],16,16,WHITE);
				} 
				puthz(HzStartx+hznow*50+16,HzStarty,temphz[hznow],16,16,YELLOW);//��ʾѡ�к��� 
			}			
		}
		strcpy(pypath,ABpath);          //����·����ԭ�������٣� 
		value=0;
	}
}

/*���ֱ�����*/ 
char *addnum(int a,char *s)
{
	switch(a)
	{
		case 1:
			strcpy(s,"1.");
			return s;
		case 2:
			strcpy(s,"2.");
			return s;
		case 3:
			strcpy(s,"3.");
			return s;
		case 4:
			strcpy(s,"4.");
			return s;
	}
}

/*���뷨С��*/ 
void pyFrm(int x1,int y1,int x2,int y2)
{
	bar(x1,y1,x2,y2,BLACK);
	line(x1+5,y1+20,x2-5,y1+20,BLACK);
	rectangle(x1,y1,x2,y2,WHITE);
}