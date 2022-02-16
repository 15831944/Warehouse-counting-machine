#include "Cwin_register.h"

//ע�ᴰ��Ĭ�Ϲ��캯��
Cregister::Cregister(){}

//ע�ᴰ�ڹ��캯��
Cregister::Cregister(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(42,7,10,2,"�û�ע��",LABEL));
	this->addCtrol(new cbutton(32,13,10,2,"ID",LABEL));
	this->addCtrol(new clabel(32,16,10,2,"�û���",LABEL));
	this->addCtrol(new clabel(32,19,10,2,"��ɫ",LABEL));
	this->addCtrol(new clabel(32,22,10,2,"����",LABEL));
	this->addCtrol(new clabel(28,25,10,2,"ȷ������",LABEL));
	this->addCtrol(new cedit(39,16,20,2,12,4,1,"",EDIT));
	this->addCtrol(new cedit(39,19,20,2,10,2,1,"",EDIT));
	this->addCtrol(new cedit(39,22,20,2,10,2,0,"",EDIT));
	this->addCtrol(new cedit(39,25,20,2,10,2,0,"",EDIT));
	this->addCtrol(new cbutton(34,30,10,2,"ȷ��",BUTTON));
	this->addCtrol(new cbutton(52,30,10,2,"ȡ��",BUTTON));
	this->addCtrol(new clabel(60,19,10,2,"1����Ա��2�̵�Ա",LABEL));
	
}
//��дע��show
void Cregister::show()
{
	//��ʾʱ��
	cwin::UserandTime();
		ctool::paintWindow(36,12,20,2);
		int newID=cdata::user_map.size()+1001;
		ctool::gotoxy(38,13);
		cout<<newID;
		ctool::paintWindow(this->x, this->y,this->width,this->height);

		for(int i=0; i<this->ctrolCount; i++)
		{
			this->ctrolArry[i]->show();
		}
		memset (this->ctrolArry[6]->get_content(),0,strlen(this->ctrolArry[6]->get_content()));
		memset (this->ctrolArry[7]->get_content(),0,strlen(this->ctrolArry[7]->get_content()));
		memset (this->ctrolArry[8]->get_content(),0,strlen(this->ctrolArry[8]->get_content()));
		memset (this->ctrolArry[9]->get_content(),0,strlen(this->ctrolArry[9]->get_content()));
}



//ע�ᴰ�ڲ�������
int Cregister::doAction()
{
	int newID;
	char name[10];//�û���
	char pwd[10];//����
	int role ;//��ɫ

	//�ؼ�Ϊȷ��ʱ
	if(this->focusIndex==10)
	{
		//�жϱ༭���Ƿ�Ϊ�ա�
		if((strlen(this->ctrolArry[6]->get_content())==0)||(strlen(this->ctrolArry[7]->get_content())==0)
		 ||(strlen(this->ctrolArry[8]->get_content())==0)||(strlen(this->ctrolArry[9]->get_content())==0))
		{
		
			ctool::gotoxy(30,27);
			cout<<"���ݲ���Ϊ�գ���������д��";
			system("pause");
			return 4;

		}
		
		//�����ȷ������һ��ʱ��
		if(strcmp(this->ctrolArry[8]->get_content(),this->ctrolArry[9]->get_content())==0)
		{
			//���볤�Ȳ���6-10֮��ʱ
			if((strlen(this->ctrolArry[8]->get_content())<4||strlen(this->ctrolArry[8]->get_content())>11))
			{
			
				ctool::gotoxy(30,27);
				cout<<"���볤��Ϊ6-10λ";
				system("pause");
				return 4;

			}
			//��ȡ�༭��ע����Ϣ
			strcpy(name,this->ctrolArry[6]->get_content());
			role=atoi(this->ctrolArry[7]->get_content());
			strcpy(pwd,this->ctrolArry[8]->get_content());
			

			//��ע����Ϣ����list��map���ļ�
			newID=cdata::user_map.size()+1001;
			cdata::user_list.push_back(new cuser(newID,name,pwd,role));
			cdata::user_map.insert(make_pair(newID,(new cuser(newID,name,pwd,role))));
			cdata::userToFile(new cuser(newID,name,pwd,role));

			ctool::gotoxy(30,27);
			cout<<"ע��ɹ����˺�Ϊ"<<newID<<"��";
			system("pause");
			return 3;
		}

		//�����ȷ�����벻һ��ʱ��
		else
		{
			
			ctool::gotoxy(37,27);
			cout<<"�����ȷ�����벻һ�£�";
			system("pause");
			return 4;
		}

	}
	if(this->focusIndex==11)
	{
		
		return 3;
	}
	return -1;
}

//ע�ᴰ����������
Cregister::~Cregister(){}