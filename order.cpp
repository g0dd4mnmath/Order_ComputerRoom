#include"order.h"


//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;

	ifs.open(ORDER_FILE, ios::in);

	string date;
	string time;
	string studentId;
	string userName;
	string room;
	string state;

	this->m_Size = 0;

	if (!ifs.is_open())
	{
		cout << "预约信息打开失败!" << endl;
	}

	while (ifs >> date && ifs >> time && ifs >> studentId && ifs >> userName && ifs >> room && ifs >> state)
	{
		/*cout << date << time << studentId << userName << room << state << endl;*/
		string key;
		string value;
		
		map<string, string>m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = time.find(":");
		if (pos != -1)
		{
			key = time.substr(0, pos);
			value = time.substr(pos + 1, time.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = studentId.find(":");
		if (pos != -1)
		{
			key = studentId.substr(0, pos);
			value = studentId.substr(pos + 1, studentId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		
		pos = userName.find(":");
		if (pos != -1)
		{
			key = userName.substr(0, pos);
			value = userName.substr(pos + 1, userName.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = room.find(":");
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = state.find(":");
		if (pos != -1)
		{
			key = state.substr(0, pos);
			value = state.substr(pos + 1, state.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//将小的map容器放入大的map容器中
		this->m_OrderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	ifs.close();
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ofs.out || ofs.trunc);

	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"] << " ";
		ofs << "time:" << this->m_OrderData[i]["time"] << " ";
		ofs << "studentId:" << this->m_OrderData[i]["studentId"] << " ";
		ofs << "userName:" << this->m_OrderData[i]["userName"] << " ";
		ofs << "room:" << this->m_OrderData[i]["room"] << " ";
		ofs << "state:" << this->m_OrderData[i]["state"] << " ";
		ofs << endl;
	}

	ofs.close();
}