#include "user_admin.h"

//����Ա����Ĭ�Ϲ��캯��
cadmin::cadmin(){}

//����Ա���ڹ��캯��
cadmin::cadmin(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new cbutton(30,13,12,2,"��Ʒ��ѯ",BUTTON));
	this->addCtrol(new cbutton(60,13,12,2,"������Ʒ",BUTTON));
	this->addCtrol(new cbutton(30,17,12,2,"��Ʒ���",BUTTON));
	this->addCtrol(new cbutton(60,17,12,2,"��Ʒ����",BUTTON));
	this->addCtrol(new cbutton(30,21,12,2,"�̵����",BUTTON));
	this->addCtrol(new cbutton(60,21,12,2,"�˳�����",BUTTON));
}

//����Ա���ڲ�������
int cadmin::doAction()
{
	//�ؼ�Ϊ��Ʒ��ѯ
	if(this->focusIndex==1)
	{
		return 6;
	}
	
	//�ؼ�Ϊ��Ʒ���
	if(this->focusIndex==3)
	{
		return 7;
	}
	//�ؼ�Ϊ��Ʒ����
	if(this->focusIndex==4)
	{
		
			
		return 11;
	}
	if(this->focusIndex==5)
	{
		
			
		return 16;
	}
	//�ؼ�Ϊ�˳�����
	if(this->focusIndex==6)
	{
		
		cwin::role=0;	
		return 3;
	}

	return -1;
}

//����Ա������������
cadmin::~cadmin(){}