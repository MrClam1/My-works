#include <stdio.h>
#include <Windows.h>
#include <iostream>

using namespace std;

int main() {
	const int N = 5;
	int a[N], max;
	max = 0;
	for (int i = 0; i < N; i++) {
		int b;
		cout << "Enter " << i << " element: \n";
		cin >> b;
		a[i] = b;
		if (a[i] > max) {
			max = a[i];
		}
	}
	cout << max;
	return (0);
}
