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
