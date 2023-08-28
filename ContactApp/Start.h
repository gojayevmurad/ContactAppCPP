#pragma once

#include <iostream>
#include "Entities.h"
#include "Functions.h"

using namespace std;

void ShowMenu() {
	cout << "Show All Contacts	[1]" << endl;
	cout << "Add New Contact    [2]" << endl;
	cout << "Delete Contact		[3]" << endl;
	cout << "Search Contact		[4]" << endl;
	cout << "Sorted Contact A-Z	[5]" << endl;
	cout << "Sorted Contact Z-A	[6]" << endl;
}

void Start() {
	Human* h1 = new Human{
		new char[15] {"John"},
		new char[15] {"+994552111111"},
		__DATE__
	};
	Human* h2 = new Human{
		new char[15] {"Aydin"},
		new char[15] {"+994514222222"},
		__DATE__
	};
	Human* h3 = new Human{
		new char[15] {"Leyla"},
		new char[15] {"+994514225522"},
		__DATE__
	};
	Human* h4 = new Human{
		new char[15] {"Akif"},
		new char[15] {"+994515487963"},
		__DATE__
	};

	auto humans = new Human * [4] {h1, h2, h3, h4};
	Contact* contact = new Contact{ humans, 4 };

	while (true){
		ShowMenu();
		int select = 0;
		cin >> select;
		system("cls");
		if (select == 1) {
			ShowAll(*contact);
		}
		else if (select == 2) {
			Human* item = GetNewHuman();
			AddNewHuman(*contact, *item);
		}
		else if (select == 3) {
			cout << "Enter NO : " << endl;
			int NO = 0;
			cin >> NO;
			int index = NO - 1;
			if (index >= 0 && index < contact->count) {
				DeleteContact(*contact, index);
				ShowAll(*contact);
			}
			else {
				cout << "NO is not defined" << endl;
			}
		}
		else if (select == 4) {
			cin.ignore();
			cin.clear();
			cout << "Enter name : " << endl;
			char* name = new char[20] {};
			cin.getline(name, 20);
			SearchContact(*contact, name);
		}
		else if (select == 5) {
			SortAZ(*contact);
			system("cls");
			ShowAll(*contact);
		}
		else if (select == 6) {
			SortAZ(*contact, true);
			system("cls");
			ShowAll(*contact);
		}
		else {
			cout << "err" << endl;
		}
	}

}