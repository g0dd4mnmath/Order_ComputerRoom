#include"Administrator.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"

//Ĭ�Ϲ���
Administrator::Administrator()
{

}

//�вι���
Administrator::Administrator(string username, string password)
{
	this->m_UserName = username;
	this->m_PassWord = password;

	//��ʼ������
	this->InitVector();
}

//��ʼ������
void Administrator::InitVector()
{
	//��ȡѧ���ļ���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "ѧ����Ϣ��ȡʧ��" << endl;
		return;
	}

	//�Ƚ��������
	vStudent.clear();
	

	Student stu;
	while (ifs >> stu.m_Id && ifs >> stu.m_UserName && ifs >> stu.m_PassWord)
	{
		vStudent.push_back(stu);
	}
	cout << "��ǰѧ������Ϊ��" << vStudent.size() << endl;
	ifs.close();
	//ѧ�������ʼ�����

	vTeacher.clear();
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "��ʦ��Ϣ��ȡʧ��" << endl;
		return;
	}
	
	Teacher tea;
	while (ifs >> tea.m_EmpId && ifs >> tea.m_UserName && ifs >> tea.m_PassWord)
	{
		vTeacher.push_back(tea);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTeacher.size() << endl;
	ifs.close();
	//��ʦ�����ʼ�����

	vRoom.clear();
	ifs.open(COMPUTERROOM_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "������Ϣ��ȡʧ��" << endl;
	}

	ComputerRoom Room;
	while (ifs >> Room.m_RoomId && ifs >> Room.m_Maxnum)
	{
		vRoom.push_back(Room);
	}
	cout << "��ǰ��������Ϊ��" << vRoom.size() << endl;
	ifs.close();
	//���������ʼ�����

}

//�˵�����
void Administrator::submenu()
{
	cout << "����Ա: " << this->m_UserName << " ���ڵ�¼" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    1������˺�                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    2���鿴�˺�                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    3���鿴����                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    4�����ԤԼ                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    0��ע����¼                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "���������ѡ��: " << endl;
}

//����˺�
void Administrator::addAccount()
{
	cout << "��ѡ��Ҫ��ӵ��˺�����: " << endl;
	cout << "1�����ѧ���˺�" << endl;
	cout << "2����ӽ�ʦ�˺�" << endl;

	int select = 0;
	cin >> select;

	string FileName;
	string tip;
	string errorTip;
	ofstream ofs;

	if (select == 1)
	{
		FileName = STUDENT_FILE;
		tip = "������ѧ��ѧ��";
		errorTip = "��ѧ����ע��ѧ���˺ţ����������룡";
	}
	else if (select == 2)
	{
		FileName = TEACHER_FILE;
		tip = "�������ʦְ�����";
		errorTip = "��ְ�������ע���ʦ�˺ţ����������룡";
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
	

	cout << "����������" << endl;
	cin >> username;

	cout << "����������" << endl;
	cin >> password;

	ofs << id << " " << username << " " << password << " " << endl;

	cout << "�˺���ӳɹ�" << endl;
	ofs.close();

	system("pause");
	system("cls");

	//ÿ�������Ϻ��ʼ������   ��ֹ����ӵ��û�û����Ϣ
	this->InitVector();

}

//�����ظ�
bool Administrator::checkRepeat(int id, int IdentityType)
{
	if (IdentityType == 1)
	{
		for (vector<Student>::iterator it = vStudent.begin(); it != vStudent.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;//�ҵ��ظ��ķ���true
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

//��ӡѧ����Ϣ
void PrintStudent(Student& stu)
{
	cout << "ѧ��ѧ��: " << stu.m_Id << "\t�û���: " << stu.m_UserName << "\t����: " << stu.m_PassWord << endl;
}

//��ӡ��ʦ��Ϣ
void PrintTeacher(Teacher& tea)
{
	cout << "ְ�����: " << tea.m_EmpId << "\t�û���: " << tea.m_UserName << "\t����: " << tea.m_PassWord << endl;
}

//�鿴�˺�
void Administrator::showAccount()
{
	cout << "��ѡ��Ҫ�鿴���˺ŵ�����" << endl;
	cout << "1���鿴ѧ����Ϣ" << endl;
	cout << "2���鿴��ʦ��Ϣ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStudent.begin(), vStudent.end(), PrintStudent);
	}
	else if (select == 2)
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTeacher.begin(), vTeacher.end(), PrintTeacher);
	}

	system("pause");
	system("cls");

}

//��ӡ������Ϣ
void PrintComputerRoom(ComputerRoom& Room)
{
	cout << "������: " << Room.m_RoomId << "\t����: " << Room.m_Maxnum << endl;
}

//�鿴������Ϣ
void Administrator::showComputerRoom()
{
	cout << "������Ϣ���£�" << endl;
	for_each(vRoom.begin(), vRoom.end(), PrintComputerRoom);
	system("pause");
	system("cls");
}

//���ԤԼ
void Administrator::clearOrder()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "ԤԼ�����" << endl;
	system("pause");
	system("cls");
}