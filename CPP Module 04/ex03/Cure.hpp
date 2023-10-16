#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		Cure & operator=(Cure const &);
		Cure(Cure const &);
		
	public:
		Cure();
		~Cure();

		Cure *clone() const;

		void use(ICharacter &target);
};

#endif