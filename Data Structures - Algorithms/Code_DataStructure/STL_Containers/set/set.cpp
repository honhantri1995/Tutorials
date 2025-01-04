#include <iostream>
#include <set>   // for ordered set

// Print all elements in set
void printSet(std::set<int> inSet)
{
    std::set<int>::iterator it;
    for (it = inSet.begin(); it != inSet.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Way 1: Create and initialize an ordered set container by assignment
    // std::set<int> s1 = {40, 30, 60, 20, 50, 50, 10};

    // Way 2: Create and initialize an ordered set container by intializer list
    // std::set<int> s2{40, 30, 60, 20, 50, 50, 10};

    // Way 3: Create and initialize an ordered set container
    std::set<int> s1;
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);
    s1.insert(50);  // Note: only one 50 will be added to the set
    s1.insert(10);

    std::set<int>::iterator it;

    // Print all elements of set s1
    std::cout << "The set s1 is: \n";
    printSet(s1);

    // Create another set called s2, then assign the elements from s1 to s2
    std::set<int> s2(s1.begin(), s1.end());     // Another way: std::set<int> s2(s1);

    // Print all elements of set ss
    printSet(s2);

    // Remove elements less than 30 in set s2
    std::cout << "The set s2 after removal of elements less than 30:\n";
    s2.erase(s2.begin(), s2.find(30));
    printSet(s2);

    // Remove 2nd element
    it = s2.begin();
    it++;
    s2.erase(it);
    std::cout << "The set s2 after removal of the 2nd element:\n";
    printSet(s2);

    // Remove element with value 50 in set s2
    int num = s2.erase(50);
    std::cout << "The set s2 after removal of the element 50:\n";
    printSet(s2);
    std::cout << " => " << num << " element is removed\n";

    return 0;
}
