#include<string>
#include "handler.h"
#include <sys/stat.h>
#include<cstdio>


Person::Person():x(getRand()), y(getRand()), ang(get_angle()), day_infection(0), incubation(0), inf(0), sym(0){}

void Person::change_inf(const int& day_count)
{
	if (inf == 0)
	{
		inf = 1;

		Handler::infec_count++;

		day_infection = day_count;
		if (getRand() > 0.5)
		{
			this->change_sym();
			incubation = int(getRand()*30);
		}

	}
	else
	{
		inf = 0;
		this->change_sym();
	}
}

void Person::change_sym(){if (sym == 0) sym = 1; else sym = 0;}

void Person::move(const float& step_rat)
{
	int flag = 0;
	do {
		ang = flag++ != 0 ? get_angle() : ang;
		// std::cout<<"Flag is :"<<flag<<std::endl;
		xy = get_xy(ang, step_rat);
	} while(x+xy.dx > 1 || x+xy.dx < 0 || y+xy.dy > 1 || y+xy.dy < 0);
	x+=xy.dx;
	y+=xy.dy;
	this->write_peep();
}

void Person::check_xy(const float& step_rat)
{
	if (x < 0 || x > 1 || y < 0 || y > 1)
	{
		ang = get_angle();
		this->move(step_rat);
	}
}

void Person::write_peep()
{
	std::ofstream myfile;
	myfile.open("Data.txt", std::ios::out|std::ios::app);
	myfile << x <<"\t" << y <<"\t" << (int)inf - (int)sym/2.0<<"\n";
	myfile.close();
}


void Person::print_everything()
{
	std::cout<<x<<"/"<<y<<"/"<<ang<<"/"<<inf<<"/"<<sym<<std::endl;
}

bool Person::expire_check(const int& day)
{
	if (day - day_infection == incubation)
	return 1;
	else
	return 0;
}

std::list<Person>::iterator Person::find_insert_it(std::list<Person>& infected)
{
	auto begin = infected.begin();
	// auto end = --infected.end();
	return begin;
}

bool check_dist(const Person& a, const Person& b, const float& infec_radius)
{
	float dist = std::sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
	if (dist < infec_radius)
		return 1;
	else
		return 0;
}

bool compare_incubation(const Person& a, const Person& b)
{
	if((a.incubation + a.day_infection) > (b.incubation + b.day_infection))
		return 1;
	else
		return 0;
}
