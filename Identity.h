#pragma once
#include<iostream>
using namespace std;

//抽象类不需要实现

//身份抽象类
class Identity
{
public:
	//子菜单  使用纯虚函数
	virtual void submenu() = 0;

public:
	string m_UserName;		//用户名
	string m_PassWord;		//密码

};