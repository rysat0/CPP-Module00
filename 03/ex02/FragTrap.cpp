#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
	if(this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << this->_name << " copy assignment operator called" << std::endl;
	return(*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if(this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't move due to low Hit Points." << std::endl;
		return;
	}
	else if(this->_energyPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't move due to low Energy Points." << std::endl;
		return;
	}
	else
	{
		(this->_energyPoints)--;
		std::cout << "FragTrap " << this->_name << " attacks "
				<< target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	return;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a high five! Hey guys, can I get a high five?" << std::endl;
}
