#include "Cgoods.h"


//����Ĭ�Ϲ��캯��
cgoods::cgoods(){}

//���ﹹ�캯��
cgoods::cgoods(string goods_ID,string goods_name,string goods_type,double goods_price,int goods_mount,string goods_Position)
{

	this->goods_ID=goods_ID;
	this->goods_name=goods_name;
	this->goods_type=goods_type;
	this->goods_Position=goods_Position;
	this->goods_price=goods_price;
	this->goods_mount=goods_mount;
	this->check_mount=0;
	this->rectification=0;

}
//���ﹹ�캯��
cgoods::cgoods(string goods_ID,string goods_name,string goods_type,double goods_price,int goods_mount,string goods_Position,int check_mount)
{

	this->goods_ID=goods_ID;
	this->goods_name=goods_name;
	this->goods_type=goods_type;
	this->goods_Position=goods_Position;
	this->goods_price=goods_price;
	this->goods_mount=goods_mount;
	this->check_mount=check_mount;
	this->rectification=0;
}

//������������
cgoods::~cgoods(){}