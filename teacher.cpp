#include"teacher.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int empid, string username, string password)
{
	this->m_EmpId = empid;
	this->m_UserName = username;
	this->m_PassWord = password;
}

//菜单界面
void Teacher::submenu()
{
	cout << "老师: " << this->m_UserName << " 正在登录" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    1、查看所有预约                |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    2、审核预约                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    0、注销登录                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "请输入你的选择: " << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		string o_date;
		switch (atoi(of.m_OrderData[i]["date"].c_str()))
		{
		case 1:o_date = "一"; break;
		case 2:o_date = "二"; break;
		case 3:o_date = "三"; break;
		case 4:o_date = "四"; break;
		case 5:o_date = "五"; break;
		}
		cout << "预约日期：周" << o_date;
		cout << "\t时间段：" << (of.m_OrderData[i]["time"] == (string)"1" ? "上午" : "下午");
		cout << "\t机房：" << of.m_OrderData[i]["room"];
		cout << "\t预约用户学号：" << of.m_OrderData[i]["studentId"];
		cout << "\t用户名：" << of.m_OrderData[i]["userName"];
		string o_state = "\t状态：";

		switch (atoi(of.m_OrderData[i]["state"].c_str()))
		{
		case 1:o_state += "审核中"; break;
		case 2:o_state += "预约成功"; break;
		case -1:o_state += "审核为通过，预约失败"; break;
		default:o_state += "预约已取消"; break;
		}
		cout << o_state << endl;
	}

	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
	}

	cout << "待审核的记录如下" << endl;

	vector<int>v;
	bool flag = false;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["state"] == "1")
		{
			v.push_back(i);
			flag = true;
			cout << i + 1 << "、";
			string o_date;
			switch (atoi(of.m_OrderData[i]["date"].c_str()))
			{
			case 1:o_date = "一"; break;
			case 2:o_date = "二"; break;
			case 3:o_date = "三"; break;
			case 4:o_date = "四"; break;
			case 5:o_date = "五"; break;
			}
			cout << "预约日期：周" << o_date;
			cout << "\t时间段：" << (of.m_OrderData[i]["time"] == (string)"1" ? "上午" : "下午");
			cout << "\t预约用户学号：" << of.m_OrderData[i]["studentId"];
			cout << "\t用户名：" << of.m_OrderData[i]["userName"];
			cout << "\t机房：" << of.m_OrderData[i]["room"];

			string o_state = "\t状态：审核中";
			cout << o_state << endl;
		}
	}
	if (!flag)
	{
		cout << "无需要审核的预约" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入要审核的预约记录（输入0代表返回）" << endl;
	int select = 0;
	int result = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			cout << "请选择审核结果:" << endl;
			cout << "1、审核通过" << endl;
			cout << "2、审核不通过" << endl;
			cin >> result;
			if (result == 1)
			{
				of.m_OrderData[v[select - 1]]["state"] = "2";
				
				cout << "预约已审核通过" << endl;
			}
			else if (result == 2)
			{
				of.m_OrderData[v[select - 1]]["state"] = "-1";
				
				cout << "预约未审核通过" << endl;
			}
			of.updateOrder();
			cout << endl;
			cout << "审核完成" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;

	}
	system("pause");
	system("cls");
}