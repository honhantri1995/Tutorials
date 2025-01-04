#include <iostream>
#include <map>
#include <tuple>        // for std::tie
#include <algorithm>    // for std::sort
#include <vector>

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

    // Help map know how to sort keys in order
    // Note: Without it, compiling error
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

    // Help std::find() know how to compare full name   --> WON'T WORK WITH STD::MAP
    // Note: Without it, compiling error
    // bool operator==(const Person& rhs) const
    // {
    //     if (firstName == rhs.firstName)
    //     {
    //         return lastName == rhs.lastName;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
};

/*
    Print all elements in map
*/
void printMap(std::map<Person, std::string> inMap)
{
    std::map<Person, std::string>::iterator it;
    std::cout << "\tKEY\tVALUE\n";

    for (it = inMap.begin(); it != inMap.end(); ++it) {
        std::cout << '\t' << it->first.firstName << " " <<  it->first.lastName 
                  << ", " << it->first.age
                  << ", " << it->second 
                  << std::endl;
    }
    std::cout << std::endl;
}

// Find person by full name, using std::find()   --> WON'T WORK WITH STD::MAP
// bool findPerson(std::map<Person, std::string> inMap, Person inPersonToFind)
// {
//     auto result = std::find(inMap.begin(), inMap.end(), inPersonToFind);        // Need to overload operator==
//     if (result != inMap.end()) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }

/*
    Another way to find person by full name, using map::find()
*/
bool findPerson_2(std::map<Person, std::string> inMap, Person inPersonToFind)
{
    auto result = inMap.find(inPersonToFind);        // Need to overload operator< (So, this way we can utilize operator<, not only for sorting but also for finding)
    if (result != inMap.end()) {
        return true;
    }
    else {
        return false;
    }
}


/*
    Sort items in map by value, in ascending order
    Note: The idea is to make another map, which uses the original map’s values as its keys and the original map’s keys as its values.
          A multimap is used because values of the original map can be duplicate.
*/
void sortMap_byValue(std::map<Person, std::string> inMap)
{
    std::multimap<std::string, Person> mp;

    // Copy map into a multimap
    for (auto person : inMap) 
    {
        mp.insert(make_pair(person.second, person.first));
    }

    // Print map
    std::cout << "Map after sorted by value:" << std::endl;
    std::cout << "\tKEY\tVALUE\n";
    for (auto person : mp)
    {
        std::cout << '\t' << person.second.firstName << " " <<  person.second.lastName 
                  << ", " << person.second.age
                  << ", " << person.first 
                  << std::endl;
    }
    std::cout << std::endl;
}

/*
    Another way to sort items in map by value, in ascending order
    Note: The idea is to copying the map into a vector of key-value pairs
          Then sort items in the vector using std::sort()
*/
void sortMap_byValue_2(std::map<Person, std::string> inMap)
{
    // Copy map into a vector
    std::vector<std::pair<Person, std::string>> vec;
    for (auto person : inMap) 
    {
        vec.push_back(make_pair(person.first, person.second));
    }

    // Sort vector
    auto cmp = [](const std::pair<Person, std::string>& lhs, const std::pair<Person, std::string>& rhs)
    {
        return lhs.second < rhs.second;
    };
    std::sort(vec.begin(), vec.end(), cmp); 

    // Print vector
    std::cout << "Map after sorted by value:" << std::endl;
    std::cout << "\tKEY\tVALUE\n";
    for (auto person : vec)
    {
        std::cout << '\t' << person.first.firstName << " " <<  person.first.lastName 
                  << ", " << person.first.age
                  << ", " << person.second 
                  << std::endl;
    }
    std::cout << std::endl;
}

// Directly sort items in map, using std::sort()    --> WON'T WORK WITH STD::MAP
// void sortMap_byValue_3(std::map<Person, std::string>& map)
// {
//     auto cmp = [](const std::pair<Person, std::string>& lhs, const std::pair<Person, std::string>& rhs)
//     {
//         return lhs.second < rhs.second;
//     };

//     std::sort(map.begin(), map.end(), cmp);
// }

int main()
{
    // This map is special because its key is an object, not a number or string
    std::map<Person, std::string> phonebook;

    phonebook[{"Max", "Waye", 21}]    = "06161123456";
    phonebook[{"Monika", "Johnson", 23}] = "06151654321";
    phonebook[{"John", "Waye", 23}] = "06202453674";

    ////////////////////////////////////////
    // Print all items in map
    printMap(phonebook);

    ////////////////////////////////////////
    // Check if found the given item
    Person personToFind;
    personToFind.firstName = "Monika";
    personToFind.lastName = "Johnson";
    // bool result = findPerson(phonebook, personToFind);   // Way 1   --> WON'T WORK WITH STD::MAP
    bool result = findPerson_2(phonebook, personToFind);    // Way 2
    if (result) {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is found!" << std::endl;
    }
    else {
        std::cout << "Person '" << personToFind.firstName << " " << personToFind.lastName << "' is not found!" << std::endl;
    }
    std::cout << std::endl;

    ////////////////////////////////////////
    // Sort map by value (by default, map is sorted by key)
    sortMap_byValue(phonebook);         // Way 1
    // sortMap_byValue_2(phonebook);    // Way 2
    // sortMap_byValue_3(phonebook);    // Way 3    --> WON'T WORK WITH STD::MAP
}
