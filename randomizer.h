#include<iostream>
#include<cmath>

float getRand(int low = 0, int high = 1);

float get_dist(const float&);

float get_angle(int ang_l = 0, int ang_u = 360);

class dist_incr
{
public:
	float dx, dy;
	dist_incr(){}
	dist_incr(const float&, const float& );
};

dist_incr get_xy(const float&, const float&);
