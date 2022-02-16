#include "Ctrol.h"

//�ؼ�Ĭ�Ϲ��캯��
ctrol::ctrol(){}


//�ؼ����캯��
ctrol::ctrol(int x,int y,int width,int height,char *pcontent,int type)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->type=type;

	if(pcontent!=NULL)
	{
		//content��Ҫ��ʼ��
		memset (this->content,0,sizeof(this->content));
		//content���ݸ�ֵ
		strcpy(this->content,pcontent);
	}
}



//�ؼ�չʾ����
void ctrol::show()
{
	switch(type)
	{
	//��ǩ��ӡ
	case LABEL:		
		ctool::gotoxy(x,y);
		cout<<this->content<<endl;
		break;
    //�༭���ӡ
	case EDIT:
		ctool::paintWindow(x-3, y-1,width, height);
		break;
	//��ť��ӡ
	case BUTTON:
		ctool::paintWindow(x-3, y-1,width, height);
		ctool::gotoxy(x,y);
		cout<<this->content<<endl;
		break;
	}
}
//��������
ctrol::~ctrol(){}
