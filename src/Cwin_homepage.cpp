#include "Cwin_homepage.h"

//��ҳ�洰��Ĭ�Ϲ��캯��
chomepage::chomepage(){}



//��ҳ�洰�ڹ��캯��
chomepage::chomepage(int x,int y,int width,int height)
:cwin(x,y,width,height)
{

	this->addCtrol(new clabel(42,7,10,2,"�̵����Ŀ",LABEL));
	this->addCtrol(new clabel(60,28,10,2,"OMO2101������",LABEL));
	this->addCtrol(new cbutton(45,13,12,2," ��¼",BUTTON));
	this->addCtrol(new cbutton(45,17,12,2," ע��",BUTTON));
	this->addCtrol(new cbutton(45,21,12,2," �ر�",BUTTON));
	
}

//��ҳ�洰�ڲ�������
int chomepage::doAction()
{
	
	switch(this->focusIndex)
	{	
	//�ؼ�Ϊ��¼ʱ
	case 2:
		{
			return 0;
		}
	//�ؼ�Ϊע��ʱ
	case 3:
		{

			return 4;
		}
	//�ؼ�Ϊȡ��ʱ
	case 4:
		{
			return 5;
		}
		
	}

	return 0;	
}

//��ҳ�洰����������
chomepage::~chomepage(){}