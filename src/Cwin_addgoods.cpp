#include "Cwin_addgoods.h"

//�����Ʒ����Ĭ�Ϲ��캯��
caddgoods::caddgoods(){}

//�����Ʒ���ڹ��캯��
caddgoods::caddgoods(int x,int y,int width,int height)
:cwin(x,y,width,height)
{
	this->addCtrol(new clabel(42,7,10,2,"��ӭʹ���̵��",LABEL));
	this->addCtrol(new cbutton(31,13,10,2,"��Ʒ��ţ�",LABEL));
	this->addCtrol(new clabel(31,16,10,2,"��Ʒ���ƣ�",LABEL));
	this->addCtrol(new clabel(31,19,10,2,"��Ʒ���ͣ�",LABEL));
	this->addCtrol(new clabel(31,22,10,2,"��Ʒ�۸�",LABEL));
	this->addCtrol(new clabel(31,25,10,2,"��λ��ţ�",LABEL));
	this->addCtrol(new cedit(45,16,20,2,12,4,1,"",EDIT));
	this->addCtrol(new cedit(45,19,20,2,10,4,1,"",EDIT));
	this->addCtrol(new cedit(45,22,20,2,10,3,1,"",EDIT));
	this->addCtrol(new cbutton(36,30,10,2,"ȷ��",BUTTON));
	this->addCtrol(new cbutton(56,30,10,2,"ȡ��",BUTTON));
	
}


//��д�����Ʒshow
void caddgoods::show()
{

	//��ʾʱ��
	cwin::UserandTime();
	 char newID[256]={0};
	 char newPosition[256]={0};

	 ctool::paintWindow(42,12,20,2);
	 ctool::paintWindow(42,24,20,2);
	 
	 sprintf(newID,"%s%d","G",cdata::goods_map.size()+1001);
	 sprintf(newPosition,"%s%d","A",cdata::goods_map.size()+1001);
	 ctool::gotoxy(44,13);
	 cout<<newID;
	 ctool::gotoxy(44,25);
	 cout<<newPosition;
	 ctool::paintWindow(this->x, this->y,this->width,this->height);

	 for(int i=0; i<this->ctrolCount; i++)
	 {
		 this->ctrolArry[i]->show();
	 }
}




//ע�ᴰ�ڲ�������
int caddgoods::doAction()
{
	char newID[20]={0};
	char newposition[256]={0};
	string goods_newID;
	string goods_name;//�û���
	string goods_type;//����
	double goods_price;
	string goods_Position;//��ɫ

	//�ؼ�Ϊȷ��ʱ
	if(this->focusIndex==9)
	{
		//�жϱ༭���Ƿ�Ϊ�ա�
		if((strlen(this->ctrolArry[6]->get_content())==0)||(strlen(this->ctrolArry[7]->get_content())==0)
		 ||(strlen(this->ctrolArry[8]->get_content())==0))
		{
			//��ձ༭�����ݡ�
			memset (this->ctrolArry[6]->get_content(),0,sizeof(this->ctrolArry[6]->get_content()));
			memset (this->ctrolArry[7]->get_content(),0,sizeof(this->ctrolArry[7]->get_content()));
			memset (this->ctrolArry[8]->get_content(),0,sizeof(this->ctrolArry[8]->get_content()));


			ctool::gotoxy(40,27);
			cout<<"���ݲ���Ϊ�գ���������д��";
			system("pause");
			return 10;

		}
		else
		{
		
			//��ȡ�༭�������Ʒ��Ϣ
			goods_name=this->ctrolArry[6]->get_content();
			goods_type=this->ctrolArry[7]->get_content();
			goods_price=atof(this->ctrolArry[8]->get_content());
			

			//�������Ʒ��Ϣ����map
			sprintf(newID,"%s%d","G",cdata::goods_map.size()+1001);
			sprintf(newposition,"%s%d","A",cdata::goods_map.size()+1001);

			goods_newID=newID;
			goods_Position=newposition;
			////����Ʒ������Ʒmap
			cdata::goods_map.insert(make_pair(goods_newID,(new cgoods(goods_newID,goods_name,goods_type, goods_price,1,goods_Position))));
			//����Ʒ�����ļ�
			ofstream fs("data/goods.txt",ios_base::app);
			fs<<goods_newID<<" "<<goods_name<<" "<<goods_type<<" "<<1<<" "<<goods_Position<<endl;
			fs.close();


			//��ձ༭�����ݡ�
			memset (this->ctrolArry[6]->get_content(),0,sizeof(this->ctrolArry[6]->get_content()));
			memset (this->ctrolArry[7]->get_content(),0,sizeof(this->ctrolArry[7]->get_content()));
			memset (this->ctrolArry[8]->get_content(),0,sizeof(this->ctrolArry[8]->get_content()));

			ctool::gotoxy(40,27);
			cout<<"��ӳɹ����������";
			system("pause");
			return 10;
		}
	}
	//���ؼ�Ϊȡ��ʱ
	if(this->focusIndex==10)
	{
		return 7;
	}
	return -1;
}

//ע�ᴰ����������
caddgoods::~caddgoods(){}