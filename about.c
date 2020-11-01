#include"public.h"
#include"about.h"
/*****************************************
about.c
COPYRIGHT:	zoubojin
FUNCTION:	information about the project
ABSTRACT:
		information about the project
DATE:2020/10/12
******************************************/

/*********************************************
FUNCTION:fgpass_drawer
DESCRIPTION：关于界面的画图函数
INPUT:void
RETURN:void
***********************************************/

void g_about()
{
	cleardevice();
	setbkcolor(WHITE);
	//clrscr();
	setcolor(DARKGRAY);
	settextstyle(1,0,2);
	puthz(250, 0, "相关信息说明", 16, 17, DARKGRAY);
	puthz(0, 16, "应用名称：", 16, 17, DARKGRAY);
	puthz(0+16*5, 16, "公共交通乘客行程系统", 16, 17, DARKGRAY);
	puthz(0, 16*2, "制作者：", 16, 17, DARKGRAY);
	puthz(0+16*4, 16*2, "沈磊", 16, 17, DARKGRAY);
	puthz(0+16*7, 16*2, "邹搏进", 16, 17, DARKGRAY);
	puthz(0, 16*3, "指导教师：", 16, 17, DARKGRAY);
	puthz(0+16*5, 16*3, "周纯杰", 16, 17, DARKGRAY);
	puthz(0+16*9, 16*3, "周凯波", 16, 17, DARKGRAY);
	puthz(0+16*13, 16*3, "彭刚", 16, 17, DARKGRAY);
	puthz(0+16*16, 16*3, "何顶新", 16, 17, DARKGRAY);
	puthz(0+16*20, 16*3, "左峥嵘", 16, 17, DARKGRAY);
	puthz(0+16*24, 16*3, "高常鑫", 16, 17, DARKGRAY);
	puthz(0+16*28, 16*3, "汪国有", 16, 17, DARKGRAY);
	puthz(0+16*32, 16*3, "桑农", 16, 17, DARKGRAY);
	puthz(0+16*35, 16*3, "陈忠", 16, 17, DARKGRAY);
	puthz(0, 16*4, "编写目的：", 16, 17, DARKGRAY);
	puthz(0, 16*5, "随着国家城市化进程的不断推进，城市公共交通愈发成为市民生活中不可或缺的一部", 16, 17, DARKGRAY);
	puthz(0, 16*6, "分，然而出于对隐私的担忧和对行程管理的重视不足，针对单个用户的行程记录和查", 16, 17, DARKGRAY);
	puthz(0, 16*7, "询的软件发展得较为缓慢。", 16, 17, DARKGRAY);
	puthz(0, 16*8, "然而在这次疫情中，针对单个用户的行程分析在追溯病毒来源和疑似感染者中扮演了", 16, 17, DARKGRAY);
	puthz(0, 16*9, "举足轻重的作用，国内疫情的有效控制很大程度上也要归功于较为完善的行程追踪机", 16, 17, DARKGRAY);
	puthz(0, 16*10, "制，因此人们对行程管理的重视度也有了显著提高。值得注意的是，行程管理不仅对", 16, 17, DARKGRAY);
	puthz(0, 16*11, "传染病的管控有着重要意义，其在刑事案件的侦察中也会发挥显著的作用。", 16, 17, DARKGRAY);
	puthz(0, 16*12, "基于以上实际的考量，编者希望编写出一款简单的公共交通行程系统，以帮助用户管", 16, 17, DARKGRAY);
	puthz(0, 16*13, "理自己的行程信息，查询乘坐过同车次公共交通工具的其他乘客，以更好地应对意外", 16, 17, DARKGRAY);
	puthz(0, 16*14, "情况发生后的追溯和紧急处理。", 16, 17, DARKGRAY);
	puthz(0, 16*15, "参考软件：", 16, 17, DARKGRAY);
	puthz(0, 16*16, "微信小程序乘车码", 16, 17, DARKGRAY);
	puthz(0, 16*17, "支付宝乘车码", 16, 17, DARKGRAY);
	puthz(0, 16*18, "主要功能：", 16, 17, DARKGRAY);
	puthz(0, 16*19, "分用户模式和游客模式", 16, 17, DARKGRAY);
	puthz(0+16*11, 16*19, "游客模式仅供用户查询使用", 16, 17, DARKGRAY);
	puthz(0, 16*20, "用户登录后自行添加乘车记录", 16, 17, DARKGRAY);
	puthz(0, 16*21, "乘车记录可视化显示", 16, 17, DARKGRAY);
	puthz(0, 16*22, "乘车车次关联乘客轨迹图形化显示功能", 16, 17, DARKGRAY);
	outtextxy(500, 16*24, "VERSION:1.0.0");
	puthz(450, 16*26, "二零二零年十月三十一日", 16, 17, DARKGRAY);
	button_back();
}

/*********************************************
FUNCTION:fgpass_drawer
DESCRIPTION：关于界面的功能函数
INPUT:void
RETURN:0
***********************************************/

int s_about()
{
	clrmous(MouseX,MouseY);
	g_about();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(mouse_press(610,0,640,30)==1)
		{
			clrmous(MouseX,MouseY);
			delay(150);
			return 0;
		}
	}
}
/*void main()//测试函数
{
	int graphdriver, graphmode;
	graphdriver = DETECT;
	initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
	g_about();
	getch();
}*/