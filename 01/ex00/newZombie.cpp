#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
	Zombie *zom;

	zom = new Zombie;
	zom->setName(name);
	return zom;
}
