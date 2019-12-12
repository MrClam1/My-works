#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <locale.h>

using namespace std;
struct Country {
	char name[20];
	char capital[20];
	char language[50];
	int people;
	int square;
	char money[10];
	char government[100];
};
struct Countries {
	Country countries[5];
};
void File() {
	int size;
	char text[1000];
	FILE* file;
	errno_t Error;
	Error = fopen_s(&file, "file.txt", "a");
	if (Error == 0) {
		while (strcmp(text, "Stop\n") != 0) {
			cout << "Enter information about countries: \n";
			cin.ignore();
			cin.get(text, 1000);
			size = strlen(text);
			text[size] = '\n';
			text[size + 1] = '\0';
			if (strcmp(text, "Stop\n") != 0) {
				fputs(text, file);
			}
		}
		fclose(file);
	}
	else {
		printf("File not opened! \n");
	}
}

int main() {
	string enter1;
	cout << "Do you want to add information about countries: Yes or No?" << endl;
	cin >> enter1;
	if (enter1 == "Yes") {
		File();
	}
	else {
		cout << "Okey" << endl;
	}

	Countries Group = {};
	char name[20], capital[20], language[50], money[10], government[100];
	int people, square;
	FILE* file;
	int count = 0;
	errno_t Error;
	Error = fopen_s(&file, "file.txt", "r");
	if (Error == 0) {
		while (!feof(file)) {
			if (fgetc(file) == '\n') {
				count++;
			}
		}
		fseek(file, 0L, SEEK_SET);
		if (file != NULL) {
			for (int i = 0; i <= count; i++) {

				fscanf_s(file, "%s %s %s %i, %i, %s %100[^\n]", name, 20, capital, 20, language, 50, &people, &square, money, 10, government, 100);
				Country country = {};
				for (int i = 0; i < 20; i++) {
					if (name[i] == ',') {
						name[i] = '\0';
					}
				}
				strcpy_s(country.name, name);
				strcpy_s(country.capital, capital);
				strcpy_s(country.language, language);
				country.people = people;
				country.square = square;
				strcpy_s(country.money, money);
				strcpy_s(country.government, government);

				Group.countries[i] = country;
			}
		}
		fclose(file);
	}
	else {
		printf("File not opened! \n");
	}
	int enter2, a;
	cout << "What would you like to find? Choose a number: " << endl;
	cout << "1. Capital of country" << endl;
	cout << "2. Language of country" << endl;
	cout << "3. Population of country" << endl;
	cout << "4. Square of country" << endl;
	cout << "5. Currency of country" << endl;
	cout << "6. Political system of country" << endl;
	cin >> enter2;
	cout << "What country would you like to find about information? Choose a number : " << endl;
	cout << "1. France" << endl;
	cout << "2. USA" << endl;
	cout << "3. Russia" << endl;
	cout << "4. UK" << endl;
	cout << "5. Japan" << endl;
	cin >> a;
	switch (enter2) {
	case 1:
		cout << "The capital of " << Group.countries[a - 1].name << " is" << Group.countries[a - 1].capital << endl;
		break;
	case 2:
		cout << "The official language of " << Group.countries[a - 1].name << " is" << Group.countries[a - 1].language << " language" << endl;
		break;
	case 3:
		cout << "The population of " << Group.countries[a - 1].name << " is " << Group.countries[a - 1].people << endl;
		break;
	case 4:
		cout << "The square of " << Group.countries[a - 1].name << " is " << Group.countries[a - 1].square << endl;
		break;
	case 5:
		cout << "The currence of " << Group.countries[a - 1].name << " is " << Group.countries[a - 1].money << endl;
		break;
	case 6:
		cout << "The political system of " << Group.countries[a - 1].name << " is " << Group.countries[a - 1].government << endl;
		break;
	default:
		cout << "Wrong number!" << endl;
		break;
	}
	cout << "=== [. . .] ===" << endl;
	Country Massive{

	};
	for (int i = count - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (Group.countries[j].people > Group.countries[j + 1].people) {
				Massive = Group.countries[j];
				Group.countries[j] = Group.countries[j + 1];
				Group.countries[j + 1] = Massive;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << Group.countries[i].name << ". Population of this country is: " << Group.countries[i].people << endl;
	}
	return 0;
}
