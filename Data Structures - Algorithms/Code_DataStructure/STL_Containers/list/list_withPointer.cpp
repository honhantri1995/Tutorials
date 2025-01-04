#include <iostream>
#include <list>
#include <functional>

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

    /*
        Help std::find() know how to compare full name    <-- std::find() WON'T WORK WITH POINTER
        Note: Without it, compiling error
    */
    // bool operator==(const Person* rhs) const
    // {
    //     if (firstName == rhs->firstName)
    //     {
    //         return lastName == rhs->lastName;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
};

/*
    Comparator for list::sort()
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
    Print all elements in list
*/
void printlist(std::list<Person*> inlist)
{
    for (auto person : inlist) {
        std::cout << person->firstName << " " << person->lastName << std::endl;
    }
    std::cout << std::endl;
}

/*
    Find person by full name, using std::find_if()
*/
bool findPerson(std::list<Person*> inlist, Person* inPersonToFind)
{
    auto isFound = [inPersonToFind](Person* lhs)
    {
        if (lhs->firstName == inPersonToFind->firstName) {
            return lhs->lastName == inPersonToFind->lastName;
        }

        return false;
    };

    auto result = std::find_if(inlist.begin(), inlist.end(), isFound);  // Don't need to overload any operator
    if (result != inlist.end()) {
        return true;
    }
    else {
        return false;
    }
}

/*
    Find person by full name, using std::find()
*/
// bool findPerson_2(std::list<Person*> inlist, Person* inPersonToFind)          // std::find() WON'T WORK WITH POINTER
// {
//     auto result = std::find(inlist.begin(), inlist.end(), inPersonToFind);    // Need to overload operator==
//     if (result != inlist.end()) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }

int main()
{
    // This list is special because its value is a pointer to object
    std::list<Person*> people;

    // Add item to list
    people.push_back(new Person("Josiah", "Bartlet", 47));
    people.push_back(new Person("Toby", "Ziegler", 17));
    people.push_back(new Person("Josh", "Lyman", 11));
    people.push_back(new Person("Leo", "McGarry", 4));
    people.push_back(new Person("Claudia Jean", "Cregg", 21));
    people.push_back(new Person("Charlie", "Young", 23));

    // Print all items in list (before sort)
    std::cout << "List before being sorted:" << std::endl;
    printlist(people);

    // Sort items in list based on full name
    people.sort(personCmp);     // Unlike std::vector, std::set and std::map, std::list provides sort() function

    // Print all items in list (after sort)
    std::cout << "List after being sorted:" << std::endl;
    printlist(people);

    // Check if found the given full name
    Person personToFind("Toby", "Ziegler", 50);
    bool result = findPerson(people, &personToFind);
    // bool result = findPerson_2(people, &personToFind);   // WON'T WORK
    if (result) {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is found!" << std::endl;
    }
    else {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is not found!" << std::endl;
    }

    // Free memory and clear list
    for (auto person : people) {
        if (person != nullptr) {
            delete person;
            person = nullptr;
        }
    }
    people.clear();
}