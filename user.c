#include"public.h"
#include"user.h"
/**************************
user.c
COPYRIGHT:	shenlei
FUNCTION:	read and write the users.txt to add registered user
ABSTRACT:
		A.make file users.txt
		B.get the users' information and make it a linked list
DATE:2020/9/11
****************************/

/*********************************************
FUNCTION:makefile
DESCRIPTION:����Ƿ����ĵ������ޣ������ĵ�
INPUT:void
RETURN:void
***********************************************/

void makefile() //
{
	FILE *file_user;
	if (fopen("USERS.txt", "r")== NULL)
	{
		if ((file_user = fopen("USERS.txt", "w+")) == NULL)//
		{
			//printf("cannot make new file\n");
			exit(-1);
		}
	}
}

/*********************************************
FUNCTION:getuser
DESCRIPTION:��ȡ�ļ��������û�����
INPUT:void
RETURN:user* phead
***********************************************/

user* getuser()//
{
	FILE* file_user;
	user* cur=NULL;
	user* phead=(user*)malloc(sizeof(user));//��̬����ͷ�ڵ���ڴ�
	phead->next = NULL;
	cur = phead;//cur����ǰ�ڵ�
	
	if ((file_user=fopen("USERS.txt","r+")) == NULL)
	{
		outtextxy(180, 30, "NULL");
		delay(1500);
		//printf("file not found");
		exit(-1);
	}
	while (1)
	{
		user* temp = (user*)malloc(sizeof(user));//
		//char* s=NULL;//�ǵø�ָ�븳��ֵ����Ȼָ��ָ��ȷ��
		char s[60];//���������ָ���޳�ʼֵ������
		char* a=NULL;
		char name[20];
		char* n=NULL;
		n=name;
		if (!temp)
			exit(-1);
		memset(s,'\0',60);
		memset(temp->username,'\0' ,20);
		memset(temp->password, '\0', 20);
		memset(temp->phonenum, '\0', 12);
		if (fscanf(file_user,"%s*%s*%s*",s)!=1)//
		{
			//outtextxy(0, 30, "don't exist");
			temp=NULL;
			//free(temp);
			break;
		}

		a=s;
		while(*a!='*')
		{
			*n=*a;
			a++;
			n++;
		}
		*n='\0';
		a++;
		strcpy(temp->username,name);
		//outtextxy(0,150,temp->username);
		n=name;

		while(*a!='*')
		{
			*n=*a;
			a++;
			n++;
		}
		*n='\0';
		a++;
		strcpy(temp->password,name);
		//outtextxy(0,170,temp->password);
		n=name;

		while(*a!='*')
		{
			*n=*a;
			a++;
			n++;
		}
		*n='\0';
		a++;
		strcpy(temp->phonenum,name);
		//outtextxy(0,190,temp->phonenum);
		n=name;

		cur->next=temp;//
		cur = temp;//
		cur->next = NULL;//����ĩβ��NULL
		free(temp);
		temp=NULL;
	}
	fclose(file_user);
	return phead;
}

/*********************************************
FUNCTION:add_user
DESCRIPTION:����������û�
INPUT:user* phead, char* name, char* pass, char* phone
RETURN:user* phead
***********************************************/

user* add_user(user* phead, char* name, char* pass, char* phone)//
{
	user* temp = (user *)malloc(sizeof(user));//�������ʱ�ڵ�
	user* cur = phead;
	user* p;

	memset(p->username,'\0' ,20);
	memset(p->password, '\0', 20);
	memset(p->phonenum, '\0', 12);
	strcpy(temp->username,name);
	strcpy(temp->password,pass);
	strcpy(temp->phonenum , phone);
	while (1)
	{
		if (strcmp(cur->username, temp->username) == 0)//˳��ȶ��ļ��е��û�����������û���
		{
			settextstyle(1, 0, 1);
			setcolor(RED);
			outtextxy(360, 120,"unavilable username");//���������Ϣ
			delay(1500);
			return NULL;
		}
		if(strcmp(cur->phonenum,temp->phonenum)==0)
		{
			settextstyle(1, 0, 1);
			setcolor(RED);
			outtextxy(360, 320, "unaviable phonenumber");//���������Ϣ
			delay(1500);
			return NULL;
		}
		if (cur->next == NULL)
		{
			cur->next = temp;
			cur = cur->next;
			cur->next = NULL;
			p=phead->next;

			temp=NULL;//�ͷ�ָ��ǰ�ǵð�ָ���ÿգ����������ָ��Ľṹ��һ���ͷ�
			//free(temp);
			settextstyle(1, 0, 1);
			setcolor(RED);
			outtextxy(360, 154 + 240,"successfully register");
			delay(150);
			return phead;
		}
		cur = cur->next;
	}
}

/*********************************************
FUNCTION:writetofile
DESCRIPTION:���û����������Ϣд���ļ�
INPUT:user* phead
RETURN:void
***********************************************/

void writetofile(user* phead)//
{
	FILE* file_user;
	user* cur = phead->next;//ͷ�ڵ�Ϊ��
	if ((file_user=fopen("USERS.txt","w+") )== NULL)//�����������ȼ���ȷ���ı��ʽ��һ��Ҫ�������ţ�������ܻ�����߼������Һ��Ѽ��
	{
		//outtextxy(180, 30, "NULL");
		//printf("file not found");
		exit(1);
	}
	while (1)
	{
		if (cur == NULL)//??cur???????��??????????
		{
			//outtextxy(0,50,"no information");
			break;
		}
		/*outtextxy(0,70,cur->username);
		outtextxy(0,90,cur->password);
		outtextxy(0,110,cur->phonenum);*/
		/*fwrite(cur->username,sizeof(char),sizeof(cur->username)/sizeof(char),file_user);//������fprintf����fwrite������ı��ļ����������⣬����dat��ʽ
		fprintf(file_user,"*");
		fwrite(cur->password,sizeof(char),sizeof(cur->password)/sizeof(char),file_user);
		fprintf(file_user,"*");
		fwrite(cur->phonenum,sizeof(char),sizeof(cur->phonenum)/sizeof(char),file_user);*/
		fprintf(file_user,"%s*%s*%s*",cur->username,cur->password,cur->phonenum);
		fprintf(file_user,'\0');
		fprintf(file_user,"\n");
		fflush(file_user);
		cur = cur->next;
		//delay(150);
	}
	fclose(file_user);
}
/*user* finduser(char* name)
{
	user* head = getuser();//?????????????????
	user* cur;//???????????????????????????????????????????????????
	user* aim;
	cur = head->next;
	while (1)
	{
		if (strcmp(cur->username, name) == 0)
		{
			aim = cur;
			free(head);
			return aim;
		}
		else if (cur == NULL)
		{
			free(head);
			return NULL;
		}
		else
		{
			cur = cur->next;
		}
	}
}*/

/*********************************************
FUNCTION:f_register
DESCRIPTION:�ж�ע���û���Ϣ�Ƿ���Ϲ淶
INPUT:char* name,char* pass,char* phone
RETURN:0 or 1
***********************************************/

int f_register(char* name,char* pass,char* phone)
{
	user* u;
	FILE* file_user;
	makefile();
	u=getuser();
	u=add_user(u,name,pass,phone);
	if(u!=NULL)
	{
		writetofile(u);
		if((file_user=fopen("records.txt","a+"))==NULL)
		{
			exit(-1);
		}
		fprintf(file_user,"\n");
		fclose(file_user);
		free(u);
		return 1;
	}
	else
	{
		free(u);
		return 0;
	}
}
