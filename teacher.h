#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"order.h"
#include<vector>


class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empid, string username, string password);

	//�˵�����
	virtual void submenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

public:
	//��ʦ���
	int m_EmpId;
};