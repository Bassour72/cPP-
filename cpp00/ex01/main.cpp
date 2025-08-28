#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

void pause_prompt(const char* sms)
{
    std::cin.clear();
    std::cout << sms;
    std::cin.get(); // wait for Enter
    system("clear"); // optional, but not recommended
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
void StartPhoneBook(void)
{
    PhoneBook phonebook;
    int totalContacts = 0;
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
            if (phonebook.CreatePhoneBookProfile(Contact::AddCo() ,totalContacts))
                 totalContacts++;
             pause_prompt("Press Enter to continue...");
        }
        else if (input == "SEARCH")
        {
            phonebook.DisplayContactList(totalContacts);
            int i = phonebook.Read_ini("Enter index :");   
            phonebook.DisplayContactByIndex(i, totalContacts);
            pause_prompt("Press Enter to continue...");
        }
        else if (input == "EXIT")
        {
            return ;
        }
        else
        {
            system("clear"); // optional, but not recommended
            std::cout << "invalid input \n";

        }
    } while (1);
    
}
int main(void)
{
    StartPhoneBook();
    return 0;
}
