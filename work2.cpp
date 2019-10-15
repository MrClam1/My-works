#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void getUserData() {
	FILE* file;
	FILE* file1;
	ofstream out("file1.txt");
	fopen_s(&file, "file.txt", "r");
	int t;
	t = 0;
	char text[100];
	if (file != NULL)
	{
		while (!feof(file)) {
			fscanf_s(file, "%s \n", text, 100);
			t = strlen(text);
			if (text[t-1] == 'x') {
				text[t-1] = 'a';
			}
			cout << text << endl;
			out << text << endl;
		}
		fclose(file);
		out.close();
	}
	else {
		cout << "File not found \n";
	}
}



int main() {
	char test[100];
	FILE* file;

	fopen_s(&file, "file.txt", "a");
	cin >> test;
	if (file != NULL)
	{
	fputs(test, file); 
	fclose(file);
	}
	else {
		cout << "File not found";
	}
	getUserData();
	return 0;
}
