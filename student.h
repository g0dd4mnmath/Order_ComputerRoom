#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"computerRoom.h"
#include"globalFile.h"
#include<fstream>
#include<vector>
#include"order.h"

//学生类
class Student :public Identity
{
public:

	//默认构造
	Student();

	//有参构造
	Student(int id, string username, string password);

	//初始化机房容器
	void InitVector();

	//菜单界面
	virtual void submenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void CancelOrder();

	//退出登录

public:
	//学生学号
	int m_Id;

	//机房容器
	vector<ComputerRoom>vRoom;
};

