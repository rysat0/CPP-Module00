#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap("CL4P-TP");
	ScavTrap scav("SC4V-TP");
	FragTrap frag("FR4G-TP");
	clap.attack("a target");
	scav.attack("a target");
	frag.attack("a target");

	scav.guardGate();
	frag.highFivesGuys();

	FragTrap scoped("scoped");

	frag.takeDamage(30);
	frag.beRepaired(10);

	FragTrap copied(frag);
	FragTrap assigned;
	assigned = copied;
	assigned.attack("a target");


	frag.takeDamage(200);
	frag.attack("a target");
	frag.beRepaired(10);
	frag.highFivesGuys();

	FragTrap healer("healer");
	healer.beRepaired(4294967295u);

	return 0;
}
