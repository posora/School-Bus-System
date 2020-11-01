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
DESCRIPTION：用户界面画图函数
INPUT:void
RETURN:void
***********************************************/

void user_menu0()//画用户界面
{
	cleardevice();
	setbkcolor(CYAN);
	//clrscr();
	setfillstyle(1, WHITE);
	bar(0, 0, 80, 20);
	bar(80, 0, 160, 20);
	bar(160, 0, 240, 20);
	puthz(0,0,"添加记录",16,17,RED);
	puthz(80,0,"乘车轨迹",16,17,RED);
	puthz(160,0,"同车次乘客",16,17,RED);
	button_back();
}

/*********************************************
FUNCTION:user_menu1
DESCRIPTION：用户菜单功能函数
INPUT:char* name
RETURN:0 or 5
***********************************************/

int user_menu1(char* name)//用户菜单功能实现
{
	int state1 = 0;//判断添加记录菜单是否处于展开状态
	int state2 = 0;//判断同车次乘客菜单是否处于展开状态
	int state3=0;//判断添加记录的车次是哪车次
	int start=0;//判断起点
	int end=0;//判断终点
	int state4=0;//判断要查询的是什么车次的乘客信息
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
		//添加记录
		if(MouseX>0&&MouseX<80&&MouseY>0&&MouseY<20)
		{
			if (mouse_press(0,0,80,20) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1, WHITE);
				bar(10, 20, 80, 80);
				puthz(10,20, "车次一",16,17,RED);
				puthz(10, 40, "车次二",16,17,RED);
				puthz(10,60, "车次三",16,17,RED);
				state1=1;
			}
			else if (mouse_press(0, 0, 80, 20) == 2)
			{
				continue;
			}
		}
		//显示轨迹
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
		//乘车车次关联乘客查询
		else if (MouseX > 160 && MouseX < 240 && MouseY>0 && MouseY < 20)
		{
			if (mouse_press(160, 0, 240, 20) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(170, 20, 240, 80);
				puthz(170, 20, "车次一", 16, 17, RED);
				puthz(170, 40, "车次二", 16, 17, RED);
				puthz(170, 60, "车次三", 16, 17, RED);
				state2 = 1;
			}
			else if (mouse_press(80, 0, 160, 20) != 1)
			{
				continue;
			}
		}
		else if (state1 == 1&& MouseX > 0 && MouseX < 80 && MouseY>20 && MouseY < 80)//选择车次和上下车站点
		{
			if (mouse_press(10,20, 80, 40) == 1)//选择车次一
			{
				clrmous(MouseX,MouseY);
				state3=1;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"起点站",48,50,RED);
				puthz(50,120+210,"终点站",48,50,RED);
				puthz(200+120-10,80,"紫菘",32,34,RED);
				puthz(200+10+80*3,80,"科技楼",32,34,RED);
				puthz(200+120-40-10,180,"机械大楼",32,34,RED);
				puthz(200+10+80*3+20,180,"喻园",32,34,RED);
				puthz(200+120-30,80+210,"科技楼",32,34,RED);
				puthz(200+10+80*3-10,80+210,"机械大楼",32,34,RED);
				puthz(200+120-30,180+210,"喻园",32,34,RED);
				puthz(200+10+80*3+20,180+210,"韵苑",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if(mouse_press(10,40,80,60)==1)//选择车次二
			{
				clrmous(MouseX,MouseY);
				state3=2;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				//上车车站和下车车站
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"起点站",48,50,RED);
				puthz(50,120+210,"终点站",48,50,RED);
				puthz(200+120-40,80,"校大门",32,34,RED);
				puthz(200+10+80*3+10,80,"图书馆",32,34,RED);
				puthz(200+120-40+10,180,"大活",32,34,RED);
				puthz(200+10+80*3,180,"集贸市场",32,34,RED);
				puthz(200+120-30,80+210,"图书馆",32,34,RED);
				puthz(200+10+80*3+10,80+210,"大活",32,34,RED);
				puthz(200+120-40,180+210,"集贸市场",32,34,RED);
				puthz(200+10+80*3+20,180+210,"韵苑",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(10, 60, 80, 80) == 1)//选择车次三
			{
				clrmous(MouseX,MouseY);
				state3=3;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				//上车车站和下车车站
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"起点站",48,50,RED);
				puthz(50,120+210,"终点站",48,50,RED);
				puthz(200+120-10,80,"校大门",32,34,RED);
				puthz(200+10+80*3,80,"图书馆",32,34,RED);
				puthz(200+120-40-10,180,"幼儿园",32,34,RED);
				puthz(200+10+80*3+20,180,"校医院",32,34,RED);
				puthz(200+120-30,80+210,"图书馆",32,34,RED);
				puthz(200+10+80*3-10,80+210,"幼儿园",32,34,RED);
				puthz(200+120-30,180+210,"校医院",32,34,RED);
				puthz(200+10+80*3+20,180+210,"喻园",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
		}
		else if (state2 == 1 && MouseX > 160 && MouseX < 240 && MouseY>20 && MouseY < 100)//选择要查询的车次或者选择查询所有乘坐过同一车次的人
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
		else if(state3!=0)//选择上下车站
		{
			if (judge_station(state3,&start,&end)!=1)//利用judge_station的返回值来判断鼠标是否在功能窗口内
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
DESCRIPTION:绘制功能界面框并重置state1，state2
INPUT:int* state1,int* state2
RETURN:void
***********************************************/

void menu_choice(int* state1,int* state2)//
{
	*state1 = 0;
	*state2 = 0;
	setfillstyle(1,CYAN);
	bar(40, 30, 600, 450);//清除功能界面，防止后面切换功能界面会和该功能界面重叠
	setfillstyle(1,YELLOW);
	setcolor(DARKGRAY);
	rectangle(40, 30, 600, 450);
	floodfill(50,40,DARKGRAY);
}

/*********************************************
FUNCTION:station
DESCRIPTION:以x，y为中心的正向公交站台标识
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
DESCRIPTION:绘制选择站点框
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
DESCRIPTION：游客菜单功能函数
INPUT:void
RETURN:void
***********************************************/

void guest_menu0()//游客界面
{
	cleardevice();
	setbkcolor(CYAN);
	setfillstyle(1, WHITE);
	bar(0, 0, 80, 20);
	bar(80, 0, 160, 20);
	bar(160, 0, 240, 20);
	puthz(0,0,"添加记录",16,17,RED);
	puthz(80,0,"乘车轨迹",16,17,RED);
	puthz(160,0,"同车次乘客",16,17,RED);
	button_back();
}


/*********************************************
FUNCTION:guest_menu1
DESCRIPTION：游客菜单功能函数
INPUT:void
RETURN:0 or 2
***********************************************/


int guest_menu1()//游客菜单功能实现
{
	int state1 = 0;//判断添加记录菜单是否处于展开状态
	int state2 = 0;//判断同车次乘客菜单是否处于展开状态
	int state3=0;//判断添加记录的车次是哪车次
	int start=0;//判断起点
	int end=0;//判断终点
	int state4=0;//判断要查询的是什么车次的乘客信息

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
		//添加记录
		if(MouseX>0&&MouseX<80&&MouseY>0&&MouseY<20)
		{
			if (mouse_press(0,0,80,20) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1, WHITE);
				bar(10, 20, 80, 80);
				puthz(10,20, "车次一",16,17,RED);
				puthz(10, 40, "车次二",16,17,RED);
				puthz(10,60, "车次三",16,17,RED);
				state1=1;
			}
			else if (mouse_press(0, 0, 80, 20) == 2)
			{
				continue;
			}
		}
		//显示轨迹
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
		//乘车车次关联乘客查询
		else if (MouseX > 160 && MouseX < 240 && MouseY>0 && MouseY < 20)
		{
			if (mouse_press(160, 0, 240, 20) == 1)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(170, 20, 240, 80);
				puthz(170, 20, "车次一", 16, 17, RED);
				puthz(170, 40, "车次二", 16, 17, RED);
				puthz(170, 60, "车次三", 16, 17, RED);
				state2 = 1;
			}
			else if (mouse_press(80, 0, 160, 20) != 1)
			{
				continue;
			}
		}
		else if (state1 == 1&& MouseX > 0 && MouseX < 80 && MouseY>20 && MouseY < 80)//选择车次和上下车站点
		{
			if (mouse_press(10,20, 80, 40) == 1)//选择车次一
			{
				clrmous(MouseX,MouseY);
				state3=1;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"起点站",48,50,RED);
				puthz(50,120+210,"终点站",48,50,RED);
				puthz(200+120-10,80,"紫菘",32,34,RED);
				puthz(200+10+80*3,80,"科技楼",32,34,RED);
				puthz(200+120-40-10,180,"机械大楼",32,34,RED);
				puthz(200+10+80*3+20,180,"喻园",32,34,RED);
				puthz(200+120-30,80+210,"科技楼",32,34,RED);
				puthz(200+10+80*3-10,80+210,"机械大楼",32,34,RED);
				puthz(200+120-30,180+210,"喻园",32,34,RED);
				puthz(200+10+80*3+20,180+210,"韵苑",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if(mouse_press(10,40,80,60)==1)//选择车次二
			{
				clrmous(MouseX,MouseY);
				state3=2;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				//上车车站和下车车站
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"起点站",48,50,RED);
				puthz(50,120+210,"终点站",48,50,RED);
				puthz(200+120-40,80,"校大门",32,34,RED);
				puthz(200+10+80*3+10,80,"图书馆",32,34,RED);
				puthz(200+120-40+10,180,"大活",32,34,RED);
				puthz(200+10+80*3,180,"集贸市场",32,34,RED);
				puthz(200+120-30,80+210,"图书馆",32,34,RED);
				puthz(200+10+80*3+10,80+210,"大活",32,34,RED);
				puthz(200+120-40,180+210,"集贸市场",32,34,RED);
				puthz(200+10+80*3+20,180+210,"韵苑",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
			else if (mouse_press(10, 60, 80, 80) == 1)//选择车次三
			{
				clrmous(MouseX,MouseY);
				state3=3;
				putimage(10, 20, saveimage3, 0);
				putimage(170, 20, saveimage4, 0);
				//上车车站和下车车站
				menu_choice(&state1,&state2);
				draw_choosesta();
				puthz(50,120,"起点站",48,50,RED);
				puthz(50,120+210,"终点站",48,50,RED);
				puthz(200+120-10,80,"校大门",32,34,RED);
				puthz(200+10+80*3,80,"图书馆",32,34,RED);
				puthz(200+120-40-10,180,"幼儿园",32,34,RED);
				puthz(200+10+80*3+20,180,"校医院",32,34,RED);
				puthz(200+120-30,80+210,"图书馆",32,34,RED);
				puthz(200+10+80*3-10,80+210,"幼儿园",32,34,RED);
				puthz(200+120-30,180+210,"校医院",32,34,RED);
				puthz(200+10+80*3+20,180+210,"喻园",32,34,RED);
				getimage(10, 20, 80, 80, saveimage1);
				getimage(170, 20, 240,100, saveimage2);
			}
		}
		else if (state2 == 1 && MouseX > 160 && MouseX < 240 && MouseY>20 && MouseY < 100)//选择要查询的车次(不能选择查询所有乘坐过同一车次的人)
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
		else if(state3!=0)//选择上下车站
		{
			if (judge_station(state3,&start,&end)!=1)//利用judge_station的返回值来判断鼠标是否在功能窗口内
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