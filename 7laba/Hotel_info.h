#pragma once

#include <string>

using namespace std;

struct HotelInfo
{
	string city;
	string Name;
	string Adress;
	string Class;
	int roomAmount;
	int cost;
	bool reserved;

	string forLoad()
	{
		string buffer;
		buffer += city;
		buffer += '_';
		buffer += Name;
		buffer += '_';
		buffer += Adress;
		buffer += '_';
		buffer += Class;
		buffer += '_';
		buffer += to_string(roomAmount).c_str();
		buffer += '_';
		buffer += to_string(cost).c_str();
		buffer += '_';
		buffer += to_string(reserved).c_str();
		buffer += '_';
		return buffer;
	}

	string forOutput()
	{
		string buffer;
		buffer += "City:" + city + " - ";
		buffer += "Name of the Hotel: " + Name + " - ";
		buffer += "Adress of the hotel: " + Adress + " - ";
		buffer += "Class of the room: " + Class + " - ";
		buffer += "Places in room: " + to_string(roomAmount) + " - ";
		buffer += "Price:" + to_string(cost) + " - ";
		buffer += '\n';
		return buffer;
	}

};

