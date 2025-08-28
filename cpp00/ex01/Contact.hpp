#include <iostream>
#include <string>
#pragma once
class Contact
{
private:
    std::string first_name;
    std::string  last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    bool exists;
public:
    Contact(/* args */);
    /// setters
    void SetFirstName(std::string FirstName);
    void SetLastName(std::string LastName);
    void SetNickName(std::string NickName);
    void SetPhoneNumber(std::string PhoneNumber);
    void SetDarkestSecret(std::string DarkestSecret);
    /// getters
   std::string GetFirstName(void);
   std::string GetLastName(void);
   std::string GetNickName(void);
   std::string GetPhoneNumber(void);
   std::string GetDarkestSecret(void);
   //// 
    bool IsValidName(const std::string &name);
    bool IsValidDarkestSecret(const std::string &name);
    bool IsPhoneNumber(const std::string &name);
  
    //
    int Read_ini(std::string display = "");
     std::string ReadUserEnter(std::string display = "");
    int AddFirstName(void);
    int AddLastName(void);
    int AddPhoneNumber(void);
    int AddNickName(void);
    int AddDarkestSecret(void);
    static Contact AddCo(void); 
    bool Exists() const;
    void SetExists(bool val);
    void markAsExists();
    void clear(); 
    ~Contact();
};
