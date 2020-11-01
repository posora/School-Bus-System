#include"public.h"
#include"register.h"
#include"user.h"
#include"judge.h"
/***************************
register.c
COPYRIGHT:	shenlei
FUNCTION:	user register
ABSTRACT:
		A.register for user
DATE:2020/9/11
****************************/

/*********************************************
FUNCTION:register_drawer
DESCRIPTION:注册界面画图函数
INPUT:void
RETURN:void
***********************************************/

void register_drawer()
{
	int i;
	setbkcolor(GREEN);
	cleardevice();
	setcolor(WHITE);
	settextstyle(4, 0, 5);
	outtextxy(200, 10, "REGISTER");
	for (i = 0; i < 3; i++)
	{
		setcolor(WHITE);
		rectangle(120, 120 + 100 * i, 360, 120 + 30 + 100 * i);
		setfillstyle(1, LIGHTGRAY);
		floodfill(240, 135 + 100 * i, WHITE);
	}
	setcolor(RED);
	settextstyle(4, 0, 3);
	outtextxy(120, 74, "username:");
	outtextxy(120, 74 + 100, "password:");
	outtextxy(120, 74 + 200, "phone number:");
	setfillstyle(1, CYAN);
	setcolor(BLUE);
	rectangle(150, 154 + 240, 260, 154 + 240 + 50);
	floodfill(160, 155 + 240, BLUE);
	setcolor(RED);
	settextstyle(1, 0, 3);
	outtextxy(165, 164 + 240, "enroll");
	button_back();
	/*getch();
	closegraph();*/
}

/*********************************************
FUNCTION:s_register
DESCRIPTION:注册界面功能函数
INPUT:char* user
RETURN:1 or 3
***********************************************/

int s_register()//
{
	char name[12] = { '\0' };
	char pass[15] = { '\0' };
	char phone[12] ={ '\0'};
	register_drawer();
	clrmous(MouseX, MouseY);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 120 && MouseX < 360 && MouseY>120 && MouseY < 150)//
		{
			if (mouse_press(120, 120, 360, 150) == 2)//
				MouseS = 2;
			else if (mouse_press(120, 120, 360, 150) == 1)
			{
				setfillstyle(1, LIGHTGRAY);
				bar(120 + 1, 120 + 1, 360 - 1, 150 - 1);
				clrmous(MouseX, MouseY);//
				input_name(name, 120, 120);//
			}
		}
		else if (MouseX > 120 && MouseX < 360 && MouseY>220 && MouseY < 250)
		{
			if (mouse_press(120, 220, 360, 250) == 2)//
				MouseS = 2;
			else if (mouse_press(120, 220, 360, 250) == 1)
			{
				setfillstyle(1, LIGHTGRAY);
				bar(120 + 1, 220 + 1, 360 - 1, 250 - 1);
				clrmous(MouseX, MouseY);
				input_password(pass, 120, 220);
			}
		}
		else if (MouseX > 120 && MouseX < 360 && MouseY>320 && MouseY < 350)//
		{
			if (mouse_press(120, 320, 360, 350) == 2)//
				MouseS = 2;

			else if (mouse_press(120, 320, 360, 350) == 1)
			{
				setfillstyle(1, LIGHTGRAY);
				bar(120 + 1, 320 + 1, 360 - 1, 350 - 1);
				clrmous(MouseX, MouseY);
				input_name(phone, 120, 320);//
			}
		}
		else if (MouseX > 150 && MouseX < 260 && MouseY>154 + 240 && MouseY < 154 + 240 + 50)//???
		{
			MouseS = 1;
			if (mouse_press(150, 154 + 240, 260, 154 + 240 + 50) == 2);
			else if (mouse_press(150, 154 + 240, 260, 154 + 240 + 50) == 1)
			{
				if (f_register(name, pass, phone) == 1)
				{
					puthz(270,154+240+50,"注册成功",16,17,RED);
					clrmous(MouseX, MouseY);
					delay(150);
					return 1;
				}
				else
				{
					clrmous(MouseX,MouseY);
					delay(150);
					return 3;
				}
			}
		}
		else if(mouse_press(610,0,640,30)==1)
		{
			clrmous(MouseX,MouseY);
			delay(150);
			return 1;
		}
		else
		{
			MouseS = 0;
		}
	}
}
/*void lightbutton()
{

}*/