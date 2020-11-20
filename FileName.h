#pragma once
#include <string>

class DateTime
{
private:
    /* data */
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int millisec;

public:
    DateTime();

    DateTime(std::string date, std::string time);

    DateTime(const DateTime& input);

    void readData(std::string date, std::string time);

    std::string readData(std::string &input, char delimiter);

    std::string toString();

    ~DateTime();

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setHour(int hour);
    void setMin(int min);
    void setSec(int sec);
    void setMilisec(int milisec);

    const int getYear(int year);
    const int getMonth(int month);
    const int getDay(int day);
    const int getHour(int hour);
    const int getMin(int min);
    const int getSec(int sec);
    const int getMilisec(int milisec);
};