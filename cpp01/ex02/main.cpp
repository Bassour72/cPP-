#include <iostream>
#include <string>

int main(void)
{
    std::string stringValue("HI THIS IS BRAIN");

    // Pointer to stringValue
    std::string* stringPTR = &stringValue;

    // Reference to stringValue
    std::string& stringREF = stringValue;

    std::cout << "================ MEMORY ADDRESSES =================\n";
    std::cout << "Address of stringValue   : " << &stringValue << '\n';
    std::cout << "Address held by stringPTR: " << stringPTR << '\n';
    std::cout << "Address held by stringREF: " << &stringREF << '\n';

    std::cout << "\n================== VALUES ========================\n";
    std::cout << "Value of stringValue     : " << stringValue << '\n';
    std::cout << "Value pointed by stringPTR: " << *stringPTR << '\n';
    std::cout << "Value referred by stringREF: " << stringREF << '\n';

    std::cout << "\n================ POINTER & REFERENCE DEMO =========\n";
    // Modify through pointer
    *stringPTR = "MODIFIED THROUGH POINTER";
    std::cout << "After modifying via pointer:\n";
    std::cout << "stringValue: " << stringValue << '\n';
    std::cout << "stringREF  : " << stringREF << '\n';

    // Modify through reference
    stringREF = "MODIFIED THROUGH REFERENCE";
    std::cout << "After modifying via reference:\n";
    std::cout << "stringValue: " << stringValue << '\n';
    std::cout << "*stringPTR : " << *stringPTR << '\n';


    // Modify through reference
    stringValue = "MODIFIED THROUGH REFERENCE";
    std::cout << "After modifying via reference:\n";
    std::cout << "stringValue: " << stringREF << '\n';
    std::cout << "*stringPTR : " << *stringPTR << '\n';
    return 0;
}

