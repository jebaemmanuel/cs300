#include "Course.h"
#include <iostream>

/**
* Create a course
* 
* @param line Deque with course details parsed from file
**/
Course::Course(deque<string> line)
{
	// Fetch first two fields for id and name
	id = line.front();
	line.pop_front();
	name = line.front();
	line.pop_front();

	// Everything else goes into prereqs
	prereqs = line;
}

/**
* Create an empty course
**/
Course::Course()
{
	id = "0";
	name = "__UNKNOWN__";
}

/**
* Check if course is an empty/dummy course
**/
bool Course::is_empty()
{
	return (id == "0" && name == "__UNKNOWN__");
}

/**
* Print details of a course
**/
void Course::print()
{
	cout << "ID: " << id << " | Name: " << name << endl;
	cout << "Prereqs: " << endl;
	for (string prereq : prereqs) { // course can have multiple prereqs
		cout << prereq << endl;
	}
	cout << endl;
}
