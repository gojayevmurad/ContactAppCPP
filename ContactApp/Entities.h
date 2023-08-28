#pragma once

struct Human {
	char* name;
	char* phone;
	const char* createdDate;
};

struct Contact{
	Human** humans;
	int count = 0;
};