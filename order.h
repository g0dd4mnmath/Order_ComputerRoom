#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<map>
#include<fstream>

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

public:
	//ԤԼ��¼������
	//key ��ʾ�ǵڼ���ԤԼ   value ��ʾԤԼ����Ϣ
	map<int, map<string, string>>m_OrderData;


	//ԤԼ����
	int m_Size;
};