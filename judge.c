#include"public.h"
#include"judge.h"
#include"user.h"
int judge_login(char* name, char* pass)//?§Ø??????????????????
{
	user* temp=NULL,*phead=NULL;
	phead = getuser();
	outtextxy(0,200,"here");
	getch();
	temp = phead->next;
	while(temp!=NULL)//??user.c??,typedef?????????????????struct???????????????????????????
	{
		outtextxy(0,200,temp->username);
		outtextxy(0,200,temp->password);
		if (strcmp(temp->username, name) == 0)
		{
			if (strcmp(temp->password, pass) == 0)
			{
				free(temp);
				return 1;
			}
			else
			{
				free(temp);
				return 0;
			}
		}
		else
		{
			temp = temp->next;
		}
	}
	free(phead);
	free(temp);
	return 0;
}
/*int judge_forgetpassword(char* username,char* phonenum)
{

}*/