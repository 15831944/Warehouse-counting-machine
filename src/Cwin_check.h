#ifndef CWIN_CHECK_H
#define CWIN_CHECK_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//--------------------------�̵�������-------------------------------
//�̵���洰����
class ccheckWin:public cwin,public cdata
{
public:
	ccheckWin();
	//�̵���洰�ڹ���
	ccheckWin(int x,int y,int width,int height);	
	//�̵���洰�ڲ�������
	int doAction();
	//�̵���洰������
	~ccheckWin();
};

//--------------------------�̵�ҳ��-------------------------------
//�̵㴰����
class ccheck:public cwin,public cdata
{
public:
	ccheck();
	//�̵㴰�ڹ���
	ccheck(int x,int y,int width,int height);
	//��д�̵�show
	void show();
	//�̵㴰�ڲ�������
	int doAction();
	//�̵㴰������
	~ccheck();

	static string str;
	static int ccheck_num;
	static string ccheck_str;
};

//--------------------------�̵��-------------------------------

class ccheck_form:public cwin,public cdata
{
public:
	ccheck_form();
	//�̵㴰�ڹ���
	ccheck_form(int x,int y,int width,int height);
	//��д�̵�������к���
	void winRun();
	//��ʾ�̵���Ʒ���ݺ���
	void goods_show(int direction);
	//�̵㴰�ڲ�������
	int doAction();
	//��д�̵㴰��show
	void show();
	//�̵㴰������
	~ccheck_form();
};
#endif