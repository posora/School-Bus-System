#include<public.h>
#include<main.h>
/**************************
main.c
COPYRIGHT:	shenlei
FUNCTION:	control the picture to skip
ABSTRACT:
		A.main function
DATE:2020/9/6
****************************/
void main()
{
	int page = 0;
	char name[20];
	int graphdriver, graphmode;
	graphdriver = DETECT;
	initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");

	mouseinit();
	while (1)
	{
		switch (page)
		{
			case 0:
				g_welcome();
				page = s_welcome();
				break;
			case 1:
				page = s_login(name);
				break;
			case 2:
				page=guest_menu1();
				break;
			case 3:
				page = s_register();
				break;
			case 4:
				page = s_fgpass();
				break;
			case 5:
				page=user_menu1(name);
				break;
			case 7:
				page=s_about();
				break;
			default:
				closegraph();
				exit(0);
		}
	}
}