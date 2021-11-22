#pragma once
#include <vector>

struct Vars
{

	bool moon = false;
	bool sprint = false;
	bool punch = false;
	bool camshake = false;
	bool airjump = false;
	
	int current_menu = 0;
};
extern Vars cVars;