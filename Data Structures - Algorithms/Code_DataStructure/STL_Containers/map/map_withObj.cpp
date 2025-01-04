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
    Print all elements in map
*/
void printMap(std::map<std::string, Person> inMap)
{
    std::map<std::string, Person>::iterator it;
    std::cout << "\tKEY\tVALUE\n";

    for (it = inMap.begin(); it != inMap.end(); ++it) {
        std::cout << '\t' << it->first 
                << '\t' << it->second.firstName << " " <<  it->second.lastName 
                << ", " <<  it->second.age
                << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::map<std::string, Person> names;

    // Add element to map using make_pair
    names.insert(std::make_pair("Max", Person("Max", "Mustermann", 21)));

    // Add element to map using uniform initializer:
    names.insert({"Monika", {"Monika", "Musterfrau", 23}});

    // Add element to map using [] operator
    names["Anna"] = Person("Anna", "Nass", 42);
    names["Peter"] = {"Peter", "Silie", 17};

    printMap(names);
}
