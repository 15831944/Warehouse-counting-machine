#ifndef CWIN_REGISTER_H
#define CWIN_REGISTER_H

#pragma warning (disable: 4786)
#include <iostream>
using namespace std;

#include "Cwin.h"
#include "Ctrol.h"
#include "Cuser.h"
#include "Cdata.h"
#include <list>


//ע�ᴰ����
class Cregister:public cwin,public cdata
{
public:
	Cregister();
	//ע�ᴰ�ڹ���
	Cregister(int x,int y,int width,int height);	
	//��дע�ᴰ��չʾ
	void show();
	//ע�ᴰ�ڲ�������
	int doAction();
	//ע�ᴰ������
	~Cregister();

};


#endif