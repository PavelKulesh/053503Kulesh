#include <iostream>
#include "Hotel_info.h"
#include "DataJoke.cpp"

using namespace std;

int PrintMenu()
{
	while (1)
	{
		cout << "\n Choose variant:\n"
				"1. Show all dostupnie\n"
				"2. fIND Suitable\n"
				"3. reserv\n"
				"4. eXIt\n";
		int digit;
		cin >> digit;
		if (digit > 4 || digit < 1)
		{
			cout << "\nTry again\n";
		}
		else
		{
			return digit;
		}
	}
}

int main()
{

	get_data("DataBase.txt");
	string s;
	while (1)
	{
		switch (int choise = PrintMenu())
		{
		case 1:
			showAvailable();

			break;
		case 2:
			//string s = "Mogilev,3,budget,min";
			cout << "Pull ur request in format:" << endl;
			cout << "City,amount of rooms,class(budget,standart,luxe),price(min/max)" << endl;

			cin >> s;
			cout << query(s);
			break;
		case 3:
			cout << "To reserv enter information like:" << endl;
			cout << "City,amount of rooms,class(budget,standart,luxe),price(min/max)" << endl;
			cin >> s;
			reserv(s);

			break;
		case 4:
			set_data("DataBase.txt");
			return 0;

		default:
			cout << "\nbad news\n";
			return 0;
		}
	}
}
