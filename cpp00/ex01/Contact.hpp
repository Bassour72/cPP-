#include <iostream>
#include <string>
#pragma once
#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__
class Contact
{
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
    bool _exists;
public:
    Contact(/* args */);
    /// setters
    void setFirstName(std::string FirstName);
    void setLastName(std::string LastName);
    void setNickName(std::string NickName);
    void setPhoneNumber(std::string PhoneNumber);
    void setDarkestSecret(std::string DarkestSecret);
    /// getters
   std::string getFirstName(void);
   std::string getLastName(void);
   std::string getNickName(void);
   std::string getPhoneNumber(void);
   std::string getDarkestSecret(void);
   //// 
    bool isValidName(const std::string &name);
    bool isValidDarkestSecret(const std::string &name);
    bool isPhoneNumber(const std::string &name);
  
    //
    int read_ini(std::string display = "");
    std::string readUserEnter(std::string display = "");
    int addFirstName(void);
    int addLastName(void);
    int addPhoneNumber(void);
    int addNickName(void);
    int addDarkestSecret(void);
    Contact &addCo(void); 
    bool exists() const;
    void setExists(bool val);
    void markAsExists();
    ~Contact();
};
#endif