#ifndef CDATA_H
#define CDATA_H

#pragma warning (disable: 4786)
#include <iostream>

#include <fstream>
using namespace std;
#include "Cuser.h"
#include "Cgoods.h"
#include <list>
#include <map>
#include <vector>

//������
class cdata
{
public:
    cdata();
	//��������Ϣ��ʼ��
    static void goods_Initialization();
	//��Ա����Ϣд���ļ�
	static void userToFile();
	//��������Ϣд���ļ�
	static void goodsToFile();
	//��Ա����Ϣд��list
	static void userToList();

	void userToFile(cuser *newuser);
	//��̬�û�list
	static list<cuser *> user_list;
	//��̬�û�map
	static map<int,cuser *> user_map;
	//��̬��Ʒmap
	static map<string ,cgoods *> goods_map;
	//��̬��ѯ��Ʒmap
	static map<string,cgoods *> goods_map2;
	//��̬�̵���Ʒmap
	static map<string,cgoods *> goods_map3;
	//��̬������Ʒmap
	static map<string,cgoods *> goods_map4;
	//��̬��Ʒ״̬map
	static map<string,string>check_state;

	static map<string,map<string,cgoods *> >multiMap;




	~cdata();
	
};
#endif
