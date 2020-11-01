#include"public.h"
#include"track.h"
#include"visual.h"
/**************************
visualize.c
COPYRIGHT:	shenlei
FUNCTION:	visualize the track and the list of the name of passengers,choose the information of trip 
ABSTRACT:
		A.visualize the track
        B.visualize the list of the name of passengers
        C.choose the information
DATE:2020/10/11
****************************/

/*********************************************
FUNCTION:judge_visual
DESCRIPTION:在显示轨迹时判断输出哪张图并输出
INPUT:int state3,int start,int end
RETURN:void
***********************************************/

void judge_visual(int state3,int start,int end)//
{   
    if(state3==1)
    {
        switch(end)
        {
            case 1:
                cleardevice();
                track000();
                track112();
                getch();
                break;
            case 2:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track113();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track123();
                    getch();
                }
                break;
            case 3:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track114();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track124();
                    getch();
                }
                else if(start==3)
                {
                    cleardevice();
                    track000();
                    track134();
                    getch();
                }
                break;
            case 4:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track115();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track125();
                    getch();
                }
                else if(start==3)
                {
                    cleardevice();
                    track000();
                    track135();
                    getch();
                }
                else if(start==4)
                {
                    cleardevice();
                    track000();
                    track145();
                    getch();
                }
                break;
        }
    }
    else if(state3==2)
    {
        switch(end)
        {
            case 1:
                cleardevice();
                track000();
                track212();
                getch();
                break;
            case 2:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track213();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track223();
                    getch();
                }
                break;
            case 3:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track214();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track224();
                    getch();
                }
                else if(start==3)
                {
                    cleardevice();
                    track000();
                    track234();
                    getch();
                }
                break;
            case 4:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track215();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track225();
                    getch();
                }
                else if(start==3)
                {
                    cleardevice();
                    track000();
                    track235();
                    getch();
                }
                else if(start==4)
                {
                    cleardevice();
                    track000();
                    track245();
                    getch();
                }
                break;
        }
    }
    else if(state3==3)
    {
        switch(end)
        {
            case 1:
                cleardevice();
                track000();
                track312();
                getch();
                break;
            case 2:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track313();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track323();
                    getch();
                }
                break;
            case 3:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track314();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track324();
                    getch();
                }
                else if(start==3)
                {
                    cleardevice();
                    track000();
                    track334();
                    getch();
                }
                break;
            case 4:
                if(start==1)
                {
                    cleardevice();
                    track000();
                    track315();
                    getch();
                }
                else if(start==2)
                {
                    cleardevice();
                    track000();
                    track325();
                    getch();
                }
                else if(start==3)
                {
                    cleardevice();
                    track000();
                    track335();
                    getch();
                }
                else if(start==4)
                {
                    cleardevice();
                    track000();
                    track345();
                    getch();
                }
                break;
        }
    }
}

/*********************************************
FUNCTION:judge_station
DESCRIPTION:判断选择的起点和终点
INPUT:int state3,int *start,int *end
RETURN:0 or 1
***********************************************/

int judge_station(int state3,int *start,int *end)//判断选择的起点和终点
{
    MouseS=0;
    if (MouseX > 250 && MouseX < 420 && MouseY>30 && MouseY < 135)
    {
        if (mouse_press(250, 30, 420, 135) == 2)
        {
            MouseS = 1;
        }
        else if(mouse_press(250, 30, 420, 135) == 1)
        {
            choice_switch(state3,1);
            *start=1;
        }
    }
    else if (MouseX > 420 && MouseX < 600 && MouseY>30 && MouseY < 135)
    {
        if (mouse_press(420, 30, 600, 135) == 2)
        {
            MouseS = 1;
        }
        else if(mouse_press(420, 30, 600, 135) == 1)
        {
            choice_switch(state3,2);
            *start=2;
        }
    }
    else if (MouseX > 250 && MouseX < 420 && MouseY>135 && MouseY < 240)
    {
        if (mouse_press(250, 135, 420, 240) == 2)
        {
            MouseS = 1;
        }
        else if(mouse_press(250, 135, 420, 240) == 1)
        {
            choice_switch(state3,3);
            *start=3;
        }
    }
    else if (MouseX > 420 && MouseX < 600 && MouseY>135 && MouseY < 240)
    {
        if (mouse_press(420, 135, 600, 240) == 2)
        {
            MouseS = 1;
        }
        else if(mouse_press(420, 135, 600, 240) == 1)
        {
            clrmous(MouseX,MouseY);
            choice_switch(state3,4);
            *start=4;
        }
    }
    else if (MouseX > 250 && MouseX < 420 && MouseY>30+210 && MouseY < 135+210)
    {
        if (mouse_press(250, 30+210, 420, 135+210) == 2)
        {
            MouseS = 1;
        }
        else if(mouse_press(250, 30+210, 420, 135+210) == 1)
        {
            choice_switch(state3,5);
            *end=1;
        }
    }
    else if (MouseX > 420 && MouseX < 600 && MouseY>30+210 && MouseY < 135+210)
    {
        if (mouse_press(420, 30+210, 600, 135+210) == 2)
        {
            MouseS = 1;
        }
        else if(mouse_press(420, 30+210, 600, 135+210) == 1)
        {
            choice_switch(state3,6);
            *end=2;
        }
    }
    else if (MouseX > 250 && MouseX < 420 && MouseY>135+210 && MouseY < 240+210)
    {
        if (mouse_press(250, 135+210, 420, 240+210) == 2)
        {
            MouseS = 1;
        }
        else if(mouse_press(250, 135+210, 420, 240+210) == 1)
        {
            choice_switch(state3,7);
            *end=3;
        }
    }
    else if (MouseX > 420 && MouseX < 600 && MouseY>135+210 && MouseY < 240+210)
    {
        if (mouse_press(420, 135+210, 600, 240+210) == 2)
        {
            MouseS = 1;
        }
        else if(mouse_press(420, 135+210, 600, 240+210) == 1)
        {
            choice_switch(state3,8);
            *end=4;
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

/*********************************************
FUNCTION:choice_switch
DESCRIPTION:选择乘车信息时单元格的按键及字符变化
INPUT:int state3,int botton
RETURN:void
***********************************************/

void choice_switch(int state3,int botton)//
{
    clrmous(MouseX,MouseY);
    setfillstyle(1,YELLOW);
    if(botton<=4)
    {
        floodfill(255,35,DARKGRAY);
        floodfill(200+10+80*3,80,DARKGRAY);
        floodfill(200+120-40-10,180,DARKGRAY);
        floodfill(200+10+80*3+20,180,DARKGRAY);
    }
    else
    {
        floodfill(200+120-30,80+210,DARKGRAY);
        floodfill(200+10+80*3-10,80+210,DARKGRAY);
        floodfill(200+120-30,180+210,DARKGRAY);
        floodfill(200+10+80*3+20,180+210,DARKGRAY);
    }
    if(state3==1)
    {
        puthz(200+120-10,80,"紫菘",32,34,RED);
        puthz(200+10+80*3,80,"科技楼",32,34,RED);
        puthz(200+120-40-10,180,"机械大楼",32,34,RED);
        puthz(200+10+80*3+20,180,"喻园",32,34,RED);
        puthz(200+120-30,80+210,"科技楼",32,34,RED);
        puthz(200+10+80*3-10,80+210,"机械大楼",32,34,RED);
        puthz(200+120-30,180+210,"喻园",32,34,RED);
        puthz(200+10+80*3+20,180+210,"韵苑",32,34,RED);
        clrmous(MouseX,MouseY);
        setcolor(DARKGRAY);
        setfillstyle(1,LIGHTRED);
        switch(botton)
        {
            case 1:
                floodfill(255,35,DARKGRAY);
                puthz(200+120-10,80,"紫菘",32,34,RED);
                break;
            case 2:
                floodfill(200+10+80*3,80,DARKGRAY);
                puthz(200+10+80*3,80,"科技楼",32,34,RED);
                break;
            case 3:
                floodfill(200+120-40-10,180,DARKGRAY);
                puthz(200+120-40-10,180,"机械大楼",32,34,RED);
                break;
            case 4:
                floodfill(200+10+80*3+20,180,DARKGRAY);
                puthz(200+10+80*3+20,180,"喻园",32,34,RED);
                break;
            case 5:
                floodfill(200+120-30,80+210,DARKGRAY);
                puthz(200+120-30,80+210,"科技楼",32,34,RED);
                break;
            case 6:
                floodfill(200+10+80*3-10,80+210,DARKGRAY);
                puthz(200+10+80*3-10,80+210,"机械大楼",32,34,RED);
                break;
            case 7:
                floodfill(200+120-30,180+210,DARKGRAY);
                puthz(200+120-30,180+210,"喻园",32,34,RED);
                break;
            case 8:
                floodfill(200+10+80*3+20,180+210,DARKGRAY);
                puthz(200+10+80*3+20,180+210,"韵苑",32,34,RED);
                break;
        }
    }
    else if(state3==2)
    {
        puthz(200+120-40,80,"校大门",32,34,RED);
        puthz(200+10+80*3+10,80,"图书馆",32,34,RED);
        puthz(200+120-40+10,180,"大活",32,34,RED);
        puthz(200+10+80*3,180,"集贸市场",32,34,RED);
        puthz(200+120-30,80+210,"图书馆",32,34,RED);
        puthz(200+10+80*3+10,80+210,"大活",32,34,RED);
        puthz(200+120-40,180+210,"集贸市场",32,34,RED);
        puthz(200+10+80*3+20,180+210,"韵苑",32,34,RED);
        clrmous(MouseX,MouseY);
        setcolor(DARKGRAY);
        setfillstyle(1,LIGHTGREEN);
        switch(botton)//字符变化
        {
            case 1:
                floodfill(200+120-10,80,DARKGRAY);
				puthz(200+120-40,80,"校大门",32,34,RED);
                break;
            case 2:
                floodfill(200+10+80*3,80,DARKGRAY);
				puthz(200+10+80*3+10,80,"图书馆",32,34,RED);
                break;
            case 3:
                floodfill(200+120-40-10,180,DARKGRAY);
				puthz(200+120-40+10,180,"大活",32,34,RED);
                break;
            case 4:
                floodfill(200+10+80*3+20,180,DARKGRAY);
				puthz(200+10+80*3,180,"集贸市场",32,34,RED);
                break;
            case 5:
                floodfill(200+120-30,80+210,DARKGRAY);
				puthz(200+120-30,80+210,"图书馆",32,34,RED);
                break;
            case 6:
                floodfill(200+10+80*3-10,80+210,DARKGRAY);
				puthz(200+10+80*3+10,80+210,"大活",32,34,RED);
                break;
            case 7:
                floodfill(200+120-30,180+210,DARKGRAY);
				puthz(200+120-40,180+210,"集贸市场",32,34,RED);
                break;
            case 8:
                floodfill(200+10+80*3+20,180+210,DARKGRAY);
				puthz(200+10+80*3+20,180+210,"韵苑",32,34,RED);
                break;
        }
    }
    else if(state3==3)
    {
        clrmous(MouseX,MouseY);
        setcolor(DARKGRAY);
        setfillstyle(1,LIGHTBLUE);
        puthz(200+120-10,80,"校大门",32,34,RED);
        puthz(200+10+80*3,80,"图书馆",32,34,RED);
        puthz(200+120-40-10,180,"幼儿园",32,34,RED);
        puthz(200+10+80*3+20,180,"校医院",32,34,RED);
        puthz(200+120-30,80+210,"图书馆",32,34,RED);
        puthz(200+10+80*3-10,80+210,"幼儿园",32,34,RED);
        puthz(200+120-30,180+210,"校医院",32,34,RED);
        puthz(200+10+80*3+20,180+210,"喻园",32,34,RED);
        switch(botton)//字符变化
        {
            case 1:
                floodfill(200+120-10,80,DARKGRAY);
                puthz(200+120-10,80,"校大门",32,34,RED);
                break;
            case 2:
                floodfill(200+10+80*3,80,DARKGRAY);
                puthz(200+10+80*3,80,"图书馆",32,34,RED);
                break;
            case 3:
                floodfill(200+120-40-10,180,DARKGRAY);
                puthz(200+120-40-10,180,"幼儿园",32,34,RED);
                break;
            case 4:
                floodfill(200+10+80*3+20,180,DARKGRAY);
                puthz(200+10+80*3+20,180,"校医院",32,34,RED);
                break;
            case 5:
                floodfill(200+120-30,80+210,DARKGRAY);
                puthz(200+120-30,80+210,"图书馆",32,34,RED);
                break;
            case 6:
                floodfill(200+10+80*3-10,80+210,DARKGRAY);
                puthz(200+10+80*3-10,80+210,"幼儿园",32,34,RED);
                break;
            case 7:
                floodfill(200+120-30,180+210,DARKGRAY);
                puthz(200+120-30,180+210,"校医院",32,34,RED);
                break;
            case 8:
                floodfill(200+10+80*3+20,180+210,DARKGRAY);
                puthz(200+10+80*3+20,180+210,"喻园",32,34,RED);
                break;
        }
    }
}

/*********************************************
FUNCTION:passenger_list
DESCRIPTION:打印乘客名单并可视化
INPUT:int checi
RETURN:0 or 1
***********************************************/

void passenger_list(int checi)
{
    FILE* fp=NULL;
    int i=0;
    int j=0;
    int k=0;
    char s[1000];
    char name[20];
    memset(s,'\0',1000);
    memset(name,'\0',20);
    bar(40, 30, 600, 450);//清除功能界面，防止后面切换功能界面会和该功能界面重叠
	setfillstyle(1,YELLOW);
	setcolor(DARKGRAY);
	rectangle(40, 30, 600, 450);
	floodfill(50,40,DARKGRAY);
    if(checi==1)
    {
        for(k=0;k<50;k++)
        {
            draw_seat(125+(k/5)*50,80+(k%5)*80,1);
        }
        if((fp=fopen("checi1.txt","r"))!=NULL)
        {
            fgets(s,1000,fp);
            fclose(fp);
        }
        else
        {
            exit(-1);
        }
    }
    else if(checi==2)
    {
        for(k=0;k<50;k++)
        {
            draw_seat(125+(k/5)*50,80+(k%5)*80,2);
        }
        if((fp=fopen("checi2.txt","r"))!=NULL)
        {
            fgets(s,1000,fp);
            fclose(fp);
        }
        else
        {
            exit(-1);
        }
    }
    else
    {
        for(k=0;k<50;k++)
        {
            draw_seat(125+(k/5)*50,80+(k%5)*80,3);
        }
        if((fp=fopen("checi3.txt","r"))!=NULL)
        {
            fgets(s,1000,fp);
            fclose(fp);
        }
        else
        {
            exit(-1);
        }
    }
    k=0;
    while(s[i]!='\0')
    {
        while(s[i]!='*')
        {
            name[j]=s[i];
            j++;
            i++;
        }
        setcolor(DARKGRAY);
        settextstyle(0,1,1);
        outtextxy(125+(k/5)*50,80+(k%5)*80,name);
        k++;
        i++;
        j=0;
        memset(name,'\0',20);
    }
    memset(s,'\0',1000);
}
void draw_seat(int x,int y,int color)
{
    setcolor(RED);
    line(x-20,y-30,x-20,y+30);
    line(x+20,y-30,x+20,y+30);
    line(x-15,y-35,x+15,y-35);
    line(x-15,y+35,x+15,y+35);
    arc(x-15,y-30,90,180,5);
    arc(x-15,y+30,180,270,5);
    arc(x+15,y-30,0,90,5);
    arc(x+15,y+30,270,360,5);
    if(color==1)
    {
        setfillstyle(1,LIGHTRED);
    }
    else if(color==2)
    {
        setfillstyle(1,LIGHTGREEN);
    }
    else
    {
        setfillstyle(1,LIGHTBLUE);
    }
    floodfill(x,y,RED);
}