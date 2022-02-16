#include "Cwin_login.h"
char cwin::name[10]={0};
int cwin::role=0;
//��¼����Ĭ�Ϲ��캯��
clogin::clogin(){}



//��¼���ڹ��캯��
clogin::clogin(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new clabel(35,13,10,2,"�û���",LABEL));
	this->addCtrol(new clabel(35,17,10,2,"����",LABEL));
	this->addCtrol(new cedit(42,13,20,2,12,3,1,"",EDIT));
	this->addCtrol(new cedit(42,17,20,2,10,2,0,"",EDIT));
	this->addCtrol(new cbutton(37,21,10,2,"ȷ��",BUTTON));
	this->addCtrol(new cbutton(55,21,10,2,"ȡ��",BUTTON));

}

//��¼���ڲ�������
int clogin::doAction()
{
	//�ؼ�Ϊȷ��ʱ
	if(this->focusIndex==5)
	{
		int irole=loginJudge();

		//�����˺Ų���ȷʱ
		if(irole==0)
		{
			//������˺Ŵ�����Ϊ��ʱ��
			if((strlen(this->ctrolArry[3]->get_content())==0)||(strlen(this->ctrolArry[4]->get_content())==0))
			{

				ctool::gotoxy(this->ctrolArry[4]->get_x()-2, this->ctrolArry[4]->get_y()+2);
				printf("�˺Ż����벻��Ϊ��!\n");
				Sleep(1000);
				
			}
			//������˺Ŵ����Ҳ�Ϊ��ʱ��
			else
			{
				ctool::gotoxy(this->ctrolArry[4]->get_x()-2, this->ctrolArry[4]->get_y()+2);
				printf("�˺Ż����벻��ȷ!\n");
				Sleep(1000);
			}
		}

		//��ձ༭��������
		memset (this->ctrolArry[3]->get_content(),0,strlen(this->ctrolArry[3]->get_content()));
		memset (this->ctrolArry[4]->get_content(),0,strlen(this->ctrolArry[4]->get_content()));

		return irole;
	}

	//�ؼ�Ϊ����ʱ
	if(this->focusIndex==6)
	{
		//��ձ༭��������
		memset (this->ctrolArry[3]->get_content(),0,strlen(this->ctrolArry[3]->get_content()));
		memset (this->ctrolArry[4]->get_content(),0,strlen(this->ctrolArry[4]->get_content()));

		return 3;
	}
	return 0;
}


//��¼��֤����
int clogin::loginJudge()
{
	//���õ���������
	list<cuser*>::iterator it;
	for (it=cdata::user_list.begin();it!=user_list.end();it++)
	{
		if(atoi(this->ctrolArry[3]->get_content())==(*it)->get_ID()
		   &&strcmp(this->ctrolArry[4]->get_content(),(*it)->get_pwd())==0)
		{
			strcpy(clogin::name,(*it)->get_name());
			clogin::role=(*it)->get_role();

			
			//��¼��֤�ɹ��󷵻ؽ�ɫ
			return (*it)->get_role();
		}
	}
	//��¼��֤ʧ�ܷ���0
	return 0;

}

//��¼������������
clogin::~clogin(){}