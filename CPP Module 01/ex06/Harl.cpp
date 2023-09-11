#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Harl has been activated!" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Harl has been deactivated!" << std::endl;
}

void    Harl::debug(void) { std::cout << DEBUG << std::endl; }

void    Harl::info(void) { std::cout << INFO << std::endl; }

void    Harl::warning(void) { std::cout << WARNING << std::endl; }

void    Harl::error(void) { std::cout << ERROR << std::endl; }

void    Harl::complain(std::string level)
{        
	void		(Harl::*ptr_complain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         i;

    i = 0;

	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*ptr_complain[i])();
			break ;
		}
        i++;
	}
	if (i == 4)
    	std::cout << "Invalid complaint level!" << std::endl;
}