#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
    _maxPhoneBookContact = 0;
    _indexPhoneBookContact =0;

}

PhoneBook::~PhoneBook()
{

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



int PhoneBook::createPhoneBookProfile() 
{
    int index = getIndex();
    contacts[index].addCo();
    if (contacts[index].exists())
    {
        std::cout << "Contact created successfully" << std::endl;
        if (getContactCount() < 8)
            setMaxContacts(getContactCount() + 1);
        setIndex((index + 1) % 8);
        return 1;
    }
    else
    {
        std::cout << "Error: cannot create contact" << std::endl;
        contacts[index].markAsExists();
        return (0);
    }
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
    std::cout << "-----------------------------------------" << std::endl;
}

void PhoneBook::displayContactList(int pos)
{
    if (pos == 0)
    {
        std::cout << "⚠️  No contacts yet." << std::endl;
        return;
    }
    std::cout << "+----------+----------+----------+----------+\n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "+----------+----------+----------+----------+\n";

    for (int i = 0; i < getContactCount(); i++)
    {
        std::cout << "|" 
                << std::setw(10) << i + 1
                << "|" << formatField(contacts[i].getFirstName())
                << "|" << formatField(contacts[i].getLastName())
                << "|" << formatField(contacts[i].getNickName())
                << "|\n";

        if (i < getContactCount() - 1)
            std::cout << "+----------+----------+----------+----------+\n";
    }

    std::cout << "+----------+----------+----------+----------+\n";
}

int PhoneBook::getContactCount() const
{
    return (PhoneBook::_maxPhoneBookContact);
}
void    PhoneBook::setMaxContacts(int maxPhoneBookContact)
{
    PhoneBook::_maxPhoneBookContact = maxPhoneBookContact;
}


int PhoneBook::getIndex()
{
    return _indexPhoneBookContact;
}

void PhoneBook::setIndex(int index)
{
    _indexPhoneBookContact = index;
}