#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
    MaxPhoneBookContact = 0;
}

PhoneBook::~PhoneBook() {}
std::string PhoneBook::ReadUserEnter(std::string display)
{
    std::string input;
    std::cout << display << std::endl;
    std::getline(std::cin, input);
    
    return input;
}
void PhoneBook::displayPhonebookMenu(void) 
{
    std::cout << "========================================" << std::endl;
    std::cout << "   📖  PHONEBOOK MANAGER                " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " 🔹 [ADD]    ➝ Add a new contact        " << std::endl;
    std::cout << " 🔹 [SEARCH] ➝ Search existing contacts " << std::endl;
    std::cout << " 🔹 [EXIT]   ➝ Exit program             " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << " 👉 Enter your command: ";
}

int PhoneBook::CreatePhoneBookProfile(Contact contacts, int pos) 
{
   if (pos > 8)
        return (0);
    if (!contacts.Exists())
        return (0);
    else
    {
        this->contacts[pos] = contacts;
        return (1);
    }
}


 int PhoneBook::Read_ini(std::string display)
 {
    int input;
    std::cout << display << std::endl;
    std::cin >> input;
    while (std::cin.fail())
    {
        if (std::cin.eof()) 
        {
            std::cin.clear();                 // clear EOF state
            std::cin.ignore(100000, '\n');
                // // flush input buffer
                // std::cin.putback('0');
            continue;                  // reprompt
        }
        else if (std::cin.fail())
        {
            std::cout << "Invalid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << display << std::endl;
            std::cin >> input;
         }
    }
    return input;
 }

std::string PhoneBook::FormatField(const std::string &field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return std::string(10 - field.length(), ' ') + field;
}
void PhoneBook::DisplayContactByIndex(int pos, int totalContacts)
{
    if (pos == 0 || pos >  totalContacts)
    {
        std::cout << "No contacts yet" << std::endl;
        return ;
    }
    std::cout << "------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Phone number |  Nickname| Darkest Secret|" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < pos; i++)
    {
        std::cout << "|" << std::setw(10) << i + 1
                  << "|" << FormatField(contacts[i].GetFirstName())
                  << "|" << FormatField(contacts[i].GetLastName())
                  << "|" << FormatField(contacts[i].GetPhoneNumber())
                  << "|" << FormatField(contacts[i].GetNickName())
                  << "|" << FormatField(contacts[i].GetDarkestSecret())
                  << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}
void PhoneBook::DisplayContactList(int pos)
{
    if (pos == 0)
    {
        std::cout << "No contacts yet" << std::endl;
        return;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < pos; i++)
    {
        std::cout << "|" << std::setw(10) << i + 1
                  << "|" << FormatField(contacts[i].GetFirstName())
                  << "|" << FormatField(contacts[i].GetLastName())
                  << "|" << FormatField(contacts[i].GetNickName())
                  << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

