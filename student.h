#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"computerRoom.h"
#include"globalFile.h"
#include<fstream>
#include<vector>
#include"order.h"

//ѧ����
class Student :public Identity
{
public:

	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string username, string password);

	//��ʼ����������
	void InitVector();

	//�˵�����
	virtual void submenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void CancelOrder();

	//�˳���¼

public:
	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom>vRoom;
};

