Summarize for me all built-in function of std::map (https://en.cppreference.com/w/cpp/container/map.html) in a table.
The table has following columns: Name, Parameters, Usage, Time, Space, Example, Reference (URL link to en.cppreference.com and cplusplus.com)
For functions that is not from C++14, but in C++17 or later, add prefix "[C++17] " to cell in column "Description"

For example:

|Name|Parameters|Usage|Time|Space|Example|Reference|
|-----|----|----|-----|----|----|-------|
|**Iterator**|
|`begin`|None|Returns an iterator to the first element.|O(1)|O(1)|`auto it = myMap.begin();`|[cppreference](https://cplusplus.com/reference/map/map/begin/), [cpp](https://cplusplus.com/reference/map/map/begin/)|
|**Lookup**|
|`find`|`const key_type& key`|Finds an element by key.|O(logn)|O(1)|`auto it = myMap.find(2);`|[cppreference](https://cplusplus.com/reference/map/map/find/), [cpp](https://en.cppreference.com/w/cpp/container/map/find)|
|`contains`|`const key_type& k`|[C++20] Checks if container contains element|O(log n)|O(1)|`bool has = myMap.contains(5);`|[cppreference](https://en.cppreference.com/w/cpp/container/map/contains)|

And so on