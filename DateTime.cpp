#include "DateTime.h"

DateTime::DateTime() {
	setCurrent();
}

string DateTime::timePassed() {

	DateTime now;

	stringstream ss;
	string convertedInt;

	if (now.year - year){
		ss << (now.year - year);
		ss >> convertedInt;
		ss.clear();
		return convertedInt + " years";
	}
	if (now.month - month){
		ss << (now.month - month);
		ss >> convertedInt;
		ss.clear();
		return convertedInt + " months";
	}
	if (now.day - day){
		ss << (now.day - day);
		ss >> convertedInt;
		ss.clear();
		return convertedInt + " days";
	}
	if (now.hour - hour){
		ss << (now.hour - hour);
		ss >> convertedInt;
		ss.clear();
		return convertedInt + " hours";
	}

	ss << (now.minute - minute);
	ss >> convertedInt;
	ss.clear();
	return	convertedInt + " minutes";

}

bool  DateTime::validDate(string &DDMMYY) {

	stringstream ss;
		int convertedString;

	if (DDMMYY[1] == '/')
		DDMMYY.insert(0, "0");
	if (DDMMYY[4] == '/')
		DDMMYY.insert(3, "0");

	if (DDMMYY.size() != 10)
		return false;

	int day;
	if (isdigit(DDMMYY[0]) && isdigit(DDMMYY[1])) {
		string DD;
		DD += DDMMYY[0];
		DD += DDMMYY[1];
		ss << DD;
		ss >> convertedString;
		ss.clear();
		day = convertedString;
	}
	else
		return false;

	int month;
	if (isdigit(DDMMYY[3]) && isdigit(DDMMYY[4])) {
		string MM;
		MM += DDMMYY[3];
		MM += DDMMYY[4];
		ss << MM;
		ss >> convertedString;
		ss.clear();
		month = convertedString;
	}
	else
		return false;

	int year;
	if (isdigit(DDMMYY[6]) && isdigit(DDMMYY[7]) && isdigit(DDMMYY[8]) && isdigit(DDMMYY[9])){
		ss << DDMMYY.substr(6, 4);
		ss >> convertedString;
		ss.clear();
		year = convertedString;
	}
	else
		return false;

	return validDate(day, month, year);
}


bool DateTime::validDate(int day, int month, int year) {
	int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 1850 || year > 2100)
		return false;

	if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		daysInMonths[1] = 29;  // Feb has 29 days in leap year

	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > daysInMonths[month - 1])
		return false;

	return true;
}

string DateTime::whatDay(int D, int M, int Y) {
	if (M == 1) {
		M = 13;
		Y--;
	}
	if (M == 2) {
		M = 14;
		Y--;
	}

	long long day, k, j;

	k = Y % 100;
	j = Y / 100;
	day = D + 13 * (M + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
	day = day % 7;

	if (day == 0)
		return ("Sat");
	else if (day == 1)
		return ("Sun");
	else if (day == 2)
		return ("Mon");
	else if (day == 3)
		return ("Tue");
	else if (day == 4)
		return ("Wed");
	else if (day == 5)
		return ("Thu");
	else
		return ("Fri");

}

void DateTime::setCurrent() {
	time_t now = time(NULL);
	string dateTime = ctime(&now);

	stringstream ss;
	int convertedString;

	for (int i = 0, counter = 0, n = dateTime.size() ; i < n ; i++, counter++) {
		string tmp;
		while (dateTime[i] != ' ' && dateTime[i] != '\n' && dateTime[i] != ':') {
			tmp += dateTime[i];
			i++;
		}

		if (counter == 0)
			dayName = tmp;
		else if (counter == 1) {
			string M[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
			for (int j = 0; j < 12; j++) {
				if (M[j] == tmp)
					month = j + 1;
			}
		}
		else if (counter == 2){
			ss << tmp;
			ss >> convertedString;
			ss.clear();
			day = convertedString;
		}
		else if (counter == 3){
			ss << tmp;
			ss >> convertedString;
			ss.clear();
			hour = convertedString;
		}
		else if (counter == 4){
			ss << tmp;
			ss >> convertedString;
			ss.clear();
			minute = convertedString;
		}
		else if (counter == 5){
			ss << tmp;
			ss >> convertedString;
			ss.clear();
			second = convertedString;
		}
		else{
			ss << tmp;
			ss >> convertedString;
			ss.clear();
			year = convertedString;
		}
	}

}

void DateTime::setDate(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
	dayName = whatDay(day, month, year);
}
void DateTime::setDate(string DDMMYY) {

	stringstream ss;
		int convertedString;


	if (validDate(DDMMYY)) {
		ss << DDMMYY.substr(0, 2);
		ss >> convertedString;
		ss.clear();
		day = convertedString;
		ss << DDMMYY.substr(3, 2);
		ss >> convertedString;
		ss.clear();
		month = convertedString;
		ss << DDMMYY.substr(6, 4);
		ss >> convertedString;
		ss.clear();
		year = convertedString;
		dayName = whatDay(day, month, year);
	}
	else
		throw "Invalid date.";
}
void DateTime::setTime(int second, int minute, int hour) {
	this->second = second;
	this->minute = minute;
	this->hour = hour;
}
void DateTime::setDayName(string dayName) {
	this->dayName = dayName;
}
void DateTime::setDayNumber(int dayNumber) {
	day = dayNumber;
}
void DateTime::setMonth(int month) {
	this->month = month;
}
void DateTime::setYear(int year) {
	this->year = year;
}
void DateTime::setSecond(int second) {
	this->second = second;
}
void DateTime::setMinute(int minute) {
	this->minute = minute;
}
void DateTime::setHour(int hour) {
	this->hour = hour;
}

string DateTime::getDate() {

	stringstream ss;
	string convertedInt;


	string date;

	date = dayName + " " ;
	ss << day;
	ss >> convertedInt;
	ss.clear ();

	date+=convertedInt;
	date += "/";

	ss << month;
	ss >> convertedInt;
	ss.clear ();

	date += convertedInt;
	date += "/";

	ss << year;
	ss >> convertedInt;
	ss.clear ();

	date+= convertedInt;

	return date;
}

string DateTime::getDayName() {
	return dayName;
}
int DateTime::getDayNumber() {
	return day;
}
int DateTime::getMonth() {
	return month;
}
int DateTime::getYear() {
	return year;
}
string DateTime::getTime() {

	stringstream ss;
	string convertedInt;
	string time;

	ss << hour;
	ss >> convertedInt;
	ss.clear();

	time = convertedInt + ":";

	ss << minute;
	ss >> convertedInt;
	ss.clear();

	time+= convertedInt;
	time+= ":";

	ss << second;
	ss >> convertedInt;
	ss.clear();

	time+= convertedInt;

	return time;
}

int DateTime::getSecond() {
	return second;
}
int DateTime::getMinute() {
	return minute;
}
int DateTime::getHour() {
	return hour;
}

ostream &operator<<(ostream &out, const DateTime &date) {
//	out << date.getDate();
	out << date.minute << " " << date.day << "/" << date.month << "/" << date.year;

	return out;
}
