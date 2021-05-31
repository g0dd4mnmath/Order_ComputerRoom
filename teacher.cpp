#include"teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empid, string username, string password)
{
	this->m_EmpId = empid;
	this->m_UserName = username;
	this->m_PassWord = password;
}

//�˵�����
void Teacher::submenu()
{
	cout << "��ʦ: " << this->m_UserName << " ���ڵ�¼" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    1���鿴����ԤԼ                |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    2�����ԤԼ                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    0��ע����¼                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "���������ѡ��: " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
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
		cout << "\t�û�����" << of.m_OrderData[i]["userName"];
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

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
	}

	cout << "����˵ļ�¼����" << endl;

	vector<int>v;
	bool flag = false;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["state"] == "1")
		{
			v.push_back(i);
			flag = true;
			cout << i + 1 << "��";
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
			cout << "\tԤԼ�û�ѧ�ţ�" << of.m_OrderData[i]["studentId"];
			cout << "\t�û�����" << of.m_OrderData[i]["userName"];
			cout << "\t������" << of.m_OrderData[i]["room"];

			string o_state = "\t״̬�������";
			cout << o_state << endl;
		}
	}
	if (!flag)
	{
		cout << "����Ҫ��˵�ԤԼ" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "������Ҫ��˵�ԤԼ��¼������0�����أ�" << endl;
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
			cout << "��ѡ����˽��:" << endl;
			cout << "1�����ͨ��" << endl;
			cout << "2����˲�ͨ��" << endl;
			cin >> result;
			if (result == 1)
			{
				of.m_OrderData[v[select - 1]]["state"] = "2";
				
				cout << "ԤԼ�����ͨ��" << endl;
			}
			else if (result == 2)
			{
				of.m_OrderData[v[select - 1]]["state"] = "-1";
				
				cout << "ԤԼδ���ͨ��" << endl;
			}
			of.updateOrder();
			cout << endl;
			cout << "������" << endl;
			break;
		}
		cout << "������������������" << endl;

	}
	system("pause");
	system("cls");
}