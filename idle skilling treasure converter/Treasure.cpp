#include "Treasure.h"

Treasure::Treasure(int treasure_id, string treasure_name){
	this->treasure_id = treasure_id;
	this->treasure_name = treasure_name;
}

void Treasure::set_treasure_id(int treasure_id){
	this->treasure_id = treasure_id;
}

void Treasure::set_treasure_name(string treasure_name){
	this->treasure_name = treasure_name;
}

int Treasure::get_treasure_id(void) const{
	return this->treasure_id;
}

string Treasure::get_treasure_name(void) const{
	return this->treasure_name;
}
