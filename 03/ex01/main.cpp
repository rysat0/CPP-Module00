#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{

	ClapTrap clap("CL4P-TP");
	ScavTrap scav("SC4V-TP");
	clap.attack("a target");
	scav.attack("a target");


	ScavTrap scoped("scoped");
	scoped.guardGate();
	std::cout << "スコープを抜けました" << std::endl;

	scav.takeDamage(30);
	scav.beRepaired(10);

	ScavTrap copied(scav);
	ScavTrap assigned;
	assigned = copied;
	assigned.attack("a target");

	scav.takeDamage(200);
	scav.attack("a target");
	scav.beRepaired(10);
	scav.guardGate();

	ScavTrap healer("healer");
	healer.beRepaired(4294967295u);

	ScavTrap tired("tired");
	int i = 0;
	while(i < 51)
	{
		tired.attack("a target");
		i++;
	}

	return 0;
}
