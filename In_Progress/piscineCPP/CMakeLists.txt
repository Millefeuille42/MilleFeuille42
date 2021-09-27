cmake_minimum_required(VERSION 3.17)
project(piscineCPP)

set(CMAKE_CXX_COMPILER /opt/homebrew/Cellar/llvm/12.0.0_1/bin/clang++)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -fsanitize=leak -g")

#add_executable(cpp00_ex00 cpp00/ex00 cpp00/ex00/megaphone.cpp)
#add_executable(cpp00_ex01 cpp00/ex01 cpp00/ex01/phoneBook.cpp cpp00/ex01/phoneBook.hpp cpp00/ex01/contact.cpp cpp00/ex01/contact.hpp)

#add_executable(cpp01_ex00 cpp01/ex00 cpp01/ex00/Pony.cpp cpp01/ex00/Pony.hpp cpp01/ex00/main.cpp)
#add_executable(cpp01_ex01 cpp01/ex01 cpp01/ex01/ex01.cpp)
#add_executable(cpp01_ex02 cpp01/ex02 cpp01/ex02/Zombie.cpp cpp01/ex02/Zombie.hpp cpp01/ex02/ZombieEvent.cpp cpp01/ex02/ZombieEvent.hpp cpp01/ex02/main.cpp)
#add_executable(cpp01_ex03 cpp01/ex03 cpp01/ex03/Zombie.cpp cpp01/ex03/Zombie.hpp cpp01/ex03/main.cpp cpp01/ex03/ZombieHorde.cpp cpp01/ex03/ZombieHorde.hpp)
#add_executable(cpp01_ex04 cpp01/ex04 cpp01/ex04/ex04.cpp)
#add_executable(cpp01_ex05 cpp01/ex05 cpp01/ex05/Brain.cpp cpp01/ex05/Brain.hpp cpp01/ex05/Human.cpp cpp01/ex05/Human.hpp cpp01/ex05/main.cpp)
#add_executable(cpp01_ex06 cpp01/ex06 cpp01/ex06/Weapon.cpp cpp01/ex06/Weapon.hpp cpp01/ex06/HumanA.cpp cpp01/ex06/HumanA.hpp cpp01/ex06/HumanB.cpp cpp01/ex06/HumanB.hpp cpp01/ex06/main.cpp)
#add_executable(cpp01_ex07 cpp01/ex07 cpp01/ex07/main.cpp)

#add_executable(cpp02_ex00 cpp02/ex00 cpp02/ex00/Fixed.cpp cpp02/ex00/Fixed.hpp cpp02/ex00/main.cpp)
#add_executable(cpp02_ex01 cpp02/ex01 cpp02/ex01/Fixed.cpp cpp02/ex01/Fixed.hpp cpp02/ex01/main.cpp)
#add_executable(cpp02_ex02 cpp02/ex02 cpp02/ex02/Fixed.cpp cpp02/ex02/Fixed.hpp cpp02/ex02/main.cpp)

#add_executable(cpp03_ex00 cpp03/ex00 cpp03/ex00/ClapTrap.cpp cpp03/ex00/ClapTrap.hpp cpp03/ex00/main.cpp)
#add_executable(cpp03_ex01 cpp03/ex01 cpp03/ex01/ClapTrap.cpp cpp03/ex01/ClapTrap.hpp cpp03/ex01/main.cpp cpp03/ex01/ScavTrap.cpp cpp03/ex01/ScavTrap.hpp)
#add_executable(cpp03_ex02 cpp03/ex02 cpp03/ex02/ClapTrap.cpp cpp03/ex02/ClapTrap.hpp cpp03/ex02/main.cpp cpp03/ex02/ScavTrap.cpp cpp03/ex02/ScavTrap.hpp cpp03/ex02/FragTrap.cpp cpp03/ex02/FragTrap.hpp)
#add_executable(cpp03_ex03 cpp03/ex03 cpp03/ex03/ClapTrap.cpp cpp03/ex03/ClapTrap.hpp cpp03/ex03/main.cpp cpp03/ex03/ScavTrap.cpp cpp03/ex03/ScavTrap.hpp cpp03/ex03/FragTrap.cpp cpp03/ex03/FragTrap.hpp cpp03/ex03/DiamondTrap.cpp cpp03/ex03/DiamondTrap.hpp)

#add_executable(cpp04_ex00 cpp04/ex00 cpp04/ex00/Sorcerer.cpp cpp04/ex00/Sorcerer.hpp cpp04/ex00/Victim.cpp cpp04/ex00/Victim.hpp cpp04/ex00/Peon.cpp cpp04/ex00/Peon.hpp cpp04/ex00/Knight.cpp cpp04/ex00/Knight.hpp cpp04/ex00/main.cpp)
#add_executable(cpp04_ex01 cpp04/ex01 cpp04/ex01/AWeapon.cpp cpp04/ex01/AWeapon.hpp cpp04/ex01/PlasmaRifle.cpp cpp04/ex01/PlasmaRifle.hpp cpp04/ex01/PowerFist.cpp cpp04/ex01/PowerFist.hpp cpp04/ex01/Enemy.cpp cpp04/ex01/Enemy.hpp cpp04/ex01/SuperMutant.cpp cpp04/ex01/SuperMutant.hpp cpp04/ex01/RadScorpion.cpp cpp04/ex01/RadScorpion.hpp cpp04/ex01/Character.cpp cpp04/ex01/Character.hpp cpp04/ex01/main.cpp)
#add_executable(cpp04_ex02 cpp04/ex02 cpp04/ex02/Squad.cpp cpp04/ex02/Squad.hpp cpp04/ex02/ISquad.hpp cpp04/ex02/ISpaceMarine.hpp cpp04/ex02/TacticalMarine.cpp cpp04/ex02/TacticalMarine.hpp cpp04/ex02/AssaultTerminator.cpp cpp04/ex02/AssaultTerminator.hpp cpp04/ex02/main.cpp)
#add_executable(cpp04_ex03 cpp04/ex03 cpp04/ex03/AMateria.cpp cpp04/ex03/AMateria.hpp cpp04/ex03/ICharacter.hpp cpp04/ex03/Ice.cpp cpp04/ex03/Ice.hpp cpp04/ex03/Cure.cpp cpp04/ex03/Cure.hpp cpp04/ex03/Character.cpp cpp04/ex03/Character.hpp cpp04/ex03/IMateriaSource.hpp cpp04/ex03/MateriaSource.cpp cpp04/ex03/MateriaSource.hpp cpp04/ex03/main.cpp)

#add_executable(cpp05_ex00 cpp05/ex00 cpp05/ex00/Bureaucrat.cpp cpp05/ex00/Bureaucrat.hpp cpp05/ex00/main.cpp)
#add_executable(cpp05_ex01 cpp05/ex01 cpp05/ex01/Bureaucrat.cpp cpp05/ex01/Bureaucrat.hpp cpp05/ex01/main.cpp cpp05/ex01/Form.cpp cpp05/ex01/Form.hpp)
#add_executable(cpp05_ex02 cpp05/ex02 cpp05/ex02/Bureaucrat.cpp cpp05/ex02/Bureaucrat.hpp cpp05/ex02/main.cpp cpp05/ex02/Form.cpp cpp05/ex02/Form.hpp cpp05/ex02/ShrubberyCreationForm.cpp cpp05/ex02/ShrubberyCreationForm.hpp cpp05/ex02/RobotomyRequestForm.cpp cpp05/ex02/RobotomyRequestForm.hpp cpp05/ex02/PresidentialPardonForm.cpp cpp05/ex02/PresidentialPardonForm.hpp)
add_executable(cpp05_ex03 cpp05/ex03 cpp05/ex03/Bureaucrat.cpp cpp05/ex03/Bureaucrat.hpp cpp05/ex03/main.cpp cpp05/ex03/Form.cpp cpp05/ex03/Form.hpp cpp05/ex03/ShrubberyCreationForm.cpp cpp05/ex03/ShrubberyCreationForm.hpp cpp05/ex03/RobotomyRequestForm.cpp cpp05/ex03/RobotomyRequestForm.hpp cpp05/ex03/PresidentialPardonForm.cpp cpp05/ex03/PresidentialPardonForm.hpp cpp05/ex03/Intern.cpp cpp05/ex03/Intern.hpp)