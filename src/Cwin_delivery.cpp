#include "Cwin_delivery.h"

//�����洰��Ĭ�Ϲ��캯��
cdeliveryWin::cdeliveryWin(){}

//�����洰�ڹ��캯��
cdeliveryWin::cdeliveryWin(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new cbutton(30,13,12,2,"  ����",BUTTON));
	this->addCtrol(new cbutton(60,13,12,2,"�����¼",BUTTON));
	this->addCtrol(new cbutton(30,17,12,2,"  ����",BUTTON));
}

//�����洰�ڲ�������
int cdeliveryWin::doAction()
{
	if(this->focusIndex==1)
	{
		return 12;
	}
	if(this->focusIndex==3)
	{
		return 1;
	}
	return -1;
}
cdeliveryWin::~cdeliveryWin(){}




//-------------------------------------------------------------------------------


//��ⴰ��Ĭ�Ϲ��캯��
cdelivery::cdelivery(){}
string cdelivery::str;
//��ⴰ�ڹ��캯��
cdelivery::cdelivery(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(20,17,10,2,"��Ʒ���ƣ�",LABEL));
	this->addCtrol(new clabel(20,20,10,2,"��Ʒ���ͣ�",LABEL));
	this->addCtrol(new clabel(20,23,10,2,"��Ʒ�۸�",LABEL));
	this->addCtrol(new clabel(20,26,10,2,"��Ʒ������",LABEL));
	this->addCtrol(new clabel(20,29,10,2,"��λ��ţ�",LABEL));
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new clabel(18,12,10,2,"��������Ʒ��ţ�",LABEL));
	this->addCtrol(new clabel(64,17,10,2,"�������������[1-10000]",LABEL));
	this->addCtrol(new cedit(37,12,20,2,12,3,1,"",EDIT));
	this->addCtrol(new cbutton(68,12,8,2,"��ѯ",BUTTON));
	this->addCtrol(new cedit(66,20,22,2,12,2,1,"",EDIT));
	this->addCtrol(new cbutton(66,24,8,2,"ȷ��",BUTTON));
	this->addCtrol(new cbutton(80,24,8,2,"����",BUTTON));
}


//��д����show
void cdelivery::show()
{
	//��ʾʱ��
	cwin::UserandTime();
		ctool::paintWindow(16,15,42,17);

		ctool::paintWindow(this->x, this->y,this->width,this->height);

		for(int i=0; i<this->ctrolCount; i++)
		{
			this->ctrolArry[i]->show();
		}
		memset (this->ctrolArry[8]->get_content(),0,strlen(this->ctrolArry[8]->get_content()));
		memset (this->ctrolArry[10]->get_content(),0,strlen(this->ctrolArry[10]->get_content()));

}




//���ⴰ�ڲ�������
int cdelivery::doAction()
{
	//�ؼ�Ϊ��ѯʱ
	if(this->focusIndex==9)
	{
		//����map����������ѯ
		map<string,cgoods *>::iterator  it=goods_map.find(this->ctrolArry[8]->get_content());
		if(it != goods_map.end())
		{
			//���ÿո񸲸�֮ǰ������
			ctool::gotoxy(30,17);
			cout<<"             ";
			ctool::gotoxy(30,20);				
			cout<<"             ";
			ctool::gotoxy(30,23);				
			cout<<"             ";
			ctool::gotoxy(30,26);				
			cout<<"             ";
			ctool::gotoxy(30,29);				
			cout<<"             ";
				
			//��ѯ���ʹ�ӡ������Ϣ
			ctool::gotoxy(30,17);
			cout<<it->second->get_goods_name();
			ctool::gotoxy(30,20);				
			cout<<it->second->get_goods_type();
			ctool::gotoxy(30,23);				
			cout<<fixed<<setprecision(2)<<it->second->get_goods_price();
			ctool::gotoxy(30,26);				
			cout<<it->second->get_goods_mount();
			ctool::gotoxy(30,29);				
			cout<<it->second->get_goods_Position();
			
			str=this->ctrolArry[8]->get_content();
			//��������
			cdelivery::winRun();
			return cdelivery::doAction();
		}

		//����ѯ��������Ϣ�͵�����ʾ
		else
		{

			MessageBox(NULL,"δ��ѯ��������������","��ʾ",0);
			return 12;
			
		}
	}

	//���ؼ�Ϊȷ��ʱ��
	if(this->focusIndex==11)
	{
		//���û�������ѯ�ı�ţ��༭������Ϊ��ʱ������ʾû�в�ѯ���޷����
		if (strlen(this->ctrolArry[8]->get_content())==0)
		{
			
			ctool::gotoxy(66,27);
			cout<<"δ��ѯ��Ʒ���޷����⣡";
			ctool::gotoxy(66,29);
			system("pause");
			return 12;
		}
		//��������������С��ʵ����������ʾ

			//����������������1-10000֮�����ʾ
		if (atoi(this->ctrolArry[10]->get_content())>10000 || atoi(this->ctrolArry[10]->get_content())<1)
		{
			ctool::gotoxy(62,27);
			cout<<"�����������[1-10000]֮�䣡";			
		}
		else
		{
		
			//����map��������ѯ
			map<string,cgoods *>::iterator  it=goods_map.find(str);
			if(it != goods_map.end())
			{
				if (it->second->get_goods_mount()<atoi(this->ctrolArry[10]->get_content()))
				{
					ctool::gotoxy(64,27);
					cout<<"������������ʵ��������";
				}
					
				else
				{
					//���ú����ӿ��޸Ļ�������
					it->second->get_goods_mount_sub(atoi(this->ctrolArry[10]->get_content()));
					ctool::gotoxy(64,27);				
					cout<<"                       ";		
					ctool::gotoxy(30,26);				
					cout<<"          ";
					ctool::gotoxy(30,26);
					cout<<it->second->get_goods_mount();
				}
				//��������
				cdelivery::winRun();
				return cdelivery::doAction();
			}
		}
	}
	

	//�ؼ�Ϊ����ʱ��
	if(this->focusIndex==12)
	{

		return 11;
	}
	return -1;
}
cdelivery::~cdelivery(){}
