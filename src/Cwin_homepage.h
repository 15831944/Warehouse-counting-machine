#ifndef CWIN_HOMEPAGE_H
#define CWIN_HOMEPAGE_H
#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include <windows.h>


#include "Ctool.h"
#include "Cwin.h"
#include "Cwin_login.h"
#include "Cwin_register.h"
#include <vector>


//��������
class chomepage:public cwin
{
public:
	chomepage();
	//�����洰�ڹ���
	chomepage(int x,int y,int width,int height);
	//�����洰�ڲ�������
	int doAction();
	//�����洰������
	~chomepage();

};


#endif