#ifndef CTOOL_FORM_H
#define CTOOL_FORM_H

#include "Ctool.h"

#include <iostream>
using namespace std;
#include "Ctrol.h"
#include <vector>
#include <string>

class cform
{
public:

	//Ĭ�Ϲ��캯��
	cform();

	static void show_form(int X,int Y,int width,int height,int row,int col,vector<string> label);
     //�����
	static void paint_form(int X,int Y,int width,int height,int row,int col);

protected:

	char *form_label[20];//�ؼ�����ָ������
	int labelCount;//�ؼ�����
};
#endif