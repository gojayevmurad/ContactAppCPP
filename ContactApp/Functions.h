#pragma once

#include <iostream>
#include "Entities.h"

using namespace std;

void ShowHuman(const Human& human) {
	cout << "==============================" << endl;
	cout << "Name : " << human.name << endl;
	cout << "Phone : " << human.phone << endl;
	cout << "Created Date : " << human.createdDate << endl;
}

void ShowAll(const Contact& contact) {
	for (size_t i = 0; i < contact.count; i++){
		cout << "NO : [" << i+1 << "]" << endl;
		ShowHuman(*contact.humans[i]);
	}
}

Human* GetNewHuman() {
	cin.ignore();
	cin.clear();

	cout << "Enter name : " << endl;
	char* name = new char[30] {};
	cin.getline(name, 30);

	cout << "Enter phone number : " << endl;
	char* phone = new char [30] {};
	cin.getline(phone, 30);

	Human* human = new Human{ name, phone , __DATE__ };

	return human;
}

void AddNewHuman(Contact& contact, const Human& human) {
	int count = contact.count;
	auto temp = new Human * [count + 1] {};
	for (size_t i = 0; i < count; i++){
		temp[i] = contact.humans[i];
	}
	temp[count] = new Human{ human };
	contact.humans = temp;
	contact.count++;
	temp = nullptr;
	cout << "New contact added succesfully " << endl;
}

void SortAZ(Contact& contact, bool reverse = false) {
	int data = 1;
	if (reverse) {
		data = -1;
	}

	for (size_t i = 0; i < contact.count-1; i++){
		for (size_t k = 0; k < contact.count-i-1; k++){

			if (strcmp(contact.humans[k]->name, contact.humans[k + 1]->name) == data) {
				auto temp = contact.humans[k];
				contact.humans[k] = contact.humans[k + 1];
				contact.humans[k + 1] = temp;
			}

		}
	}

}

void DeleteContact(Contact& contact, int index) {
	int count = contact.count;
	auto temp = new Human * [count - 1] {};

	for (size_t i = 0,k=0; i < count; i++,k++){
		if (i != index) {
			temp[k] = contact.humans[i];
		}
		else {
			k--;
		}
	}
	contact.humans = temp;
	contact.count--;
	temp == nullptr;

	cout << "Contact deleted succeesfully" << endl;
}

void SearchContact(Contact& contact, char* name) {
	for (size_t i = 0; i < contact.count; i++){
		if (strstr(contact.humans[i]->name, name) != nullptr) {
			ShowHuman(*contact.humans[i]);
		}
	}
}