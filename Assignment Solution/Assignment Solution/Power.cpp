#include "Power.h"

Power::Power() : GameObject()
{
	tag = "Power";
	AddComponent<PowerScript>();
}


