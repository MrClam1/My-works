#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <locale.h>
#include <Time.h>
#include <conio.h>

using namespace std;

struct Personal {
	string name;
	string number;
	string start;
	string end;
	int debt;
	int credit;
};
struct Service {
	string name_service;
	int id;
	float cost;
	string time_service;
};
struct Information_Service {
	string number_service;
	int id_service;
	string data;
	string time_services;
	int seconds_services;
};
struct Time_services {
	int data_serv;
	int month_serv;
	int year_serv;
	int hour_serv;
	int min_serv;
	int sec_serv;
};
struct Report {
	string start_document;
	string number_telephone;
	int summa;
	int ident;
	int seconds_service;
};
struct Group {
	Personal person[10];
	Service services[10];
	Information_Service information_services[10];
	Time_services time_serv[10];
	Report end_programm[10];
	Report finish[10];
};
Group Groupofpeople = {};
int Read_information() {
	char name_person[50], number_person[20], start_person[20], end_person[20], second[50];
	string second_test;
	int debt_person, credit_person, test = 0;
	float cost_serv;
	FILE* file_name;
	FILE* file_services;
	FILE* file_information;
	errno_t Error1, Error2, Error3;
	Error1 = fopen_s(&file_name, "Name.txt", "r");
	if (Error1 == 0) {
		fseek(file_name, 0L, SEEK_SET);
		for (int i = 0; i < 10; i++) {
			fscanf_s(file_name, "%50[^,], %20[^,], %20[^,], %20[^,], %d, %d \n", name_person, 50, number_person, 20, start_person, 20, end_person, 20, &debt_person, &credit_person);
			Personal Person = {};
			Person.name = name_person;
			Person.number = number_person;
			Person.start = start_person;
			Person.end = end_person;
			Person.credit = credit_person;
			Person.debt = debt_person;
			Groupofpeople.person[i] = Person;
		}
		fclose(file_name);
		test++;
	}
	else {
		cout << "=== [INFORMATION ABOUT CLIENTS NOT FOUND!] ===" << endl;
		cout << "=== [PLEASE, CHECK A FILE] ===" << endl;
	}
	Error2 = fopen_s(&file_services, "Services.txt", "r");
	if (Error2 == 0) {
		fseek(file_services, 0L, SEEK_SET);
		for (int i = 0; i < 10; i++) {
			fscanf_s(file_services, "%50[^,], %d, %f, %20[^\n] \n", name_person, 50, &debt_person, &cost_serv, number_person, 20);
			Service Services = {};
			Services.name_service = name_person;
			Services.id = debt_person;
			Services.cost = cost_serv;
			Services.time_service = number_person;
			Groupofpeople.services[i] = Services;
		}
		fclose(file_services);
		test++;
	}
	else {
		cout << "=== [INFORMATION ABOUT SERVICES NOT FOUND!] ===" << endl;
		cout << "=== [PLEASE, CHECK A FILE] ===" << endl;
	}
	Error3 = fopen_s(&file_information, "Information Services.txt", "r");
	if (Error3 == 0) {
		int data_services, month_services, year_services, seconds;
		int hour_services, min_services, second_services;
		fseek(file_information, 0L, SEEK_SET);
		for (int i = 0; i < 10; i++) {
			fscanf_s(file_information, "%20[^,], %d, %s %20[^,], %50[^\n] \n", number_person, 20, &debt_person, name_person, 50, start_person, 20, second, 50);
			Information_Service Name_services = {};
			Time_services data_s = {};
			second_test = second;
			if (second_test == "#") {
				Name_services.seconds_services = 1;
			}
			else {
				sscanf_s(second, "%d", &seconds);
				Name_services.seconds_services = seconds;
			}
			Name_services.number_service = number_person;
			Name_services.id_service = debt_person;
			Name_services.data = name_person;
			Name_services.time_services = start_person;
			sscanf_s(name_person, "%d.%d.%d", &data_services, &month_services, &year_services);
			sscanf_s(start_person, "%d:%d:%d", &hour_services, &min_services, &second_services);
			data_s.data_serv = data_services;
			data_s.month_serv = month_services;
			data_s.year_serv = year_services;
			data_s.hour_serv = hour_services;
			data_s.min_serv = min_services;
			data_s.sec_serv = second_services;
			Groupofpeople.time_serv[i] = data_s;
			Groupofpeople.information_services[i] = Name_services;
		}
		fclose(file_information);
		test++;
	}
	else {
		cout << "=== [INFORMATION ABOUT CLIENTS AND SERVICES NOT FOUND!] ===" << endl;
		cout << "=== [PLEASE, CHECK A FILE] ===" << endl;
	}
	return test;
}

int Report_information() {
	FILE* param_file;
	errno_t Error;
	float report_inf = 0;
	Error = fopen_s(&param_file, "Param.txt", "r");
	if (Error == 0) {
		fseek(param_file, 0L, SEEK_SET);
		fscanf_s(param_file, "%f \n", &report_inf);
		if (report_inf >= 0) {
			return report_inf;
		}
		else {
			cout << "=== [WRONG INFORMATION] ===" << endl;
			cout << "=== [PLEASE, CHECK A FILE] ===" << endl;
			return -1;
		}
		fclose(param_file);
	}
	else {
		cout << "=== [FILE PARAM NOT FOUND] ===" << endl;
		cout << "=== [PLEASE, CHECK A FILE] ===" << endl;
		return -1;
	}
}
int main() {
	float report = Report_information();
	if (report != -1) {
		Report end = {};
		int option;
		int test = Read_information();
		if (test == 3) {
			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);
			int Time_second, Time_minute, Time_hour, Time_day, Time_month, Time_year;
			Time_second = newtime.tm_sec;
			Time_minute = newtime.tm_min;
			Time_hour = newtime.tm_hour;
			Time_day = newtime.tm_mday;
			Time_month = 1 + newtime.tm_mon;
			Time_year = 1900 + newtime.tm_year;
			// Сравним 2 даты
			struct tm timeinfo;
			int time1, time2 = mktime(&newtime);
			int counts_report = 0;
			localtime_s(&timeinfo, &now);
			for (int j = 0; j < 10; j++) {
				timeinfo.tm_year = Groupofpeople.time_serv[j].year_serv - 1900;
				timeinfo.tm_mon = Groupofpeople.time_serv[j].month_serv - 1;
				timeinfo.tm_mday = Groupofpeople.time_serv[j].data_serv;
				timeinfo.tm_hour = Groupofpeople.time_serv[j].hour_serv;
				timeinfo.tm_min = Groupofpeople.time_serv[j].min_serv;
				timeinfo.tm_sec = Groupofpeople.time_serv[j].sec_serv;
				time1 = mktime(&timeinfo);
				if (abs(time2 - time1) <= 7 * 24 * 60 * 60) {
					Groupofpeople.end_programm[counts_report].number_telephone = Groupofpeople.information_services[j].number_service;
					Groupofpeople.end_programm[counts_report].ident = Groupofpeople.information_services[j].id_service;
					Groupofpeople.end_programm[counts_report].seconds_service = Groupofpeople.information_services[j].seconds_services;
					for (int k = 0; k < 10; k++) {
						if (Groupofpeople.person[k].number == Groupofpeople.information_services[j].number_service) {
							Groupofpeople.end_programm[counts_report].start_document = Groupofpeople.person[k].start;
						}
					}
					counts_report++;
				}
			}
			int identification = 0, summa_serv = 0, summa_all;
			for (int i = 0; i < counts_report; i++) {
				for (int j = 0; j < 10; j++) {
					if (Groupofpeople.services[j].id == Groupofpeople.end_programm[i].ident) {
						if (Groupofpeople.services[j].time_service == "#") {
							summa_all = Groupofpeople.end_programm[i].seconds_service * Groupofpeople.services[j].cost;
						}
						else {
							if (Groupofpeople.services[j].time_service == "min") {
								summa_all = (Groupofpeople.end_programm[i].seconds_service / 60) * Groupofpeople.services[j].cost;
							}
							else {
								if (Groupofpeople.services[j].time_service == "days") {
									summa_all = (Groupofpeople.end_programm[i].seconds_service / (60 * 60 * 24)) * Groupofpeople.services[j].cost;
								}
								else {
									if (Groupofpeople.services[j].time_service == "month") {
										summa_all = (Groupofpeople.end_programm[i].seconds_service / (60 * 60 * 24 * 31)) * Groupofpeople.services[j].cost;
									}
									else {
										cout << "=== [ERROR!!!] ===" << endl;
									}
								}
							}
						}
					}
					if (summa_all >= report) {
						Groupofpeople.finish[summa_serv].number_telephone = Groupofpeople.end_programm[i].number_telephone;
						Groupofpeople.finish[summa_serv].start_document = Groupofpeople.end_programm[i].start_document;
						summa_serv++;
						identification++;
						summa_all = report - 100;
					}
				}
			}
			FILE* report_file;
			errno_t Error4;
			float report_inf = 0;
			Error4 = fopen_s(&report_file, "Report.txt", "w");
			if (Error4 == 0) {
				for (int q = 0; q < identification; q++) {
					fprintf_s(report_file, "%s %d %s", "The", q + 1, "people has number: ");
					fprintf_s(report_file, "%s \n", Groupofpeople.finish[q].number_telephone.c_str());
					fprintf_s(report_file, "%s %d %s", "The", q + 1, "people has start document: ");
					fprintf_s(report_file, "%s \n", Groupofpeople.finish[q].start_document.c_str());
					fprintf_s(report_file, "\n");
				}
				fclose(report_file);
			}
		}
		else {
			cout << "=== [INFORMATION NOT FOUND!!!] ===" << endl;
			cout << "=== [PLEASE, CHECK ALL FILES!!!] ===" << endl;
		}
	}
	return 0;
}
