#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>        // for std::sort

#include <functional>
using std::function;

#include "person.h"

void printPhoneBook(vector<Person>& inPhoneBook)
{
    for (auto& p : inPhoneBook) {
        cout << p.getFirstName() << " " << p.getLastName() << ", " << p.getAge() << endl;
    }
    cout << endl << endl;
}

int main()
{
    vector<Person> phoneBook;

    phoneBook.push_back(Person("Hubert", "Kah", 23));
    phoneBook.push_back(Person("Max", "Mustermann", 30));
    phoneBook.push_back({"Melinda", "Musterfrau", 25});     // Using uniform initializer also works
    phoneBook.push_back({"Adele", "Werther", 26});
    phoneBook.push_back({"Chloe", "Delaitre", 45});
    phoneBook.push_back({"Jerome", "Seguret", 38});
    phoneBook.push_back({"Simon", "Delaitre", 31});
    phoneBook.push_back({});                                // This will call default constructor of class Person

    // Sort items in ascending order based on first name
    // Syntax: The elements must be compared using operator<
    std::sort(phoneBook.begin(), phoneBook.end(),
                [](const auto& lhs, const auto& rhs)
                {
                    return lhs.getFirstName() < rhs.getFirstName();
                });
    cout << "Phone book after sorting based on first name:" << endl;
    printPhoneBook(phoneBook);

    // Sort items in ascending order based on last name
    std::sort(phoneBook.begin(), phoneBook.end(),
                [](const Person& lhs, const Person& rhs)
                {
                    return lhs.getLastName() < rhs.getLastName();
                });
    cout << "Phone book after sorting based on last name:" << endl;
    printPhoneBook(phoneBook);


    // Sort items in ascending order based on last name
    // Syntax: In second version of std::sort, the elements are compared using a comparator
    std::sort(phoneBook.begin(), phoneBook.end(),
                [](const Person& lhs, const Person& rhs)
                {
                    return lhs.getAge() < rhs.getAge();
                });
    cout << "Phone book after sorting based on age" << endl;
    printPhoneBook(phoneBook);

    return 0;
}
