#include <iostream>
#include "Calendar.h"

int main() {

	Calendar calendar; // instantiate calender object for use below
	bool enter = true; // used to enter while loop below

	while(enter) {
		// display menu
		std::cout << "\nHello!"
		          << "\nWelcome to the school calendar"
		          << "\nPlease login as a (1)student or (2)teacher"
		          << "\nEnter a choice (1 or 2) and hit enter:\t"
		          << std::endl;

		int choice{0};
		std::cin >> choice; // get menu choice

		switch (choice) {
			case 1: {
				// student
				std::cout << "\nThe current semester date is: "
				          << calendar
				          << std::endl;
				// ask for days to increment into semester, initialized to 1/1/1
				std::cout << "\nHow many days would you like to advance the calendar?"
				          << "\nEnter a number in days:\t"
				          << std::endl;
				int day_increment{0};
				std::cin >> day_increment;
				// call date increment function
				calendar.incrementDate(day_increment);
				// display new semester date
				std::cout << "\nThe new current semester date is: "
				          << calendar
				          << std::endl;
				// warn student if warner enabled and date matches by calling function
				// function will not return warning if not enabled through teacher menu
				calendar.warnStudent();

				// allow to get back into menu or exit
				std::cout << "\n(1)Main Menu \n(2)Exit"
				          << "\nEnter a choice (1 or 2) and hit enter:\t"
				          << std::endl;

				int enter_choice{0};
				std::cin >> enter_choice;
				enter = enter_choice == 1 ? true : false;
				break;
			}
			case 2: {
				// teacher
				std::cout << "\nThe current semester date is: "
				          << calendar
				          << std::endl;
				// allow teacher to increment semester days
				std::cout << "\nHow many days would you like to advance the calendar?"
				          << "\nEnter a number in days:\t"
				          << std::endl;
				int day_increment{0};
				std::cin >> day_increment;
				calendar.incrementDate(day_increment);
				// display new semester date after incrementing
				std::cout << "\nThe new current semester date is: "
				          << calendar
				          << std::endl;
				// allow teacher to set warning
				std::cout << "\nWould you like to set a warning for students?"
				          << "\nThe warning will notify when the last day is to drop a class"
				          << "\nEnter (1) to enable warning and \n(2) to proceed without setting a warning:\t"
				          << std::endl;
				// get menu choice
				int w_choice{0};
				std::cin >> w_choice;

				if (w_choice == 1) {
					// set warner
					calendar.setWarner(true);
					int day{0};
					int week{0};
					int month{0};
					std::cout << "\nPlease enter the semester month, week and day to warn students:\t"
					          << std::endl;
					std::cout << "\nMonth:\t" << std::endl;
					std::cin >> month;
					std::cout << "\nWeek:\t" << std::endl;
					std::cin >> week;
					std::cout << "\nDay:\t" << std::endl;
					std::cin >> day;
					calendar.setWarnerDate(month, week, day);

					std::cout << "\nWarning set successfully!"
					          << std::endl;
				}
				// allow to go back to menu
				std::cout << "\n(1)Main Menu \n(2)Exit"
				          << "\nEnter a choice (1 or 2) and hit enter:\t"
				          << std::endl;

				int enter_choice{0};
				std::cin >> enter_choice;
				enter = enter_choice == 1 ? true : false;

				break;
			}
			default: {
				std::cout << "\nInvalid entry, please try again."
				          << std::endl;
			}
		}
	}
	return 0;
}