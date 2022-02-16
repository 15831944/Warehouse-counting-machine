#ifndef CWIN_H
#define CWIN_H

#include <iostream>
using namespace std;
#pragma warning (disable: 4786)
#include "Ctrol_label.h"
#include "Ctrol_button.h"
#include "Ctrol_edit.h"
#include "Ctool.h"
#include "Cuser.h"

#include<ctime>
#include<windows.h>



//���ڻ���
class cwin
{
public:
	cwin();
	cwin(int x,int y,int width,int height);
	//��ӿؼ�
	void addCtrol(ctrol *ctrolArry);

	//��ʾ
	virtual void show();
	//��������
	virtual void winRun();
	//��ʾ�û���ʱ��
	void UserandTime();
	//���ڲ��������麯��
	virtual int doAction(){return 0;};
	~cwin();

	static char name[10];
	static int  role;
	 
protected:
	int x;
	int y;
	int width;
	int height;
	int focusIndex;
	int ctrolCount;//�ؼ�����
	int userCount;//�ؼ�����
	
	ctrol *ctrolArry[20];//�ؼ�����ָ������



};


#endif