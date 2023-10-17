#include "CSVParser.h"
#include <fstream>
#include <iostream>

/** 
* Open a file and read into multidimensional vector
* 
* @param filename String with name of input file in csv format
**/
void CSVParser::read(string filename) {
	string line;
		
	ifstream ifile(filename.c_str());
	if (ifile.is_open()) {
		while (ifile.good()) {
			getline(ifile, line);
			cout << line << endl;
			if (line != "")
				lines.push_back(splitLine(line));
		}
		ifile.close();
	}
	else {
		throw("Unable to open file");
	}
}

/**
* Create Courses and add to binary search tree
*
* @param courses BST Binary Search tree that will maintain courses in sorted order
**/
void CSVParser::createCourses(BinarySearchTree *courses)
{
	if (lines.size() == 0) {
		throw("CSV File not read  yet"); // better approach would be to just read the file here but we don't have filename
	}
		
	for (deque<string> line: lines)
	{
		try { // try catch block to handle invalid courses
			Course course = Course(line);
			courses->Insert(course);
		}
		catch(exception e) {
			cout << "Invalid Course" << e.what() << endl;
		}
			
	}
}

/**
* Split a CSV line to into separate strings
*
* @param line String with entire line
**/
deque<string> CSVParser::splitLine(string line) {
	size_t start = 0;
	size_t end = line.size();
	string substr;
	deque<string> result;

	// loop finding commas and extracting substring till commas
	while ((end = line.find(",", start)) != string::npos) {
		substr = line.substr(start, end - start);
		start = end + 1;
		result.push_back(substr);
	}
	result.push_back(line.substr(start)); // extract final substring
	if (result.size() < 2) {
		throw("Course has insufficient values"); 
	}
	return result;
}

