#ifndef USER_ADMIN_H
#define USER_ADMIN_H

#include "Ctool.h"
#include "Cwin.h"


//����Ա���ࣺ
class cadmin:public cwin
{
public:
	cadmin();
	//����Ա���ڹ���
	cadmin(int x,int y,int width,int height);
	//����Ա���ڲ�������
	int doAction();
	//����Ա��������
	~cadmin();
};

#endif