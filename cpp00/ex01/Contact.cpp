 
 #include "Contact.hpp"

 Contact::Contact(/* args */)
{
    this->markAsExists();
}

void Contact::SetFirstName(std::string FirstName)
{
    this->first_name = FirstName;
}
void Contact::SetLastName(std::string LastName)
{
    this->last_name = LastName;
}
void Contact::SetNickName(std::string NickName)
{
    this->nickname = NickName;
}
void Contact::SetPhoneNumber(std::string PhoneNumber)
{
    this->phone_number = PhoneNumber;
}

void Contact::SetDarkestSecret(std::string DarkestSecret)
{
    this->darkest_secret = DarkestSecret;
}
    /// getters
std::string Contact::GetFirstName(void)
{
    return (this->first_name);
}
std::string Contact::GetLastName(void)
{
    return (this->last_name);
}
std::string Contact::GetNickName(void)
{
    return (this->nickname);
}
std::string Contact::GetPhoneNumber(void)
{
    return (this->phone_number);
}
std::string Contact::GetDarkestSecret(void)
{
    return (this->darkest_secret);
}

bool Contact::IsValidName(const std::string &name)
{
    if (name.empty())
        return false;
    for (size_t i = 0; i < name.length(); i++)
    {
        if (!std::isalpha((char)(name[i])))
            return false;
    }
    
    return true;
}

bool Contact::IsValidDarkestSecret(const std::string &name)
{
    if (name.empty())
        return false;
    for (size_t i = 0; i < name.length(); i++)
    {
        if (!std::isdigit((char)(name[i])))
            return false;
    }
    
    return true;
}
bool Contact::IsPhoneNumber(const std::string &name)
{
    size_t i = 0;
    if (name.empty())
        return false;
    if(name[i] == '+')
        i++;
    for (i = 0; i < name.length(); i++)
    {
        if (!std::isdigit((char)(name[i])))
            return false;
    }
    
    return true;
}

std::string Contact::ReadUserEnter(std::string display)
{
    std::string input;
    std::cout << display << std::endl;
    std::getline(std::cin, input);
    
    return input;
}

int Contact::AddFirstName(void) 
{
    std::string input = ReadUserEnter("Enter the first name: ");
    if (!this->IsValidName(input))
    {
        this->SetExists(false);
        return (0);
    }
    this->SetFirstName(input);
    return (1);
}

int Contact::AddLastName(void) 
{
    std::string input = ReadUserEnter("Enter the last name: ");
    if (!this->IsValidName(input))
    {
        this->SetExists(false);
        return (0);
    }
    this->SetLastName(input);
    return (1);
}

int Contact::AddPhoneNumber(void) 
{
    std::string input = ReadUserEnter("Enter the phone number: ");
    if (!this->IsPhoneNumber(input))
    {
        this->SetExists(false);
        return (0);
    }
    this->SetPhoneNumber(input);
    return (1);
}

int Contact::AddNickName(void) 
{
    std::string input = ReadUserEnter("Enter the nickname: ");
    if (!this->IsValidName(input))
    {
        this->SetExists(false);
        return (0);
    };
    this->SetNickName(input);
    return (1);
}

int Contact::AddDarkestSecret(void) 
{
    std::string input = ReadUserEnter("Enter the darkest secret: ");
    if (!this->IsValidDarkestSecret(input))
    {
        this->SetExists(false);
        return (0);
    }
    this->SetDarkestSecret(input);
    return (1);
}

bool Contact::Exists() const 
{
    return this->exists;
}

void Contact::SetExists(bool val) 
{
    this->exists = val;
}

void Contact::markAsExists() 
{
    this->exists = true;
}

void Contact::clear()
{
    this->exists = false;
}


Contact Contact::AddCo(void) 
{
    Contact contact;
    contact.AddFirstName();
    contact.AddLastName();
    contact.AddPhoneNumber();
    contact.AddNickName();
    contact.AddDarkestSecret();
    return (contact);
}

Contact::~Contact()
{
}