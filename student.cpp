#include"student.h"


//默认构造
Student::Student()
{

}

//有参构造
Student::Student(int id, string username, string password)
{
	this->m_Id = id;
	this->m_UserName = username;
	this->m_PassWord = password;

	this->InitVector();
}

//初始化机房容器
void Student::InitVector()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);

	ComputerRoom Room;
	while (ifs >> Room.m_RoomId && ifs >> Room.m_Maxnum)
	{
		vRoom.push_back(Room);
	}
	cout << "当前机房数: " << vRoom.size() << endl;
	ifs.close();
}


//菜单界面
void Student::submenu()
{
	cout << "学生: " << this->m_UserName << " 正在登录" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    1、申请预约                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    2、查看自身预约                |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    3、查看所有预约                |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    4、取消预约                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    0、注销登录                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "请输入你的选择: " << endl;
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放的时间为周一到周五" << endl;
	cout << "请选择预约的时间: " << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date = 0;
	int time = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择预约的时间段" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> time;
		if (time >= 1 && time <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择预约的机房" << endl;
	for (vector<ComputerRoom>::iterator it = this->vRoom.begin(); it != this->vRoom.end(); it++)
	{
		cout << it->m_RoomId << "\t 容量：" << it->m_Maxnum << endl;
	}
	
	while (true)
	{
		int symbol = 0;
		cin >> room;
		for (vector<ComputerRoom>::iterator it = this->vRoom.begin(); it != this->vRoom.end(); it++)
		{
			if (it->m_RoomId == room)
			{
				symbol = 1;
				break;
			}
		}
		if (symbol == 1)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功，等待老师审核" << endl;


	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "time:" << time << " ";
	ofs << "studentId:" << this->m_Id << " ";
	ofs << "userName:" << this->m_UserName << " ";
	ofs << "room:" << room << " ";
	ofs << "state:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//查看自身预约
void Student::showMyOrder()
{
	OrderFile of;
	
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	bool flag = false;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_OrderData[i]["studentId"].c_str()) == this->m_Id)
		{
			flag = true;

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
	}

	if (!flag)
	{
		cout << "用户自身无预约" << endl;
	}

	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder()
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

//取消预约
void Student::CancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
	}

	cout << "审核中或预约成功的记录可以取消" << endl;
	
	vector<int>v;
	int index = 1;
	bool flag = false;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_OrderData[i]["studentId"].c_str()) == this->m_Id)
		{
			if (of.m_OrderData[i]["state"] == "1" || of.m_OrderData[i]["state"] == "2")
			{
				v.push_back(i);
				flag = true;
				cout << index++ << "、";
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

				string o_state = "\t状态：";

				switch (atoi(of.m_OrderData[i]["state"].c_str()))
				{
				case 1:o_state += "审核中"; break;
				case 2:o_state += "预约成功"; break;
				}
				cout << o_state << endl;
			}
			
		}
	}
	if (!flag)
	{
		cout << "无可取消预约" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入要取消的预约记录（输入0代表返回）" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			of.m_OrderData[v[select - 1]]["state"] = "0";
			of.updateOrder();
			cout << "预约已取消" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
		
	}
	system("pause");
	system("cls");
}