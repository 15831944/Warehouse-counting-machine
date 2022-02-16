#include "Cwin_popup.h"

//��������Ĭ�Ϲ��캯��
cpopup::cpopup(){}

//�������ڹ��캯��
cpopup::cpopup(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(x+3,y+2,10,2,"��ʾ��",LABEL));
	this->addCtrol(new clabel(x+6,y+4,10,2,"δ�ҵ���Ӧ����Ʒ��",LABEL));
	this->addCtrol(new cbutton(x+11,y+7,12,2,"��������",BUTTON));
	this->addCtrol(new cbutton(x+11,y+11,12,2,"������Ʒ",BUTTON));
	
}
void cpopup::show()
{
	for (int i=0;i<this->height;i++)
	{
		ctool::gotoxy(this->x+2,this->y+1+i);
		cout<<"                            ";
	}
	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

}
//�������ڲ�������
int cpopup::doAction()
{
	switch(this->focusIndex)
	{	
	//�ؼ�Ϊȷ��ʱ
	case 2:
		{
			return 8;
		}
	//�ؼ�Ϊ����ʱ
	case 3:
		{
			return 10;
		}
	}

	return -1;	
}

//����������������
cpopup::~cpopup(){}

//----------------------------------------------------------

//��������Ĭ�Ϲ��캯��
cpopup2::cpopup2(){}

//�������ڹ��캯��
cpopup2::cpopup2(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(x+3,y+2,10,2,"��ʾ��",LABEL));
	this->addCtrol(new clabel(x+6,y+4,10,2,"δ�ҵ���Ӧ����Ʒ��",LABEL));
	this->addCtrol(new cbutton(x+11,y+7,12,2,"��������",BUTTON));

	
}
void cpopup2::show()
{
	for (int i=0;i<this->height;i++)
	{
		ctool::gotoxy(this->x+2,this->y+1+i);
		cout<<"                            ";
	}
	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

}
//�������ڲ�������
int cpopup2::doAction()
{
	switch(this->focusIndex)
	{	
	//�ؼ�Ϊ��������ʱ
	case 2:
		{

			return 8;
		}


	}

	return -1;	
}

//����������������
cpopup2::~cpopup2(){}




//---------------------�̵�����ĵ���---------------------------

//�̵�����ĵ�������Ĭ�Ϲ��캯��
cpopup3::cpopup3(){}

//�̵�����ĵ������ڹ��캯��
cpopup3::cpopup3(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(x+3,y+2,10,2,"������¼��",LABEL));
	this->addCtrol(new clabel(x+3,y+5,10,2,"����������",LABEL));
	this->addCtrol(new clabel(x+3,y+8,10,2,"����˵����",LABEL));
	this->addCtrol(new cedit(x+15,y+5,18,2,10,3,1,"",EDIT));
	this->addCtrol(new cedit(x+15,y+8,18,4,10,3,1,"",EDIT));
	this->addCtrol(new clabel(x+10,y+14,10,2,"ȷ��",BUTTON));
	this->addCtrol(new cbutton(x+25,y+14,10,2,"ȡ��",BUTTON));

	
}
//�̵�����ĵ����������ݴ�ӡ
void cpopup3::show()
{
	
	for (int i=0;i<this->height;i++)
	{
		ctool::gotoxy(this->x+2,this->y+1+i);
		cout<<"                                     ";
	}
	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

}
//�̵�����ĵ������ڲ�������
int cpopup3::doAction()
{
	switch(this->focusIndex)
	{	
	case 5:
		{
			//����map������������������ͳ���˵��
			map<string,cgoods *>::iterator  it=cdata::goods_map4.find(ccheck_correct::str);
			if(it != goods_map4.end())
			{
				//��������������ڲ�����������ʾ
				if (atoi(this->ctrolArry[3]->get_content())>it->second->get_difference_mount())
				{
					MessageBox(NULL,"�̵��������ܴ��ڲ�������","��ʾ",0);
					cmanwin::winArry[18]->winRun();
					return cmanwin::winArry[18]->doAction();	
				}
				//��֮���޸�����
				else
				{
				
				it->second->get_rectification(atoi(this->ctrolArry[3]->get_content()));
				it->second->get_explain(this->ctrolArry[4]->get_content());	
				it->second->get_modify();
				
				}
			}
			//��������༭������
			memset (this->ctrolArry[3]->get_content(),0,strlen(this->ctrolArry[3]->get_content()));
			memset (this->ctrolArry[4]->get_content(),0,strlen(this->ctrolArry[4]->get_content()));

			return 17;
		}
	//�ؼ�Ϊ����ʱ
	case 6:
		{

			return 17;
		}


	}

	return -1;	
}
//����������������
cpopup3::~cpopup3(){}