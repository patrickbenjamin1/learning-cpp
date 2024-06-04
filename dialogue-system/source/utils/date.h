#include <map>
#include <string>

#ifndef DATE_DEFS

#define DATE_DEFS

enum class Season
{
    Spring,
    Summer,
    Autumn,
    Winter
};

struct YearMonthDay
{
    int year;
    int month;
    int day;
};

struct ReadableYearMonthDay
{
    int year;
    std::string month;
    int day;
};

struct MonthInfo
{
    int numerical;
    int days;
    Season season;
    std::string name;
    bool isLeapMonth;
};

const std::map<int, MonthInfo> monthInfos = {
    {1, {1, 31, Season::Winter, "January", false}},
    {2, {2, 28, Season::Winter, "February", true}},
    {3, {3, 31, Season::Spring, "March", false}},
    {4, {4, 30, Season::Spring, "April", false}},
    {5, {5, 31, Season::Spring, "May", false}},
    {6, {6, 30, Season::Summer, "June", false}},
    {7, {7, 31, Season::Summer, "July", false}},
    {8, {8, 31, Season::Summer, "August", false}},
    {9, {9, 30, Season::Autumn, "September", false}},
    {10, {10, 31, Season::Autumn, "October", false}},
    {11, {11, 30, Season::Autumn, "November", false}},
    {12, {12, 31, Season::Winter, "December", false}}};

class Date
{
private:
    // underlying date is stored in unix time
    int unixTime;

public:
    // construct with a unix timestamp
    Date(int unixTime);

    // construct with year, month, day
    Date(YearMonthDay yearMonthDay);

    // construct with current date
    Date();

    // get if a given year is a leap year
    static int getIsLeapYear(int year);

    // get the number of days in a month
    static int getDaysInMonth(int year, int month);

    // get the number of days in a year
    static int getDaysInYear(int year);

    // check if a yearMonthDay looks legit
    static void validateYearMonthDay(YearMonthDay yearMonthDay);

    // convert year, month, day to unix time
    static int yearMonthDayToUnix(YearMonthDay yearMonthDay);

    // convert unix time to year
    static YearMonthDay unixToYearMonthDay(int unixTime);

    // get the info for a month
    static MonthInfo getMonthInfo(int month);

    // get the underlying unix time
    int getUnix();

    // get the year, month, day
    YearMonthDay getYearMonthDay();

    // convert to a readable string
    std::string toReadableString();

    // check if this date is after a given date
    bool isAfter(Date date);
};

#endif