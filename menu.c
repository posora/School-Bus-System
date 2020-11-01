#include"menu.h"
#include"public.h"
#include"track.h"
#include"visual.h"
#include"record.h"
#include"user.h"
/********************************** 
menu .c
COPYRIGHT:	shenlei
FUNCTION:	user login
ABSTRACT:
		A.menu for user
		B.menu for guest
DATE:2020/9/16
***********************************/

/*********************************************
FUNCTION:user_menu0
DESCRIPTION���û����滭ͼ����
INPUT:void
RETURN:void
***********************************************/

void user_menu0()//���û�����
{
	cleardevice();
	setbkcolor(CYAN);
	//clrscr();
	setfillstyle(1, WHITE);
	bar(0, 0, 80, 20);
	bar(80, 0, 160, 20);
	bar(160, 0, 240, 20);
	puthz(0,0,"��Ӽ�¼",16,17,RED);
	puthz(80,0,"�˳��켣",16,17,RED);
	puthz(160,0,"ͬ���γ˿�",16,17,RED);
	button_back();
}

/*********************************************
FUNCTION:user_menu1
DESCRIPTION���û��˵����ܺ���
INPUT:char* name
RETURN:0 or 5
***********************************************/

int user_menu1(char* name)//�û��˵�����ʵ��
{
	int state1 = 0;//�ж���Ӽ�¼�˵��Ƿ���չ��״̬
	int state2 = 0;//�ж�ͬ���γ˿Ͳ˵��Ƿ���չ��״̬
	int state3=0;//�ж���Ӽ�¼�ĳ������ĳ���
	int start=0;//�ж����
	int end=0;//�ж��յ�
	int state4=0;//�ж�Ҫ��ѯ����ʲô���εĳ˿���Ϣ
	char temp[1000];

	void* saveimage1 = (void *)malloc(imagesize(10, 20, 80, 80));
	void* saveimage2 = (void *)malloc(imagesize(170, 20, 240,100));
	void* saveimage3 = (void *)malloc(imagesize(10, 20, 80, 30));
	void* saveimage4 = (void *)malloc(imagesize(170, 20, 240, 30));
	user_menu0();
	clrmous(MouseX,MouseY);
	getimage(10, 20, 80, 80, saveimage1);
	getimage(170, 20, 240,100, saveimage2);
	getimage(10, 20, 80, 30, saveimage3);
	getimage(170, 20, 240,30, saveimage4);
	memset(temp,'\0',1000);

	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);//
		MouseS=0;
		//��Ӽ�¼
		if(MouseX>0&&MouseX<80&&MouseY>0&&MouseY<20)
		{
			if (mouse_press(0,0,80,20) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1, WHITE);
				bar(10, 20, 80, 80);
				puthz(10,20, "����һ",16,17,RED);
				puthz(10, 40, "���ζ�",16,17,RED);
				puthz(10,60, "������",16,17,RED);
				state1=1;
			}
			else if (mouse_press(0, 0, 80, 20) == 2)
			{
				continue;
			}
		}
		//��ʾ�켣
		else if(MouseX>80&&MouseX<160&&MouseY>0&&MouseY<20)
		{
			if ((mouse_press(80, 0,160, 20) == 1) && (state3 != 0) && (start != 0) && (end != 0))
			{
				judge_visual(state3,start,end);
				record(name,state3,start,end,temp);
				free(saveimage1);
				free(saveimage2);
				free(saveimage3);
				free(saveimage4);
				return 5;
			}
			else if (mouse_press(80,0,160,20) != 1)
			{
				continue;
			}
		}
		//�˳����ι����˿Ͳ�ѯ
		else if (MouseX > 160 && MouseX < 240 && MouseY>0 && MouseY < 20)
		{
			if (mouse_press(160, 0, 240, 20) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(170, 20, 240, 80);
				puthz(170, 20, "����һ", 16, 17, RED);
				puthz(170, 40, "���ζ�", 16, 17, RED);
				puthz(170, 60, "������", 16, 17, RED);
				state2 = 1;
			}
			else if (mouse_press(80, 0, 160, 20) != 1)
			{
				continue;
			}
		}
		else if (state1 == 1&& MouseX > 0 && MouseX < 80 && MouseY>20 && MouseY < 80)//ѡ�񳵴κ����³�վ��
		{
			if (mouse_press(10,20, 80, 40) == 1)//ѡ�񳵴�һ
			{
				clrmous(MouseX,MouseY);
				state3=1;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"���վ",48,50,RED);
				puthz(50,120+210,"�յ�վ",48,50,RED);
				puthz(200+120-10,80,"��ݿ",32,34,RED);
				puthz(200+10+80*3,80,"�Ƽ�¥",32,34,RED);
				puthz(200+120-40-10,180,"��е��¥",32,34,RED);
				puthz(200+10+80*3+20,180,"��԰",32,34,RED);
				puthz(200+120-30,80+210,"�Ƽ�¥",32,34,RED);
				puthz(200+10+80*3-10,80+210,"��е��¥",32,34,RED);
				puthz(200+120-30,180+210,"��԰",32,34,RED);
				puthz(200+10+80*3+20,180+210,"��Է",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if(mouse_press(10,40,80,60)==1)//ѡ�񳵴ζ�
			{
				clrmous(MouseX,MouseY);
				state3=2;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				//�ϳ���վ���³���վ
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"���վ",48,50,RED);
				puthz(50,120+210,"�յ�վ",48,50,RED);
				puthz(200+120-40,80,"У����",32,34,RED);
				puthz(200+10+80*3+10,80,"ͼ���",32,34,RED);
				puthz(200+120-40+10,180,"���",32,34,RED);
				puthz(200+10+80*3,180,"��ó�г�",32,34,RED);
				puthz(200+120-30,80+210,"ͼ���",32,34,RED);
				puthz(200+10+80*3+10,80+210,"���",32,34,RED);
				puthz(200+120-40,180+210,"��ó�г�",32,34,RED);
				puthz(200+10+80*3+20,180+210,"��Է",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(10, 60, 80, 80) == 1)//ѡ�񳵴���
			{
				clrmous(MouseX,MouseY);
				state3=3;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				//�ϳ���վ���³���վ
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"���վ",48,50,RED);
				puthz(50,120+210,"�յ�վ",48,50,RED);
				puthz(200+120-10,80,"У����",32,34,RED);
				puthz(200+10+80*3,80,"ͼ���",32,34,RED);
				puthz(200+120-40-10,180,"�׶�԰",32,34,RED);
				puthz(200+10+80*3+20,180,"УҽԺ",32,34,RED);
				puthz(200+120-30,80+210,"ͼ���",32,34,RED);
				puthz(200+10+80*3-10,80+210,"�׶�԰",32,34,RED);
				puthz(200+120-30,180+210,"УҽԺ",32,34,RED);
				puthz(200+10+80*3+20,180+210,"��԰",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
		}
		else if (state2 == 1 && MouseX > 160 && MouseX < 240 && MouseY>20 && MouseY < 100)//ѡ��Ҫ��ѯ�ĳ��λ���ѡ���ѯ���г�����ͬһ���ε���
		{
			if (mouse_press(170, 20, 240, 40) == 1)
			{
				clrmous(MouseX,MouseY);
				state3 = 0;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				setfillstyle(1, CYAN);
				bar(10,30,80,80);
				menu_choice(&state1,&state2);
				passenger_list(1);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(170, 40, 240, 60) == 1)
			{
				clrmous(MouseX,MouseY);
				state3 = 0;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				setfillstyle(1, CYAN);
				bar(10,30,80,80);
				menu_choice(&state1,&state2);
				passenger_list(2);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(170, 60, 240, 80) == 1)
			{
				clrmous(MouseX,MouseY);
				state3 = 0;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				setfillstyle(1, CYAN);
				bar(10,30,80,80);
				menu_choice(&state1,&state2);
				passenger_list(3);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(170, 80, 240, 100) == 1)
			{
				clrmous(MouseX,MouseY);
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				setfillstyle(1, CYAN);
				bar(10,30,80,80);
				menu_choice(&state1,&state2);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
		}
		else if(state3!=0)//ѡ�����³�վ
		{
			if (judge_station(state3,&start,&end)!=1)//����judge_station�ķ���ֵ���ж�����Ƿ��ڹ��ܴ�����
			{
				if((mouse_press(0,20,640,480)==1)&&(mouse_press(10,20,80,80)!=1)&&(mouse_press(170,20,240,100)!=1))
				{
					putimage(10, 20, saveimage1, 0);
					putimage(170, 20, saveimage2, 0);
					state1 = 0;
					state2 = 0;
				}
				else
				{
					continue;
				}
			}
		}
		else if(mouse_press(610,0,640,30)==1)
		{
			clrmous(MouseX,MouseY);
			delay(150);
			free(saveimage1);
			free(saveimage2);
			free(saveimage3);
			free(saveimage4);
			return 0;
		}
		else
		{
			if ((mouse_press(0, 20, 640, 480) == 1) && (mouse_press(10, 20, 80, 80) != 1) && (mouse_press(170, 20, 240, 100) != 1))
			{
				putimage(10, 20, saveimage1,0);
				putimage(170, 20, saveimage2,0);
				state1 = 0;
				state2 = 0;
			}
		}
	}
	free(saveimage1);
	free(saveimage2);
	free(saveimage3);
	free(saveimage4);
}

/*********************************************
FUNCTION:menu_choice
DESCRIPTION:���ƹ��ܽ��������state1��state2
INPUT:int* state1,int* state2
RETURN:void
***********************************************/

void menu_choice(int* state1,int* state2)//
{
	*state1 = 0;
	*state2 = 0;
	setfillstyle(1,CYAN);
	bar(40, 30, 600, 450);//������ܽ��棬��ֹ�����л����ܽ����͸ù��ܽ����ص�
	setfillstyle(1,YELLOW);
	setcolor(DARKGRAY);
	rectangle(40, 30, 600, 450);
	floodfill(50,40,DARKGRAY);
}

/*********************************************
FUNCTION:station
DESCRIPTION:��x��yΪ���ĵ����򹫽�վ̨��ʶ
INPUT:void
RETURN:void
***********************************************/

void station(int x,int y)//
{
	int sta[14];
	sta[0]=x;
	sta[1]=y;
	sta[2]=x-30;
	sta[3]=y-30;
	sta[4]=x+60;
	sta[5]=y-30;
	sta[6]=x+90;
	sta[7]=y;
	sta[8]=x+60;
	sta[9]=y+30;
	sta[10]=x-30;
	sta[11]=y+30;
	sta[12]=x;
	sta[13]=y;
	setcolor(BLUE);
	setfillstyle(1,BROWN);
	ellipse(x+30,y-60,0,360,10,5);
	line(x+20,y-60,x+20,y+60);
	line(x+40,y-60,x+40,y+60);
	ellipse(x+30,y+60,180,360,10,5);
	floodfill(x+30,y-60,BLUE);
	floodfill(x+30,y,BLUE);

	setfillstyle(1, LIGHTGREEN);
	setcolor(RED);
	drawpoly(7,sta);
	floodfill(x+30,y,RED);
}

/*********************************************
FUNCTION:draw_choosesta
DESCRIPTION:����ѡ��վ���
INPUT:void
RETURN:void
***********************************************/

void draw_choosesta()//
{
	setfillstyle(1, CYAN);
	bar(10,30,40,80);
	station(90,120);
	station(90,120+210);
	setcolor(DARKGRAY);
	line(250,30,250,450);
	line(420,30,420,450);
	line(250,135,600,135);
	line(40,240,600,240);
	line(250,345,600,345);
}

/*********************************************
FUNCTION:guest_menu0
DESCRIPTION���οͲ˵����ܺ���
INPUT:void
RETURN:void
***********************************************/

void guest_menu0()//�οͽ���
{
	cleardevice();
	setbkcolor(CYAN);
	setfillstyle(1, WHITE);
	bar(0, 0, 80, 20);
	bar(80, 0, 160, 20);
	bar(160, 0, 240, 20);
	puthz(0,0,"��Ӽ�¼",16,17,RED);
	puthz(80,0,"�˳��켣",16,17,RED);
	puthz(160,0,"ͬ���γ˿�",16,17,RED);
	button_back();
}


/*********************************************
FUNCTION:guest_menu1
DESCRIPTION���οͲ˵����ܺ���
INPUT:void
RETURN:0 or 2
***********************************************/


int guest_menu1()//�οͲ˵�����ʵ��
{
	int state1 = 0;//�ж���Ӽ�¼�˵��Ƿ���չ��״̬
	int state2 = 0;//�ж�ͬ���γ˿Ͳ˵��Ƿ���չ��״̬
	int state3=0;//�ж���Ӽ�¼�ĳ������ĳ���
	int start=0;//�ж����
	int end=0;//�ж��յ�
	int state4=0;//�ж�Ҫ��ѯ����ʲô���εĳ˿���Ϣ

	void* saveimage1 = (void *)malloc(imagesize(10, 20, 80, 80));
	void* saveimage2 = (void *)malloc(imagesize(170, 20, 240,100));
	void* saveimage3 = (void *)malloc(imagesize(10, 20, 80, 30));
	void* saveimage4 = (void *)malloc(imagesize(170, 20, 240, 30));
	clrmous(MouseX,MouseY);
	guest_menu0();
	getimage(10, 20, 80, 80, saveimage1);
	getimage(170, 20, 240,100, saveimage2);
	getimage(10, 20, 80, 30, saveimage3);
	getimage(170, 20, 240,30, saveimage4);
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);//
		MouseS=0;
		//��Ӽ�¼
		if(MouseX>0&&MouseX<80&&MouseY>0&&MouseY<20)
		{
			if (mouse_press(0,0,80,20) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1, WHITE);
				bar(10, 20, 80, 80);
				puthz(10,20, "����һ",16,17,RED);
				puthz(10, 40, "���ζ�",16,17,RED);
				puthz(10,60, "������",16,17,RED);
				state1=1;
			}
			else if (mouse_press(0, 0, 80, 20) == 2)
			{
				continue;
			}
		}
		//��ʾ�켣
		else if(MouseX>80&&MouseX<160&&MouseY>0&&MouseY<20)
		{
			if ((mouse_press(80, 0,160, 20) == 1)&&state3!=0&&start!=0&&end!=0)
			{
				judge_visual(state3,start,end);
				free(saveimage1);
				free(saveimage2);
				free(saveimage3);
				free(saveimage4);
				return 2;
			}
			else if (mouse_press(80,0,160,20) != 1)
			{
				continue;
			}
		}
		//�˳����ι����˿Ͳ�ѯ
		else if (MouseX > 160 && MouseX < 240 && MouseY>0 && MouseY < 20)
		{
			if (mouse_press(160, 0, 240, 20) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(170, 20, 240, 80);
				puthz(170, 20, "����һ", 16, 17, RED);
				puthz(170, 40, "���ζ�", 16, 17, RED);
				puthz(170, 60, "������", 16, 17, RED);
				state2 = 1;
			}
			else if (mouse_press(80, 0, 160, 20) != 1)
			{
				continue;
			}
		}
		else if (state1 == 1&& MouseX > 0 && MouseX < 80 && MouseY>20 && MouseY < 80)//ѡ�񳵴κ����³�վ��
		{
			if (mouse_press(10,20, 80, 40) == 1)//ѡ�񳵴�һ
			{
				clrmous(MouseX,MouseY);
				state3=1;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"���վ",48,50,RED);
				puthz(50,120+210,"�յ�վ",48,50,RED);
				puthz(200+120-10,80,"��ݿ",32,34,RED);
				puthz(200+10+80*3,80,"�Ƽ�¥",32,34,RED);
				puthz(200+120-40-10,180,"��е��¥",32,34,RED);
				puthz(200+10+80*3+20,180,"��԰",32,34,RED);
				puthz(200+120-30,80+210,"�Ƽ�¥",32,34,RED);
				puthz(200+10+80*3-10,80+210,"��е��¥",32,34,RED);
				puthz(200+120-30,180+210,"��԰",32,34,RED);
				puthz(200+10+80*3+20,180+210,"��Է",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if(mouse_press(10,40,80,60)==1)//ѡ�񳵴ζ�
			{
				clrmous(MouseX,MouseY);
				state3=2;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				//�ϳ���վ���³���վ
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"���վ",48,50,RED);
				puthz(50,120+210,"�յ�վ",48,50,RED);
				puthz(200+120-40,80,"У����",32,34,RED);
				puthz(200+10+80*3+10,80,"ͼ���",32,34,RED);
				puthz(200+120-40+10,180,"���",32,34,RED);
				puthz(200+10+80*3,180,"��ó�г�",32,34,RED);
				puthz(200+120-30,80+210,"ͼ���",32,34,RED);
				puthz(200+10+80*3+10,80+210,"���",32,34,RED);
				puthz(200+120-40,180+210,"��ó�г�",32,34,RED);
				puthz(200+10+80*3+20,180+210,"��Է",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(10, 60, 80, 80) == 1)//ѡ�񳵴���
			{
				clrmous(MouseX,MouseY);
				state3=3;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				//�ϳ���վ���³���վ
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"���վ",48,50,RED);
				puthz(50,120+210,"�յ�վ",48,50,RED);
				puthz(200+120-10,80,"У����",32,34,RED);
				puthz(200+10+80*3,80,"ͼ���",32,34,RED);
				puthz(200+120-40-10,180,"�׶�԰",32,34,RED);
				puthz(200+10+80*3+20,180,"УҽԺ",32,34,RED);
				puthz(200+120-30,80+210,"ͼ���",32,34,RED);
				puthz(200+10+80*3-10,80+210,"�׶�԰",32,34,RED);
				puthz(200+120-30,180+210,"УҽԺ",32,34,RED);
				puthz(200+10+80*3+20,180+210,"��԰",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
		}
		else if (state2 == 1 && MouseX > 160 && MouseX < 240 && MouseY>20 && MouseY < 100)//ѡ��Ҫ��ѯ�ĳ���(����ѡ���ѯ���г�����ͬһ���ε���)
		{
			if (mouse_press(170, 20, 240, 40) == 1)
			{
				clrmous(MouseX,MouseY);
				state3 = 0;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				setfillstyle(1, CYAN);
				bar(10,30,80,80);
				menu_choice(&state1,&state2);
				passenger_list(1);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(170, 40, 240, 60) == 1)
			{
				clrmous(MouseX,MouseY);
				state3 = 0;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				setfillstyle(1, CYAN);
				bar(10,30,80,80);
				menu_choice(&state1,&state2);
				passenger_list(2);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(170, 60, 240, 80) == 1)
			{
				clrmous(MouseX,MouseY);
				state3 = 0;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				setfillstyle(1, CYAN);
				bar(10,30,80,80);
				menu_choice(&state1,&state2);
				passenger_list(3);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
		}
		else if(state3!=0)//ѡ�����³�վ
		{
			if (judge_station(state3,&start,&end)!=1)//����judge_station�ķ���ֵ���ж�����Ƿ��ڹ��ܴ�����
			{
				if((mouse_press(0,20,640,480)==1)&&(mouse_press(10,20,80,80)!=1)&&(mouse_press(170,20,240,100)!=1))
				{
					putimage(10, 20, saveimage1, 0);
					putimage(170, 20, saveimage2, 0);
					state1 = 0;
					state2 = 0;
				}
				else
				{
					continue;
				}
			}
		}
		else if(mouse_press(610,0,640,30)==1)
		{
			clrmous(MouseX,MouseY);
			delay(150);
			free(saveimage1);
			free(saveimage2);
			free(saveimage3);
			free(saveimage4);
			return 0;
		}
		else
		{
			if ((mouse_press(0, 20, 640, 480) == 1) && (mouse_press(10, 20, 80, 80) != 1) && (mouse_press(170, 20, 240, 100) != 1))
			{
				putimage(10, 20, saveimage1,0);
				putimage(170, 20, saveimage2,0);
				state1 = 0;
				state2 = 0;
			}
		}
	}
	free(saveimage1);
	free(saveimage2);
	free(saveimage3);
	free(saveimage4);
}
/*void main()
{
	int graphdriver, graphmode;
	graphdriver = DETECT;
	initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
	mouseinit();
	user_menu();
}*/