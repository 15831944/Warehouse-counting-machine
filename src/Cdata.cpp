#include "Cdata.h"

list<cuser *> cdata::user_list;
map<int, cuser *> cdata::user_map;
map<string, cgoods *> cdata::goods_map;
map<string, cgoods *> cdata::goods_map2;
map<string,cgoods *> cdata::goods_map3;
map<string,cgoods *> cdata::goods_map4;
map<string,string>cdata::check_state;
map<string,map<string,cgoods *> > cdata::multiMap;


//��ϢĬ�Ϲ��캯��
cdata::cdata(){}


//��������Ϣ��ʼ��
void cdata::goods_Initialization()
{
	cdata::goods_map.insert(make_pair(string("G1001"),new cgoods("G1001","�����ʼǱ�","���Ӳ�Ʒ",5999.5,2,"A1001")));
	cdata::goods_map.insert(make_pair(string("G1002"),new cgoods("G1002","�������","���Ӳ�Ʒ",4999.5,2,"A1002")));
	cdata::goods_map.insert(make_pair(string("G1003"),new cgoods("G1003","��ˢ","����Ʒ",9.9,10,"A1003")));
	cdata::goods_map.insert(make_pair(string("G1004"),new cgoods("G1004","ϴ����","����Ʒ",99.9,10,"A1004")));
	cdata::goods_map.insert(make_pair(string("G1005"),new cgoods("G1005","��ԡ¶","����Ʒ",9.5,6,"A1005")));
	cdata::goods_map.insert(make_pair(string("G1006"),new cgoods("G1006","����","����Ʒ",9.9,10,"A1006")));
	cdata::goods_map.insert(make_pair(string("G1007"),new cgoods("G1007","�ɿ���","ʳ��",8.9,10,"A1007")));
	cdata::goods_map.insert(make_pair(string("G1008"),new cgoods("G1008","ˮ��","����Ʒ",9.5,6,"A1008")));
	cdata::goods_map.insert(make_pair(string("G1009"),new cgoods("G1009","��Ƭ","ʳ��",9.9,10,"A1009")));
	cdata::goods_map.insert(make_pair(string("G1010"),new cgoods("G1010","�ɿڿ���","ʳ��",3.0,10,"A1010")));
	cdata::goods_map.insert(make_pair(string("G1011"),new cgoods("G1011","��ţ��","ʳ��",40.0,10,"A1011")));
	cdata::goods_map.insert(make_pair(string("G1012"),new cgoods("G1012","ϴ��ˮ","����Ʒ",20.6,6,"A1012")));
	cdata::goods_map.insert(make_pair(string("G1013"),new cgoods("G1013","�¼�","����Ʒ",9.9,10,"A1013")));
	cdata::goods_map.insert(make_pair(string("G1014"),new cgoods("G1014","��Ƭ��","ʳ��",8.9,10,"A1014")));
  

	//��Ա����Ϣд���ļ�
	cdata::goodsToFile();
}


//��Ա����Ϣд���ļ�
void cdata::userToFile()
{
    //����list��������
	ofstream fs("data/user.txt");

	//���õ����������ļ�
	for(list<cuser*>::iterator it=user_list.begin();it!=user_list.end();it++)
	{
		fs<<(*it)->get_ID()<<" "<<(*it)->get_name()<<" "<<(*it)->get_pwd()<<" "<<(*it)->get_role()<<endl;
	}
	fs.close();
}




//��������Ϣд���ļ�
void cdata::goodsToFile()
{
    //����list��������
	ofstream fs("data/goods.txt");

	//���õ����������ļ�
	for(map <string,cgoods *>::iterator it=goods_map.begin();it!=goods_map.end();it++)
	{
		fs<<it->second->get_goods_ID()<<" "<<it->second->get_goods_name()<<" "
		  <<it->second->get_goods_type()<<" "<<it->second->get_goods_price()<<" "
		  <<it->second->get_goods_mount()<<" "<<it->second->get_goods_Position()<<endl;
	}

	fs.close();
}



//��Ա����Ϣд��list
void cdata::userToList()
{
    int ID;
	char name[10];//�û���
	char pwd[10];//����
	int role ;//��ɫ
	char buf[256]={0};
	cdata::user_list.clear();
	ifstream fs("data/user.txt");

	
	while(fs.peek()!=EOF)
	{
		fs.getline(buf,256);
		//��ȡ����
		sscanf(buf,"%d %s %s %d",&ID,name,pwd,&role);
		//����list��map
		cdata::user_list.push_back(new cuser(ID,name,pwd,role));
		cdata::user_map.insert(make_pair(ID,(new cuser(ID,name,pwd,role))));
	}
	fs.close();

}


//��ע��Ա����Ϣд���ļ�
void cdata::userToFile(cuser *newuser)
{   

	ofstream fs("data/user.txt",ios_base::app);
	fs<<newuser->get_ID()<<" "<<newuser->get_name()<<" "<<newuser->get_pwd()<<" "<<newuser->get_role()<<endl;
	fs.close();
}






cdata::~cdata(){}
