#ifndef CWIN_OUT_H
#define CWIN_OUT_H

#include <iostream>
using namespace std;
#pragma warning (disable: 4786)
#include <windows.h>

#include "Ctool.h"
#include "Cwin.h"

#include <vector>


//�˳�������
class out:public cwin
{
public:
	out();
	//�˳����ڹ���
	out(int x,int y,int width,int height);
	//�˳����ڲ�������
	int doAction();
	//�˳���������
	~out();

};


#endif