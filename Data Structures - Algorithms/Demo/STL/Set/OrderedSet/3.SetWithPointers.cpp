#include <iostream>
#include <set>

class Person
{
public:
    std::string firstName;
    std::string lastName;
    int age;

public:
    Person(std::string fn, std::string ln, int a)
        : firstName(fn), lastName(ln), age(a)
    {
    }
};


/*
    Compare items in set, so the set knows how to sort its items
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
    Print all elements in set
*/
void printSet(std::set<Person*, decltype(&personCmp)> inSet)
{
    for (auto person : inSet) {
        std::cout << person->firstName << " " << person->lastName << std::endl;
    }
    std::cout << std::endl;
}

/*
    Find person by full name, using set::find()
*/
bool findPerson(std::set<Person*, decltype(&personCmp)> inSet, Person* inPersonToFind)
{
    auto result = inSet.find(inPersonToFind);
    if (result != inSet.end()) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    // This set is special because its value is a pointer to object
    // It has a custom comparator too
    std::set<Person*, decltype(&personCmp)> people(personCmp);

    // Insert item to set
    people.insert(new Person("Josiah", "Bartlet", 47));
    people.insert(new Person("Toby", "Ziegler", 17));
    people.insert(new Person("Josh", "Lyman", 11));
    people.insert(new Person("Leo", "McGarry", 4));
    people.insert(new Person("Claudia Jean", "Cregg", 21));
    people.insert(new Person("Charlie", "Young", 23));

    // Print all items in set
    printSet(people);

    // Check if found the given full name
    Person personToFind("Toby", "Ziegler", 50);
    bool result = findPerson(people, &personToFind);
    if (result) {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is found!" << std::endl;
    }
    else {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is not found!" << std::endl;
    }

    // Free memory and clear set
    for (auto person : people) {
        if (person != nullptr) {
            delete person;
            person = nullptr;
        }
    }
    people.clear();
}