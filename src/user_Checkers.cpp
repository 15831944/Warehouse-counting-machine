#include "user_Checkers.h"

//�̵�Ա����Ĭ�Ϲ��캯��
checkers::checkers(){}	

//�̵�Ա���ڹ��캯��
checkers::checkers(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new cbutton(30,13,12,2,"��Ʒ��ѯ",BUTTON));
	this->addCtrol(new cbutton(60,13,12,2,"�ֿ��̵�",BUTTON));
	this->addCtrol(new cbutton(30,17,12,2,"�˳�����",BUTTON));
}


int checkers::doAction()
{
	//�ؼ�Ϊ��Ʒ��ѯ
	if(this->focusIndex==1)
	{
		return 6;
	}
	//�ؼ�Ϊ�ֿ��̵�
	if(this->focusIndex==2)
	{
		return 13;
	}
	
	//�ؼ�Ϊ�˳�����
	if(this->focusIndex==3)
	{
		cwin::role=0;
		return 3;
	}
	
	return -1;
}


//�̵�Ա������������
checkers::~checkers(){}





