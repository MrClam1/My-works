#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;


int main() {
	const int N = 3, M = 3;
	int mas[N][M];
	cout << "Enter numbers in massive: \n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mas[i][j];
		}
	}
	cout << "Your massive: \n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
int main() {
	const int N = 3, M = 3;
	int mas[N][M];
	int sum = 0;
	int i, j;
	cout << "Enter numbers in massive: \n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mas[i][j];
		}
	}
	cout << "Your massive: \n";
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			sum = sum + mas[i][j];
		}
		cout << "Amount of numbers in " << i + 1 << " line: " << sum << endl;
		sum = 0;
	}
	for (j = 0; j < N; j++) {
		for (i = 0; i < M; i++) {
			sum = sum + mas[i][j];
		}
		cout << "Amount of numbers in " << j + 1 << " column: " << sum << endl;
		sum = 0;
	}
	return 0;
}
*/
