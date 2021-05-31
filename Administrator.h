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
	//Ĭ�Ϲ���
	Administrator();

	//�вι���
	Administrator(string username, string password);

	//��ʼ������
	void InitVector();

	//�˵�����
	virtual void submenu();

	//����˺�
	void addAccount();

	//�����ظ�
	bool checkRepeat(int id , int IdentityType);

	//�鿴�˺�
	void showAccount();

	//�鿴������Ϣ
	void showComputerRoom();

	//���ԤԼ
	void clearOrder();

public:
	//ѧ������
	vector<Student>vStudent;

	//��ʦ����
	vector<Teacher>vTeacher;

	//��������
	vector<ComputerRoom>vRoom;
};