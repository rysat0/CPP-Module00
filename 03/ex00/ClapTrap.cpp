#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap()
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << this->_name << " copy assignment operator called" << std::endl;
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move due to low Hit Points." << std::endl;
		return;
	}
	else if(this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move due to low Energy Points." << std::endl;
		return;
	}
	else
	{
		(this->_energyPoints)--;
		std::cout << "ClapTrap " << this->_name << " attacks "
				<< target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " is attacked, " << amount << " points decreased" << std::endl;
	if(amount > this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << "'s Hit Points is now at 0" << std::endl;
	}
	else
	{
		this->_hitPoints = this->_hitPoints - amount;
		std::cout << "ClapTrap " << this->_name << "'s Hit Points is now at " << this->_hitPoints << std::endl;
	}
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move due to low Hit Points." << std::endl;
		return;
	}
	else if(this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move due to low Energy Points." << std::endl;
		return;
	}
	else
	{
		(this->_energyPoints)--;
		if(amount > UINT_MAX - this->_hitPoints)
		{
			this->_hitPoints = UINT_MAX;
			std::cout << "ClapTrap " << this->_name << "'s HP is capped, now at " << this->_hitPoints << std::endl;
		}
		else
		{
			this->_hitPoints = this->_hitPoints + amount;
			std::cout << "ClapTrap " << this->_name << "'s HP heals, now at " << this->_hitPoints << std::endl;
		}
	}
}
