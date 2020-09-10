#include "initializer.cpp"
#include "timeme.cpp"
#include <sys/stat.h>
#include<cstdio>

inline bool exists_test3 (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int main()
{
	TimeMe k;
	int pop_density = 1000;
	int inf_people = (int)pop_density*0.1;
	float step_rat = 0.01;
	float infec_radius = 0.0015;
	int nof_days = 100;

	std::ofstream myfile;
	if(exists_test3("Data.txt"))
		std::remove("Data.txt");
	Handler master_population = init_pop(pop_density, inf_people, step_rat, infec_radius);
	for (int i =0; i<nof_days;i++)
	{
		myfile.open("Data.txt", std::ios::out|std::ios::app);
		myfile<<"Day : "<<i<<std::endl;
		myfile.close();
		std::cout<<"Day: "<<i<<", Infection :"<<Handler::infec_count<<std::endl;
		master_population.infection();
	}


	return 1;
}
