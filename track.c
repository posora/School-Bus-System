#include"public.h"

/*****************************************
track.c
COPYRIGHT:	zoubojin
FUNCTION:	a map of school's bus routes
ABSTRACT:
        all bus routes
DATE:2020/9/25
******************************************/

/*********************************************
FUNCTION:track000
DESCRIPTION:总的学校地图
INPUT:void
RETURN:void
***********************************************/

void track000()//
{
    int i,j;
    setbkcolor(WHITE);
    //clrscr();
    setcolor(LIGHTGRAY);
    setlinestyle(0, 1, 3);
	for (i = 0; i <= 8; i++)
	{
		for(j=0;j<=3;j++)
        {  
                line(100+50*i+3*j, 100, 100+50*i+3*j, 415);
        }
	}
    for (i = 0; i <= 9; i++)
	{
		for(j=0;j<=3;j++)
        {  
                line(100, 100+35*i+3*j, 500+9, 100+35*i+3*j);
        }
	}
    setcolor(WHITE);
    for(i=0;i<=3;i++)
    {
        line(100+4*3-1,170+3*i,150-2,170+3*i);
        line(100+4*3-1,205+3*i,150-2,205+3*i);
        line(150+4*3-1,135+3*i,200-2,135+3*i);
        line(250+3*i,100+4*3-1,250+3*i,135-2);
    }
    setcolor(WHITE);
    bar(300+4*3-1,305+4*3+3,400-2,415-2+4*3);
    bar(450+4*3-1,275+4*3-1,500+4*3-1,415+4*3+1);
    bar(350+4*3-1,100-1,450-2,170-2);
}
/*********************************************
FUNCTION:track115
DESCRIPTION:第一条线的全程
INPUT:void
RETURN:void
***********************************************/
void track115()
{
    int i,j;
    for(i=0;i<=3;i++)
    {   
        setcolor(RED);
        setlinestyle(0,1,3);
        line(100+4*3-2,275+3*i,400+4*3-2,275+3*i);
        line(400+3*i,275,400+3*i,205);
        line(400,205+3*i,450,205+3*i);
        circle(106,281,6+1*i);
        circle(256, 281, 6 + i);
        circle(406,281,6+i);
        circle(406,211,6+i);
        circle(456,211,6+i);       
    }
    setcolor(WHITE);
    for(i=0;i<6;i++)
    {
        circle(106,281,i);
        circle(256,281,i);
        circle(406,281,i);
        circle(406,211,i);
        circle(456,211,i);      
    }
}
/*********************************************
FUNCTION:track112
DESCRIPTION:第一条线第一站到第二站
INPUT:void
RETURN:void
***********************************************/
void track112()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        line(100 + 4 * 3 - 2, 275 + 3 * i, 256, 275 + 3 * i);
        //line(400 + 3 * i, 275, 400 + 3 * i, 205);
        //line(400, 205 + 3 * i, 450, 205 + 3 * i);
        circle(106, 281, 6 + 1 * i);
        circle(256, 281, 6 + i);
        //circle(406, 281, 6 + i);
        //circle(406, 211, 6 + i);
        //circle(456, 211, 6 + i);
        
        
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(106, 281, i);
        circle(256, 281, i);
        //circle(406, 281, i);
        //circle(406, 211, i);
        //circle(456, 211, i);
        
    }
}
/*********************************************
FUNCTION:track113
DESCRIPTION:第一条线第一站到第三站
INPUT:void
RETURN:void
***********************************************/
void track113()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        line(100 + 4 * 3 - 2, 275 + 3 * i, 406, 275 + 3 * i);
        //line(400 + 3 * i, 275, 400 + 3 * i, 205);
        //line(400, 205 + 3 * i, 450, 205 + 3 * i);
        circle(106, 281, 6 + 1 * i);
        circle(256, 281, 6 + i);
        circle(406, 281, 6 + i);
        //circle(406, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(106, 281, i); 
        circle(256, 281, i);
        circle(406, 281, i);      
        //circle(406, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track114
DESCRIPTION:第一条线第一站到第四站
INPUT:void
RETURN:void
***********************************************/
void track114()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        line(100 + 4 * 3 - 2, 275 + 3 * i, 400 + 4 * 3 - 2, 275 + 3 * i);
        line(400 + 3 * i, 275, 400 + 3 * i, 205);
        //line(400, 205 + 3 * i, 450, 205 + 3 * i);
        circle(106, 281, 6 + 1 * i);
        circle(256, 281, 6 + i);
        circle(406, 281, 6 + i);
        circle(406, 211, 6 + i);
        //circle(456, 211, 6 + i);
       
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(106, 281, i); 
        circle(256, 281, i);
        circle(406, 281, i);
        circle(406, 211, i);
        //circle(456, 211, i);      
    }
}
/*********************************************
FUNCTION:track123
DESCRIPTION:第一条线第二站到第三站
INPUT:void
RETURN:void
***********************************************/
void track123()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        line(256, 275 + 3 * i, 400 + 4 * 3 - 2, 275 + 3 * i);
        //line(400 + 3 * i, 275, 400 + 3 * i, 205);
        //line(400, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(106, 281, 6 + 1 * i);
        circle(256, 281, 6 + i);
        circle(406, 281, 6 + i);
        //circle(406, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(106, 281, i);
        circle(256, 281, i);
        circle(406, 281, i);
        //circle(406, 211, i);
        //circle(456, 211, i);       
    }
}
/*********************************************
FUNCTION:track123
DESCRIPTION:第一条线第二站到第四站
INPUT:void
RETURN:void
***********************************************/
void track124()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        line(256, 275 + 3 * i, 400 + 4 * 3 - 2, 275 + 3 * i);
        line(400 + 3 * i, 275, 400 + 3 * i, 205);
        //line(400, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(106, 281, 6 + 1 * i);
        circle(256, 281, 6 + i);
        circle(406, 281, 6 + i);
        circle(406, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(106, 281, i);
        circle(256, 281, i);
        circle(406, 281, i);
        circle(406, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track123
DESCRIPTION:第一条线第二站到第五站
INPUT:void
RETURN:void
***********************************************/
void track125()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        line(256, 275 + 3 * i, 400 + 4 * 3 - 2, 275 + 3 * i);
        line(400 + 3 * i, 275, 400 + 3 * i, 205);
        line(400, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(106, 281, 6 + 1 * i);
        circle(256, 281, 6 + i);
        circle(406, 281, 6 + i);
        circle(406, 211, 6 + i);
        circle(456, 211, 6 + i);      
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(106, 281, i);
        circle(256, 281, i);
        circle(406, 281, i);
        circle(406, 211, i);
        circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track134
DESCRIPTION:第一条线第三站到第四站
INPUT:void
RETURN:void
***********************************************/
void track134()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        //line(100 + 4 * 3 - 2, 275 + 3 * i, 400 + 4 * 3 - 2, 275 + 3 * i);
        line(400 + 3 * i, 275, 400 + 3 * i, 205);
        //line(400, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(106, 281, 6 + 1 * i);
        //circle(256, 281, 6 + i);
        circle(406, 281, 6 + i);
        circle(406, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(106, 281, i);
        //circle(256, 281, i);
        circle(406, 281, i);
        circle(406, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track135
DESCRIPTION:第一条线第三站到第五站
INPUT:void
RETURN:void
***********************************************/
void track135()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        //line(100 + 4 * 3 - 2, 275 + 3 * i, 400 + 4 * 3 - 2, 275 + 3 * i);
        line(400 + 3 * i, 275, 400 + 3 * i, 205);
        line(400, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(106, 281, 6 + 1 * i);
        //circle(256, 281, 6 + i);
        circle(406, 281, 6 + i);
        circle(406, 211, 6 + i);
        circle(456, 211, 6 + i); 
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(106, 281, i);
        //circle(256, 281, i);
        circle(406, 281, i);
        circle(406, 211, i);
        circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track123
DESCRIPTION:第一条线第四站到第五站
INPUT:void
RETURN:void
***********************************************/
void track145()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(RED);
        setlinestyle(0, 1, 3);
        //line(100 + 4 * 3 - 2, 275 + 3 * i, 400 + 4 * 3 - 2, 275 + 3 * i);
        //line(400 + 3 * i, 275, 400 + 3 * i, 205);
        line(400, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(106, 281, 6 + 1 * i);
        //circle(256, 281, 6 + i);
        //circle(406, 281, 6 + i);
        circle(406, 211, 6 + i);
        circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(106, 281, i);
        //circle(256, 281, i);
        //circle(406, 281, i);
        circle(406, 211, i);
        circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track215
DESCRIPTION:第二条线第一站到第五站
INPUT:void
RETURN:void
***********************************************/
void track215()
{
    int i,j;
    for(i=0;i<=3;i++)
    {   
        setcolor(GREEN);
        setlinestyle(0,1,3);
        line(200+3*i,415,200+3*i,275);
        line(200,275+3*i,250,275+3*i);
        line(250+3*i,275,250+3*i,205);
        line(250,205+3*i,450,205+3*i);
        circle(206,421,6+1*i);
        circle(206,281,6+i);
        circle(256,281,6+i);
        circle(256,211,6+i);
        circle(456,211,6+i);
    }
    setcolor(WHITE);
    for(i=0;i<6;i++)
    {
        circle(206,421,1*i);
        circle(206,281,i);
        circle(256,281,i);
        circle(256,211,i);
        circle(456,211,i);
    }   
}
/*********************************************
FUNCTION:track212
DESCRIPTION:第二条线第一站到第二站
INPUT:void
RETURN:void
***********************************************/
void track212()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        line(200 + 3 * i, 415, 200 + 3 * i, 275);
        //line(200, 275 + 3 * i, 250, 275 + 3 * i);
        //line(250 + 3 * i, 275, 250 + 3 * i, 205);
        //line(250, 205 + 3 * i, 450, 205 + 3 * i);
        circle(206, 421, 6 + 1 * i);
        circle(206, 281, 6 + i);
        //circle(256, 281, 6 + i);
        //circle(256, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(206, 421, 1 * i);
        circle(206, 281, i);
        //circle(256, 281, i);
        //circle(256, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track213
DESCRIPTION:第二条线第一站到第三站
INPUT:void
RETURN:void
***********************************************/
void track213()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        line(200 + 3 * i, 415, 200 + 3 * i, 275);
        line(200, 275 + 3 * i, 250, 275 + 3 * i);
        //line(250 + 3 * i, 275, 250 + 3 * i, 205);
        //line(250, 205 + 3 * i, 450, 205 + 3 * i);
        circle(206, 421, 6 + 1 * i);
        circle(206, 281, 6 + i);
        circle(256, 281, 6 + i);
        //circle(256, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(206, 421, 1 * i);
        circle(206, 281, i);
        circle(256, 281, i);
        //circle(256, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track214
DESCRIPTION:第二条线第一站到第四站
INPUT:void
RETURN:void
***********************************************/
void track214()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        line(200 + 3 * i, 415, 200 + 3 * i, 275);
        line(200, 275 + 3 * i, 250, 275 + 3 * i);
        line(250 + 3 * i, 275, 250 + 3 * i, 205);
        //line(250, 205 + 3 * i, 450, 205 + 3 * i);
        circle(206, 421, 6 + 1 * i);
        circle(206, 281, 6 + i);
        circle(256, 281, 6 + i);
        circle(256, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(206, 421, 1 * i);
        circle(206, 281, i);
        circle(256, 281, i);
        circle(256, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track223
DESCRIPTION:第二条线第二站到第三站
INPUT:void
RETURN:void
***********************************************/
void track223()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 275);
        line(200, 275 + 3 * i, 250, 275 + 3 * i);
        //line(250 + 3 * i, 275, 250 + 3 * i, 205);
        //line(250, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        circle(206, 281, 6 + i);
        circle(256, 281, 6 + i);
        //circle(256, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        circle(206, 281, i);
        circle(256, 281, i);
        //circle(256, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track224
DESCRIPTION:第二条线第二站到第四站
INPUT:void
RETURN:void
***********************************************/
void track224()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 275);
        line(200, 275 + 3 * i, 250, 275 + 3 * i);
        line(250 + 3 * i, 275, 250 + 3 * i, 205);
        //line(250, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        circle(206, 281, 6 + i);
        circle(256, 281, 6 + i);
        circle(256, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        circle(206, 281, i);
        circle(256, 281, i);
        circle(256, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track225
DESCRIPTION:第二条线第二站到第五站
INPUT:void
RETURN:void
***********************************************/
void track225()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 275);
        line(200, 275 + 3 * i, 250, 275 + 3 * i);
        line(250 + 3 * i, 275, 250 + 3 * i, 205);
        line(250, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        circle(206, 281, 6 + i);
        circle(256, 281, 6 + i);
        circle(256, 211, 6 + i);
        circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        circle(206, 281, i);
        circle(256, 281, i);
        circle(256, 211, i);
        circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track234
DESCRIPTION:第二条线第三站到第四站
INPUT:void
RETURN:void
***********************************************/
void track234()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 275);
        //line(200, 275 + 3 * i, 250, 275 + 3 * i);
        line(250 + 3 * i, 275, 250 + 3 * i, 205);
        //line(250, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        //circle(206, 281, 6 + i);
        circle(256, 281, 6 + i);
        circle(256, 211, 6 + i);
        //circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        //circle(206, 281, i);
        circle(256, 281, i);
        circle(256, 211, i);
        //circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track235
DESCRIPTION:第二条线第三站到第五站
INPUT:void
RETURN:void
***********************************************/
void track235()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 275);
        //line(200, 275 + 3 * i, 250, 275 + 3 * i);
        line(250 + 3 * i, 275, 250 + 3 * i, 205);
        line(250, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        //circle(206, 281, 6 + i);
        circle(256, 281, 6 + i);
        circle(256, 211, 6 + i);
        circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        //circle(206, 281, i);
        circle(256, 281, i);
        circle(256, 211, i);
        circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track245
DESCRIPTION:第二条线第四站到第五站
INPUT:void
RETURN:void
***********************************************/
void track245()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(GREEN);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 275);
        //line(200, 275 + 3 * i, 250, 275 + 3 * i);
        //line(250 + 3 * i, 275, 250 + 3 * i, 205);
        line(250, 205 + 3 * i, 450, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        //circle(206, 281, 6 + i);
        //circle(256, 281, 6 + i);
        circle(256, 211, 6 + i);
        circle(456, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        //circle(206, 281, i);
        //circle(256, 281, i);
        circle(256, 211, i);
        circle(456, 211, i);
    }
}
/*********************************************
FUNCTION:track315
DESCRIPTION:第三条线第一站到第五站
INPUT:void
RETURN:void
***********************************************/
void track315()
{
    int i,j;
    for(i=0;i<=3;i++)
    {   
        setcolor(YELLOW);
        setlinestyle(0,1,3);
        line(200+3*i,415,200+3*i,135);
        line(200,135+3*i,300,135+3*i);
        line(300+3*i,135,300+3*i,205);
        line(300,205+3*i,350,205+3*i);
        circle(206,421,6+1*i);
        circle(206,141,6+i);
        circle(306,141,6+i);
        circle(306,211,6+i);
        circle(356,211,6+i);
    }
    setcolor(WHITE);
    for(i=0;i<6;i++)
    {
        circle(206,421,1*i);
        circle(206,141,i);
        circle(306,141,i);
        circle(306,211,i);
        circle(356,211,i);
    }
}
/*********************************************
FUNCTION:track315
DESCRIPTION:第三条线第一站到第二站
INPUT:void
RETURN:void
***********************************************/
void track312()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        line(200 + 3 * i, 421, 200 + 3 * i, 135);
        //line(200, 135 + 3 * i, 300, 135 + 3 * i);
        //line(300 + 3 * i, 135, 300 + 3 * i, 205);
        //line(300, 205 + 3 * i, 350, 205 + 3 * i);
        circle(206, 421, 6 + 1 * i);
        circle(206, 141, 6 + i);
        //circle(306, 141, 6 + i);
        //circle(306, 211, 6 + i);
        //circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(206, 421, 1 * i);
        circle(206, 141, i);
        //circle(306, 141, i);
        //circle(306, 211, i);
        //circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track313
DESCRIPTION:第三条线第一站到第三站
INPUT:void
RETURN:void
***********************************************/
void track313()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        line(200 + 3 * i, 415, 200 + 3 * i, 135);
        line(200, 135 + 3 * i, 300, 135 + 3 * i);
        //line(300 + 3 * i, 135, 300 + 3 * i, 205);
        //line(300, 205 + 3 * i, 350, 205 + 3 * i);
        circle(206, 421, 6 + 1 * i);
        circle(206, 141, 6 + i);
        circle(306, 141, 6 + i);
        //circle(306, 211, 6 + i);
        //circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(206, 421, 1 * i);
        circle(206, 141, i);
        circle(306, 141, i);
        //circle(306, 211, i);
        //circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track315
DESCRIPTION:第三条线第一站到第四站
INPUT:void
RETURN:void
***********************************************/
void track314()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        line(200 + 3 * i, 415, 200 + 3 * i, 135);
        line(200, 135 + 3 * i, 300, 135 + 3 * i);
        line(300 + 3 * i, 135, 300 + 3 * i, 205);
        //line(300, 205 + 3 * i, 350, 205 + 3 * i);
        circle(206, 421, 6 + 1 * i);
        circle(206, 141, 6 + i);
        circle(306, 141, 6 + i);
        circle(306, 211, 6 + i);
        //circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(206, 421, 1 * i);
        circle(206, 141, i);
        circle(306, 141, i);
        circle(306, 211, i);
        //circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track315
DESCRIPTION:第三条线第二站到第三站
INPUT:void
RETURN:void
***********************************************/
void track323()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 135);
        line(200, 135 + 3 * i, 300, 135 + 3 * i);
        //line(300 + 3 * i, 135, 300 + 3 * i, 205);
        //line(300, 205 + 3 * i, 350, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        circle(206, 141, 6 + i);
        circle(306, 141, 6 + i);
        //circle(306, 211, 6 + i);
        //circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        circle(206, 141, i);
        circle(306, 141, i);
        //circle(306, 211, i);
        //circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track324
DESCRIPTION:第三条线第二站到第四站
INPUT:void
RETURN:void
***********************************************/
void track324()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 135);
        line(200, 135 + 3 * i, 300, 135 + 3 * i);
        line(300 + 3 * i, 135, 300 + 3 * i, 205);
        //line(300, 205 + 3 * i, 350, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        circle(206, 141, 6 + i);
        circle(306, 141, 6 + i);
        circle(306, 211, 6 + i);
        //circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        circle(206, 141, i);
        circle(306, 141, i);
        circle(306, 211, i);
        //circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track325
DESCRIPTION:第三条线第二站到第五站
INPUT:void
RETURN:void
***********************************************/
void track325()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 135);
        line(200, 135 + 3 * i, 300, 135 + 3 * i);
        line(300 + 3 * i, 135, 300 + 3 * i, 205);
        line(300, 205 + 3 * i, 350, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        circle(206, 141, 6 + i);
        circle(306, 141, 6 + i);
        circle(306, 211, 6 + i);
        circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        circle(206, 141, i);
        circle(306, 141, i);
        circle(306, 211, i);
        circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track334
DESCRIPTION:第三条线第三站到第四站
INPUT:void
RETURN:void
***********************************************/
void track334()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 135);
        //line(200, 135 + 3 * i, 300, 135 + 3 * i);
        line(300 + 3 * i, 135, 300 + 3 * i, 205);
        //line(300, 205 + 3 * i, 350, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        //circle(206, 141, 6 + i);
        circle(306, 141, 6 + i);
        circle(306, 211, 6 + i);
        //circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        //circle(206, 141, i);
        circle(306, 141, i);
        circle(306, 211, i);
        //circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track315
DESCRIPTION:第三条线第三站到第五站
INPUT:void
RETURN:void
***********************************************/
void track335()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 135);
        //line(200, 135 + 3 * i, 300, 135 + 3 * i);
        line(300 + 3 * i, 135, 300 + 3 * i, 205);
        line(300, 205 + 3 * i, 350, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        //circle(206, 141, 6 + i);
        circle(306, 141, 6 + i);
        circle(306, 211, 6 + i);
        circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        //circle(206, 141, i);
        circle(306, 141, i);
        circle(306, 211, i);
        circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track345
DESCRIPTION:第三条线第四站到第五站
INPUT:void
RETURN:void
***********************************************/
void track345()
{
    int i, j;
    for (i = 0; i <= 3; i++)
    {
        setcolor(YELLOW);
        setlinestyle(0, 1, 3);
        //line(200 + 3 * i, 415, 200 + 3 * i, 135);
        //line(200, 135 + 3 * i, 300, 135 + 3 * i);
        //line(300 + 3 * i, 135, 300 + 3 * i, 205);
        line(300, 205 + 3 * i, 350, 205 + 3 * i);
        //circle(206, 421, 6 + 1 * i);
        //circle(206, 141, 6 + i);
        //circle(306, 141, 6 + i);
        circle(306, 211, 6 + i);
        circle(356, 211, 6 + i);
    }
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        //circle(206, 421, 1 * i);
        //circle(206, 141, i);
        //circle(306, 141, i);
        circle(306, 211, i);
        circle(356, 211, i);
    }
}
/*********************************************
FUNCTION:track_sta
DESCRIPTION:绘制线路图上的站点
INPUT:void
RETURN:void
***********************************************/
void track_sta()
{
    int i,j;
    setcolor(WHITE);
    for (i = 0; i < 6; i++)
    {
        circle(106, 281, i);
        circle(256, 281, i);
        circle(406, 281, i);
        circle(406, 211, i);
        circle(456, 211, i);

        circle(206, 421, i);
        circle(206, 281, i);
        //circle(256, 281, i);
        circle(256, 211, i);
        //circle(456, 211, i);

        //circle(206, 421, i);
        circle(206, 141, i);
        circle(306, 141, i);
        circle(306, 211, i);
        circle(356, 211, i);
    }
}
/*void main()//测试函数
{
    int graphdriver, graphmode;
	graphdriver = DETECT;
	initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
    track000();
    //track115();
    //track112();
    //track113();
    //track114();
    //track123();
    //track124();
    //track125();
    //track134();
    //track135();
    //track145();
    //track215();
    //track212();
    //track213();
    //track214();
    //track223();
    //track224();
    //track225();
    //track234();
    //track235();
    //track245();
    //track315();
    //track312();
    //track313();
    //track314();
    //track323();
    //track324();
    //track325();
    //track334();
    //track335();
    //track345();
    //track_sta();
    getch();//delete
}
*/