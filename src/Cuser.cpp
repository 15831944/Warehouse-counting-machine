#include "Cuser.h"

//�û�Ĭ�Ϲ��캯��
cuser::cuser(){}

//�û����캯��
cuser::cuser(int ID,char name[10],char pwd[10],int role)
{
	this->ID=ID;
	strcpy(this->name,name);
	strcpy(this->pwd,pwd);
	this->role=role;
}

//�û���������
cuser::~cuser(){}