#ifndef USER_CHECKERS_H
#define USER_CHECKERS_H

#include "Ctool.h"
#include "Cwin.h"


//�̵�Ա���ࣺ
class checkers:public cwin
{
public:
	checkers();
	//�̵�Ա���ڹ���
	checkers(int x,int y,int width,int height);
	//�̵�Ա���ڲ�������
	int doAction();
	//�̵�Ա��������
	~checkers();

};



#endif