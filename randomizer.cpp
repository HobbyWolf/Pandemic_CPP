#include<cstdlib>
#include "randomizer.h"

dist_incr::dist_incr(const float& angle, const float& step_rat):dx(get_dist(step_rat)*std::cos(angle)), dy(get_dist(step_rat)*std::sin(angle)){}

float getRand(int low, int high)
{
	float randNum = (std::rand()%((high - low)*1000) + low)/1000.0;
	return randNum;
}

float get_dist(const float& step_rat)
{
	return getRand()*step_rat;
}

float get_angle(int ang_l, int ang_u)
{
    return getRand(ang_l, ang_u);
}


dist_incr get_xy(const float& angle, const float& step_rat)
{
	dist_incr A(angle, step_rat);
	return A;
}
