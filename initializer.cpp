#include "handler.h"


Handler init_pop(const int& pop_density, const int& inf_people, const float& step_rat, const float& infec_radius)
{
	std::list<Person> population(pop_density);
	std::list<Person> inf_population;
	std::vector<Person> immune_population;
	immune_population.reserve((int)(pop_density*0.5));
	std::list<Person>::iterator pop_it = population.begin();

	float inf_perc = (float)inf_people/(float)pop_density;

	// std::cout<<"Intializer starting..\n";

	for(int i = 0; i < inf_people && pop_it != population.end();)
	{
		if(getRand() < inf_perc)
		{
			pop_it->change_inf(0);
			i++;
			inf_population.push_back(*pop_it);
			pop_it = population.erase(pop_it);
			continue;
		}
		pop_it++;
	}
	inf_population.sort(compare_incubation);
	Handler master = Handler(population, inf_population, immune_population, step_rat, infec_radius);
	return master;
}
