#ifndef CWIN_LOGIN_H_
#define CWIN_LOGIN_H_

#pragma warning (disable: 4786)
#include "Cwin.h"
#include <string.h>
#include "Ctrol.h"
#include "Cuser.h"
#include "user_Checkers.h"
#include "user_admin.h"
#include "Cdata.h"
#include "Cwin.h"

#include <list>
#include <vector>
using namespace std;

//��¼������
class clogin:public cwin,public cdata
{
public:
	
	clogin();
	clogin(int x,int y,int width,int height);	
	//��¼�ж�
	int loginJudge();
	//��¼���ڲ�������
	int doAction();
	//��¼��������
	~clogin();

	friend class cwin;


};


#endif