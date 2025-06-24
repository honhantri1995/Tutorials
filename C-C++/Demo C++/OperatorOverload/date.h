#include <ostream>
#include <string>

class Date
{
private:
    static constexpr int m_daysPerMonth[] = {
        0,  31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};        // TODO: Check for leap year

    int m_day;
    int m_month;
    int m_year;

    mutable std::string m_dateAsString;

public:
    Date(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool operator<(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    std::string getDateAsString() const;
    Date& operator+=(int rhs);
    void addYear(int y);
    void addMonth(int m);
    void addDay(int d);
};

std::ostream& operator<<(std::ostream& os, const Date& rhs);
