#include "PhoneBook.hpp"


void pause_prompt(const char* sms)
{
    std::string dummy;
    std::cout << sms << std::endl;
    std::cin.clear();
    std::cin.ignore(1000000, '\n');
    std::getline(std::cin, dummy);
    std::system("clear");
}

std::string ReadUserEnter(std::string display)
{
    std::string input;
    std::cout << display << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return "";
    
    return input;
}
void startPhoneBook(void)
{
    PhoneBook phonebook;
    int totalContacts = 0;
    int index = 0;
    std::string input;
    do
    {
        phonebook.displayPhonebookMenu();
        std::getline(std::cin, input);
        if (std::cin.eof())
            return;
        if (input == "")
         { 
            system("clear"); 
            continue;
        }
        else if (input == "ADD")
        {
            if (phonebook.createPhoneBookProfile(Contact::addCo() ,totalContacts))
                 totalContacts = phonebook.getContactCount();
            pause_prompt("Press Enter to continue... \n");
        }
        else if (input == "SEARCH")
        {
            phonebook.displayContactList(totalContacts);
            index  = phonebook.read_ini("Enter index :");   
            phonebook.displayContactByIndex(index, totalContacts);
            pause_prompt("Press Enter to continue...\n");
        }
        else if (input == "EXIT")
        {
            return;
        }
        else
        {
           std::system("clear");
            std::cout << "invalid input `" << input << "`" << std::endl;

        }
        
    } while (1);
    
}
int main(void)
{
    startPhoneBook();

    return 0;
}
