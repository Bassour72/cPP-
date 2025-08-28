#pragma once
#ifndef  __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__
#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include <unistd.h>

class PhoneBook 
{
private:
    int MaxPhoneBookContact;
    Contact contacts[10];

public:
    PhoneBook();
    ~PhoneBook();

    void displayPhonebookMenu(void);
   std::string ReadUserEnter(std::string display = "");
    int CreatePhoneBookProfile(Contact contacts, int pos);
    int Read_ini(std::string display = "");
    void DisplayContactList(int pos);
   std::string FormatField(const std::string &field);
   void DisplayContactByIndex(int pos, int totalContacts);
};

#endif

/*
Accessors (getters) → Usually start with get (getContactCount()).

Mutators (setters) → Usually start with set (setMaxContacts()
*/