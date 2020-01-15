#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Treasure{
private:
	int treasure_id;									//just read the variable name
	string treasure_name;
public:
	Treasure(int treasure_id, string treasure_name);	//treasure constructor

	void set_treasure_id(int treasure_id);				//a write to function for the id of the treasure
	void set_treasure_name(string treasure_name);		//a write to function for the name of the treasure

	int get_treasure_id(void)const;						//a read function for the id of the treasure
	string get_treasure_name(void)const;				//a read function for the name of the treasure
};
