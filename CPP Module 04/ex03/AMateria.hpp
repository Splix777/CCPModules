#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string const	_type;

		AMateria &operator=(AMateria const &);
	public:
		AMateria();
		AMateria(std::string const & type);

		virtual ~AMateria();

		AMateria(AMateria const &copy);

		virtual std::string const &getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif