#include <iostream>
#include <list>   // for list
using namespace std;

void printList(std::list<int> inList)
{
    std::list<int>::iterator it;
    for (it = inList.begin(); it != inList.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
}

int main()
{
    std::list<int> list1, list2;

    // Create lists
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);         // Another way: list1.emplace_back(). How it's different: https://stackoverflow.com/a/59330916/14835442
        list2.push_front(i);        // Another way: list1.emplace_front()
    }

    // Create an iterator for list
    std::list<int>::iterator it;

    // Print lists
    cout << "list1:";
    printList(list1);

    cout << "list2:";
    printList(list2);

    // Get the front element of list
    cout << "list1.front(): " << list1.front() << endl;

    // Get the back element of list
    cout << "list1.back(): " << list1.back() << endl;

    // Remove front element out of list
    list1.pop_front();
    cout << "list1.pop_front():";
    printList(list1);

    // Remove back element out of list
    list2.pop_back();
    cout << "list2.pop_back():";
    printList(list2);

    // Sort elements in ascending order
    list1.sort();
    cout << "list2.sort() - ascending:";
    printList(list1);

    // Sort elements in descending order
    list2.sort(
        [](int lhs, int rhs) {
            return lhs > rhs; 
        }
    );
    cout << "list2.sort() - descending:";
    printList(list2);

    // Reverse orders of elements
    list2.reverse();
    cout << "list2.reverse():";
    printList(list2);

    // Resize list (elements at the back will be removed if the new size < old size)
    list1.resize(7);
    cout << "list1.resize():";
    printList(list1);

    // Remove 2nd element out of list
    it = list1.begin();
    ++it;
    it = list1.erase(it);       // After erasing, iterator moves to the following element
    cout << "list1.erase() 2nd element:";
    printList(list1);

    // Insert 2nd element with value of 2 to list
    list1.insert(it, 2);
    cout << "list1.insert() 2nd element:";
    printList(list1);

    // Get the back element of list, but using reverse iterator
    std::list<int>::reverse_iterator rit;
    rit = list1.rbegin();                   // Same as "it = list1.end();"
    cout << "list1.begin(): " << *rit << endl;

    // Merge list1 into list2, and sort elements in ascending order
    list2.merge(list1);
    cout << "list2.merge(list1):";
    printList(list2);

    // Remove duplicate elements
    // NOTE: unique() only works on consecutive elements (eg: "1 2 2 3" will be "1 2 3", but "1 2 3 2" will be still "1 2 3 2")
    list2.unique();
    cout << "list2.unique():";
    printList(list2);

    // Remove element with value 6 out of list
    list2.remove(6);
    cout << "list2.remove(6):";
    printList(list2);

    // Remove elements which have value > 7
    list2.remove_if([](int value) { return value > 7; });
    cout << "list2.remove_if(value > 7):";
    printList(list2);

    // Remove all elements of list2
    list2.clear();
    cout << "list2.clear()):";
    printList(list2);

    // Get max number of elements a list can hold
    cout << "list2.max_size()): " << list2.max_size() << endl;

    return 0;
}
