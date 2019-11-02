#include <stdio>
#include <Windows.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Human {
  char* name;
  int weight;
  int height;
};

int main () {
  int max = 0;
  int counts;
  cout << "Enter counts of people: \n";
  cin >> counts;
  Human *users = new Human[counts];
  cout << "Enter information about people";
  for (int i = 0; i < counts; i++) {
    char *name = new char[50];
    int WEIGHT;
    int HEIGHT;
    cin.ignore();
    cin.get(name, 50);
    cout << "Enter weight of " << i + 1 << " human: \n";
    cin >> WEIGHT;
    cout << "Enter height of " << i + 1 << " human: \n";
    cin >> HEIGHT;
    Human people = {
      name,
      WEIGHT,
      HEIGHT
    };
    users[i] = people;
  }
  for (int i = 0; i < counts; i++) {
    if (max < users[i].weight) {
      max = i;
    }
  }
  cout << "The highest weight is " << users[max].weight << endl;
  cout << "Human< who have the highest weight is " << users[max].name << endl;
  for (int i = 0; i < counts; i++) {
    delete[] users[i].name;;
  }
  delete[] users;
  return 0;
}
