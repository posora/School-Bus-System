#include"public.h"
#include"record.h"
#include"user.h"
/*****************************************
record.c
COPYRIGHT:	zoubojin
FUNCTION:	record user's data
ABSTRACT:
		record user's data
DATE:2020/10/10
******************************************/
int findline(char* name)
{
	user* temp=NULL,*phead=NULL;
	int i=0;
	char t[2];
	t[1]='\0';
	phead = getuser();
	temp = phead->next;
	while(temp!=NULL)//
	{
		if (strcmp(temp->username, name) == 0)
		{
			free(phead);
			free(temp);
			//setcolor(RED);
			//settextstyle(1,0,6);
			//t[0]=(char)(i-1+'1');
			//outtextxy(100,200,t);
			return i;//找到用户后，将乘车信息输入到用户所在行的末尾
		}
		else
		{
			temp = temp->next;
			i++;
		}
	}
	free(phead);
	free(temp);
	exit(-1);
}
void readrecord(char* name,char* t)
{
	int i=0;
	int j=0;
	int k=0;
	int count=0;
	char s[1000];
	int move=findline(name);
	FILE* file_user;
	memset(s,'\0',1000);
	memset(t,'\0',1000);
	
	if((file_user=fopen("records.txt","r"))!=NULL)
	{
		fseek(file_user,0L,SEEK_SET);
		for(i=0;i<=move;i++)
		{
			fgets(s,1000,file_user);
		}
		strcpy(t,s);
		fclose(file_user);
	}
	else
		exit(-1);
}
void writerecord(char* name,char* route)//添加乘车记录
{
	int i=0;
	int j=0;
	int k=0;
	int distance=0;
	int len_line=0;
	char ch;
	char s[1000];
	char temp[1000];
	char t[2];
	FILE* file_temp;
	FILE* file_record;
	
	int move=findline(name);
	
	memset(s,'\0',1000);
	if((file_temp=fopen("temp.txt","w"))==NULL)//只允许可写
	{
		exit(-1);
	}
	if((file_record=fopen("records.txt","r"))!=NULL)//只允许可读，防止读取recoed.txt里的信息时因为写被全部修改
	{
		fseek(file_record,0L,SEEK_SET);
		do
		{	
			//len_line=strlen(s);
			//distance+=len_line;
			fgets(s,1000,file_record);//将文件指针移到文件中用户名对应的行
			// if(i==move)
			// {
			// 	fseek(file_user,distance,SEEK_SET);
			// 	strcpy(temp,route);
			// 	strcat(temp,s);
			// 	t[0]=(char)(distance-1+'1');
			// 	outtextxy(300,300,t);
			// 	//while((ch = getchar()) !='\n' && ch != EOF);
			// 	fprintf(file_user,"%s\0",temp);
			// }
			fseek(file_record,0L,SEEK_CUR);//不能直接交替进行文件的读和写的操作
			fprintf(file_temp,"%s",s);
		}while(fgetc(file_record)!=EOF&&(!fseek(file_record,-1L,SEEK_CUR)));
		fclose(file_record);
		fclose(file_temp);
	}
	memset(s,'\0',1000);
	len_line=0;
	distance=0;
	if((file_temp=fopen("temp.txt","r"))==NULL)//只允许可读,防止读取的时候temp.txt信息因为可写而被修改
	{
		exit(-1);
	}
	if((file_record=fopen("records.txt","w"))!=NULL)//只允许可写
	{
		fseek(file_record,0L,SEEK_SET);
		do
		{
			//len_line=strlen(s);
			//distance+=len_line;
			fgets(s,1000,file_temp);//将文件指针移到文件中用户名对应的行
			if(i==move)
			{
				fseek(file_temp,0L,SEEK_CUR);
				strcpy(temp,route);
				strcat(temp,s);
				//while((ch = getchar()) !='\n' && ch != EOF);
				fprintf(file_record,"%s",temp);
			}
			else
			{
				fseek(file_temp,0L,SEEK_CUR);//不能直接交替进行文件的读和写的操作
				fprintf(file_record,"%s",s);
			}
			i++;
		}while(fgetc(file_temp)!=EOF&&(!fseek(file_temp,-1L,SEEK_CUR)));
		// while(s[j]!='\n')
		// {
		// 	j++;
		// 	fseek(file_user,1L,SEEK_CUR);
		// 	t[0]=(char)(i-1+'1');
		// 	t[1]='\0';
		// 	setcolor(RED);
		// 	settextstyle(1,0,1);
		// 	outtextxy(100,400,t);
		// 	t[0]=(char)(distance-1+'1');
		// 	outtextxy(300,400,t);
		// 	while((ch = getchar()) !='\n' && ch != EOF);
		//getch();
		// }
		fclose(file_record);
		fclose(file_temp);
	}
	else
		exit(-1);
}
void writeuser(char* name,int checi)
{
	FILE* file_user;
	char ch;
	if(checi==1)
	{
		if((file_user=fopen("checi1.txt","a+"))!=NULL)
		{
			fseek(file_user,0L,SEEK_END);
			//while((ch = getchar()) != '\n' && ch != EOF);
			fprintf(file_user,"%s*",name);
			fclose(file_user);
		}
		else
			exit(-1);
	}
	else if(checi==2)
	{
		if((file_user=fopen("checi2.txt","a+"))!=NULL)
		{
			fseek(file_user,0L,SEEK_END);
			//while(ch=(getchar()) != '\n' && ch != EOF);
			fprintf(file_user,"%s*",name);
			fclose(file_user);
		}
		else
			exit(-1);
	}
	else
	{
		if((file_user=fopen("checi3.txt","a+"))!=NULL)
		{
			fseek(file_user,0L,SEEK_END);
			//while((ch = getchar()) != '\n' && ch != EOF);
			fprintf(file_user,"%s*",name);
			fclose(file_user);
		}
		else
			exit(-1);
	}
}
void record(char* name,int checi,int start,int end,char* t)
{
	int i=0;
	char route[5];
	route[0]=(char)(checi-1+'1');
	route[1]=(char)(start-1+'1');
	route[2]=(char)(end-1+'1');
	route[3]='*';
	route[4]='\0';
	
	writerecord(name,route);
	writeuser(name,checi);
	readrecord(name,t);
	cleardevice();
	setbkcolor(CYAN);
	setcolor(RED);
	settextstyle(1,0,3);
	//outtextxy(20,100,t);
	while(t[i]!='\0')
	{
		if(((i+1)%4)!=0)
		{
			route[i%4]=t[i];
			if((i%4)==0)
			{
				if(t[i]=='1')
					puthz(40+320*(i/4)%2,30+40*(i/4)/2,"车次一",16,17,WHITE);
				else if(t[i]=='2')
					puthz(40+320*(i/4)%2,30+40*(i/4)/2,"车次二",16,17,WHITE);
				else if(t[i]=='3')
					puthz(40+320*(i/4)%2,30+40*(i/4)/2,"车次三",16,17,WHITE);
			}
			else if((i%4)==1)
			{
				if(t[i-1]=='1')
				{
					if(t[i]=='1')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"紫菘",16,17,WHITE);
					else if(t[i]=='2')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"科技楼",16,17,WHITE);
					else if(t[i]=='3')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"机械大楼",16,17,WHITE);
					else if(t[i]=='4')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"喻园",16,17,WHITE);
				}
				else if(t[i-1]=='2')
				{
					if(t[i]=='1')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"校大门",16,17,RED);
					else if(t[i]=='2')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"图书馆",16,17,RED);
					else if(t[i]=='3')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"大活",16,17,RED);
					else if(t[i]=='4')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"集贸市场",16,17,RED);
				}
				else if(t[i-1]=='3')
				{
					if(t[i]=='1')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"校大门",16,17,RED);
					else if(t[i]=='2')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"图书馆",16,17,RED);
					else if(t[i]=='3')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"幼儿园",16,17,RED);
					else if(t[i]=='4')
						puthz(120+320*(i/4)%2,30+40*(i/4)/2,"校医院",16,17,RED);
				}
			}
			else if((i%4)==2)
			{
				if(t[i-2]=='1')
				{
					if(t[i]=='1')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"科技楼",16,17,WHITE);
					else if(t[i]=='2')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"机械大楼",16,17,WHITE);
					else if(t[i]=='3')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"喻园",16,17,WHITE);
					else if(t[i]=='4')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"韵苑",16,17,WHITE);
				}
				else if(t[i-2]=='2')
				{
					if(t[i]=='1')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"图书馆",16,17,RED);
					else if(t[i]=='2')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"大活",16,17,RED);
					else if(t[i]=='3')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"集贸市场",16,17,RED);
					else if(t[i]=='4')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"韵苑",16,17,RED);
				}
				else if(t[i-2]=='3')
				{
					if(t[i]=='1')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"图书馆",16,17,RED);
					else if(t[i]=='2')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"幼儿园",16,17,RED);
					else if(t[i]=='3')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"校医院",16,17,RED);
					else if(t[i]=='4')
						puthz(210+320*(i/4)%2,30+40*(i/4)/2,"喻园",16,17,RED);
				}
			}
		}
		else
		{
			setcolor(RED);
			settextstyle(1,0,3);
			//outtextxy(50+(i%4)*30,20+20*(i/4)*20,route);
		}
		i++;
	}
	getch();
}