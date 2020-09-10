#include<chrono>
#include<iostream>

class TimeMe
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;
public:
	TimeMe()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~TimeMe()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end-start;
		std::cout<<"\nTotal run time : "<<duration.count()<<std::endl;
	}
};
