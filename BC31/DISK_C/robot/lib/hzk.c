/*
    hzk.c

	Partly adapted by pervious version
    Initial version: 2020.7.13
    Lastest update: 2020.7.22
    Author: mfp
*/
#include "headers.h"

void puthz(int x,int y,char *s,int size,int part,int form,int color)
{
	FILE *hzk_p=NULL; //定义汉字库文件指针
	unsigned char qm,wm; //汉字的区码和位码
	unsigned long offset; //汉字在字库中的偏移量
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; //功能数组，用于显示汉字点阵中的亮点
	int i,j,pos;

	switch(size) //不同的size对应不同汉字库，实现了根据需求改变汉字的大小
	{		
		case 16 :
		{
			char mat[32]; //16*16-32byte
			int y0=y,x0=x;
			if(form=='F') hzk_p=fopen("HZK\\HZK16F","rb");
			else if(form=='H') hzk_p=fopen("HZK\\HZK16H","rb");
			else if(form=='K') hzk_p=fopen("HZK\\HZK16K","rb");
			else if(form=='S') hzk_p=fopen("HZK\\HZK16S","rb");
			if(hzk_p==NULL)
			{
				outtextxy(10,10,"Missing hzk16 file! Press any key to quit...",20,20,20,BLACK);
				getch();
				exit(1);
			}
			while(*s!=NULL)
			{
				while(x<1024-size&&(*s!=NULL))
				{
					y=y0;
					qm=s[0]-0xa0,wm=s[1]-0xa0; //求区码位码
					offset=(94*(qm-1)+(wm-1))*32L; //求出汉字在字库文件中的偏移量
					fseek(hzk_p,offset,SEEK_SET); //重定位文件指针
					fread(mat,32,1,hzk_p); //读出该汉字的点阵数据,1为要读入的项数
					for(i=0;i<16;i++)
					{
						pos=2*i; //16*16矩阵每行有2个外字节
						for(j=0;j<16;j++) //按行扫描，将1的点显示出来，每行16位
						{
							if((mask[j%8]&mat[pos+j/8])!=NULL) //j%8 0—8, j/8 0-1
								Putpixel64k(x+j,y,color);
						}
						y++;
					}
					x+=part; //给x一个偏移量
					s+=2; //汉字里存放的是内码，2个字节
				}
				x=x0, y0+=size+10; //一行汉字显示完后,重新从左侧开始输出汉字，给y一个偏移量
			}
			break;
		}

		case 24 :
		{
			char mat[72]; //24*24-72byte
			int y0=y,x0=x;
			if(form=='F') hzk_p=fopen("HZK\\HZK24F","rb");
			else if(form=='H') hzk_p=fopen("HZK\\HZK24H","rb");
			else if(form=='K') hzk_p=fopen("HZK\\HZK24K","rb");
			else if(form=='S') hzk_p=fopen("HZK\\HZK24S","rb");
			if(hzk_p==NULL)
			{
				outtextxy(10,10,"Missing hzk24 file! Press any key to quit...",20,20,20,BLACK);
				getch();
				exit(1);
			}
			while(*s!=NULL)
			{
				while(x<1024-size&&(*s!=NULL))
				{
					y=y0;
					qm=s[0]-0xa0,wm=s[1]-0xa0;
					offset=(94*(qm-1)+(wm-1))*72L;
					fseek(hzk_p,offset,SEEK_SET);
					fread(mat,72,1,hzk_p);
					for(i=0;i<24;i++)
					{
						pos=3*i; //16*16矩阵每行有3个外字节
						for (j=0;j<24;j++) //每行24位
						{
							if ((mask[j%8]&mat[pos+j/8])!=NULL)
								Putpixel64k(x+j,y,color);
						}
						y++;
					}
					x+=part;
					s+=2;
				}
				x=x0;y0+=size+10;
			}
			break;
		}

		case 32 :
		{
			char mat[128]; //32*32-128byte
			int y0=y,x0=x;
			if(form=='F') hzk_p=fopen("HZK\\HZK32F","rb");
			else if(form=='H') hzk_p=fopen("HZK\\HZK32H","rb");
			else if(form=='K') hzk_p=fopen("HZK\\HZK32K","rb");
			else if(form=='S') hzk_p=fopen("HZK\\HZK32S","rb");
			if(hzk_p==NULL)
			{
				outtextxy(10,10,"Missing hzk32 file! Press any key to quit...",20,20,20,BLACK);
				getch();
				exit(1);
			}
			while(*s!=NULL)
			{
				while(x<1024-size&&(*s!=NULL))
				{
					y=y0;
					qm=s[0]-0xa0,wm=s[1]-0xa0;
					offset=(94*(qm-1)+(wm-1))*128L;
					fseek(hzk_p,offset,SEEK_SET);
					fread(mat,128,1,hzk_p);
					for(i=0;i<32;i++)
					{
						pos=4*i; //32*32矩阵每行有4个外字节
						for(j=0;j<32;j++) //每行32位
							if((mask[j%8]&mat[pos+j/8])!=NULL)
								Putpixel64k(x+j,y,color);
						y++;
					}
					x+=part;
					s+=2;
				}
				x=x0, y0+=size+10;
			}
			break;
		}

		case 48:
		{
			char mat[288]; //48*48-288byte
			int y0=y,x0=x;
			if(form=='F') hzk_p=fopen("HZK\\HZK48F","rb");
			else if(form=='H') hzk_p=fopen("HZK\\HZK48H","rb");
			else if(form=='K') hzk_p=fopen("HZK\\HZK48K","rb");
			else if(form=='S') hzk_p=fopen("HZK\\HZK48S","rb");
			if(hzk_p==NULL)
			{
				outtextxy(10,10,"Can't open hzk48 file!Press any key to quit...",20,20,20,BLACK);
				getch();
				exit(1);

			}
			while(*s!=NULL)
			{
				while(x<1024-size&&(*s!=NULL))
				{
					y=y0;
					qm=s[0]-0xa0,wm=s[1]-0xa0;
					offset=(94*(qm-1)+(wm-1))*288L;
					fseek(hzk_p,offset,SEEK_SET);
					fread(mat,288,1,hzk_p);
					for(i=0;i<48;i++)
					{
						pos=6*i; //48*48矩阵每行有6个外字节
						for(j=0;j<48;j++) //每行48位
							if((mask[j%8]&mat[pos+j/8])!=NULL)
								Putpixel64k(x+j,y,color);
						y++;
					}
					x+=part;
					s+=2;
				}
				x=x0, y0+=size+10;
			}
			break;
		}

		default:break;
	}
	fclose(hzk_p);
}

void puthz1(int x,int y,char *s)
{
	FILE *hzk_p=NULL; //定义汉字库文件指针
	unsigned char qm,wm; //汉字的区码和位码
	unsigned long offset; //汉字在字库中的偏移量
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; //功能数组，用于显示汉字点阵中的亮点
	int i,j,pos;
    char mat[32]; //16*16-32byte
	int y0=y,x0=x;
    int size=16, part=16;
    int color=BLACK;

	hzk_p=fopen("HZK\\HZK16K","rb");
	if(hzk_p==NULL)
	{
		outtextxy(10,10,"Missing hzk16 file! Press any key to quit...",20,20,20,BLACK);
		getch();
		exit(1);
	}
	while(*s!=NULL)
	{
		while(x<1017-size&&(*s!=NULL))
		{
			y=y0;
			qm=s[0]-0xa0,wm=s[1]-0xa0; //求区码位码
			offset=(94*(qm-1)+(wm-1))*32L; //求出汉字在字库文件中的偏移量
			fseek(hzk_p,offset,SEEK_SET); //重定位文件指针
			fread(mat,32,1,hzk_p); //读出该汉字的点阵数据,1为要读入的项数
			for(i=0;i<16;i++)
			{
				pos=2*i; //16*16矩阵每行有2个外字节
				for(j=0;j<16;j++) //按行扫描，将1的点显示出来，每行16位
				{
					if((mask[j%8]&mat[pos+j/8])!=NULL) //j%8 0—8, j/8 0-1
						Putpixel64k(x+j,y,color);
				}
				y++;
			}
			x+=part; //给x一个偏移量
			s+=2; //汉字里存放的是内码，2个字节
		}
		x=x0, y0+=size+4;//一行汉字显示完后,重新从左侧开始输出汉字，给y一个偏移量
	}
	fclose(hzk_p);
}

void putEngletter(int x1,int y1,int ascii,int mx,int my,int color)
{
	char *English_save;
	int x0, y0, yt, xt, i=0, j=0, k=0;
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	unsigned long offest;
	FILE *fh;
	fh=fopen("HZK\\ASC16.DZK","rb");
   	if(fh==NULL)
	{
		printf("the asc can't open\n");
		getch();
		exit(1);
	}
   	English_save=(char *)malloc(32*sizeof(char));
   	if(English_save==NULL)
	{
		getch();
		exit(1);
	}

	offest=ascii*32l;
	fseek(fh,offest,0);
	fread(English_save,32,1,fh);
	fclose(fh);
	
	x0=x1, y0=y1;
	while(i<16) //输出英文字母
	{
		for(yt=0;yt<my;yt++)
		{
			for(j=0;j<2;j++)
			{
				for(k=0;k<8;k++)
				{
					for(xt=0;xt<mx;xt++)
					{
						if((English_save[2*i+j]&mask[k%8])!=0)
							Putpixel64k(x0,y0,color);
						x0++;
					}
				}

			}
			x0=x1, y0++;
		}
		i++;
	}
	free(English_save);
}

void outtextxy(int x,int y,char *c,int mx,int my,int part,int color)
{
	int a;
	char *p=c;
	while(*p!='\0')
	{
		a=(int)(*p);
		putEngletter(x,y,a,mx,my,color);
		p++, x+=part;
	}
}