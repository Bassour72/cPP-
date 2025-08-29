 #include "Contact.hpp"
 #include "Contact.hpp"
#include "Contact.hpp"
Contact::Contact(/* args */)
{
    this->markAsExists();
}

void Contact::setFirstName(std::string FirstName)
{
    this->_first_name = FirstName;
}
void Contact::setLastName(std::string LastName)
{
    this->_last_name = LastName;
}
void Contact::setNickName(std::string NickName)
{
    this->_nickname = NickName;
}
void Contact::setPhoneNumber(std::string PhoneNumber)
{
    this->_phone_number = PhoneNumber;
}

void Contact::setDarkestSecret(std::string DarkestSecret)
{
    this->_darkest_secret = DarkestSecret;
}
    /// getters
std::string Contact::getFirstName(void)
{
    return (this->_first_name);
}
std::string Contact::getLastName(void)
{
    return (this->_last_name);
}
std::string Contact::getNickName(void)
{
    return (this->_nickname);
}
std::string Contact::getPhoneNumber(void)
{
    return (this->_phone_number);
}
std::string Contact::getDarkestSecret(void)
{
    return (this->_darkest_secret);
}

bool Contact::isValidName(const std::string &name)
{
    if (name.empty())
        return false;
    for (size_t i = 0; i < name.length(); i++)
    {
        if (!std::isalpha((char)(name[i])))
            return false;
    }
    
    return (true);
}

bool Contact::isValidDarkestSecret(const std::string &name)
{
    if (name.empty())
        return false;
    for (size_t i = 0; i < name.length(); i++)
    {
        if (!std::isdigit((char)(name[i])))
            return false;
    }
    
    return (true);
}
bool Contact::isPhoneNumber(const std::string &name)
{
    size_t i = 0;
    if (name.empty())
        return false;
    for (i = 0; i < name.length(); i++)
    {
        if (!std::isdigit((char)(name[i])))
            return false;
    }
    
    return (true);
}

std::string Contact::readUserEnter(std::string display)
{
    std::string input;
    std::cout << display << std::endl;
    std::getline(std::cin, input);
    
    return (input);
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
    };
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

Contact Contact::addCo(void) 
{
    Contact contact;
    contact.addFirstName();
    contact.addLastName();
    contact.addPhoneNumber();
    contact.addNickName();
    contact.addDarkestSecret();
    return (contact);
}

Contact::~Contact()
{
}