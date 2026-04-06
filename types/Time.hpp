#include <iostream>
using namespace std;
struct Time
{
    int hour;
    int minute;
    int second;
};
struct Date
{
    int day;
    int month;
    int year;
};
int checkLegalDate(int day, int month, int year)
{
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return 0;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        daysInMonth[1] = 29; // Năm nhuận
    return day <= daysInMonth[month - 1];
}
enum DayOfWeek
{
    Sunday = 1,
    Monday = 2,
    Tuesday = 3,
    Wednesday = 4,
    Thursday = 5,
    Friday = 6,
    Saturday = 7
};
DayOfWeek calculateDayOfWeek(int day, int month, int year)
{
    if (month < 3)
    {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int f = day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 - 2 * j;
    return static_cast<DayOfWeek>((f % 7 + 7) % 7 + 1); // Đảm bảo kết quả dương
}

class DateTime
{
public:
    Date date;
    Time time;
    DayOfWeek dayOfWeek;
    DateTime()
    {
        date.day = 1;
        date.month = 1;
        date.year = 2006;
        time.hour = 0;
        time.minute = 0;
        time.second = 0;
        dayOfWeek = calculateDayOfWeek(date.day, date.month, date.year);
    }
    DateTime(int day, int month, int year, int hour, int minute, int second)
    {
        if (!checkLegalDate(day, month, year))
        {
            throw invalid_argument("Invalid date");
        }
        date.day = day;
        date.month = month;
        date.year = year;
        time.hour = hour;
        time.minute = minute;
        time.second = second;
        dayOfWeek = calculateDayOfWeek(day, month, year);
    }
};