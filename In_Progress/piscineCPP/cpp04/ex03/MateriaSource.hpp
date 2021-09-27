//
// Created by Millefeuille on 01/07/2021.
//

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);

	~MateriaSource();

	void learnMateria(AMateria *materia);

	AMateria *createMateria(const std::string &type);

	MateriaSource & operator=(MateriaSource const & rhs);
private:
	AMateria **_materias;
	int	_materiasCount;
};


#endif //MATERIASOURCE_HPP
