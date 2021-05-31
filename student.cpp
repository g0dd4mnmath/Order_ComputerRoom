#include"student.h"


//Ĭ�Ϲ���
Student::Student()
{

}

//�вι���
Student::Student(int id, string username, string password)
{
	this->m_Id = id;
	this->m_UserName = username;
	this->m_PassWord = password;

	this->InitVector();
}

//��ʼ����������
void Student::InitVector()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);

	ComputerRoom Room;
	while (ifs >> Room.m_RoomId && ifs >> Room.m_Maxnum)
	{
		vRoom.push_back(Room);
	}
	cout << "��ǰ������: " << vRoom.size() << endl;
	ifs.close();
}


//�˵�����
void Student::submenu()
{
	cout << "ѧ��: " << this->m_UserName << " ���ڵ�¼" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    1������ԤԼ                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    2���鿴����ԤԼ                |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    3���鿴����ԤԼ                |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    4��ȡ��ԤԼ                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    0��ע����¼                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "���������ѡ��: " << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;
	cout << "��ѡ��ԤԼ��ʱ��: " << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

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
		cout << "������������������" << endl;
	}

	cout << "��ѡ��ԤԼ��ʱ���" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> time;
		if (time >= 1 && time <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ��ԤԼ�Ļ���" << endl;
	for (vector<ComputerRoom>::iterator it = this->vRoom.begin(); it != this->vRoom.end(); it++)
	{
		cout << it->m_RoomId << "\t ������" << it->m_Maxnum << endl;
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
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ����ȴ���ʦ���" << endl;


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

//�鿴����ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
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
			case 1:o_date = "һ"; break;
			case 2:o_date = "��"; break;
			case 3:o_date = "��"; break;
			case 4:o_date = "��"; break;
			case 5:o_date = "��"; break;
			}
			cout << "ԤԼ���ڣ���" << o_date;
			cout << "\tʱ��Σ�" << (of.m_OrderData[i]["time"] == (string)"1" ? "����" : "����");
			cout << "\t������" << of.m_OrderData[i]["room"];
			
			string o_state = "\t״̬��";

			switch (atoi(of.m_OrderData[i]["state"].c_str()))
			{
			case 1:o_state += "�����"; break;
			case 2:o_state += "ԤԼ�ɹ�"; break;
			case -1:o_state += "���Ϊͨ����ԤԼʧ��"; break;
			default:o_state += "ԤԼ��ȡ��"; break;
			}
			cout << o_state << endl;
		}
	}

	if (!flag)
	{
		cout << "�û�������ԤԼ" << endl;
	}

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		string o_date;
		switch (atoi(of.m_OrderData[i]["date"].c_str()))
		{
		case 1:o_date = "һ"; break;
		case 2:o_date = "��"; break;
		case 3:o_date = "��"; break;
		case 4:o_date = "��"; break;
		case 5:o_date = "��"; break;
		}
		cout << "ԤԼ���ڣ���" << o_date;
		cout << "\tʱ��Σ�" << (of.m_OrderData[i]["time"] == (string)"1" ? "����" : "����");
		cout << "\t������" << of.m_OrderData[i]["room"];
		cout << "\tԤԼ�û�ѧ�ţ�" << of.m_OrderData[i]["studentId"];

		string o_state = "\t״̬��";

		switch (atoi(of.m_OrderData[i]["state"].c_str()))
		{
		case 1:o_state += "�����"; break;
		case 2:o_state += "ԤԼ�ɹ�"; break;
		case -1:o_state += "���Ϊͨ����ԤԼʧ��"; break;
		default:o_state += "ԤԼ��ȡ��"; break;
		}
		cout << o_state << endl;
	}

	system("pause");
	system("cls");

}

//ȡ��ԤԼ
void Student::CancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ��" << endl;
	
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
				cout << index++ << "��";
				string o_date;
				switch (atoi(of.m_OrderData[i]["date"].c_str()))
				{
				case 1:o_date = "һ"; break;
				case 2:o_date = "��"; break;
				case 3:o_date = "��"; break;
				case 4:o_date = "��"; break;
				case 5:o_date = "��"; break;
				}
				cout << "ԤԼ���ڣ���" << o_date;
				cout << "\tʱ��Σ�" << (of.m_OrderData[i]["time"] == (string)"1" ? "����" : "����");
				cout << "\t������" << of.m_OrderData[i]["room"];

				string o_state = "\t״̬��";

				switch (atoi(of.m_OrderData[i]["state"].c_str()))
				{
				case 1:o_state += "�����"; break;
				case 2:o_state += "ԤԼ�ɹ�"; break;
				}
				cout << o_state << endl;
			}
			
		}
	}
	if (!flag)
	{
		cout << "�޿�ȡ��ԤԼ" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "������Ҫȡ����ԤԼ��¼������0�����أ�" << endl;
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
			cout << "ԤԼ��ȡ��" << endl;
			break;
		}
		cout << "������������������" << endl;
		
	}
	system("pause");
	system("cls");
}