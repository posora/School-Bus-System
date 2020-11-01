#ifndef _user_h
#define _user_h

typedef struct The_users
{
	char username[20];
	char password[20];
	char phonenum[12];
	struct user* next;
} user;
void makefile();
user* getuser();
user* add_user(user* phead,char* name, char* pass, char* phone);
//user* finduser(char* name);
void writetofile(user* phead);
int f_register(char* name,char* pass,char* phone);

#endif