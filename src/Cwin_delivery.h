#ifndef CWIN_DELIVERY_H
#define CWIN_DELIVERY_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>
#include "Cwin_popup.h"
#include "CmanagerWin.h"
//������洰����
class cdeliveryWin:public cwin,public cdata
{
public:
	cdeliveryWin();
	//������洰�ڹ���
	cdeliveryWin(int x,int y,int width,int height);	
	//��д������洰�ڲ�������
	int doAction();
	//������洰������
	~cdeliveryWin();

};


//���ⴰ����
class cdelivery:public cwin,public cdata
{
public:
	cdelivery();
	//���ⴰ�ڹ���
	cdelivery(int x,int y,int width,int height);	
	//��д���ⴰ�ڲ�������
	int doAction();
	//��д���ⴰ����ʾshow
	void show();
	//���ⴰ������
	~cdelivery();

	static string str;

};

#endif