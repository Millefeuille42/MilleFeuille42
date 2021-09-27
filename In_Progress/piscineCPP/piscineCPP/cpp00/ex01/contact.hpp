//
// Created by millefeuille on 3/22/21.
//

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

static const std::string fields[11] = {
		"First Name",
		"Last Name",
		"Nickname",
		"Login",
		"Postal Address",
		"Email Address",
		"Phone Number",
		"Birthday Date",
		"Favorite Meal",
		"Underwear Color",
		"Darkest Secret"
};

class Contact {
	private:
		int			index;
		std::string	dataFields[11];
	public:
		void	createContact(int contactNumber);
		void	displayContact() const ;
		void	displayContactSearch() const ;
};

#endif
