#include "Ctool_form.h"

//Ĭ�Ϲ��캯��
cform::cform(){}




void cform::show_form(int X,int Y,int width,int height,int row,int col, vector<string> label)
{
	int i=0;
	cform::paint_form(X,Y,width,height,row,col);
	
	for(vector<string>::iterator it=label.begin();it!=label.end();it++,i++)
	{
		ctool::gotoxy(X+2+i*width/row,Y+1);
        cout<<*it;
    }

}
//�����
void cform::paint_form(int X,int Y,int width,int height,int row,int col)
{
	int i=0;
	int j=0;



		//���Ʊ߽�
	    ctool::gotoxy(X,Y);
		printf("��");
		ctool::gotoxy(X+width,Y);
		printf("��");
		ctool::gotoxy(X,Y+height);
		printf("��"); 
		ctool::gotoxy(X+width,Y+height);
		printf("��"); 
	
    //�����ϲ����²�
		for(j=2;j<width;j+=2)
		{
			if(j%(width/row)==0)
			{
				ctool::gotoxy(X+j,Y+height);
				printf("��");
				ctool::gotoxy(X+j,Y);
			    printf("��");
			}
			else
			{
				ctool::gotoxy(X+j,Y+height);
				printf("��");
				ctool::gotoxy(X+j,Y);
			    printf("��");
			}
		}

 
	


    //������ߺ��ұ�
		for(j=1;j<height;j+=1)
		{
			if(j%(height/col)==0)
			{
				ctool::gotoxy(X+width,Y+j);
				printf("��");
				ctool::gotoxy(X,Y+j);
			    printf("��");			
			}
			else
			{
				ctool::gotoxy(X+width,Y+j);
				printf("��");
				ctool::gotoxy(X,Y+j);
		    	printf("��");
			}
		}
	

   //��������
	for(i=(width/row);i<width;i+=(width/row))
	{
		for(j=1;j<height;j+=1)
		{
			ctool::gotoxy(X+i,Y+j);
			printf("��");
		}
	}

	//���ƺ���
	for(i=2;i<width;i+=2)
	{
		for(j=(height/col);j<height;j+=(height/col))
		{
		   
			ctool::gotoxy(X+i,Y+j);
			printf("��");
		}
	}
	
    
	for(i=(width/row);i<width-2;i+=(width/row))
	{
		for(j=(height/col);j<height;j+=(height/col))
		{
			ctool::gotoxy(X+i,Y+j);
			printf("��");
		}
	}
}