#ifndef CUSER_H
#define CUSER_H

#include <iostream>
using namespace std;

#include <string.h>
#include <stdio.h>
#include "Ctool.h"


#define ADMIN 1
#define CHECKERS 2


//Ա������
class cuser
{
public:

	cuser();
	cuser(int ID,char name[10],char pwd[10],int role);
	~cuser();

	//��Ľӿ�
	int get_ID(){return ID;};
	char *get_name(){return name;};
	char *get_pwd(){return pwd;};
	int get_role(){return role;};

protected:
	int ID;
	char name[10];//�û���
	char pwd[10];//����
	int role ;//��ɫ

};
#endif