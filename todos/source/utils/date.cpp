#include <iostream>
#include <map>
#include <string>

#include "date.h"

// construct with a unix timestamp
Date::Date(int unixTime)
{
    this->unixTime = unixTime;
}

// construct with year, month, day
Date::Date(YearMonthDay yearMonthDay)
{
    // convert year, month, day to unix time
    this->unixTime = Date::yearMonthDayToUnix(yearMonthDay);
}

// construct with current date
Date::Date()
{
    this->unixTime = time(NULL);
}

// get if a given year is a leap year
int Date::getIsLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// get the number of days in a given month (by number)
int Date::getDaysInMonth(int year, int month)
{
    MonthInfo monthInfo = Date::getMonthInfo(month);

    if (monthInfo.isLeapMonth && Date::getIsLeapYear(year))
    {
        return monthInfo.days + 1;
    }

    return monthInfo.days;
}

int Date::getDaysInYear(int year)
{
    return Date::getIsLeapYear(year) ? 366 : 365;
}

// check if a yearMonthDay looks legit
void Date::validateYearMonthDay(YearMonthDay yearMonthDay)
{
    if (yearMonthDay.year < 1970)
    {
        throw std::invalid_argument("Year must be greater than 1970");
    }

    if (yearMonthDay.month < 1 || yearMonthDay.month > 12)
    {
        throw std::invalid_argument("Month must be between 1 and 12");
    }

    if (yearMonthDay.day < 1 || yearMonthDay.day > Date::getDaysInMonth(yearMonthDay.year, yearMonthDay.month))
    {
        throw std::invalid_argument("Day must be between 1 and the number of days in the month");
    }
}

// convert year, month, day to unix time
int Date::yearMonthDayToUnix(YearMonthDay yearMonthDay)
{
    Date::validateYearMonthDay(yearMonthDay);

    int yearsSinceEpoch = yearMonthDay.year - 1970;

    int leapYearsSinceEpoch = 0;

    for (int i = 1970; i < yearMonthDay.year; i++)
    {
        if (Date::getIsLeapYear(i))
        {
            leapYearsSinceEpoch++;
        }
    }

    int monthToDays = 0;

    for (int i = 1; i < yearMonthDay.month; i++)
    {
        monthToDays += Date::getDaysInMonth(yearMonthDay.year, i);
    }

    int daysSinceEpoch = (yearsSinceEpoch * 365) + leapYearsSinceEpoch + monthToDays + yearMonthDay.day;

    return daysSinceEpoch * 24 * 60 * 60;
}

// convert unix time to year
YearMonthDay Date::unixToYearMonthDay(int unixTime)
{
    int daysSinceEpoch = unixTime / (24 * 60 * 60);
    int year = 1970;

    // Calculate the year
    while (true)
    {
        int daysInYear = Date::getDaysInYear(year);

        if (daysSinceEpoch < daysInYear)
        {
            break;
        }

        daysSinceEpoch -= daysInYear;
        year++;
    }

    // Calculate the month
    int month = 1;
    while (true)
    {
        int daysInMonth = Date::getDaysInMonth(year, month);
        if (daysSinceEpoch < daysInMonth)
        {
            break;
        }
        daysSinceEpoch -= daysInMonth;
        month++;
    }

    // Remaining daysSinceEpoch is the day of the month
    int day = daysSinceEpoch;

    return {year, month, day};
}

// get the info for a month
MonthInfo Date::getMonthInfo(int month)
{
    return monthInfos.at(month);
}

// get the underlying unix time
int Date::getUnix()
{
    return this->unixTime;
}

// get the year, month, day
YearMonthDay Date::getYearMonthDay()
{
    return Date::unixToYearMonthDay(this->unixTime);
}

// convert to a readable string
std::string Date::toReadableString()
{
    YearMonthDay yearMonthDay = this->getYearMonthDay();

    MonthInfo monthInfo = Date::getMonthInfo(yearMonthDay.month);

    return std::to_string(yearMonthDay.year) + "-" + monthInfo.name + "-" + std::to_string(yearMonthDay.day);
}

// check if a date is after a given date
bool Date::isAfter(Date date)
{
    return this->unixTime > date.getUnix();
}