#include "Cwin_out.h"

//��ҳ�洰��Ĭ�Ϲ��캯��
out::out(){}

//��ҳ�洰�ڹ��캯��
out::out(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(45,7,10,2,"ȷ�Ϲرգ�",LABEL));
	this->addCtrol(new cbutton(45,13,12,2,"ȷ��",BUTTON));
	this->addCtrol(new cbutton(45,17,12,2,"����",BUTTON));
}

//��ҳ�洰�ڲ�������
int out::doAction()
{
	switch(this->focusIndex)
	{	
	//�ؼ�Ϊȷ��ʱ
	case 1:
		{

			return -1;
		}
	//�ؼ�Ϊ����ʱ
	case 2:
		{

			return 3;
		}
	}

	return -1;	
}

//��ҳ�洰����������
out::~out(){}