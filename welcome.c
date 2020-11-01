#include"public.h"
#include"welcome.h"
/***************************
welcome.c
COPYRIGHT:	shenlei
FUNCTION:	welcome page
ABSTRACT:
		A.welcome and choose pattern
DATE:2020/9/5
****************************/

/*********************************************
FUNCTION:button_back
DESCRIPTION:���ذ�ť�Ļ���
INPUT:void
RETURN:void
***********************************************/

void button_back()
{
	setcolor(DARKGRAY);
	settextstyle(1,0,3);
	setfillstyle(1,LIGHTGRAY);
	bar(610,0,639,30);
	outtextxy(615,5,"X");
}

/*********************************************
FUNCTION:button_back
DESCRIPTION:��ӭ����Ļ���
INPUT:void
RETURN:void
***********************************************/

void g_welcome()
{
	int i;
	setbkcolor(GREEN);//���ñ�������
	cleardevice();

	setfillstyle(1, 14);
	bar(49, 401, 192, 440);//�������ܰ���
	bar(257, 401, 384, 440);
	bar(449, 401, 576, 440);
	setcolor(WHITE);
	settextstyle(1, 0, 5);
	puthz(70, 40, "������ͨ�˿��г�ϵͳ",48,51,WHITE);
	setlinestyle(0, 1, 3);
	for (i = 0; i <= 3; i++)//����ѭ�����Ӵ�����
	{
		setcolor(BROWN);//���û�ͼ��ɫ
		line(100, 200 + 3 * i, 500, 200 + 3 * i);
		setcolor(BLUE);//
		line(110, 300 + 3 * i, 470, 130 + 3 * i);
		line(70, 300 + 3 * i, 109, 300 + 3 * i);
		line(470, 130 + 3 * i, 520, 150 + 3 * i);
		setcolor(CYAN);//
		line(200 + 3 * i, 120, 200 + 3 * i, 330);
		line(210, 321 + 3 * i, 329, 321 + 3 * i);
		line(330, 321 + 3 * i, 371, 360 + 3 * i);
		setcolor(MAGENTA);//
		line(530, 311 + 3 * i, 480, 311 + 3 * i);
		line(480, 311 + 3 * i, 320, 140 + 3 * i);
		line(319, 140 + 3 * i, 90, 140 + 3 * i);
	}
	settextstyle(1, 0, 4);
	setcolor(RED);
	outtextxy(89, 399, "User");
	outtextxy(281, 399, "Guest");
	outtextxy(473, 399, "About");
	button_back();
	/*getch();
	closegraph();*/
}

/*********************************************
FUNCTION:s_welcome
DESCRIPTION:��ӭ����Ļ���
INPUT:void
RETURN:int
***********************************************/

int s_welcome()
{
	clrmous(MouseX,MouseY);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);//�������״̬
		if (mouse_press(49,401,192,440)==1)
		{
			clrmous(MouseX, MouseY);
			delay(150);//��ʱ��������ֹ�������
			return 1;
		}
		else if (mouse_press(257, 401, 384, 440) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(150);
			return 2;
		}
		else if (mouse_press(449, 401, 576, 440) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(150);
			return 7;
		}
		else if(mouse_press(610,0,640,30)==1)
		{
			clrmous(MouseX,MouseY);
			delay(150);
			exit(1);
		}
	}
}
/*void main()
{
	int i, graphdriver, graphmode;
	graphdriver = DETECT;
	initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
	g_welcome();
}*/