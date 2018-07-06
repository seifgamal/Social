#ifndef SOCIAL_DATETIME_H
#define SOCIAL_DATETIME_H

#include <bits/stdc++.h>

using namespace std;

class DateTime {
private:
	int day, month, year;
	int second, minute, hour;
	string dayName, monthName;
	bool validDate(int day, int month, int year);
	bool validDate(string &DDMMYY);

	void setCurrent();
public:
	DateTime();

	static string whatDay(int Y, int M, int D); // formula

	string timePassed();

	string getDate(); // dayName DD/MM/YY
	void setDate(int day, int month, int year);
	void setDate(string DDMMYY); // DD/MM/YYYY format

	string getTime();
	void setTime(int second, int minute, int hour);

	string getDayName();
	void setDayName(string);
	int getDayNumber();
	void setDayNumber(int);
	int getMonth();
	void setMonth(int);
	int getYear();
	void setYear(int);
	int getSecond();
	void setSecond(int);
	int getMinute();
	void setMinute(int);
	int getHour();
	void setHour(int);

	friend ostream &operator<<(ostream &out, const DateTime &date);
};


#endif //SOCIAL_DATETIME_H
