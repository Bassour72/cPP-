#include "FileReplacer.hpp"

#include "FileReplacer.hpp"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    FileReplacer fileReplacer(argv[1], argv[2], argv[3]);

    if (!fileReplacer.areFileArgumentsValid())
    {
        std::cerr << "Error: Arguments cannot be empty strings.\n";
        return 1;
    }

    if (!fileReplacer.replaceFileContent())
    {
        std::cerr << "Error: File replacement failed.\n";
        return 1;
    }

    return 0;
}

