#ifndef CWIN_QUERY_H
#define CWIN_QUERY_H

#include "Ctool_form.h"
#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cuser.h"
#include "Cdata.h"
#include <list>
#include<windows.h>
#include <algorithm>
#include <iomanip>

//��ѯ������
class cquery:public cwin,public cdata
{
public:
	cquery();
	//��ѯ���ڹ���
	cquery(int x,int y,int width,int height);
	//��д��ѯ����չʾ
	void show();

	//��д�������к���
	void winRun();
	//��ѯ���ڲ�������
	int doAction();

	void goods_show(int direction);


	//��ѯ��������
	~cquery();

};


#endif