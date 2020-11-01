#include"public.h"
#include"forget.h"
#include"user.h"
#include"judge.h"

/**************************
forgetpass.c
COPYRIGHT:	shenlei
FUNCTION:	find lost pass
ABSTRACT:
		A.find lost pass
DATE:2020/10/7
****************************/

/*********************************************
FUNCTION:fgpass_drawer
DESCRIPTION：忘记密码界面的画图函数
INPUT:void
RETURN:void
***********************************************/

void fgpass_drawer()
{
	int i;
	setbkcolor(GREEN);
	cleardevice();
	setcolor(WHITE);
	settextstyle(4, 0, 5);
	outtextxy(200, 10, "FORGETPASS");
	for (i = 0; i < 2; i++)
	{
		setcolor(WHITE);
		rectangle(120, 120 + 100 * i, 360, 120 + 30 + 100 * i);
		setfillstyle(1, LIGHTGRAY);
		floodfill(240, 135 + 100 * i, WHITE);
	}
	setcolor(RED);
	settextstyle(4, 0, 3);
	outtextxy(120, 74, "username:");
	outtextxy(120, 74 + 100, "phone number:");
	setfillstyle(1, CYAN);
	setcolor(BLUE);
	rectangle(150, 154 + 240, 260, 154 + 240 + 50);
	floodfill(160, 155 + 240, BLUE);
	setcolor(RED);
	settextstyle(1, 0, 3);
	outtextxy(165, 164 + 240, "confirm");
	button_back();
	/*getch();
	closegraph();*/
}

/*********************************************
FUNCTION:s_fgpass
DESCRIPTION：忘记密码界面的功能函数
INPUT:void
RETURN:1 or 4
***********************************************/

int s_fgpass()//找回密码功能实现
{
	char name[12] = { '\0' };
	char pass[15] = { '\0' };
	char phone[12] = { '\0' };
	fgpass_drawer();
	clrmous(MouseX, MouseY);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 120 && MouseX < 360 && MouseY>120 && MouseY < 150)
		{
			if (mouse_press(120, 120, 360, 150) == 2)
				MouseS = 2;
			else if (mouse_press(120, 120, 360, 150) == 1)
			{
				clrmous(MouseX, MouseY);
				setfillstyle(1, LIGHTGRAY);
				bar(120 + 1, 120 + 1, 360 - 1, 150 - 1);
				input_name(name, 120, 120);
			}
		}
		else if (MouseX > 120 && MouseX < 360 && MouseY>220 && MouseY < 250)
		{
			if (mouse_press(120, 220, 360, 250) == 2)
				MouseS = 2;
			else if (mouse_press(120, 220, 360, 250) == 1)
			{
				clrmous(MouseX, MouseY);
				setfillstyle(1, LIGHTGRAY);
				bar(120 + 1, 220 + 1, 360 - 1, 250 - 1);
				input_password(phone, 120, 220);
			}
		}
		else if (MouseX > 150 && MouseX < 260 && MouseY>154 + 240 && MouseY < 154 + 240 + 50)//按下确认键
		{
			MouseS = 1;
			if (mouse_press(150, 154 + 240, 260, 154 + 240 + 50) == 2);
			else if (mouse_press(150, 154 + 240, 260, 154 + 240 + 50) == 1)
			{
				if (judge_forgetpassword(name,pass,phone) == 1)
				{
					puthz(270, 154 + 240 + 50, "找回密码成功，密码为：", 16, 17, RED);
					outtextxy(270+16*12,154+240+50,pass);
					puthz(270,400, "按回车键继续",16,17,RED);
					clrmous(MouseX, MouseY);
					getch();
					return 1;
				}
				else
				{
					puthz(270, 154 + 240 + 50, "用户名或电话号码不正确", 16, 17, RED);
					delay(1500);
					return 4;
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