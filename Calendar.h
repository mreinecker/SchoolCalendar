//
// Created by Marc Reinecker on 9/22/17.
//

#ifndef FINAL_2_CALENDAR_H
#define FINAL_2_CALENDAR_H


#include <ostream>

class Calendar {
// data members store warner bool and month week and day
	int _month;
	int _day;
	int _week;
	bool warner;
// warner month week and day
	int _warn_month;
	int _warn_day;
	int _warn_week;

public:

	// default constructor
	Calendar();
	// constructor with arguments
	Calendar(int month, int day, int week);
	// getters and setters
	int getMonth() const;

	void setMonth(int month);

	int getDay() const;

	void setDay(int day);

	int getWeek() const;

	void setWeek(int week);

	void setDate(int day, int week, int month);

	void getDate();

	bool isWarner() const;

	// set warner function
	void setWarner(bool warner);
	// set warner date function
	void setWarnerDate(int wmonth, int wweek, int wday);
	// increment semester date by passing in an amount in days
	void incrementDate(int amount);
	// warn student function if warner enabaled
	void warnStudent();
	// overloaded << operator to properly format and make displaying date easier
	friend std::ostream &operator<<(std::ostream &os, const Calendar &calendar);


};


#endif //FINAL_2_CALENDAR_H
