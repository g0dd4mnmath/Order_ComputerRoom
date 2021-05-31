#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include<algorithm>
#include<fstream>
#include<vector>
class Administrator :public Identity
{
public:
	//默认构造
	Administrator();

	//有参构造
	Administrator(string username, string password);

	//初始化容器
	void InitVector();

	//菜单界面
	virtual void submenu();

	//添加账号
	void addAccount();

	//检验重复
	bool checkRepeat(int id , int IdentityType);

	//查看账号
	void showAccount();

	//查看机房信息
	void showComputerRoom();

	//清空预约
	void clearOrder();

public:
	//学生容器
	vector<Student>vStudent;

	//老师容器
	vector<Teacher>vTeacher;

	//机房容器
	vector<ComputerRoom>vRoom;
};