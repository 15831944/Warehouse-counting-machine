#ifndef CWIN_POPUP_H
#define CWIN_POPUP_H

#include <iostream>
#pragma warning (disable: 4786)
#include <map>
using namespace std;

#include "Ctool.h"
#include "Cwin.h"
#include "Cdata.h"
#include "Cgoods.h"
#include "Cwin_check_record.h"

//����������
class cpopup:public cwin
{
public:
	cpopup();
	//�������ڹ���
	cpopup(int x,int y,int width,int height);
	//�������ڲ�������
	int doAction();
	void show();
	//������������
	~cpopup();

};


//����������
class cpopup2:public cwin
{
public:
	cpopup2();
	//�������ڹ���
	cpopup2(int x,int y,int width,int height);
	//�������ڲ�������
	int doAction();
	void show();
	//������������
	~cpopup2();

};

//����������
class cpopup3:public cwin,public cdata
{
public:
	cpopup3();
	//�������ڹ���
	cpopup3(int x,int y,int width,int height);
	//�������ڲ�������
	int doAction();
	void show();
	//������������
	~cpopup3();

};



#endif