#include <string>
#include <deque>
#define COURSE
using namespace std;


class Course {
public:
	string id;
	string name;
	deque<string> prereqs;
	Course(deque<string> line);
	Course();
	bool is_empty();
	void print();
};