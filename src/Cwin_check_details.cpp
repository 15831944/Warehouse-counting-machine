#include "Cwin_check_details.h"
//----------------------�̵�����ҳ��----------------------------
int ccheck_details::direction=1;
//�̵����鴰��Ĭ�Ϲ��캯��
ccheck_details::ccheck_details(){}

//�̵����鴰�ڹ��캯��
ccheck_details::ccheck_details(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(42,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new clabel(60,12,10,2,"�̵�״̬��",LABEL));
	this->addCtrol(new clabel(18,12,10,2,"�̵��ţ�",LABEL));
	this->addCtrol(new cbutton(18,26,12,2,"�����̵�",BUTTON));
	this->addCtrol(new cbutton(35,26,12,2,"  ����",BUTTON));
}



//��ʾ�̵�������Ʒ���ݺ���
void ccheck_details::goods_show(int direction)
{
	int j=1;
	int x=0;
	//���õ���������
	map<string,cgoods *>::iterator it;

	

	
	//�ÿո�ȥ��ձ��
	for (j=1;j<4;j++)
	{
		x=0;
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<"              ";
	}
	j=1;
	//��������ҳ��ƫ�Ʒ�����ҳ����
	advance(it=goods_map4.begin(),3*direction-3);
	//������ӡ����
	for( it;it!= goods_map4.end()&&j<4;it++,j++)
	{
		x=0;
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_goods_ID();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_goods_name();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_goods_mount();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_check_mount();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_difference_mount();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_rectification();
		ctool::gotoxy(17+16*x++,16+2*j);
		cout<<it->second->get_explain();
	}
		
}



//��д�̵�����show
void ccheck_details::show()
{
	//��ʾʱ��
	cwin::UserandTime();

	//��ʾ��ź�״̬
	ctool::gotoxy(28,12);
	cout<<ccheck_record::ccheck_str;
	ctool::gotoxy(70,12);
	cout<<check_state[ccheck_record::ccheck_str];

	//��ӡ�ؼ�
	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}
	ctool::paintWindow(this->x, this->y,this->width,this->height);
	//��ӡ���
	vector<string>label;
	label.push_back("��Ʒ���");
	label.push_back("��Ʒ����");
	label.push_back("�������");
	label.push_back("�̵�����");
	label.push_back("��������");
	label.push_back("��������");
	label.push_back("����˵��");
	cform::show_form(15,15,112,8,7,4,label);

	ctool::gotoxy(60,32);
	cout<<"���� ����ҳ";

	ctool::gotoxy(48,24);
	cout<<"1"<<"/"<<goods_map4.size()/3+1<<"   ";


	goods_show(direction);
	
}

//��д�̵����鴰�����к���
void ccheck_details::winRun()
{
	int i=0;
	int j=1;
	int x=0;
	int key;
	
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
					   ctool::gotoxy(this->ctrolArry[i]->get_x() , this->ctrolArry[i]->get_y());
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
					   ctool::gotoxy(this->ctrolArry[i]->get_x() , this->ctrolArry[i]->get_y());
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
				   
				  ctool::gotoxy (this->ctrolArry[i+1]->get_x() , this->ctrolArry[i+1]->get_y());
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
				    
					//��ʾ��Ʒ����

				  ctool::gotoxy(48,24);
				  cout<<--direction<<"/"<<goods_map4.size()/3+1<<"   ";
				  goods_show(direction);
				  
				  break;
			   }
			   
		   case RIGHT:	
			   {
				   //���ҳ�������һҳ����ʾ
				   

				    //��ʾ��Ʒ����

				   if(direction==goods_map3.size()/3+1)
				   {
					   MessageBox(NULL,"�Ѿ������һҳ��","��ʾ",0);
					   break;										   
				   }	  
				    ctool::gotoxy(48,24);
					cout<<++direction<<"/"<<goods_map4.size()/3+1<<"   ";
					goods_show(direction);
					
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



//�̵����鴰�ڲ�������
int ccheck_details::doAction()
{
	char filename[40]={0};
	//�ؼ�Ϊ�����ļ�
	if(this->focusIndex==3)
	{
		//������̵�Ա���ؼ�������
		if (cwin::role==2)
		{
			MessageBox(NULL,"�̵�Ա���ܵ���","��ʾ",0);
			//��������
			ccheck_details::winRun();
			return ccheck_details::doAction();
			
		}

		else
		{
			sprintf(filename,"data/check/%s.txt",ccheck_record::ccheck_str.c_str());
			//��ѯ������Ϣͨ��map�����������ļ�
			ofstream fs(filename);
			//���õ����������ļ�
			for(map <string,cgoods *>::iterator it=goods_map4.begin();it!=goods_map4.end();it++)
			{
				fs<<it->second->get_goods_ID()<<" "<<it->second->get_goods_name()<<" "
				  <<it->second->get_goods_type()<<" "<<it->second->get_goods_price()<<" "
				  <<it->second->get_goods_mount()<<" "<<it->second->get_check_mount()<<" "
				  <<it->second->get_difference_mount()<<" "<<it->second->get_rectification()<<" "
				  <<it->second->get_explain()<<endl;
			}
			fs.close();
			MessageBox(NULL,"�����ɹ���","��ʾ",0);
			//��������
			ccheck_details::winRun();
			return ccheck_details::doAction();
		}
	
	}
	if(this->focusIndex==4)
	{
		return 16;
	}
	return -1;
}
ccheck_details::~ccheck_details(){}