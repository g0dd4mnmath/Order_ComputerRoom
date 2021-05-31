#include"Administrator.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"

//默认构造
Administrator::Administrator()
{

}

//有参构造
Administrator::Administrator(string username, string password)
{
	this->m_UserName = username;
	this->m_PassWord = password;

	//初始化容器
	this->InitVector();
}

//初始化容器
void Administrator::InitVector()
{
	//读取学生文件信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "学生信息读取失败" << endl;
		return;
	}

	//先将容器清空
	vStudent.clear();
	

	Student stu;
	while (ifs >> stu.m_Id && ifs >> stu.m_UserName && ifs >> stu.m_PassWord)
	{
		vStudent.push_back(stu);
	}
	cout << "当前学生数量为：" << vStudent.size() << endl;
	ifs.close();
	//学生数组初始化完成

	vTeacher.clear();
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "教师信息读取失败" << endl;
		return;
	}
	
	Teacher tea;
	while (ifs >> tea.m_EmpId && ifs >> tea.m_UserName && ifs >> tea.m_PassWord)
	{
		vTeacher.push_back(tea);
	}
	cout << "当前教师数量为：" << vTeacher.size() << endl;
	ifs.close();
	//教师数组初始化完成

	vRoom.clear();
	ifs.open(COMPUTERROOM_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "机房信息读取失败" << endl;
	}

	ComputerRoom Room;
	while (ifs >> Room.m_RoomId && ifs >> Room.m_Maxnum)
	{
		vRoom.push_back(Room);
	}
	cout << "当前机房数量为：" << vRoom.size() << endl;
	ifs.close();
	//机房数组初始化完成

}

//菜单界面
void Administrator::submenu()
{
	cout << "管理员: " << this->m_UserName << " 正在登录" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    1、添加账号                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    2、查看账号                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    3、查看机房                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    4、清空预约                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    0、注销登录                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "请输入你的选择: " << endl;
}

//添加账号
void Administrator::addAccount()
{
	cout << "请选择要添加的账号类型: " << endl;
	cout << "1、添加学生账号" << endl;
	cout << "2、添加教师账号" << endl;

	int select = 0;
	cin >> select;

	string FileName;
	string tip;
	string errorTip;
	ofstream ofs;

	if (select == 1)
	{
		FileName = STUDENT_FILE;
		tip = "请输入学生学号";
		errorTip = "该学号已注册学生账号，请重新输入！";
	}
	else if (select == 2)
	{
		FileName = TEACHER_FILE;
		tip = "请输入教师职工编号";
		errorTip = "该职工编号已注册教师账号，请重新输入！";
	}

	ofs.open(FileName, ios::out | ios::app);
	int id;
	string username;
	string password;
	
	

	while (true)
	{
		cout << tip << endl;
		cin >> id;

		bool ret = this->checkRepeat(id,select);

		if (ret == true)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "请输入姓名" << endl;
	cin >> username;

	cout << "请输入密码" << endl;
	cin >> password;

	ofs << id << " " << username << " " << password << " " << endl;

	cout << "账号添加成功" << endl;
	ofs.close();

	system("pause");
	system("cls");

	//每次添加完毕后初始化容器   防止刚添加的用户没有信息
	this->InitVector();

}

//检验重复
bool Administrator::checkRepeat(int id, int IdentityType)
{
	if (IdentityType == 1)
	{
		for (vector<Student>::iterator it = vStudent.begin(); it != vStudent.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;//找到重复的返回true
			}
		}
	}
	else if (IdentityType == 2)
	{
		for (vector<Teacher>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}

//打印学生信息
void PrintStudent(Student& stu)
{
	cout << "学生学号: " << stu.m_Id << "\t用户名: " << stu.m_UserName << "\t密码: " << stu.m_PassWord << endl;
}

//打印老师信息
void PrintTeacher(Teacher& tea)
{
	cout << "职工编号: " << tea.m_EmpId << "\t用户名: " << tea.m_UserName << "\t密码: " << tea.m_PassWord << endl;
}

//查看账号
void Administrator::showAccount()
{
	cout << "请选择要查看的账号的类型" << endl;
	cout << "1、查看学生信息" << endl;
	cout << "2、查看教师信息" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStudent.begin(), vStudent.end(), PrintStudent);
	}
	else if (select == 2)
	{
		cout << "所有教师信息如下：" << endl;
		for_each(vTeacher.begin(), vTeacher.end(), PrintTeacher);
	}

	system("pause");
	system("cls");

}

//打印机房信息
void PrintComputerRoom(ComputerRoom& Room)
{
	cout << "机房号: " << Room.m_RoomId << "\t容量: " << Room.m_Maxnum << endl;
}

//查看机房信息
void Administrator::showComputerRoom()
{
	cout << "机房信息如下：" << endl;
	for_each(vRoom.begin(), vRoom.end(), PrintComputerRoom);
	system("pause");
	system("cls");
}

//清空预约
void Administrator::clearOrder()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "预约已清空" << endl;
	system("pause");
	system("cls");
}