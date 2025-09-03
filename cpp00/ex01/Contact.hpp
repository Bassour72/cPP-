#include <iostream>
#include <string>
#pragma once
#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__
class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	bool _exists;
public:
	Contact(/* args */);
	/// setters
	void		setFirstName(std::string FirstName);
	void		setLastName(std::string LastName);
	void		setNickName(std::string NickName);
	void		setPhoneNumber(std::string PhoneNumber);
	void		setDarkestSecret(std::string DarkestSecret);
	/// getters
   std::string	getFirstName(void);
   std::string	getLastName(void);
   std::string	getNickName(void);
   std::string	getPhoneNumber(void);
   std::string	getDarkestSecret(void);
   //// 
	bool		isValidName(const std::string &name);
	bool		isValidDarkestSecret(const std::string &name);
	bool		isPhoneNumber(const std::string &name);
  
	//
	int			addFirstName(void);
	int			addLastName(void);
	int			addPhoneNumber(void);
	int			addNickName(void);
	int			addDarkestSecret(void);
	bool		addCo(void); 
	bool		exists() const;
	void		setExists(bool val);
	void		markAsExists();
	~Contact();
};
std::string		readUserEnter(std::string display = "");
#endif