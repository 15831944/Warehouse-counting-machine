#ifndef CTOOL_H
#define CTOOL_H

#include <windows.h>
#include <stdio.h>
#include<conio.h>

#define DOWN 80
#define UP 72

#define LEFT 75 
#define RIGHT 77
#define ENTER 13
#define ESC 27
#define BACK 8


class ctool
{
public:

	//Ĭ�Ϲ��캯��
	ctool();
     //��궨λ��������ʼλ��Ϊx��y��
	static void gotoxy(int x,int y);

	//����������ʼλ��x��y�ᣬwidth��height�����Ŀ�Ⱥ͸߶�
	static void paintWindow(int X,int Y,int width,int height);

	//��ȡ���̰���
	static int getKey();


};
#endif