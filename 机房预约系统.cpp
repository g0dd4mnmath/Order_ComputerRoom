#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"Administrator.h"

//����Ա�˵�����
void AdministratorMenu(Identity*& admin)
{
	while (true)
	{
		//��ʾ����Ա�˵�
		admin->submenu();

		Administrator* adm = (Administrator*)admin;//�Ѹ���ָ��ǿתΪ����ָ�� ���������е������ӿ�
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://����˺�
			/*cout << "����˺�" << endl;*/
			adm->addAccount();
			break;
		case 2://�鿴�˺�
			//cout << "�鿴�˺�" << endl;
			adm->showAccount();
			break;
		case 3://�鿴����
			//cout << "�鿴����" << endl;
			adm->showComputerRoom();
			break;
		case 4://���ԤԼ
			//cout << "���ԤԼ" << endl;
			adm->clearOrder();
			break;
		case 0://ע����¼
			delete admin;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//��ʦ�˵�����ʵ��
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
			//cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();
			break;
		case 2:
			//cout << "���ԤԼ" << endl;
			tea->validOrder();
			break;
		case 0:
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//ѧ���˵�����ʵ��
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
			//cout << "����ԤԼ" << endl;
			stu->applyOrder();
			break;
		case 2:
			//cout << "�鿴����ԤԼ" << endl;
			stu->showMyOrder();
			break;
		case 3:
			//cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
			break;
		case 4:
			//cout << "ȡ��ԤԼ" << endl;
			stu->CancelOrder();
			break;
		case 0:
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//��¼���� ȫ�ֺ���
void LoginIn(string FileName, int IdentityType)
{
	//����ָ�� ָ���������
	Identity* Person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(FileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string username = "";
	string password = "";

	//�ж����
	if (IdentityType == 1)
	{
		cout << "���������ѧ��: " << endl;
		cin >> id; 
	}
	else if (IdentityType == 2)
	{
		cout << "����������ְ�����: " << endl;
		cin >> id;
	}

	cout << "�������û���: " << endl;
	cin >> username;

	cout << "����������:" << endl;
	cin >> password;

	//��֤���
	if (IdentityType == 1)
	{
		//ѧ�������֤
		//���ļ��ж�ȡ��ѧ�� �û��� ����
		int fId;
		string fUserName;
		string fPassword;
		while (ifs >> fId && ifs >> fUserName && ifs >> fPassword)
		{
			//���û��������Ϣ�Ա�
			if (fId == id && fUserName == username && fPassword == password)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				//����ѧ������
				Person = new Student(id, username, password);

				//����ѧ���Ӳ˵�
				StudentMenu(Person);
				return;
			}
		}

	}
	else if (IdentityType == 2)
	{
		//��ʦ�����֤
		int fId;
		string fUserName;
		string fPassword;

		while (ifs >> fId && ifs >> fUserName && ifs >> fPassword)
		{
			if (fId == id && fUserName == username && fPassword == password)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				//������ʦ����
				Person = new Teacher(id, username, password);

				//������ʦ�Ӳ˵�
				TeacherMenu(Person);

				return;
			}
		}

	}
	else if (IdentityType == 3)
	{
		//����Ա�����֤
		string fUserName;
		string fPassword;
		
		while (ifs >> fUserName && ifs >> fPassword)
		{
			if (fUserName == username && fPassword == password)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				//��������Ա����
				Person = new Administrator(username, password);

				//�������Ա�Ӳ˵�
				AdministratorMenu(Person);
				return;
			}
		}
	}

	cout << "��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}

//��ʾ�˵�
void showMenu()
{
	cout << "==================== ��ӭ��������ɵ�ƻ���ԤԼϵͳ ====================" << endl;
	cout << endl << "��ѡ��������" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    1��ѧ������                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    2����    ʦ                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    3���� �� Ա                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t|                    0����    ��                    |" << endl;
	cout << "\t\t|                                                   |" << endl;
	cout << "\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	cout << "���������ѡ��: " << endl;
}

int main() {


	int select = 0;

	while (true)
	{
		showMenu();
		cin >> select;


		switch (select)
		{
		case 1://ѧ������
			LoginIn(STUDENT_FILE, select);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, select);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, select);
			break;
		case 0://�˳�
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "��������������ѡ��!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");

	return 0;
}