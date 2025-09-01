#include "PhoneBook.hpp"

bool IsDigits(std::string input)
{
    for (size_t i = 0; i < input.size(); i++)
    {   
        if (!std::isdigit(input[i]))
            return (false);
    }
    return (true);
}

 int read_ini(std::string display)
 {
    std::string input;
    std::cout << display << std::endl;
    std::cin >> input;
    while (std::cin.fail() || std::cin.eof())
    {
        if (std::cin.eof()) 
        {
            std::cin.clear(); 
            std::cin.ignore(100000, '\n');
            return (-1); 
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
    if (!IsDigits(input))
        return (-1);
    return (std::stoi(input)); 
 }

void pause_prompt(const char* sms)
{
    std::string dummy;
    std::cout << sms << std::endl;
    std::cin.clear();
    std::getline(std::cin, dummy);
    
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

    while (true)
    {
        phonebook.displayPhonebookMenu();
        std::getline(std::cin, input);
        
        if (std::cin.eof())
            return;

        if (input.compare("ADD") == 0)
        {
            if (phonebook.createPhoneBookProfile(totalContacts))
                totalContacts = phonebook.getContactCount();
            std::cout << totalContacts << std::endl;
            pause_prompt("Press enter to continue...");
        }
        else if (input.compare("SEARCH") == 0)
        {
            if (totalContacts == 0)
            {
                std::cout << "No contacts available. Please add contacts first." << std::endl;
                pause_prompt("Press enter to continue...");
                continue;
            }

            phonebook.displayContactList(totalContacts);
            index = read_ini("Enter index :");
            if (index < 0)
            {
                std::cout << "Invalid input." << std::endl;
                pause_prompt("Press enter to continue...");
            }
            else
            {
                phonebook.displayContactByIndex(index, totalContacts);
                pause_prompt("Press enter to continue...");
            }
        }
        else if (input.compare("EXIT") == 0)
        {
            return;
        }
        else
        {
            std::cout << "Invalid input `" << input << "`" << std::endl;
            pause_prompt("Press enter to continue...");
        }

        std::cin.clear();
    }
}

int main(void)
{
    startPhoneBook();

    return 0;
}