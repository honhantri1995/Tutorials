#include <iostream>
#include <map>

class Person
{
public:
    std::string firstName;
    std::string lastName;
    int age;

public:
    Person()
    {
    }

    Person(std::string fn, std::string ln, int age) :
        firstName(fn),
        lastName(ln),
        age(age)
    {
    }
};

/*
    Compare items in map, so the map knows how to sort its items
*/
bool personCmp(const Person* lhs, const Person* rhs)
{
    if (lhs->firstName == rhs->firstName) {
        return lhs->lastName < rhs->lastName;
    }
    else {
        return lhs->firstName < rhs->firstName;
    }
}

/*
    Print all elements in map
*/
void printMap(std::map<Person*, std::string, decltype(&personCmp)> inMap)
{
    std::map<Person*, std::string, decltype(&personCmp)>::iterator it;
    std::cout << "\tKEY\tVALUE\n";

    for (it = inMap.begin(); it != inMap.end(); ++it) {
        std::cout << '\t' << it->first->firstName << " " <<  it->first->lastName 
                  << ", " << it->first->age
                  << ", " << it->second 
                  << std::endl;
    }
    std::cout << std::endl;
}

/*
    Find person by full name, using map::find()
*/
bool findPerson(std::map<Person*, std::string, decltype(&personCmp)> inMap, Person* inPersonToFind)
{
    auto result = inMap.find(inPersonToFind);
    if (result != inMap.end()) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    // This map is special because its key is a pointer to object
    // It has a custom comparator too
    std::map<Person*, std::string, decltype(&personCmp)> phonebook(personCmp);

    phonebook[new Person("Max", "Waye", 21)]    = "06161123456";
    phonebook[new Person("Monika", "Johnson", 23)] = "06151654321";
    phonebook[new Person("John", "Waye", 23)] = "06202453674";

    ////////////////////////////////////////
    // Print all items in map
    printMap(phonebook);

    ////////////////////////////////////////
    // Check if found the given item
    Person personToFind;
    personToFind.firstName = "Monika";
    personToFind.lastName = "Johnson";
    bool result = findPerson(phonebook, &personToFind);
    if (result) {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is found!" << std::endl;
    }
    else {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is not found!" << std::endl;
    }
    std::cout << std::endl;
}
