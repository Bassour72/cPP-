#include "Contact.hpp"

Contact::Contact(/* args */)
{
    markAsExists();
}

void Contact::setFirstName(std::string FirstName)
{
    this->_firstName = FirstName;
}
void Contact::setLastName(std::string LastName)
{
    this->_lastName = LastName;
}
void Contact::setNickName(std::string NickName)
{
    this->_nickName = NickName;
}
void Contact::setPhoneNumber(std::string PhoneNumber)
{
    this->_phoneNumber = PhoneNumber;
}

void Contact::setDarkestSecret(std::string DarkestSecret)
{
    this->_darkestSecret = DarkestSecret;
}
    /// getters
std::string Contact::getFirstName(void)
{
    return (this->_firstName);
}
std::string Contact::getLastName(void)
{
    return (this->_lastName);
}
std::string Contact::getNickName(void)
{
    return (this->_nickName);
}
std::string Contact::getPhoneNumber(void)
{
    return (this->_phoneNumber);
}
std::string Contact::getDarkestSecret(void)
{
    return (this->_darkestSecret);
}

bool Contact::isValidName(const std::string &name)
{
      int count_alph = 0;
    if (name.empty())
        return (false);
    for (size_t i = 0; i < name.length(); i++)
    {
        if (!std::isalpha((char)(name[i])) && !std::isspace((char)(name[i])))
            return (false);
        if (std::isalpha((char)(name[i])))
            count_alph++;
    }
    if (count_alph == 0)
        return (false);
    return (true);
}

bool Contact::isValidDarkestSecret(const std::string &secret)
{
    int count_alph = 0;
    if (secret.empty())
        return (false);
    for (size_t i = 0; i < secret.length(); i++)
    {
        if (!std::isalpha((char)(secret[i])) && !std::isspace((char)(secret[i])) && !std::isdigit((char)(secret[i])))
            return (false);
        if (std::isalpha((char)(secret[i])))
            count_alph++;
    }
    if (count_alph == 0)
        return (false);
    return (true);
}

bool Contact::isPhoneNumber(const std::string &name)
{
    size_t i = 0;
    if (name.empty())
        return false;
    if (name[i] == '+')
        i++;
    for (; i < name.length(); i++)
    {
        if (!std::isdigit((char)(name[i])))
            return false;
    }
    return (true);
}

int Contact::addFirstName(void) 
{
  
    std::string input = readUserEnter("Enter the first name: ");
    if (!this->isValidName(input))
    {
        this->setExists(false);
        return (0);
    }
    this->setFirstName(input);
    return (1);
}

int Contact::addLastName(void) 
{
    std::string input = readUserEnter("Enter the last name: ");
    if (!this->isValidName(input))
    {
        this->setExists(false);
        return (0);
    }
    this->setLastName(input);
    return (1);
}

int Contact::addPhoneNumber(void) 
{
    std::string input = readUserEnter("Enter the phone number: ");
    if (!this->isPhoneNumber(input))
    {
        this->setExists(false);
        return (0);
    }
    this->setPhoneNumber(input);
    return (1);
}

int Contact::addNickName(void) 
{
    std::string input = readUserEnter("Enter the nickname: ");
    if (!this->isValidName(input))
    {
        this->setExists(false);
        return (0);
    }
    this->setNickName(input);
    return (1);
}

int Contact::addDarkestSecret(void) 
{
    std::string input = readUserEnter("Enter the darkest secret: ");
    if (!this->isValidDarkestSecret(input))
    {
        this->setExists(false);
        return (0);
    }
    this->setDarkestSecret(input);
    return (1);
}

bool Contact::exists() const 
{
    return (this->_exists);
}

void Contact::setExists(bool val) 
{
    this->_exists = val;
}

void Contact::markAsExists() 
{
    this->_exists = true;
}
bool Contact::addCo(void)
{
    
    if (this->addFirstName()== 0)
        return false;
    if (this->addLastName() == 0)
        return false;
    if (this->addPhoneNumber()== 0)
        return false;
    if (this->addNickName()== 0)
        return false;
    if (this->addDarkestSecret() == 0)
        return false;
    return true;
}
std::string Contact::readUserEnter(std::string display)
{
    std::string input;
    std::cout << display << std::endl;
    std::getline(std::cin, input, '\n');
    if (std::cin.eof())
        return "";
    
    return input;
}
Contact::~Contact()
{
}