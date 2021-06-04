#pragma once
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include "Hotel_info.h"

using namespace std;

int get_data(string Path);
int set_data(string Path);
void showAvailable();
vector<HotelInfo> queryResult(string city, string nPersons, string roomClass, string price);
void reservResult(string city, string nPersons, string roomClass, string price);
int reserv(string s);

string query(string s);
