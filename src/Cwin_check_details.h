#ifndef CWIN_CHECK_DETAILS_H
#define CWIN_CHECK_DETAILS_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//--------------------------�̵��������-------------------------------
//�̵����������
class ccheck_details:public cwin,public cdata
{
public:
	ccheck_details();
	//�̵�������ڹ���
	ccheck_details(int x,int y,int width,int height);
	
	void goods_show(int direction);
	
	//��д�̵����show
	void show();
	void winRun();
	
	//�̵�������ڲ�������
	int doAction();
	//�̵������������
	~ccheck_details();
	static int direction;
};
#endif