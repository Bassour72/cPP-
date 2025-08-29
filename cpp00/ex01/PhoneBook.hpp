#pragma once
# ifndef	__PHONEBOOK_HPP__
# define    __PHONEBOOK_HPP__
# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include <limits>

class PhoneBook 
{
private:
		static int _maxPhoneBookContact;
		Contact contacts[10];

public:
		PhoneBook();
		int			getContactCount() const;
		int			createPhoneBookProfile(Contact contacts, int pos);
		int			read_ini(std::string display = "");
		std::string	readUserEnter(std::string display = "");
		std::string	formatField(const std::string &field);
		void		setMaxContacts(int maxPhoneBookContact);
		void		displayContactList(int pos);
		void		displayPhonebookMenu(void);
		void		displayContactByIndex(int pos, int totalContacts);
		
		~PhoneBook();
};
#endif
