#ifndef CWIN_CHECK_RECORD_H
#define CWIN_CHECK_RECORD_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//--------------------------�̵��¼����-------------------------------
//�̵��¼������
class ccheck_record:public cwin,public cdata
{
public:
	ccheck_record();
	//�̵��¼���ڹ���
	ccheck_record(int x,int y,int width,int height);	
	void goods_show(int direction);
	//��д�̵��¼show
	void show();
	void winRun();
	//�̵��¼���ڲ�������
	int doAction();
	//�̵��¼��������
	~ccheck_record();
	static int direction;
	static string ccheck_str;
};
#endif