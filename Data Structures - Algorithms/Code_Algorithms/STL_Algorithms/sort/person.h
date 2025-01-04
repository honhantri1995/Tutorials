#pragma once

#include <string>
using std::string;

class Person
{
private:
    string m_firstName;
    string m_lastName;
    int m_age;

public:
    Person();
    Person(const string& firstName, const string& lastName, const int& age);

    string getFirstName() const;
    string getLastName() const;
    int getAge() const;
};