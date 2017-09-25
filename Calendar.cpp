//
// Created by Marc Reinecker on 9/22/17.
//

#include "Calendar.h"
#include <iostream>

// default constructor
Calendar::Calendar() {
	_week = 1;
	_month = 1;
	_day = 1;
	warner = false;
	_warn_month = 0;
	_warn_day = 0;
	_warn_week = 0;
}

// constructor with arguments, initializes warner dates to 0 and warner to false
Calendar::Calendar(int month, int day, int week) : _month(month), _day(day), _week(week) {
	warner = false;
	_warn_month = 0;
	_warn_day = 0;
	_warn_week = 0;

}
// getters and setters
int Calendar::getMonth() const {
	return _month;
}

void Calendar::setMonth(int month) {
	Calendar::_month = month;
}

int Calendar::getDay() const {
	return _day;
}

void Calendar::setDay(int day) {
	Calendar::_day = day;
}

int Calendar::getWeek() const {
	return _week;
}

void Calendar::setWeek(int week) {
	Calendar::_week = week;
}

bool Calendar::isWarner() const {
	return warner;
}

void Calendar::setWarner(bool warner) {
	Calendar::warner = warner;
}

void Calendar::setDate(int day, int week, int month) {

	this->_day = day;
	this->_week = week;
	this->_month = month;

}

void Calendar::getDate() {

	std::cout << this;

}

std::ostream &operator<<(std::ostream &os, const Calendar &calendar) {
	os << "Month: " << calendar._month << " Week: " << calendar._week << " Day: " << calendar._day;
	return os;
}

void Calendar::incrementDate(int amount) {

bool end = false;
// date increment will increment day, week or month
	for (int i = 0; i < amount; ++i) {
		++_day;
		if (_day > 7){
			_day = 1;
			++_week;
			if (_week > 4){
				_week = 1;
				++_month;
				if (_month > 12){
					_month = 12;
					end = true;
				}
			}
		}
	}
// stop at month 12
	if (end){
		std::cout << "\nThe semester ended. Cannot go past month 12!" << std::endl;
	}
}
// warn student if enabled and date set, if date matches current semester date
void Calendar::warnStudent() {
	if (this->warner) {
		if (_warn_month == _month && _warn_week == _week && _warn_day == _day) {
			std::cout << "\nTODAY IS THE LAST DAY TO DROP THE COURSE"
			          << std::endl;
		}
	}
}

// set warner date function
void Calendar::setWarnerDate(int wmonth, int wweek, int wday) {
	_warn_day = wday;
	_warn_week = wweek;
	_warn_month = wmonth;
}
