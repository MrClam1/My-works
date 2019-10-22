#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	char text[100];
	int lenght;
	cout << "Enter your text: " << endl;
	cin.get(text, 100);
	lenght = strlen(text);
	for (int i = 0; i < lenght; i++) {
		if (text[0] == 'c' || (text[i] == 'c' && text[i - 1] == ' ')) {
			if (text[i] != ' ') {
				cout << text[i];
			}
			else {
				cout << " ";
			}
		}
	}
	return 0;
}
