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
DESCRIPTION�����ڽ���Ļ�ͼ����
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
	puthz(250, 0, "�����Ϣ˵��", 16, 17, DARKGRAY);
	puthz(0, 16, "Ӧ�����ƣ�", 16, 17, DARKGRAY);
	puthz(0+16*5, 16, "������ͨ�˿��г�ϵͳ", 16, 17, DARKGRAY);
	puthz(0, 16*2, "�����ߣ�", 16, 17, DARKGRAY);
	puthz(0+16*4, 16*2, "����", 16, 17, DARKGRAY);
	puthz(0+16*7, 16*2, "�޲���", 16, 17, DARKGRAY);
	puthz(0, 16*3, "ָ����ʦ��", 16, 17, DARKGRAY);
	puthz(0+16*5, 16*3, "�ܴ���", 16, 17, DARKGRAY);
	puthz(0+16*9, 16*3, "�ܿ���", 16, 17, DARKGRAY);
	puthz(0+16*13, 16*3, "���", 16, 17, DARKGRAY);
	puthz(0+16*16, 16*3, "�ζ���", 16, 17, DARKGRAY);
	puthz(0+16*20, 16*3, "�����", 16, 17, DARKGRAY);
	puthz(0+16*24, 16*3, "�߳���", 16, 17, DARKGRAY);
	puthz(0+16*28, 16*3, "������", 16, 17, DARKGRAY);
	puthz(0+16*32, 16*3, "ɣũ", 16, 17, DARKGRAY);
	puthz(0+16*35, 16*3, "����", 16, 17, DARKGRAY);
	puthz(0, 16*4, "��дĿ�ģ�", 16, 17, DARKGRAY);
	puthz(0, 16*5, "���Ź��ҳ��л����̵Ĳ����ƽ������й�����ͨ������Ϊ���������в��ɻ�ȱ��һ��", 16, 17, DARKGRAY);
	puthz(0, 16*6, "�֣�Ȼ�����ڶ���˽�ĵ��ǺͶ��г̹�������Ӳ��㣬��Ե����û����г̼�¼�Ͳ�", 16, 17, DARKGRAY);
	puthz(0, 16*7, "ѯ�������չ�ý�Ϊ������", 16, 17, DARKGRAY);
	puthz(0, 16*8, "Ȼ������������У���Ե����û����г̷�����׷�ݲ�����Դ�����Ƹ�Ⱦ���а�����", 16, 17, DARKGRAY);
	puthz(0, 16*9, "�������ص����ã������������Ч���ƺܴ�̶���ҲҪ�鹦�ڽ�Ϊ���Ƶ��г�׷�ٻ�", 16, 17, DARKGRAY);
	puthz(0, 16*10, "�ƣ�������Ƕ��г̹�������Ӷ�Ҳ����������ߡ�ֵ��ע����ǣ��г̹�������", 16, 17, DARKGRAY);
	puthz(0, 16*11, "��Ⱦ���Ĺܿ�������Ҫ���壬�������°����������Ҳ�ᷢ�����������á�", 16, 17, DARKGRAY);
	puthz(0, 16*12, "��������ʵ�ʵĿ���������ϣ����д��һ��򵥵Ĺ�����ͨ�г�ϵͳ���԰����û���", 16, 17, DARKGRAY);
	puthz(0, 16*13, "���Լ����г���Ϣ����ѯ������ͬ���ι�����ͨ���ߵ������˿ͣ��Ը��õ�Ӧ������", 16, 17, DARKGRAY);
	puthz(0, 16*14, "����������׷�ݺͽ�������", 16, 17, DARKGRAY);
	puthz(0, 16*15, "�ο������", 16, 17, DARKGRAY);
	puthz(0, 16*16, "΢��С����˳���", 16, 17, DARKGRAY);
	puthz(0, 16*17, "֧�����˳���", 16, 17, DARKGRAY);
	puthz(0, 16*18, "��Ҫ���ܣ�", 16, 17, DARKGRAY);
	puthz(0, 16*19, "���û�ģʽ���ο�ģʽ", 16, 17, DARKGRAY);
	puthz(0+16*11, 16*19, "�ο�ģʽ�����û���ѯʹ��", 16, 17, DARKGRAY);
	puthz(0, 16*20, "�û���¼��������ӳ˳���¼", 16, 17, DARKGRAY);
	puthz(0, 16*21, "�˳���¼���ӻ���ʾ", 16, 17, DARKGRAY);
	puthz(0, 16*22, "�˳����ι����˿͹켣ͼ�λ���ʾ����", 16, 17, DARKGRAY);
	outtextxy(500, 16*24, "VERSION:1.0.0");
	puthz(450, 16*26, "���������ʮ����ʮһ��", 16, 17, DARKGRAY);
	button_back();
}

/*********************************************
FUNCTION:fgpass_drawer
DESCRIPTION�����ڽ���Ĺ��ܺ���
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
/*void main()//���Ժ���
{
	int graphdriver, graphmode;
	graphdriver = DETECT;
	initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
	g_about();
	getch();
}*/