#include <iostream>
#include <unordered_map>

int main()
{
    // Create an ordered map
    std::unordered_map<int, int> m1;
    m1[1] = 40;
    m1[2] = 30;
    m1[3] = 60;
    m1[4] = 20;

    // Another way of inserting a value in a map
    m1.insert(std::pair<int, int>(7, 10));
    m1.insert(std::pair<int, int>(5, 50));
    m1.insert(std::pair<int, int>(6, 50));
    m1.insert(std::pair<int, int>(6, 90));

    // Print all elements in map m1
    std::unordered_map<int, int>::iterator it;
    std::cout << "\nMap m1 is:\n";
    std::cout << "\tKEY\tVALUE\n";
    for (it = m1.begin(); it != m1.end(); ++it) {
        std::cout << '\t' << it->first << '\t' << it->second << std::endl;
    }

    // Create another map called m2, then assign all elements from m1 to m2
    std::unordered_map<int, int> m2(m1.begin(), m1.end());


    // Remove an element with key 4 in m2
    int num = m2.erase(4);
    std::cout << "\nMap m2 after removal of element at key 4:\n";
    std::cout << "  ==> " << num << " element is removed\n";
    std::cout << "\tKEY\tVALUE\n";
    for (it = m2.begin(); it != m2.end(); ++it) {
        std::cout << '\t' << it->first << '\t' << it->second << std::endl;
    }

    return 0;
}
