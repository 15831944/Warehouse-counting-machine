#ifndef CGOODS_H
#define CGOODS_H

#include <iostream>
using namespace std;

#include <string>
#include <stdio.h>
#include "Ctool.h"



//��Ʒ��
class cgoods
{
public:

	cgoods();
	cgoods(string goods_ID,string goods_name,string goods_type,double goods_price,int goods_mount,string goods_Position);
	cgoods(string goods_ID,string goods_name,string goods_type,double goods_price,int goods_mount,string goods_Position,int check_mount);
	~cgoods();

	//��ȡ��ƷID
	string get_goods_ID(){return goods_ID;};
	//��ȡ��Ʒ����
	string get_goods_name(){return goods_name;};
	//��ȡ��Ʒ����
	string get_goods_type(){return goods_type;};
	//��ȡ��Ʒ��λ���
	string get_goods_Position(){return goods_Position;};
	//��ȡ����˵��
	string get_explain(){return goods_explain;};
	//��ȡ��Ʒ�۸�
	float get_goods_price(){return goods_price;};
	//��ȡ��Ʒ����
	int get_goods_mount(){return goods_mount;};
	//��ȡ�̵�����
	int get_check_mount(){return check_mount;};
	//��ȡ��������
	int get_rectification(){return rectification;};
	//��ȡ��������
	int get_difference_mount(){return check_mount>=goods_mount?check_mount-goods_mount:goods_mount-check_mount;};
	//�����Ʒ����
	void get_goods_mount_add(int i){this->goods_mount=this->goods_mount+i;};
	//������Ʒ����
	void get_goods_mount_sub(int i){this->goods_mount=this->goods_mount-i;};
	//�޸��̵�����
	void get_check_mount(int i){this->check_mount=this->check_mount+i;};
	//�޸ĳ�������
	void get_rectification(int i){this->rectification=i;};
	//�޸ĳ���˵��
	void get_explain(string str){this->goods_explain=str;};
	//�޸Ŀ������
	void get_modify(){this->check_mount>=this->goods_mount?this->goods_mount=this->goods_mount+this->rectification:this->goods_mount=this->goods_mount-this->rectification;};



protected:
	string goods_ID;//��Ʒ���
	string goods_name;//��Ʒ����
	string goods_type;//��Ʒ����
	string goods_Position;
	string goods_explain;
	float goods_price;
	int goods_mount;
	int check_mount;
	int rectification;
	


};
#endif