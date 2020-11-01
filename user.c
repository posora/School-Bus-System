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
DESCRIPTION:检查是否有文档，若无，创建文档
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
DESCRIPTION:读取文件，生成用户链表
INPUT:void
RETURN:user* phead
***********************************************/

user* getuser()//
{
	FILE* file_user;
	user* cur=NULL;
	user* phead=(user*)malloc(sizeof(user));//动态分配头节点的内存
	phead->next = NULL;
	cur = phead;//cur代表当前节点
	
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
		//char* s=NULL;//记得给指针赋初值，不然指针指向不确定
		char s[60];//用数组避免指针无初始值的问题
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
		cur->next = NULL;//链表末尾置NULL
		free(temp);
		temp=NULL;
	}
	fclose(file_user);
	return phead;
}

/*********************************************
FUNCTION:add_user
DESCRIPTION:往链表里加用户
INPUT:user* phead, char* name, char* pass, char* phone
RETURN:user* phead
***********************************************/

user* add_user(user* phead, char* name, char* pass, char* phone)//
{
	user* temp = (user *)malloc(sizeof(user));//链表的临时节点
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
		if (strcmp(cur->username, temp->username) == 0)//顺序比对文件中的用户名和输入的用户名
		{
			settextstyle(1, 0, 1);
			setcolor(RED);
			outtextxy(360, 120,"unavilable username");//输出错误信息
			delay(1500);
			return NULL;
		}
		if(strcmp(cur->phonenum,temp->phonenum)==0)
		{
			settextstyle(1, 0, 1);
			setcolor(RED);
			outtextxy(360, 320, "unaviable phonenumber");//输出错误信息
			delay(1500);
			return NULL;
		}
		if (cur->next == NULL)
		{
			cur->next = temp;
			cur = cur->next;
			cur->next = NULL;
			p=phead->next;

			temp=NULL;//释放指针前记得把指针置空，否则会连着指向的结构体一起释放
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
DESCRIPTION:将用户链表里的信息写入文件
INPUT:user* phead
RETURN:void
***********************************************/

void writetofile(user* phead)//
{
	FILE* file_user;
	user* cur = phead->next;//头节点为空
	if ((file_user=fopen("USERS.txt","w+") )== NULL)//对于运算优先级不确定的表达式，一定要加上括号，否则可能会出现逻辑错误并且很难检查
	{
		//outtextxy(180, 30, "NULL");
		//printf("file not found");
		exit(1);
	}
	while (1)
	{
		if (cur == NULL)//??cur???????β??????????
		{
			//outtextxy(0,50,"no information");
			break;
		}
		/*outtextxy(0,70,cur->username);
		outtextxy(0,90,cur->password);
		outtextxy(0,110,cur->phonenum);*/
		/*fwrite(cur->username,sizeof(char),sizeof(cur->username)/sizeof(char),file_user);//无论用fprintf还是fwrite输出到文本文件还是有问题，试试dat格式
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
DESCRIPTION:判断注册用户信息是否符合规范
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
