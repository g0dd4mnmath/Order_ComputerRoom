#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<map>
#include<fstream>

class OrderFile
{
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

public:
	//预约记录的容器
	//key 表示是第几条预约   value 表示预约的信息
	map<int, map<string, string>>m_OrderData;


	//预约条数
	int m_Size;
};