#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
    _maxPhoneBookContact = 0;
}

PhoneBook::~PhoneBook()
{

}
std::string PhoneBook::readUserEnter(std::string display)
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


int PhoneBook::createPhoneBookProfile(int pos) 
{
    int totalContact = getContactCount();

    pos = totalContact % 8;
    contacts[pos].addCo();

    if (!contacts[pos].exists())
        return 0;
    if (totalContact < 8)
        setMaxContacts(totalContact + 1);
    else
        setMaxContacts(8);

    return 1;
}

std::string PhoneBook::formatField(const std::string &field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return std::string(10 - field.length(), ' ') + field;
}
void PhoneBook::displayContactByIndex(int pos, int totalContacts)
{
    if (pos <= 0 || pos > totalContacts)
    {
        std::cout << "❌ Invalid index. Please try again." << std::endl;
        return;
    }
    Contact &c = contacts[pos - 1];
    std::cout << "\n📇 Contact Details (Index " << pos << ")\n";
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "👤 First Name      : " << c.getFirstName() << std::endl;
    std::cout << "👥 Last Name       : " << c.getLastName() << std::endl;
    std::cout << "📞 Phone Number    : " << c.getPhoneNumber() << std::endl;
    std::cout << "🏷️  Nickname       : " << c.getNickName() << std::endl;
    std::cout << "🔒 Darkest Secret  : " << c.getDarkestSecret() << std::endl;
    std::cout << "-----------------------------------------\n" << std::endl;
}

void PhoneBook::displayContactList(int pos)
{
    if (pos == 0)
    {
        std::cout << "⚠️  No contacts yet." << std::endl;
        return;
    }
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│     Index│First Name│ Last Name│  Nickname│" << std::endl;
    std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
    for (int i = 0; i < getContactCount(); i++)
    {
        std::cout << "│" << std::setw(10) << i + 1
                  << "│" << formatField(contacts[i].getFirstName())
                  << "│" << formatField(contacts[i].getLastName())
                  << "│" << formatField(contacts[i].getNickName())
                  << "│" << std::endl;
        if (i < getContactCount() - 1)
            std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
    }
    std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

int PhoneBook::getContactCount() const
{
    return (PhoneBook::_maxPhoneBookContact);
}
void    PhoneBook::setMaxContacts(int maxPhoneBookContact)
{
    PhoneBook::_maxPhoneBookContact = maxPhoneBookContact;
}