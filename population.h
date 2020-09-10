#include "randomizer.h"
#include<list>
#include <fstream>

class Person
{
	float x, y, ang;
	int day_infection;
	int incubation;
	bool inf, sym;
	dist_incr xy;

	void check_xy(const float&);
	void write_peep();
public:

	Person();
	friend bool check_dist(const Person&, const Person&, const float&);
	friend bool compare_incubation(const Person&, const Person&);
	void change_inf(const int&);
	void change_sym();
	void move(const float&);
	void print_everything();
	std::list<Person>::iterator find_insert_it(std::list<Person>& );
	bool expire_check(const int&);
};

bool check_dist(const Person&, const Person&, const float&);

bool compare_incubation(const Person&, const Person&);
