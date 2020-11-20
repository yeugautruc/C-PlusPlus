#include <string>
#include "FileName.h"

DateTime::DateTime()
{
	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	min = 0;
	sec = 0;
	millisec = 0;
}

DateTime::DateTime(std::string date, std::string time)
{
	readData(date, time);
}

DateTime::DateTime(const DateTime& input){
        this->year = input.year;
        this->month = input.month;
        this->day = input.day;
        this->hour = input.hour;
        this->min = input.min;
        this->sec = input.sec;
        this->millisec = input.millisec;
    }

void DateTime::readData(std::string date, std::string time)
{
	year = stoi(readData(date, '-'));
	month = stoi(readData(date, '-'));
	day = stoi(date);
	hour = stoi(readData(time, '-'));
	min = stoi(readData(time, '-'));
	sec = stoi(readData(time, '-'));
	millisec = stoi(time);
}

std::string DateTime::readData(std::string &input, char delimiter)
{
	std::string output = input.substr(0, input.find(delimiter));
	input.erase(0, input.find(output) + output.length() + 1);
	return output;
}

std::string DateTime::toString()
{
	return " (" + std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year) + "-" + std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(sec) + "):";
}

void DateTime::setYear(int year){
	this->year = year;
};
void DateTime::setMonth(int month){
	this->month = month;
};
void DateTime::setDay(int day){
	this->day = day;
};
void DateTime::setHour(int hour){
	this->hour = hour;
};
void DateTime::setMin(int min){
	this->min = min;
};
void DateTime::setSec(int sec){
	this->sec = sec;
};
void DateTime::setMilisec(int milisec){
	this->millisec = milisec;
};

const int DateTime::getYear(int year){
	return year;
};
const int DateTime::getMonth(int month){
	return month;
};
const int DateTime::getDay(int day){
	return day;
};
const int DateTime::getHour(int hour){
	return hour;
};
const int DateTime::getMin(int min){
	return min;
};
const int DateTime::getSec(int sec){
	return sec;
};
const int DateTime::getMilisec(int milisec){
	return milisec;
};

DateTime::~DateTime()
{
}
