#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	const int N = 3;
	int mas1[N], mas2[N];
	cout << "Enter numbers in first massive: \n";
	for (int i = 0; i < N; i++) {
		cin >> mas1[i];
	}
	cout << "Enter numbers in second massive: \n";
	for (int i = 0; i < N; i++) {
		cin >> mas2[i];
	}
	cout << "Your third massive: \n";
	for (int i = 0; i < N; i++) {
		cout << mas1[i] + mas2[i] << " ";
	}
	return 0;
}
