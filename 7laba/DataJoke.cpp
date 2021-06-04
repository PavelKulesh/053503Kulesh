#include "DataJoke.h"

list<HotelInfo> dbase;

int get_data(string Path)
{
	ifstream file(Path);
	if (!file)
	{
		cout << "File not created!";
		return -1;
	}
	else
	{
		cout << "File Opened!" << endl;
	}

	string temp;
	while (getline(file, temp))
	{
		string temp2;
		HotelInfo info;
		int i = 0;
		while (temp[i] != '_')
		{
			temp2 += temp[i];
			i++;
		}
		info.city = temp2;
		i++;
		temp2.clear();

		while (temp[i] != '_')
		{
			temp2 += temp[i];
			i++;
		}
		info.Name = temp2;
		i++;
		temp2.clear();

		while (temp[i] != '_')
		{
			temp2 += temp[i];
			i++;
		}
		info.Adress = temp2;
		i++;
		temp2.clear();

		while (temp[i] != '_')
		{
			temp2 += temp[i];
			i++;
		}
		info.Class = temp2;
		i++;
		temp2.clear();

		while (temp[i] != '_')
		{
			temp2 += temp[i];
			i++;
		}
		info.roomAmount = stoi(temp2);
		i++;
		temp2.clear();

		while (temp[i] != '_')
		{
			temp2 += temp[i];
			i++;
		}
		info.cost = stoi(temp2);
		i++;
		temp2.clear();

		while (temp[i] != '_')
		{
			temp2 += temp[i];
			i++;
		}
		info.reserved = stoi(temp2);
		i++;
		temp2.clear();

		dbase.push_back(info);
	}

	file.close();
	return 0;
}

int set_data(string Path)
{
	ofstream file(Path);
	if (!file)
	{
		cout << "File not created!";
		return -1;
	}
	else
	{
		cout << "File Saved!" << endl;
	}
	for (auto it = dbase.begin(); it != dbase.end(); it++)
	{
		file << it->forLoad();
		file << "\n";
	}

	file.close();
	return 0;
}

void showAvailable()
{
	for (auto it = dbase.begin(); it != dbase.end(); it++)
	{
		if (!it->reserved)
			cout << it->forOutput();
	}
}

vector<HotelInfo> queryResult(string city, string nPersons, string roomClass, string price)
{
	vector<HotelInfo> result;

	for (auto i : dbase)
	{
		if (i.reserved)
			continue;
		if (i.city == city)
		{
			int pers = stoi(nPersons);
			if (i.roomAmount <= pers)
			{
				if (i.Class == roomClass)
				{
					if (price == "min" || price == "max")
					{
						result.push_back(i);
						continue;
					}

					int pr = stoi(price);
					if (pr >= i.cost)
						result.push_back(i);
				}
			}
		}
	}
	return result;
}

string query(string s)
{
	int i = 0;
	string city;
	while (i < (int)s.size() && s[i] != ',')
	{
		city += s[i];
		i++;
	}

	i++;
	string nPersons;
	while (i < (int)s.size() && s[i] != ',')
	{
		nPersons += s[i];
		i++;
	}

	i++;
	string roomClass;
	while (i < (int)s.size() && s[i] != ',')
	{
		roomClass += s[i];
		i++;
	}

	i++;
	string price;
	while (i < (int)s.size() && s[i] != ',')
	{
		price += s[i];
		i++;
	}

	auto res = queryResult(city, nPersons, roomClass, price);
	string ans;
	if ((int)res.size() == 0)
		return "No results found for your query.";
	else
	{
		ans += to_string((int)res.size()) + " result(s) found: ";
		for (auto i : res)
		{
			ans += i.forOutput();
			ans += '\n';
		}
	}
	return ans;
}

void reservResult(string city, string nPersons, string roomClass, string price)
{
	for (auto i = dbase.begin(); i != dbase.end(); i++)
	{
		if (i->reserved)
			continue;
		if (i->city == city)
		{
			int pers = stoi(nPersons);
			if (i->roomAmount <= pers)
			{
				if (i->Class == roomClass)
				{
					if (price == "min" || price == "max")
					{
						i->reserved = true;
						continue;
					}

					int pr = stoi(price);
					if (pr >= i->cost)
						cout << "a";
				}
			}
		}
	}
}

int reserv(string s)
{
	int i = 0;
	string city;
	while (i < (int)s.size() && s[i] != ',')
	{
		city += s[i];
		i++;
	}

	i++;
	string nPersons;
	while (i < (int)s.size() && s[i] != ',')
	{
		nPersons += s[i];
		i++;
	}

	i++;
	string roomClass;
	while (i < (int)s.size() && s[i] != ',')
	{
		roomClass += s[i];
		i++;
	}

	i++;
	string price;
	while (i < (int)s.size() && s[i] != ',')
	{
		price += s[i];
		i++;
	}

	reservResult(city, nPersons, roomClass, price);
	return 0;
}
