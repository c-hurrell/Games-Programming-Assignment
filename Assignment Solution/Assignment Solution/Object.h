#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>
#include "Behaviour.h"
using namespace std;

class GameObject
{
	string tag;
	vector<Behaviour> behaviours;
};

#endif

