#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "Treasure.h"

vector<Treasure> generate_tvector(void) {					//generating the vector containing all of the treasure names ordered by id
	vector<string>treasure_names{ "coin","ore veins","crown","candle","heavy bars","starlight","wealth obol","music note","diamond","maybe soap","silver booty","champ cup","shrapnel",
		"frozen obel","irish clover","octagox","cristils","leaf ring","geode","jade","calming obel","blobbish","ruby","prime meat","scroll","sigil" };
	vector<Treasure>t_vector;
	for (int i = 0; i < treasure_names.size(); i++) {		//generating a vector with all the treasure names and id stored in a treasure class
		t_vector.push_back(Treasure(i + 1, treasure_names[i]));
	}
	return t_vector;
}

int select_treasure(vector<Treasure>t_vector) {				//selecting which treasure the user would want to get/convert
	int w = 5;
	string input;
	cout << "what treasure?" << endl;
	for (int i = 0; i < t_vector.size(); i++) {				//listing all the treasures in order of id
		cout << t_vector[i].get_treasure_id() << ". " << t_vector[i].get_treasure_name();
		if ((i+1) % 3 == 0) {
			cout << endl;
		}
		cout << endl;
	}
	getline(cin, input);
	return stoi(input);										//returning the selected treasure id
}

vector<double> treasure_needed(vector<Treasure>t_vector, int amount, int selected_t) { //function for the case where the user wants to know how much of a treasure is needed to get the treasure he wants
	vector<double>numbers;									//generate a vector with the amounts of treasures needed
	for (int i = 0; i < t_vector.size(); i++) {				//check if the current treasure is lower or higher then the selected treasure
		if (t_vector[i].get_treasure_id() >= selected_t) {
			numbers.push_back(amount*pow(3, (selected_t - t_vector[i].get_treasure_id()))); //mafs
		}
		else {												//if its lower then selected it puts 0 next to that treasure
			numbers.push_back(0);
		}
	}
	return numbers;
}

vector<double> treasure_worth(vector<Treasure>t_vector, int amount, int selected_t) { // this is for the second case where the user wants to know how much a treasure is worth
	vector<double>numbers;									//generate a vector with the amounts of treasures needed		
	for (int i = 0; i < t_vector.size(); i++) {				//check if the current treasure is lower or higher then the selected treasure
		if (t_vector[i].get_treasure_id() <= selected_t) {
			numbers.push_back(amount*pow(3, (selected_t - t_vector[i].get_treasure_id()))); //more mafs
		}
		else {
			numbers.push_back(0);							//if its higher then selected it puts 0 next to that treasure
		}
	}
	return numbers;
}

void print(vector<Treasure> t_vector, vector<double>numbers, string sentence) {
	cout << sentence << endl;								//says a case specific sentance (basically needed or will get)
	for (int i = 0; i < t_vector.size(); i++) {				//prints all the numbers gotten from previous functions next to the treasure id
		if (numbers[i] != 0) {
			cout << numbers[i] << " " << t_vector[i].get_treasure_name() << " (id " << t_vector[i].get_treasure_id() << ")" << endl;
		}
	}
}

int main() {
	string s_input, sentence, s_amount;						//whole load of variables
	int selected_t, input, amount;							
	vector<Treasure>t_vector = generate_tvector();			//generates a vector with Treasure class which contains treasure id and name
	vector<double>numbers;									//vector used to contain all the numbers for the final print
	cout << "what would you want to do?" << endl << "1. how much of x do i need for the needed treasure?" << endl << "or" << endl << "2. how much will the treasure give?" << endl
	<< "CAUTION: only enter whole numbers or the program will crash" << endl;
	getline(cin, s_input);									//gets the user input for the case below
	input = stoi(s_input);
	selected_t = select_treasure(t_vector);					//requests which treasure the user wants to convert
	switch (input) {										//case for the 2 options listed in the question above 
	case 1:													//how much is needed of each treasure to get x amount of the treasure you want
		cout << "how much of that treasure do you need? " << endl;
		getline(cin, s_amount);
		amount = stoi(s_amount);
		numbers = treasure_needed(t_vector, amount, selected_t);
		sentence = "you will need: ";
		print(t_vector, numbers, sentence);
		break;
	case 2:															//how much can a treasure be converted into
		cout << "how much of that treasure do you want to convert? " << endl;
		getline(cin, s_amount);
		amount = stoi(s_amount);
		numbers = treasure_worth(t_vector, amount, selected_t);
		sentence = "you will get: ";
		print(t_vector, numbers, sentence);
		break;
	}
	
	system("pause");
	return 0;
}

