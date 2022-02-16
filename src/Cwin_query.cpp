#include "Cwin_query.h"

//��ѯ����Ĭ�Ϲ��캯��
cquery::cquery(){}

//��ѯ���ڹ��캯��
cquery::cquery(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	
	this->addCtrol(new clabel(40,7,10,2,"��ӭʹ���̵��ϵͳ",LABEL));
	this->addCtrol(new clabel(18,12,10,2,"��������Ʒ��ţ�",LABEL));
	this->addCtrol(new cedit(37,12,20,2,12,3,1,"",EDIT));
	this->addCtrol(new cbutton(68,12,8,2,"��ѯ",BUTTON));
	this->addCtrol(new cbutton(26,26,16,2,"������Ʒ��Ϣ",BUTTON));
	this->addCtrol(new cbutton(60,26,16,2,"   ����",BUTTON));
	goods_map2=goods_map;
}

void cquery::show()
{
	int j=1;
	int direction=1;
	//��ʾ�߿�
	ctool::paintWindow(this->x, this->y,this->width,this->height);
	//��ʾʱ��
	cwin::UserandTime();
	//��ʾ�ؼ�
	for(int i=0; i<this->ctrolCount; i++)
	{
		this->ctrolArry[i]->show();
	}
	//��ʾ���
		vector<string>label;
		label.push_back("��Ʒ���");
		label.push_back("��Ʒ����");
		label.push_back("��Ʒ����");
		label.push_back("��Ʒ�۸�");
		label.push_back("��Ʒ����");
		label.push_back("��λ���");

		cform::show_form(14,15,72,8,6,4,label);

	//��ʾ��������

		cquery::goods_show(direction);
		ctool::gotoxy(48,24);
		cout<<"1"<<"/"<<goods_map2.size()/3+1<<"   ";
}



//��д��ѯ�������к���
void cquery::winRun()
{
	//vector <cgoods *>::iterator it;
	
	
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
			ctool::gotoxy (this->ctrolArry[i]->get_x()-1+strlen(this->ctrolArry[i]->get_content()),this->ctrolArry[i]->get_y());
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
				   cout<<--direction<<"/"<<goods_map2.size()/3+1<<"   ";
				   //��ʾ��Ʒ����
				   cquery::goods_show(direction);				   					
				   break;
			   }
			   
		   case RIGHT:	
			   {
				   				    
				   //���ҳ�������һҳ����ʾ
				   if(direction==goods_map2.size()/3+1)
				   {
					   MessageBox(NULL,"�Ѿ������һҳ��","��ʾ",0);
					   break;
				   }
				   ctool::gotoxy(48,24);
				   cout<<++direction<<"/"<<goods_map2.size()/3+1;
				   //��ʾ��Ʒ����
				   cquery::goods_show(direction);				   				 				   
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



//��ʾ��ѯ��Ʒ���ݺ���
void cquery::goods_show(int direction)
{
	int j=1;
	int x=0;
	//���õ���������
	map <string,cgoods *>::iterator it;

	//�ÿո�ȥ��ձ��
	for (j=1;j<4;j++)
	{
		x=0;
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<"          ";
	}
	j=1;
	//��������ҳ��ƫ�Ʒ�����ҳ����
	advance(it=goods_map2.begin(),3*direction-3);
	//������ӡ����
	for(it;it!=goods_map2.end()&&j<4;it++,j++)
	{
							
		x=0;
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_ID();
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_name();
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_type();
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<fixed<<setprecision(2)<<it->second->get_goods_price();						
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_mount();
		ctool::gotoxy(16+12*x++,16+2*j);
		cout<<it->second->get_goods_Position();
   }

}
//��ѯ���ڲ�������
int cquery::doAction()
{
	
	switch(this->focusIndex)
	{	
	//�ؼ�Ϊ��ѯʱ
	case 3:
		{
			//��ȡ��ѯ����
			string str1=this->ctrolArry[2]->get_content();
			goods_map2.clear();
			//���õ���������ѯ
			map<string,cgoods *>::iterator it;
			for (it=goods_map.begin();it!=goods_map.end();it++)
			{
				string str=it->second->get_goods_ID();
				//��ѯ������map2��������ʾ
				if (str.find(str1)!=string::npos)
				{	
					goods_map2.insert(make_pair(str,new cgoods(it->second->get_goods_ID(),it->second->get_goods_name(),it->second->get_goods_type(),
						                                       it->second->get_goods_price(),it->second->get_goods_mount(),it->second->get_goods_Position())));
					
				}
				else
				{
					
				}
			}
			if (goods_map2.size()==0)		
			{
				goods_map2=goods_map;
				MessageBox(NULL,"δ��ѯ����Ʒ","��ʾ",0);
			}
			cquery::show();
				cquery::winRun();
				return cquery::doAction();
			
			
		}
	//�ؼ�Ϊ����ʱ
	case 4:
		{
			char filename[30] = {0};
			
			time_t now = time(0); 
			tm *ltm = localtime(&now);
			//��ȡʱ���������ļ�
			sprintf(filename,"data/query/%d%d%dGI.txt",1900+ltm->tm_year,1+ltm->tm_mon,ltm->tm_mday);

			//��ѯ������Ϣͨ��map�����������ļ�
			ofstream fs(filename);

			//���õ����������ļ�
			for(map <string,cgoods *>::iterator it=goods_map2.begin();it!=goods_map2.end();it++)
			{
				fs<<it->second->get_goods_ID()<<" "<<it->second->get_goods_name()<<" "
				  <<it->second->get_goods_type()<<" "<<it->second->get_goods_price()<<" "
				  <<it->second->get_goods_mount()<<" "<<it->second->get_goods_Position()<<endl;
			}
			fs.close();
			ctool::gotoxy(43,29);
			cout<<"�����ļ��ɹ�";
			
			cquery::winRun();
			cquery::doAction();
		}

	case 5:

		goods_map2=goods_map;
		return cwin::role;
	}
	
	return -1;	
}

//��ѯ������������
cquery::~cquery(){}

			   