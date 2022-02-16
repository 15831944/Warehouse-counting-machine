#include "Cwin_check.h"
//----------------------�̵���ҳ��----------------------------
//�̵���洰��Ĭ�Ϲ��캯��
ccheckWin::ccheckWin(){}

//�̵���洰�ڹ��캯��
ccheckWin::ccheckWin(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new cbutton(30,13,12,2,"�½��̵�",BUTTON));
	this->addCtrol(new cbutton(60,13,12,2,"�̵��¼",BUTTON));
	this->addCtrol(new cbutton(30,17,12,2,"  ����",BUTTON));
}

//�̵���洰�ڲ�������
int ccheckWin::doAction()
{
	//�ؼ�Ϊ�½��̵�ʱ
	if(this->focusIndex==1)
	{
		return 14;
	}
	//���ؼ�Ϊ�̵��¼ʱ
	if(this->focusIndex==2)
	{
		return 16;
	}
	//�ؼ�Ϊ����ʱ
	if(this->focusIndex==3)
	{
		return 2;
	}
	return -1;
}
ccheckWin::~ccheckWin(){}





//--------------------------�̵�ҳ��-------------------------------



//�̵㴰��Ĭ�Ϲ��캯��
ccheck::ccheck(){}
string ccheck::str;
int ccheck::ccheck_num=1;
string ccheck::ccheck_str;
//�̵㴰�ڹ��캯��
ccheck::ccheck(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	this->addCtrol(new clabel(18,12,10,2,"�̵��ţ�",LABEL));
	this->addCtrol(new clabel(20,20,10,2,"��Ʒ���ƣ�",LABEL));
	this->addCtrol(new clabel(20,23,10,2,"��Ʒ���ͣ�",LABEL));
	this->addCtrol(new clabel(20,26,10,2,"��Ʒ�۸�",LABEL));
	this->addCtrol(new clabel(20,29,10,2,"��λ��ţ�",LABEL));
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new clabel(18,15,10,2,"�������Ʒ��ţ�",LABEL));
	this->addCtrol(new clabel(64,19,10,2,"�������̵�����[1-10000]",LABEL));
	this->addCtrol(new cedit(37,15,20,2,12,3,1,"",EDIT));
	this->addCtrol(new cbutton(68,15,8,2,"��ѯ",BUTTON));
	this->addCtrol(new cedit(66,22,22,2,12,2,1,"",EDIT));
	this->addCtrol(new cbutton(66,26,8,2,"ȷ��",BUTTON));
	this->addCtrol(new cbutton(80,26,8,2,"����",BUTTON));
	this->addCtrol(new cbutton(66,30,22,2,"    �����̵��",BUTTON));

}

//��д�̵�show
void ccheck::show()
{
	char num[20]={0};
	//��ʾʱ��
	cwin::UserandTime();
	ctool::paintWindow(16,18,42,14);

	//�������
	time_t now = time(0); 
	tm *ltm = localtime(&now);
	sprintf(num,"%d%02d%d-%03d",1900+ltm->tm_year,1+ltm->tm_mon,ltm->tm_mday,ccheck_num);
	ccheck_str=num;
	//��ӡ���
	ctool::gotoxy(28,12);
	cout<<num;
	//��ӡ�߿�Ϳؼ�
	ctool::paintWindow(this->x, this->y,this->width,this->height);
	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}
	//��������༭�����ݣ��Ա��ٴβ�ѯ
	memset (this->ctrolArry[8]->get_content(),0,strlen(this->ctrolArry[8]->get_content()));
	memset (this->ctrolArry[10]->get_content(),0,strlen(this->ctrolArry[10]->get_content()));

}




//�̵㴰�ڲ�������
int ccheck::doAction()
{
	
	if(this->focusIndex==9)
	{
		//����map����������ѯ
		map<string,cgoods *>::iterator  it=goods_map.find(this->ctrolArry[8]->get_content());
		if(it != goods_map.end())
		{	
			//���ÿո񸲸�֮ǰ������
			ctool::gotoxy(30,20);				
			cout<<"             ";
			ctool::gotoxy(30,23);				
			cout<<"             ";
			ctool::gotoxy(30,26);				
			cout<<"             ";
			ctool::gotoxy(30,29);				
			cout<<"             ";
			
			//��ѯ���ʹ�ӡ������Ϣ
			ctool::gotoxy(30,20);				
			cout<<it->second->get_goods_name();
			ctool::gotoxy(30,23);				
			cout<<fixed<<setprecision(2)<<it->second->get_goods_type();
			ctool::gotoxy(30,26);				
			cout<<it->second->get_goods_price();
			ctool::gotoxy(30,29);				
			cout<<it->second->get_goods_Position();
			//��ȡ��ǰ����Ʒ��ţ����ڴ�������
			str=this->ctrolArry[8]->get_content();
			//��������
			ccheck::winRun();
			return ccheck::doAction();
		}

		//����ѯ��������Ϣ�͵�����ʾ
		else
		{
			MessageBox(NULL,"δ��ѯ��������������","��ʾ",0);
			return 14;			
		}
	
	}
	if(this->focusIndex==11)
	{
		//���û�������ѯ�ı�ţ��༭������Ϊ��ʱ������ʾû�в�ѯ���޷����
		if (strlen(this->ctrolArry[8]->get_content())==0)
		{
			
			ctool::gotoxy(66,27);
			cout<<"δ��ѯ��Ʒ���޷��̵㣡";
			ctool::gotoxy(66,29);
			system("pause");
			return 14;
		}


		//����������������1-10000֮�����ʾ
		if (atoi(this->ctrolArry[10]->get_content())>10000 || atoi(this->ctrolArry[10]->get_content())<1)
		{
			MessageBox(NULL,"�����������[1-10000]֮�䣡","��ʾ",0);

		}
		else
		{
			//����map����������Ҫ�̵������
			map<string,cgoods *>::iterator  it=goods_map.find(str);
			if(it != goods_map.end())
			{
				it->second->get_check_mount(atoi(this->ctrolArry[10]->get_content()));
		
				cdata::goods_map3[str]=new cgoods(it->second->get_goods_ID(),it->second->get_goods_name(),it->second->get_goods_type(),
						                                       it->second->get_goods_price(),it->second->get_goods_mount(),
															   it->second->get_goods_Position(),it->second->get_check_mount());
				
			}				
		}
		//��������
		ccheck::winRun();
		return ccheck::doAction();
	}
	

	if(this->focusIndex==12)
	{
		goods_map3.clear();	
		return 13;
	}
	if(this->focusIndex==13)
	{
		
		
		cdata::check_state[ccheck_str]="������";

		
		return 15;
	}
	return -1;
}
ccheck::~ccheck(){}


//--------------------------�̵��ҳ��-------------------------------
//�̵����Ĭ�Ϲ��캯��
ccheck_form::ccheck_form(){}

//�̵���ڹ��캯��
ccheck_form::ccheck_form(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new clabel(60,12,10,2,"�̵�״̬��",LABEL));
	this->addCtrol(new clabel(18,12,10,2,"�̵��ţ�",LABEL));
	this->addCtrol(new cbutton(20,26,12,2,"�����̵�",BUTTON));
	this->addCtrol(new cbutton(40,26,8,2,"����",BUTTON));
}



//��д�̵�show
void ccheck_form::show()
{
	int direction=1;
	char num[20]={0};
	//��ʾʱ��
	cwin::UserandTime();
	vector<string>label;
	label.push_back("  ��Ʒ���");
	label.push_back("  ��Ʒ����");
	label.push_back("  �������");
	label.push_back("  �̵�����");
	label.push_back("  ��������");
	cform::show_form(14,15,70,8,5,4,label);

	//��ӡ��ʾ
	ctool::gotoxy(60,32);
	cout<<"���� ����ҳ��������ѡ������";
	//��ӡ�̵���
	ctool::gotoxy(28,12);
	cout<<ccheck::ccheck_str;
	//��ӡҳ��
	ctool::gotoxy(48,24);
	cout<<"1"<<"/"<<goods_map3.size()/3+1<<"   ";
	//��ӡ�̵�״̬
	ctool::gotoxy(70,12);
	cout<<check_state[ccheck::ccheck_str];

	//��ӡ�߿�Ϳؼ�
	ctool::paintWindow(this->x, this->y,this->width,this->height);
	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}


	ccheck_form::goods_show(direction);
	
}



//��д�̵�������к���
void ccheck_form::winRun()
{	
	int i=0;
	int j=1;
	int x=0;
	int key;
	int direction=1;
	//��궨λ
	for(i=0; i<this->ctrolCount;i++)
	{
		if(this->ctrolArry[i]->get_type() == EDIT)//�༭��
		{
			ctool::gotoxy (this->ctrolArry[i]->get_x()-1  ,this->ctrolArry[i]->get_y());
			break;
		}
		else if(this->ctrolArry[i]->get_type() == BUTTON)//��ť
		{
			ctool::gotoxy(this->ctrolArry[i]->get_x() , this->ctrolArry[i]->get_y());
			break;
		}
	}
	while(1)
	{
		map <int,cgoods *>::iterator it;
		
		//��ȡ����ֵ
		key=ctool::getKey();
		
	   switch(key)
	   {
		   case DOWN:
			   i++;
			   if(i==this->ctrolCount)
			   {
				   i=0;
			   }
			   for(;i<this->ctrolCount;i++)
			   {
				   if(this->ctrolArry[i]->get_type() == EDIT)//�༭��
				   {
				   
					   ctool::gotoxy (this->ctrolArry[i]->get_x()-1+strlen(this->ctrolArry[i]->get_content()) ,this->ctrolArry[i]->get_y());
					   break;
				   }
				   else if(this->ctrolArry[i]->get_type() == BUTTON)//��ť
				   {
					   ctool::gotoxy(this->ctrolArry[i]->get_x()-1 , this->ctrolArry[i]->get_y());
					   break;
				   }
			   }
			   break;
		   case UP:
			   i--;
			   if(i==-1)
			   {
				   i=this->ctrolCount-1;
			   }
			   while(this->ctrolArry[i]->get_type()==LABEL) //������ǩ
			   {
					i--;
					if(i<0)  //�������һ���ؼ�
					{
						i=this->ctrolCount-1;
					}
			   }
			   
			   for(;i>0;i--)
			   {
				   if(this->ctrolArry[i]->get_type() == EDIT)//�༭��
				   {
					   ctool::gotoxy (this->ctrolArry[i]->get_x()-1+strlen(this->ctrolArry[i]->get_content()),this->ctrolArry[i]->get_y());
					   break;
				   }
				   else if(this->ctrolArry[i]->get_type() == BUTTON)//��ť
				   {
					   ctool::gotoxy(this->ctrolArry[i]->get_x()-1 , this->ctrolArry[i]->get_y());
					   break;
				   }
			   }
			   
			   break;
		   case ENTER:
			   if(this->ctrolArry[i]->get_type() == BUTTON)//��ť
			   {
				   this->focusIndex=i;
				   
				   return;
			   }
			   
			   if(this->ctrolArry[i]->get_type() == EDIT)//�༭��
			   {
				   
				  ctool::gotoxy (this->ctrolArry[i+1]->get_x()-1 , this->ctrolArry[i+1]->get_y());
				  i++;		  
			   }
			   break;
		   
		   case LEFT:
			   {
				   //���ҳ����1����ʾ
				   if(direction==1)
				   {
					   MessageBox(NULL,"�Ѿ��ǵ�һҳ��","��ʾ",0);
					   break;
				   }				   			
				  //��ʾҳ��
				  ctool::gotoxy(48,24);
				  cout<<--direction<<"/"<<goods_map3.size()/3+1<<"   ";
				  //��ʾ��Ʒ����
				  ccheck_form::goods_show(direction);
				  break;
			   }
			   
		   case RIGHT:	
			   {				   			
				    //���ҳ�������һҳ����ʾ
				   if(direction==goods_map3.size()/3+1)
				   {
					   MessageBox(NULL,"�Ѿ������һҳ��","��ʾ",0);
					   break;										   
				   }	  
				    ctool::gotoxy(48,24);
					cout<<++direction<<"/"<<goods_map3.size()/3+1<<"   ";
					//��ʾ��Ʒ����
					ccheck_form::goods_show(direction);
					break;
			   }
			   
		   default:

			   if(this->ctrolArry[i]->get_type() == EDIT)//�༭��
			   {
				   this->ctrolArry[i]->editKeyListen(key); 
				   break;
			   }
			   break;
	   }
	}
}





//��ʾ�̵���Ʒ���ݺ���
void ccheck_form::goods_show(int direction)
{
	int j=1;
	int x=0;

	//���õ���������
	map <string,cgoods *>::iterator it;

	//�ÿո�ȥ��ձ��
	for (j=1;j<4;j++)
	{
		x=0;
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<"            ";
	}
	j=1;
	//��������ҳ��ƫ�Ʒ�����ҳ����
	advance(it=goods_map3.begin(),3*direction-3);
	//������ӡ����
	for(it;it!=goods_map3.end()&&j<4;it++,j++)
	{
							
		x=0;
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_goods_ID();
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_goods_name();					
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_goods_mount();
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_check_mount();
		ctool::gotoxy(16+14*x++,16+2*j);
		cout<<it->second->get_difference_mount();
   }

}



//�̵㴰�ڲ�������
int ccheck_form::doAction()
{
	//���ؼ�Ϊ�����̵�ʱ
	if(this->focusIndex==3)
	{
		//�����ݴ���map��
		cdata::multiMap.insert(make_pair(ccheck::ccheck_str, goods_map3));
		//�ñ�����̵�״̬���δ����
		check_state[ccheck::ccheck_str]="δ����";
		ccheck::ccheck_num++;
		//����������ݣ��Ա��´�ʹ��
		goods_map3.clear();

		return 13;
	}

	//���ؼ�Ϊ����ʱ
	if(this->focusIndex==4)
	{
		return 14;
	}
	return -1;
}
	
ccheck_form::~ccheck_form(){}
