#include "Zombie.hpp"

int main()
{
	Zombie *heapZom;

	randomChump("stackZombie");
	heapZom = newZombie("heapZombie");
	heapZom->announce();
	delete heapZom;
	return(0);
}
/*
int main()
{
	Zombie *heapZom;

	randomChump("stackZombie");
	std::cin.get();
	heapZom = newZombie("heapZombie");
	heapZom->announce();
	std::cin.get();
	delete heapZom;
	return(0);
}
*/
