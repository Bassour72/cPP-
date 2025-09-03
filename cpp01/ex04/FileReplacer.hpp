#pragma once
#ifndef __FILE_REPLACER_HPP__
#define __FILE_REPLACER_HPP__

#include <string>
#include <iostream>
#include <fstream>

class FileReplacer
{
private:
    const std::string _filename;
    std::string _search;
    std::string _replaceWith;
    std::string _outputFile;

public:
    FileReplacer(const std::string& filename,
                 const std::string& search,
                 const std::string& replaceWith);

    void setOutputFilename(const std::string& extension);
    bool areFileArgumentsValid() const;
    std::string searchAndReplace(const std::string& line) const;
    bool replaceFileContent() const;

    const std::string& getFilename() const;
    const std::string& getSearch() const;
    const std::string& getReplaceWith() const;
    const std::string& getOutputFilename() const;

    ~FileReplacer();
};

#endif // __FILE_REPLACER_HPP__

