#ifndef CTROL_EDIT_H
#define CTROL_EDIT_H

#include <iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "Ctrol.h"

//�༭����
class cedit:public ctrol
{
public:
    cedit();

	cedit(int x,int y,int width,int height,int maxLen,int iputType,int ips,char *pcontent,int type);
	void editKeyListen(int key);

	~cedit();
	
private:
	
	int maxLen;//����������󳤶�
	
	int iputType;//����������������: 1-���֣�2-��ĸ��3-������ĸ
	
	int ips;//��ʾ��ʽ: ����1������0
	
	int key;//���̰���


};

#endif