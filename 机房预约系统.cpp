#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"Administrator.h"

//管理员菜单功能
void AdministratorMenu(Identity*& admin)
{
	while (true)
	{
		//显示管理员菜单
		admin->submenu();

		Administrator* adm = (Administrator*)admin;//把父类指针强转为子类指针 调用子类中的其他接口
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://添加账号
			/*cout << "添加账号" << endl;*/
			adm->addAccount();
			break;
		case 2://查看账号
			//cout << "查看账号" << endl;
			adm->showAccount();
			break;
		case 3://查看机房
			//cout << "查看机房" << endl;
			adm->showComputerRoom();
			break;
		case 4://清空预约
			//cout << "清空预约" << endl;
			adm->clearOrder();
			break;
		case 0://注销登录
			delete admin;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//老师菜单功能实现
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->submenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			//cout << "查看所有预约" << endl;
			tea->showAllOrder();
			break;
		case 2:
			//cout << "审核预约" << endl;
			tea->validOrder();
			break;
		case 0:
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//学生菜单功能实现
void StudentMenu(Identity*& student)
{
	while (true)
	{
		student->submenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		
		switch (select)
		{
		case 1:
			//cout << "申请预约" << endl;
			stu->applyOrder();
			break;
		case 2:
			//cout << "查看自身预约" << endl;
			stu->showMyOrder();
			break;
		case 3:
			//cout << "查看所有预约" << endl;
			stu->showAllOrder();
			break;
		case 4:
			//cout << "取消预约" << endl;
			stu->CancelOrder();
			break;
		case 0:
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//登录功能 全局函数
void LoginIn(string FileName, int IdentityType)
{
	//父类指针 指向子类对象
	Identity* Person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(FileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string username = "";
	string password = "";

	//判断身份
	if (IdentityType == 1)
	{
		cout << "请输入你的学号: " << endl;
		cin >> id; 
	}
	else if (IdentityType == 2)
	{
		cout << "请输入您的职工编号: " << endl;
		cin >> id;
	}

	cout << "请输入用户名: " << endl;
	cin >> username;

	cout << "请输入密码:" << endl;
	cin >> password;

	//验证身份
	if (IdentityType == 1)
	{
		//学生身份验证
		//从文件中读取的学号 用户名 密码
		int fId;
		string fUserName;
		string fPassword;
		while (ifs >> fId && ifs >> fUserName && ifs >> fPassword)
		{
			//与用户输入的信息对比
			if (fId == id && fUserName == username && fPassword == password)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");

				//创建学生对象
				Person = new Student(id, username, password);

				//进入学生子菜单
				StudentMenu(Person);
				return;
			}
		}

	}
	else if (IdentityType == 2)
	{
		//老师身份验证
		int fId;
		string fUserName;
		string fPassword;

		while (ifs >> fId && ifs >> fUserName && ifs >> fPassword)
		{
			if (fId == id && fUserName == username && fPassword == password)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");

				//创建老师对象
				Person = new Teacher(id, username, password);

				//进入老师子菜单
				TeacherMenu(Person);

				return;
			}
		}

	}
	else if (IdentityType == 3)
	{
		//管理员身份验证
		string fUserName;
		string fPassword;
		
		while (ifs >> fUserName && ifs >> fPassword)
		{
			if (fUserName == username && fPassword == password)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				//创建管理员对象
				Person = new Administrator(username, password);

				//进入管理员子菜单
				AdministratorMenu(Person);
				return;
			}
		}
	}

	cout << "登录失败！" << endl;
	system("pause");
	system("cls");
}

//显示菜单
void showMenu()
{
	cout << "==================== 欢迎来到你是傻逼机房预约系统 ====================" << endl;
	cout << endl << "请选择你的身份" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    1、学生代表                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    2、老    师                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    3、管 理 员                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    0、退    出                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "请输入你的选择: " << endl;
}

int main() {


	int select = 0;

	while (true)
	{
		showMenu();
		cin >> select;


		switch (select)
		{
		case 1://学生代表
			LoginIn(STUDENT_FILE, select);
			break;
		case 2://老师
			LoginIn(TEACHER_FILE, select);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, select);
			break;
		case 0://退出
			cout << "欢迎下一次使用" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "输入有误，请重新选择!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");

	return 0;
}