#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "--- 1. constructor / attack ---" << std::endl;
	ClapTrap test1("alex");
	ClapTrap test2("bob");

	test1.attack("a wooden dummy");
	test1.attack("the air");
	test1.attack("the ground");

	std::cout << std::endl << "--- 2. energy points run out after 10 actions ---" << std::endl;
	int i = 0;
	while(i < 7)
	{
		test1.attack("fight!");
		i++;
	}
	test1.attack("the air");
	test1.beRepaired(10);

	std::cout << std::endl << "--- 3. no hit points left -> can't act ---" << std::endl;
	test2.takeDamage(150);
	test2.attack("the air");
	test2.beRepaired(10);

	std::cout << std::endl << "--- 4. beRepaired does not overflow (UINT_MAX) ---" << std::endl;
	ClapTrap test3("carol");
	test3.beRepaired(4294967295u);

	std::cout << std::endl << "--- 5. default constructor has a name ---" << std::endl;
	ClapTrap test4;
	test4.attack("a target");

	std::cout << std::endl << "--- 6. copy constructor / copy assignment ---" << std::endl;
	ClapTrap original("dave");
	original.attack("a target");
	ClapTrap copied(original);
	copied.attack("a target");
	ClapTrap assigned;
	assigned = copied;
	assigned.attack("a target");

	return 0;
}
