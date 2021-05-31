#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"order.h"
#include<vector>


class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int empid, string username, string password);

	//菜单界面
	virtual void submenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

public:
	//老师编号
	int m_EmpId;
};