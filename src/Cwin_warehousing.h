#ifndef CWIN_WAREHOUSING_H
#define CWIN_WAREHOUSING_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//�����洰����
class cwarehousingWin:public cwin,public cdata
{
public:
	cwarehousingWin();
	//�����洰�ڹ���
	cwarehousingWin(int x,int y,int width,int height);	
	//�����洰�ڲ�������
	int doAction();
	//�����洰������
	~cwarehousingWin();

};


//��ⴰ����
class cwarehousing:public cwin,public cdata
{
public:
	cwarehousing();
	//��ⴰ�ڹ���
	cwarehousing(int x,int y,int width,int height);	
	//��ⴰ�ڲ�������
	int doAction();

	void show();
	//��ⴰ������
	~cwarehousing();

	static string str;

};

#endif