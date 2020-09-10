#include "handler.h"
#include <exception>

int Handler::day_count = 0;
float Handler::step_rat = 0;
float Handler::infec_radius = 0;
int Handler::infec_count = 0;

Handler::Handler(std::list<Person>& normal, std::list<Person>&infected, std::vector<Person>& immune, const float& step_rat, const float& infec_radius):normal(normal), infected(infected), immune(immune)
{
	Handler::step_rat = step_rat;
	Handler::infec_radius = infec_radius;
}

void Handler::infection()
{

	this->update_position();
	// std::cout<<"Updated Position\n";
	this->immune_check();
	// std::cout<<"Check immunity\n";
	this->proximity_check();
	// std::cout<<"proximity_check\n";
}

void Handler::update_position()
{
	norm_it = normal.begin();
	infec_it = infected.begin();
	immune_it = immune.begin();

	for (;norm_it != normal.end(); norm_it++)
	norm_it->move(Handler::step_rat);

	for (;infec_it != infected.end(); infec_it++)
	infec_it->move(Handler::step_rat);

	for (;immune_it != immune.end();immune_it++)
	immune_it->move(Handler::step_rat);

	Handler::day_count++;
}

void Handler::immune_check()
{
	if (infected.size())
	if (infected.back().expire_check(Handler::day_count))
	{
		if (getRand() > 0.2)
		{
			infected.back().change_inf(0);
			immune.emplace_back(infected.back());
			infected.erase(--infected.end());
		}
	}
}


void Handler::proximity_check()
{
	norm_it = normal.begin();
	auto temp_infected = infected;
	infec_it = temp_infected.begin();
	for (;infec_it!=temp_infected.end();infec_it++)
		for (;norm_it!=normal.end();)
		{
			if(check_dist(*infec_it, *norm_it, Handler::infec_radius))
			{
				norm_it->change_inf(Handler::day_count);
				infected.push_back(*norm_it);
				norm_it = normal.erase(norm_it);
				continue;
				// dissect(norm_it);
			}
			norm_it++;
		}
	infected.sort(compare_incubation);
}

void Handler::dissect(std::list<Person>::iterator& it)
{

}
