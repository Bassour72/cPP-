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
		int		_maxPhoneBookContact;
		int		_indexPhoneBookContact;
		Contact	contacts[8];
public:
		PhoneBook();
		int			getContactCount() const;
		int			createPhoneBookProfile(int pos);
		std::string	formatField(const std::string &field);
		void		setMaxContacts(int maxPhoneBookContact);
		void		displayContactList(int pos);
		void		displayPhonebookMenu(void);
		void		displayContactByIndex(int pos, int totalContacts);
		int			getIndex(void);
		void		setIndex(int index);
		~PhoneBook();
};
#endif