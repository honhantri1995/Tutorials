#include <iostream>
#include <set>

class Person
{
public:
    std::string firstName;
    std::string lastName;
    int age;

public:
    /*
        Help set know how to sort keys in order
        Note: Without it, compiling error
    */
    bool operator<(const Person& rhs) const
    {
        // Sort by first name. If first names are same, sort by last name
        if (firstName != rhs.firstName)
        {
            return firstName < rhs.firstName;
        }
        return lastName < rhs.lastName;

        // Another way:
        // return std::tie(firstName, lastName) < std::tie(rhs.firstName, rhs.lastName);
    }

    /*
        Help std::find know how to compare full name
        Note: Without it, compiling error
    */
    bool operator==(const Person& rhs) const
    {
        if (firstName == rhs.firstName)
        {
            return lastName == rhs.lastName;
        }
        else
        {
            return false;
        }
    }
};

/*
    Print all elements in set
*/
void printSet(std::set<Person> inSet)
{
    std::set<Person>::iterator it;
    for (it = inSet.begin(); it != inSet.end(); it++) {
        std::cout << it->firstName << " " << it->lastName << std::endl;
    }
    std::cout << std::endl;
}

/*
    Find person by full name, using std::find()
*/
bool findPerson(std::set<Person> inSet, Person inPersonToFind)
{
    auto result = std::find(inSet.begin(), inSet.end(), inPersonToFind);        // Need to overload operator==
    if (result != inSet.end()) {
        return true;
    }
    else {
        return false;
    }
}

/*
    Another way to find person by full name, using set::find()
*/
bool findPerson_2(std::set<Person> inSet, Person inPersonToFind)
{
    auto result = inSet.find(inPersonToFind);        // Need to overload operator< (So, this way we can utilize operator<, not only for sorting but also for finding)
    if (result != inSet.end()) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    std::set<Person> people;

    // Insert item to set
    people.insert({"Josiah", "Bartlet", 47});
    people.insert({"Toby", "Ziegler", 17});
    people.insert({"Josh", "Lyman", 11});
    people.insert({"Leo", "McGarry", 4});
    people.insert({"Claudia Jean", "Cregg", 21});
    people.insert({"Charlie", "Young", 23});

    // Print all items in set
    printSet(people);

    // Check if foud the given full name
    Person personToFind;
    personToFind.firstName = "Toby";
    personToFind.lastName = "Ziegler";
    bool result = findPerson(people, personToFind);         // Way 1
    // bool result = findPerson_2(people, personToFind);    // Way 2
    if (result) {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is found!" << std::endl;
    }
    else {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is not found!" << std::endl;
    }
}