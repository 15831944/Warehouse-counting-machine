#ifndef CWIN_ADDGOODS_H
#define CWIN_ADDGOODS_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cdata.h"
#include <list>


//ע�ᴰ����
class caddgoods:public cwin,public cdata
{
public:
	caddgoods();
	//ע�ᴰ�ڹ���
	caddgoods(int x,int y,int width,int height);	
	//��дע�ᴰ��չʾ
	void show();
	//ע�ᴰ�ڲ�������
	int doAction();
	//ע�ᴰ������
	~caddgoods();

};


#endif