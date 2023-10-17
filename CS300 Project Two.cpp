// CS300 Project Two.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CSVParser.h"
using namespace std;
int main()
{
	
	BinarySearchTree *courses = new BinarySearchTree();
	Course course;
	CSVParser parser = CSVParser();

	string id; // for searching
	clock_t ticks; // for performance monitoring
	

	cout << "Welcome to Project Two" << endl;
	

	int choice = 0;
	while (choice != 9) {
		cout << endl << "Menu: " << endl;
		cout << "1. Load Data" << endl;
		cout << "2. Print Course List" << endl;
		cout << "3. Print Course" << endl;
		cout << "9. Exit" << endl;
		
		cin >> choice;

		switch (choice) {
		case 1:
			// Initialize a timer variable
			ticks = clock();
			
			parser.read("input.csv");
			parser.createCourses(courses);

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;
		case 2:
			// Initialize a timer variables
			ticks = clock();

			cout << "Here is a sample schedule" << endl;
			courses->InOrder();

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;
		case 3:
			cout << "What course do you want to know about? " << endl;
			cin >> id;

			// Initialize a timer variable before loading bids
			ticks = clock();

			course = courses->Search(id);
			if (!course.is_empty()) {
				cout << "Matched" << endl;
				course.print();
			}
			else {
				cout << "No Match" << endl;
			}

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;

		case 9: 
			break;

		default:
			cout << choice << " is not a valid option." << endl;
		}
	}

	cout << "Thank you for using code planner" << endl;


}
