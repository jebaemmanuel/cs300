#pragma once
#include <sstream>
#include <vector>
#include <deque>
#ifndef COURSE
#include "Course.h"
#endif // !COURSE

#include "BST.h"
#include <exception>
using namespace std;
class CSVParser
{
public:
	vector<deque<string>> lines;
	void read(string filename);
	void createCourses(BinarySearchTree *courses);
private:
	deque<string> splitLine(string line);
};

