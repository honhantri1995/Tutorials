#include <sstream>
#include <stdexcept>
#include <string>
#include "date.h"

using std::string;
using std::stringstream;

std::ostream& operator<<(std::ostream& os, const Date& rhs)
{
    os << rhs.getDateAsString();
    return os;
}

Date::Date(int d, int m, int y)
    : m_day(d),
      m_month(m),
      m_year(y)
{
    if (m_month <= 0 || m_month > 12) {
        throw std::invalid_argument("Month is not valid!");
    }

    if (m_day < 0 || m_day > m_daysPerMonth[m_month]) {
        throw std::invalid_argument("Day is not valid");
    }
}

bool Date::operator<(const Date& rhs) const
{
    // If year is different, we can simply compare dates by year
    if (m_year != rhs.m_year) {
        return m_year < rhs.m_year;
    }

    // If year is different, we can compare dates by month
    if (m_month != rhs.m_month) {
        return m_month < rhs.m_month;
    }

    // Year and month are equal, so we compare days
    return m_day < rhs.m_day; 
}

bool Date::operator==(const Date& rhs) const
{
    if (m_year != rhs.m_year) {
        return false;
    }

    if (m_month != rhs.m_month) {
        return false;
    }

    return m_day == rhs.m_day;
}

string Date::getDateAsString() const
{
    stringstream str;
    str << m_day << "/" << m_month << "/" << m_year;
    m_dateAsString      = str.str();
    return m_dateAsString;
}

int Date::getDay() const
{
    return m_day;
}

int Date::getMonth() const
{
    return m_month;
}

int Date::getYear() const
{
    return m_year;
}

Date& Date::operator+=(int rhs)
{
  addDay(rhs);
  return *this;
}

void Date::addYear(int y)
{
    m_year += y;
}

void Date::addMonth(int m)
{
    m_month += m;
    while (m_month > 12) {
        addYear(1);
        m_month -= 12;
    }
}

void Date::addDay(int d)
{
    m_day += d;
    while (m_day > m_daysPerMonth[m_month]) {
        m_day -= m_daysPerMonth[m_month];
        addMonth(1);
    }
}