#include "CmanagerWin.h"

//��vector�洰��
vector<cwin *> cmanwin::winArry;

//�����ڴ���
cmanwin::cmanwin()
{
	this->addWin(new clogin(10,5,80,29));//��¼0

	this->addWin(new cadmin(10,5,80,29));//����Ա1
	this->addWin(new checkers(10,5,80,29));//�̵�Ա2

	this->addWin(new chomepage(10,5,80,29));//������3
	this->addWin(new Cregister(10,5,80,29));//ע��4
	this->addWin(new out(10,5,80,25));//�˳�5

	this->addWin(new cquery(10,5,80,29));//��ѯ6
	
	this->addWin(new cwarehousingWin(10,5,80,29));//���������7
	this->addWin(new cwarehousing(10,5,80,29));//���8

	this->addWin(new cpopup(35,14,30,15));//����ⵯ��9
	this->addWin(new caddgoods(10,5,80,29));//��Ʒ���10

	this->addWin(new cdeliveryWin(10,5,80,29));//����������11
	this->addWin(new cdelivery(10,5,80,29));//����12

	this->addWin(new ccheckWin(10,5,80,29));//�̵�������13
	this->addWin(new ccheck(10,5,80,29));//�̵�14
	this->addWin(new ccheck_form(10,5,80,29));//�̵��15

	this->addWin(new ccheck_record(10,5,80,29));//�̵��¼16
	this->addWin(new ccheck_correct(10,5,120,29));//�̵����17
	this->addWin(new cpopup3(35,14,40,17));//�̵��������18

	this->addWin(new ccheck_details(10,5,120,29));//�̵�����19
	
}


//���洰�ڵĺ���
void cmanwin::addWin(cwin * win)
{
	this->winArry.push_back(win);
}

cmanwin::~cmanwin(){}