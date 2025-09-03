#include <iostream>
#include <string>


void makeAllUpper(const std::string input) 
{
    for (size_t i = 0; i < input.size(); i++) 
    {
        char ch = input[i];
        if (std::isalpha(ch) && std::islower(ch))
            std::cout <<(char)(std::toupper(ch));
        else
            std::cout << ch;
    }
}

int main(int argc, char const *argv[])
{
    if (argc > 1) 
    {
        for (int i = 1; argv[i]; i++) 
        {
            makeAllUpper(argv[i]);
        }
        std::cout << std::endl;
    } 
    else 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return (0);
}
