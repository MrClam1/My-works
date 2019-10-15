#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;


int main() {
	int number;
	int a, b;
	cout << "Enter your favourite number: \n";
	cin >> number;
	cout << "Your upside down number: ";
	while (number > 0) {
		b = number % 10;
		a = b;
		number = number / 10;
		cout << a;
	}
	return 0;
}
