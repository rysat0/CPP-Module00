#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->_name << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
	if(this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap " << this->_name << " copy assignment operator called" << std::endl;
	return(*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't move due to low Hit Points." << std::endl;
		return;
	}
	else if(this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't move due to low Energy Points." << std::endl;
		return;
	}
	else
	{
		(this->_energyPoints)--;
		std::cout << "ScavTrap " << this->_name << " attacks "
				<< target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	return;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode" << std::endl;
}
