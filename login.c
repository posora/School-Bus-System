#include"login.h"
#include"public.h"
#include"input.h"
#include"judge.h"
/*****************************************
login.c
COPYRIGHT:	shenlei
FUNCTION:	user login
ABSTRACT:
		A.login for user
DATE:2020/9/6
******************************************/


/**********************************************
FUNCTION:user_login
DESCRIPTION???????????????
INPUT:func,u
RETURN:??
***********************************************/

void g_login()
{
	int i;
	setbkcolor(GREEN);
	cleardevice();
	setcolor(WHITE);
	settextstyle(4,0,6);
	outtextxy(250,40,"LOGIN");
	for(i = 0; i < 2;i++)
	{
		setcolor(WHITE);
		rectangle(120,180+120*i,360,180+30+120*i);
		setfillstyle(1,LIGHTGRAY);
		floodfill(240, 195 + 120 * i, WHITE);
	}
	setcolor(RED);
	settextstyle(4, 0, 3);
	outtextxy(120, 134, "username:");
	outtextxy(120, 134 + 120, "password:");
	settextstyle(1,0,2);
	outtextxy(330,114 + 240,"forget password?");
	line(330,136+240,330+16*10,136+240);
	outtextxy(330,154 + 240,"register");
	line(330,176+240,330+8*10,176+240);

	setfillstyle(1,CYAN);
	setcolor(BLUE);
	rectangle(150,134+240,260,134+240+50);
	floodfill(160,135+240,BLUE);
	setcolor(RED);
	settextstyle(1,0,3);
	outtextxy(165,144+240,"sign in");
}
int s_login()
{
	char name[20] ;
	char ps[20] ;
	g_login();
	memset(name, '\0', 20);
	memset(ps, '\0', 20);
	clrmous(MouseX, MouseY);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 120 && MouseX < 360 && MouseY>180 && MouseY < 210)
		{
			if (mouse_press(120, 180, 360, 210) == 2)
			{
				MouseS = 2;
			}
			else if(mouse_press(120, 180, 360, 210) == 1)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(120 + 1, 180 + 1, 360 - 1, 210 - 1);
				//???????????????????????????ï…??????????????
				input_name(name,120,180);//input_name??????????input.c??
			}
			continue;
		}
		else if (MouseX > 120 && MouseX < 360 && MouseY>300 && MouseY < 330)
		{
			if (mouse_press(120, 300, 360, 330) == 2)
			{
				MouseS = 2;

			}
			else if(mouse_press(120, 300, 360, 330) == 1)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(120 + 1, 300 + 1, 360 - 1, 330 - 1);
				clrmous(MouseX, MouseY);
				input_password(ps,120,300);
			}
			continue;
		}
		else if (MouseX > 150 && MouseX < 260 && MouseY>374 && MouseY < 424)//?????
		{
			if (mouse_press(150, 374, 260, 424) == 2)
			{
				MouseS = 1;
			}
			else if(mouse_press(150, 374, 260, 424) == 1)
			{
				if (judge_login(name, ps)==1)//?§Ø??????????§Õ
				{
					outtextxy(260,374,"welcome 123");
					clrmous(MouseX, MouseY);
					delay(15000);
					return 5;
				}
				else
				{
					settextstyle(1, 0, 1);
					setcolor(RED);
					outtextxy(360, 185, "username or password error");
					delay(150);
				}
				memset(name, '\0', 20);
				memset(ps, '\0', 20);
			}
			continue;
		}
		else if (MouseX > 330 && MouseX < 330 + 160 && MouseY>114 + 240 && MouseY < 136 + 240)//????????
		{
			if (mouse_press(330, 114 + 240,330 + 16 * 10, 136 + 240) == 2)
			{
				MouseS = 1;
			}
			else if (mouse_press(330, 114 + 240,330 + 16 * 10, 136 + 240) == 1)
			{
				clrmous(MouseX, MouseY);
				delay(150);
				return 4;
			}
		}
		else if (MouseX > 330 && MouseX < 330 + 80 && MouseY>114 + 240 && MouseY < 176 + 240)//???
		{
			if (mouse_press(330, 114 + 240, 330 + 8 * 10, 176 + 240) == 2)
			{
				MouseS = 1;
			}
			else if (mouse_press(330, 114 + 240, 330 + 8 * 10, 176 + 240) == 1)
			{
				clrmous(MouseX, MouseY);
				delay(150);
				return 3;
			}
		}
		else
		{
			MouseS = 0;
		}
	}
}
/*void main()
{
	int i, graphdriver, graphmode;
	graphdriver = DETECT;
	initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
	mouseinit();
	s_login();
}*/