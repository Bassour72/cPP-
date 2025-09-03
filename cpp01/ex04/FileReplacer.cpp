#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename,
                           const std::string& search,
                           const std::string& replaceWith)
: _filename(filename), _search(search), _replaceWith(replaceWith)
{
    setOutputFilename(".replace");
}

void FileReplacer::setOutputFilename(const std::string& extension)
{
    _outputFile = _filename + extension;
}

bool FileReplacer::areFileArgumentsValid() const
{
    return (!_filename.empty() && !_search.empty() && !_replaceWith.empty());
}

std::string FileReplacer::searchAndReplace(const std::string& line) const
{
    std::string result;
    size_t i = 0;

    if (_search.empty())
        return (line);

    while (i < line.size())
    {
        if (i + _search.size() <= line.size() &&
            line.compare(i, _search.size(), _search) == 0)
        {
            result += _replaceWith;
            i += _search.size();
        }
        else
        {
            result += line[i];
            i++;
        }
    }

    return (result);
}

bool FileReplacer::replaceFileContent() const
{
    std::ifstream inputFile(_filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Failed to open input file: " << _filename << '\n';
        return (false);
    }

    std::ofstream outputFile(_outputFile, std::ios::trunc);
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Failed to open output file: " << _outputFile << '\n';
        return (false);
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << searchAndReplace(line) << '\n';
    }

    return (true);
}


const std::string& FileReplacer::getFilename() const 
{ return (_filename); }
const std::string& FileReplacer::getSearch() const 
{ return (_search); }
const std::string& FileReplacer::getReplaceWith() const 
{ return (_replaceWith); }
const std::string& FileReplacer::getOutputFilename() const 
{ return (_outputFile); }

// Destructor
FileReplacer::~FileReplacer() {}
