#include <iostream>
#include <map>      // for ordered map

// Print all elements in map
void printMap(std::map<int, int> inMap)
{
    std::map<int, int>::iterator it;
    std::cout << "\tKEY\tVALUE\n";
    for (it = inMap.begin(); it != inMap.end(); ++it) {
        std::cout << '\t' << it->first << '\t' << it->second << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    // Create an ordered map
    std::map<int, int> m1;
    m1[1] = 40;
    m1[2] = 30;
    m1[3] = 60;
    m1[4] = 20;
    // Another way of inserting a value in a map
    m1.insert(std::pair<int, int>(7, 10));
    m1.insert(std::pair<int, int>(5, 50));   // Note: All items will be sorted in ascending order based on the key value
    m1.insert(std::pair<int, int>(6, 50));   // Another way: m1.emplace(std::pair<int, int>(6, 50));
    m1.insert(std::pair<int, int>(6, 90));   // Note: Inserting element with the same key is ignored

    // Print all elements in map m1
    std::cout << "The map m1 is:\n";
    printMap(m1);

    // Create another map called m2, then assign all elements from m1 to m2
    std::map<int, int> m2(m1.begin(), m1.end());    // Another way: "std::map<int, int> m2(m1);"

    // Create iterator for map
    std::map<int, int>::iterator it;

    // Print all elements in map m2
    std::cout << "The map m2 is:\n";
    printMap(m2);

    // Remove 2nd element
    it = m1.begin();
    it++;
    m1.erase(it);
    std::cout << "The map m1 after removal of the 2nd element:\n";
    printMap(m1);

    // Remove elements with keys smaller than 3
    m2.erase(m2.begin(), m2.find(3));
    std::cout << "The map m2 after removal of elements with keys smaller than 3:\n";
    printMap(m2);

    // Remove element at key 4
    int num = m2.erase(4);
    std::cout << "The map m2 after removal of element at key 4:\n";
    std::cout << "  ==> " << num << " element is removed\n";
    printMap(m2);

    // Count element with key 4
    std::cout << "There are " << m1.count(4) << " elements with key 4\n";

    return 0;
}
