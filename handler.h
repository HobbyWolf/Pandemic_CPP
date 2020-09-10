#include "population.h"
#include<list>
#include<vector>

class Handler
{
	std::list<Person> normal, infected;
	std::vector<Person> immune;
	std::list<Person>::iterator norm_it, infec_it;
	std::vector<Person>::iterator immune_it;
	static float step_rat;
	static float infec_radius;
	static int day_count;

	void update_position();
	void dissect(std::list<Person>::iterator&);
	void immune_check();
	void proximity_check();
public:
	static int infec_count;

	Handler(std::list<Person>&, std::list<Person>&, std::vector<Person>&, const float&, const float&);
	Handler() = delete;
	void infection();


};
