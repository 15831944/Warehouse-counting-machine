#include "Ctrol_edit.h"
//�༭��Ĭ�Ϲ��캯��
cedit::cedit(){}


//�༭���캯��
cedit::cedit(int x,int y,int width,int height,int maxLen,int iputType,int ips,char *pcontent,int type)
:ctrol(x,y,width,height,pcontent,type)
{

	this->maxLen=maxLen;
	this->iputType=iputType;
	this->ips=ips;	
}


//�༭���������
void cedit::editKeyListen(int key)
{
	int count=strlen(this->content);
	
	if(count>0 && key=='\b')
	{
		//���������
		if(this->iputType==4)
		{
			cout<<"\b \b";
			cout<<"\b \b";
			this->content[--count]='\0';
			this->content[--count]='\0';
			
		}
		cout<<"\b \b";
		this->content[--count]='\0';
	}
	if(count==this->maxLen)
	{
		return;
	}
	else
	{
		//������������ĸ
		if(this->iputType==1)
		{
			if(key>='a'&& key<='z'|| key>='A'&& key<='Z')
			{
				if(this->ips==1)
				{
					putch(key);
				}
				else if(this->ips==0)
				{
					putch('*');					
				}
				this->content[count]=key;
			}
		}

		//��������������
		else if(this->iputType==2)
		{
			if(key>='0'&& key<='9')
			{
				if(this->ips==1)
				{
					putch(key);
				}
				else if(this->ips==0)
				{
					putch('*');
				}
				this->content[count]=key;				
			}
		}

		//�������������ֺ���ĸ
		else if(this->iputType==3)
		{
			if(key>='0'&& key<='9'||key>='a'&& key<='z'|| key>='A'&& key<='Z')
			{
				if(this->ips==1)
				{
					putch(key);

				}
				else if(this->ips==0)
				{
					putch('*');
				}
				this->content[count]=key;			
			}
		}
		//��������������
		else if(this->iputType==4)
		{
			char ch2= getch();

			if((unsigned char)key>=0xA1 && (unsigned char)key<=0xFE)
			{
				if((unsigned char)ch2>=0xA1 && (unsigned char)ch2<=0xFE)
				{
					printf("%c%c",key,ch2);
					this->content[count++]=key;
					this->content[count]=key;
				}
			}
		}
	}
}
//�༭����������
cedit::~cedit(){}