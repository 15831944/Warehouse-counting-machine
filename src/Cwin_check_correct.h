#ifndef CWIN_CHECK_CORRECT_H
#define CWIN_CHECK_CORRECT_H

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
class ccheck_correct:public cwin,public cdata
{
public:
	ccheck_correct();
	//�̵�������ڹ���
	ccheck_correct(int x,int y,int width,int height);
	
	void goods_show(int direction);
	
	//��д�̵����show
	void show();
	void winRun();
	
	//�̵�������ڲ�������
	int doAction();
	//�̵������������
	~ccheck_correct();
	static int direction;
	static string str;
};
#endif