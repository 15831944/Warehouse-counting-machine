#ifndef CLABEL_H
#define CLABEL_H

#include <iostream>
using namespace std;

#include "Ctrol.h"

//��ǩ��
class clabel:public ctrol
{
public:
	//Ĭ�Ϲ��캯��
    clabel();
	//���������캯��
	clabel(int x,int y,int width,int height,char *pcontent,int type);
	~clabel();

};

#endif