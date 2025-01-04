#include "person.h"

// Without this constructor, compiler will trigger error "undefined reference to `Person::Person()"
//   when calling "phoneBook.push_back({})"
Person::Person() : Person("Anonymous", "Anonymous", 0)
{
}

Person::Person(const std::string& firstName, const std::string& lastName, const int& age)
    : m_firstName(firstName),
      m_lastName(lastName),
      m_age(age)
{
}

std::string Person::getFirstName() const
{
    return m_firstName;
}

std::string Person::getLastName() const
{
    return m_lastName;
}

int Person::getAge() const
{
    return m_age;
}
