#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

struct Fruit {
	string name;
	string colour;
};

string fru (string Name) {
	Fruit Plum = {
		"Plum",
		"Blue"
	};
	Fruit Apple = {
		"Apple",
		"Red"
	};
	Fruit Banana = {
		"Banana",
		"Yellow"
	};
	Fruit Count[3] = {
		Plum,
		Apple,
		Banana
	};
	for (int i = 0; i < 3; i++) {
		if (Name == Count[i].name) {
			return Count[i].colour;
		}
		else {
			return "Error!!! Word is wrong! Try again! \n";
		}
	}
}
int main() {
	string Name;
	cout << "Choose one of these fruits: Plum, Apple, Banana \n";
	cin >> Name;
	cout << fru(Name);
	return 0;
}
