#include "Cwin_check_record.h"
//----------------------�̵��¼ҳ��----------------------------
int ccheck_record::direction=1;
string ccheck_record::ccheck_str;
//�̵��¼����Ĭ�Ϲ��캯��
ccheck_record::ccheck_record(){}

//�̵��¼���ڹ��캯��
ccheck_record::ccheck_record(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(42,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new cbutton(27,18,0,0,"��",BUTTON));
	this->addCtrol(new cbutton(27,20,0,0,"��",BUTTON));
	this->addCtrol(new cbutton(27,22,0,0,"��",BUTTON));
	this->addCtrol(new cbutton(30,26,12,2,"  ����",BUTTON));
}



//��ʾ�̵������Ʒ���ݺ���
void ccheck_record::goods_show(int direction)
{
	int j=1;
	int x=0;

	//���õ���������
	map<string,map<string,cgoods *> >::iterator it;

	//�ÿո�ȥ��ձ��
	for (j=1;j<4;j++)
	{
		x=0;
		ctool::gotoxy(32+20*x++,16+2*j);
		cout<<"                  ";
		ctool::gotoxy(32+20*x++,16+2*j);
		cout<<"                  ";
	}
	j=1;
	//��������ҳ��ƫ�Ʒ�����ҳ����
	advance(it=multiMap.begin(),3*direction-3);
	//������ӡ����
	for(it;it!=multiMap.end()&&j<4;it++,j++)
	{				
		x=0;
		ctool::gotoxy(32+20*x++,16+2*j);
		cout<<it->first;
		ctool::gotoxy(32+20*x++,16+2*j);
		cout<<check_state[it->first];
		
   }

}

//��д�̵��¼show
void ccheck_record::show()
{

	
	//��ʾʱ��
	cwin::UserandTime();
	vector<string>label;
	label.push_back("     �̵���");
	label.push_back("     �̵�״̬");
	cform::show_form(30,15,40,8,2,4,label);

	ctool::gotoxy(60,32);
	cout<<"���� ����ҳ��������ѡ������";

	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

	ctool::gotoxy(24,17);
	cout<<" ";
	ctool::gotoxy(24,19);
	cout<<" ";
	ctool::gotoxy(24,21);
	cout<<" ";
	
	goods_show(direction);
	ctool::gotoxy(50,24);
	cout<<"1"<<"/"<<multiMap.size()/3+1<<"   ";
}


//��д�̵�������к���
void ccheck_record::winRun()
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
				  cout<<--direction<<"/"<<multiMap.size()/3+1<<"   ";
				  goods_show(direction);
				  
				  break;
			   }
			   
		   case RIGHT:	
			   {
				   //���ҳ�������һҳ����ʾ
				   

				    //��ʾ��Ʒ����

				   if(direction==multiMap.size()/3+1)
				   {
					   MessageBox(NULL,"�Ѿ������һҳ��","��ʾ",0);
					   break;										   
				   }	  
				    ctool::gotoxy(48,24);
					cout<<++direction<<"/"<<multiMap.size()/3+1<<"   ";
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

//�̵���洰�ڲ�������
int ccheck_record::doAction()
{
	//�ؼ�Ϊ�½��̵�ʱ
	if(this->focusIndex==1||this->focusIndex==2||this->focusIndex==3)
	{
		
			
		map<string,map<string,cgoods *> >::iterator it;
		advance(it=multiMap.begin(),3*direction-3+this->focusIndex-1);
				
		if (it!=multiMap.end())
		{
			ccheck_record::ccheck_str=it->first;
			//�̵�Ա���ܲ��������ѳ���������
			if (cwin::role==2&&check_state[ccheck_record::ccheck_str]!="�ѳ���")
			{
				MessageBox(NULL,"���ܲ���","��ʾ",0);
				ccheck_record::winRun();
				return ccheck_record::doAction();

			}
			//�Ѿ������������̵�����
			if (check_state[ccheck_record::ccheck_str]=="�ѳ���")
			{
				
				return 19;
			}
			//�����ѳ����ľ���ת���̵����
			else
			{
				
				goods_map4=it->second;
				check_state[ccheck_record::ccheck_str]="������";
				return 17;
			}
		}
		else
		{
			//û�����ݾ���ʾ
			MessageBox(NULL,"û������","��ʾ",0);
			ccheck_record::winRun();
			return ccheck_record::doAction();

		}
		
	}
	//�ؼ�Ϊ����ʱ
	if(this->focusIndex==4)
	{
		//����ǹ���Ա�ͷ��ع���Ա��ҳ�棬�̵�Ա�ͷ����̵�Ա����
		if (cwin::role==1)
		{
			return 1;
		}
		else
		{
			return 13;
		}
		
	}
	return -1;
}
ccheck_record::~ccheck_record(){}
