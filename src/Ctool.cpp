#include "Ctool.h"

//���궨
void ctool::gotoxy(int x,int y)
{
	HANDLE hOut;
	COORD pos= {x,y};                       
	hOut = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition (hOut, pos); 

} 


//������
void ctool::paintWindow(int X,int Y,int width,int height)
{
	int i=0;
	int j=0;

	gotoxy(X,Y);
	printf("��");
	gotoxy(X+width,Y);
	printf("��");
	gotoxy(X,Y+height);
	printf("��"); 
	gotoxy(X+width,Y+height);
	printf("��"); 
	
    //�����ϲ����²�
	 	
		for(j=2;j<width;j+=2)
		{		
			gotoxy(X+j,Y+height);
			printf("��");
			gotoxy(X+j,Y);
		    printf("��");
		}

    //������ߺ��ұ�
		for(j=1;j<height;j+=1)
		{
			gotoxy(X+width,Y+j);
			printf("��");
			gotoxy(X,Y+j);
		   	printf("��");
		}
}


//��ȡ����ֵ
//ENTERֵ13��ESCֵ27��BACKֵ8��UPֵ72��downֵ80��LEFTֵ75��RIGHTֵ77
int ctool::getKey()
{
	int key;
	key=getch();
	if(key==ENTER)//ENTERֵ13
	{
		return ENTER;
	}
	else if(key==ESC)//ESCֵ27
	{
		return ESC;
	}
	else if(key==BACK)//BACKֵ8
	{
		return BACK;
	}
	else if(key==224)//�����������ֵ����Ҫ��ȡ����
	{
		key=getch();
		switch(key)
		{
		   case UP:
			   return UP;//UPֵ72
		   case DOWN:
			   return DOWN;//DOWNֵ80
		   case LEFT:
			   return LEFT;//LEFTֵ75
		   case RIGHT:
			   return RIGHT;//RIGHTֵ77
		}
	}
	else
	{
		return key;
	}
	return 0;
}


