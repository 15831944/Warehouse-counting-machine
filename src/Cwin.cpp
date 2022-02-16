#include "Cwin.h"

//����Ĭ�Ϲ��캯��
cwin::cwin(){}



//���ڹ��캯��
cwin::cwin(int x,int y,int width,int height)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->ctrolCount=0;
	this->userCount=0;
	
}



//��ʾ�û���ʱ��
void cwin::UserandTime()
{
	if(cwin::role==1||cwin::role==2)
	{
		//ʱ����ʾ
		ctool::gotoxy(61,9); 
		time_t now = time(0); 
		tm *ltm = localtime(&now);
		printf("���ڣ�%d-%02d-%d",1900+ltm->tm_year,1+ltm->tm_mon,ltm->tm_mday);

		//�û���ʾ
		if(cwin::role==1)
		{
			ctool::gotoxy(22,9); 
			cout<<"��ӭ��"<<cwin::name<<"����Ա"<<endl;
		}
		if(cwin::role==2)
		{
			ctool::gotoxy(22,9); 
			cout<<"��ӭ��"<<cwin::name<<"�̵�Ա"<<endl;
		}
	}		
}


//��ӿؼ�����
void cwin::addCtrol(ctrol *ctrolArry)
{

	this->ctrolArry[this->ctrolCount++]=ctrolArry;
}


//��ʾ�ؼ�
void cwin::show()
{
	cwin::UserandTime();

    //����
	ctool::paintWindow(this->x, this->y,this->width,this->height);

	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}

}

//�������к���
void cwin::winRun()
{
	int i=0;
	int key;
	//��궨λ
	for(i=0; i<this->ctrolCount;i++)
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
	while(1)
	{
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

		   break;

	   case RIGHT:

		   break;

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

//������������
cwin::~cwin()
{
	for(int i=0; i<this->ctrolCount;i++)
	{
		delete this->ctrolArry[i];
	}
	
}