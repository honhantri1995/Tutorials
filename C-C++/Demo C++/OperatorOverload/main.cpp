#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include "date.h"

// Buble sort. Don't use operator overload
void bublesort_1(vector<Date>& dates)
{
    for (size_t i = 0; i < dates.size(); i++) {
        for (size_t j = 0; j < dates.size() - 1; j++) {
            if (dates[j + 1].getYear() == dates[j].getYear()) {
                if (dates[j + 1].getMonth() == dates[j].getMonth()) {
                    if (dates[j + 1].getDay() < dates[j].getDay()) {
                        std::swap(dates[j + 1], dates[j]);
                    }
                }
                else if (dates[j + 1].getMonth() < dates[j].getMonth()) {
                    std::swap(dates[j + 1], dates[j]);
                }
            }
            else if (dates[j + 1].getYear() < dates[j].getYear()) {
                std::swap(dates[j + 1], dates[j]);
            }
        }
    }
}

// Buble sort. Comparing Data object by overloading operator<
void bublesort_2(vector<Date>& dates)
{
    for (size_t i = 0; i < dates.size(); i++) {
        for (size_t j = 0; j < dates.size() - 1; j++) {
            if (dates[j + 1] < (dates[j])) {
                std::swap(dates[j + 1], dates[j]);
            }
        }
    }
}

int main()
{
    vector<Date> dates;
    dates.push_back({1, 1, 2017});
    dates.push_back({1, 1, 2020});
    dates.push_back({1, 12, 2014});
    dates.push_back({17, 4, 2014});
    dates.push_back({21, 2, 2014});
    dates.push_back({13, 7, 2014});
    dates.push_back({13, 8, 2014});
    dates.push_back({12, 8, 2014});
    dates.push_back({1, 1, 2009});
    dates.push_back({1, 1, 2007});
    dates.push_back({1, 1, 2013});
    dates.push_back({1, 1, 2004});

    /////////////////////////////////
    // Way 1: Sort dates using std::sort
    std::sort(dates.begin(), dates.end());  // Need to overload operator<

    // Way 2: Sort dates using bublesort 1
    // bublesort_1(dates);

    // Way 3: Sort dates using bublesort 1
    // bublesort_2(dates);                  // Need to overload operator<

    // Print all dates after being sorted
    for (const auto& date : dates) {
        cout << date << endl;               // Need to overload operator<<
    }
    cout << endl;


    /////////////////////////////////
    // Check if foud the given date
    Date dateToFind = Date(1, 1, 2020);
    auto result = std::find(dates.begin(), dates.end(), dateToFind);  // Need to overload operator==
    if (result != dates.end()) {
        cout << "Date " << dateToFind << " found!" << endl;           // Need to overload operator<<
    }
    cout << endl;


    /////////////////////////////////
    // Add dates
    Date d1(31, 12, 2021);
    cout << "Original date: " << d1 << endl;

    d1 += 1;        // Need to overload operator+=
    cout << "After adding 1 day: " << d1 << endl;

    d1 += 30;
    cout << "After adding 30 days: " << d1 << endl;

    d1 += 80;
    cout << "After adding 80 days: " << d1 << endl;

    d1 += 700;
    cout << "After adding 700 days: " << d1 << endl;
}
