#include <iostream>
#include <assert.h>
#include "Hotel_info.h"
#include "DataJoke.h"

using namespace std;

int main()
{
	string s = "Mogilev,3,budget,min";
	assert(get_data("DataBase.txt") == 0);
	showAvailable();
	  cout << query(s);
	assert(query(s) != "");
	assert(reserv(s) == 0);
	assert(set_data("DataBase.txt") == 0);
	
  	return 0;
}
