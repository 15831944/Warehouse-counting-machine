#ifndef CTROL_H
#define CTROL_H

#include <iostream>
using namespace std;

#include <string.h>
#include "Ctool.h"

#define LABEL 1
#define EDIT 2
#define BUTTON 3

//�ؼ�����
class ctrol
{
public:
	ctrol();

	ctrol(int x,int y,int width,int height,char *pcontent,int type);
	virtual void editKeyListen(int key){};


	
	void show();
	~ctrol();

	int get_x(){return x;};
	int get_y(){return y;};
	int get_width(){return width;};
	int get_height(){return height;};
	int get_type(){return type;};
	char *get_content(){return content;};


protected:
	int x;//��ʼ�M����
	int y;//��ʼ������
	int width;//���
	int height;//�߶�
	int type;//�ؼ�����
	char content[20];//�������ݵ�

};

#endif