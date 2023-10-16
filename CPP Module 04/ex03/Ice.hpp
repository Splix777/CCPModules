#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		Ice & operator=(Ice const &);
		Ice(Ice const &);

	public:
		Ice();
		~Ice();

		Ice *clone() const;

		void use(ICharacter &target);
};

#endif