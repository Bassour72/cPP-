#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string _ideas[100];
    int _indexIdeas;
    static const int _MaxIndexIdeas = 100;

public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    virtual ~Brain();

    const std::string& getIdeas() const;
    void setIdeas(const std::string &str);

    int  getIndexIdeas() const;
    void setIndexIdeas(int index);
};

#endif /* BRAIN_HPP */
